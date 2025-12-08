; Trabalho 4 - Programa Timer-Serial-ADC
; Integrante 1: Fernando Hiroshi Murusaki (RA 241025851)
; Integrante 2: Igor dos Reis Gomes (RA 241025265) 

; FUNCIONAMENTO E OBJETIVO
; O objetivo deste programa é controlar a velocidade do piscar de um LED (conectado ao pino RB7) através de 
; comandos numericos enviados pela comunicação serial e ADC. O programa opera em duas partes principais:
; 1. Interrupção (Timer0): O Timer0 gera interrupções 125 vezes por segundo que decrementam o contador TIQUES e, quando TIQUES chega a 0, o LED tem seu estado invertido
; 2. Laço Principal (Serial e ADC): O programa fica em um laço infinito monitorando a porta serial. Ao receber o byte:
;    - Se for 1, 2, 3 ou 4: Atualiza TIQUES para 0.125s, 0.25s, 0.5s ou 1s e retorna o valor configurado.
;    - Se for 5: Lê a tensão no pino analógico (ADC), define a velocidade conforme a faixa de tensão (0-255, 256-511, etc.)
;      e envia de volta 3 bytes: Byte Alto do ADC, Byte Baixo do ADC e o valor de TIQUES que foi configurado.

; Configuracoes iniciais do PIC
#INCLUDE <P16F873A.INC>    
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _BOREN_ON & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF

; --- Definições de variáveis usadas no programa ---
TIQUES          EQU 0x20 ; Variavel TIQUES que realiza o controle do LED ao entrar na interrupção (contador decrementa)
TIQUES_RECEBIDO EQU 0x21 ; Valor total de TIQUES que foi recebido. Usado para recarregar TIQUES quando chega em 0
BYTE_RECEBIDO   EQU 0x22 ; Variavel para armazenar o byte recebido da porta serial

; --- Definições de variáveis para o funcionamento do ADC ---
ADC_ALTO        EQU 0x23 ; Armazena a parte Alta (High) do valor lido no ADC
ADC_BAIXO        EQU 0x24 ; Armazena a parte Baixa (Low) do valor lido no ADC
DELAY_ADC       EQU 0x25 ; Variavel auxiliar para gerar o delay de aquisição do ADC

ORG 0x0000
    	
    GOTO INICIO

ORG 0x0004		        ; Tratamento da interrupção
    BCF INTCON, T0IF    ; Limpa a flag de interrupção do Timer0
    MOVLW D'131'		; Valor calculado para gerar interrupções a cada 8ms com base no clock de 4Mhz
    MOVWF TMR0          ; Recarrega o Timer0

    ; --- Lógica para piscar o LED em RB7 (Controlado via Serial) ---

        DECFSZ TIQUES, F    ; Decrementa TIQUES
        GOTO FIM_INT        ; Se TIQUES nao for 0, vai para o fim

        ; Se TIQUES for 0, o LED pisca:
        BANKSEL PORTB
        MOVLW B'10000000'   ; Mascara para o LED RB7
        XORWF PORTB, F      ; Inverte o LED

        MOVF TIQUES_RECEBIDO, W    ; Carrega o valor variavel de TIQUES_RECEBIDO em W
        MOVWF TIQUES               ; Reinicia TIQUES com o valor recebido

    FIM_INT:
        RETFIE              ; Retorna da interrupção

INICIO:
    ; --- Configuração de Entrada/Saída ---
    BANKSEL TRISB         ; Seleciona o banco de memória 1 para acessar o registrador TRISB
    CLRF TRISB            ; Limpa o TRISB, configurando todos os pinos do PORTB como sa�da

    ; [NOVO] Configuração do pino do ADC (RA0)
    BANKSEL TRISA         ; Seleciona o banco de memória 1 para acessar TRISA
    BSF TRISA, 0          ; Configura o pino RA0 como entrada (para o ADC)

    BANKSEL TRISC         ; Seleciona o banco de memória 1 para acessar o registrador TRISC
    MOVLW B'10000000'     ; Carrega em W a configuração (RC7 = RX (ENTRADA) e RC6 = TX (SAIDA))
    MOVWF TRISC           ; Move a configuração de W para o TRISC
    
    BANKSEL PORTB         ; Seleciona o banco de memória 0 para acessar o registrador PORTB
    CLRF PORTB            ; Limpa o PORTB, garantindo que todos os pinos de sa�da iniciem desligados

    ; --- Configuração da Comunicação Serial ---
    BANKSEL TXSTA         ; Seleciona o banco de memória 1 para acessar TXSTA
    MOVLW b'00100100'     ; Carrega em W a config (TXEN = 1, BRGH  1, ASYNC)
    MOVWF TXSTA           ; Move a configura��o de W para o TXSTA
    
    BANKSEL RCSTA         ; Seleciona o banco de memória 0 para acessar RCSTA
    MOVLW b'10010000'     ; Carrega em W a config (SPEN = 1, CREN = 1)
    MOVWF RCSTA           ; Move a configuração de W para o RCSTA

    BANKSEL SPBRG         ; Seleciona o banco de memória 1 para acessar SPBRG
    MOVLW d'25'           ; Carrega em W o valor 25, ideal para Baud Rate de 9600
    MOVWF SPBRG           ; Move o valor de W para o SPBRG
    
    ; --- Configuração do Timer ---
    BANKSEL INTCON        ; Seleciona o banco de memória onde está o registrador INTCON
    MOVLW B'10100000'     ; Carrega em W o valor para habilitar a interrupção global (GIE) e a do Timer0 (T0IE)
    MOVWF INTCON          ; Move a configuração de W para o INTCON

    BANKSEL OPTION_REG    ; Seleciona o banco de memória 1 para acessar o registrador OPTION_REG
    MOVLW B'10000101'     ; Carrega em W o valor para configurar o Timer0 com prescaler de 1:64
    MOVWF OPTION_REG      ; Move a configuração de W para o OPTION_REG

    BANKSEL TMR0          ; Seleciona o banco de memória 0 para acessar o registrador TMR0
    MOVLW D'131'          ; Carrega o valor inicial do timer (131) em W
    MOVWF TMR0            ; Move o valor de W para o TMR0

    ; --- Configuração do Conversor ADC ---
    BANKSEL ADCON0        ; Seleciona o banco 0
    MOVLW B'01000001'     ; Configura Fosc/8, Canal AN0, e liga o módulo (ADON=1)
    MOVWF ADCON0          ; Move o valor de W para ADCON0

    BANKSEL ADCON1        ; Seleciona o banco 1
    MOVLW B'10000000'     ; Configura ADFM = 1 e portas como analógicas
    MOVWF ADCON1          ; Move para ADCON1
    
    ; --- Inicialização das variaveis de contagem (de inicio LED pisca a cada 0.125s) ---
    MOVLW D'15'           ; Carrega o valor inicial 15 em W
    MOVWF TIQUES_RECEBIDO ; Inicializa a variavel que define TIQUES com 15
    MOVWF TIQUES          ; Inicializa a variavel de contagem atual com 15

    ; --- Laço de espera de recebimento de um byte ---
    RECEBE_BYTE:
        BANKSEL PIR1          ; Seleciona o banco para acessar a flag de recepção
        BTFSS PIR1, RCIF      ; Testa a flag RCIF. Se for 1, o byte chegou
        GOTO RECEBE_BYTE      ; Se não chegou (0), entra em loop, voltando para RECEBE_BYTE até receber 0.
        ; Quando o byte é recebido:
        BANKSEL RCREG         ; Seleciona o banco do registrador de recepção
        MOVF RCREG, W         ; Lê o byte recebido para W
        MOVWF BYTE_RECEBIDO   ; Salva o byte na variável auxiliar

    ; --- Verificação de qual byte foi recebido ---
    ; Checa se leitura foi 1
    VERIFICA1:
        DECFSZ BYTE_RECEBIDO, F     ; BYTE_RECEBIDO vira (BYTE_RECEBIDO - 1). O resultado é 0?
        GOTO VERIFICA2              ; NAO: Pula para testar se era 2
        GOTO VALOR_UM               ; SIM (era 1): Pula para a ação de VALOR_UM

    ; Checa se leitura foi 2
    VERIFICA2: 
        DECFSZ BYTE_RECEBIDO, F     ; BYTE_RECEBIDO vira (BYTE_RECEBIDO - 1). O resultado é 0?
        GOTO VERIFICA3              ; NAO: Pula para testar se era 3
        GOTO VALOR_DOIS             ; SIM (era 2): Pula para a ação de VALOR_DOIS

    ; Checa se leitura foi 3
    VERIFICA3: 
        DECFSZ BYTE_RECEBIDO, F     ; BYTE_RECEBIDO vira (BYTE_RECEBIDO - 1). O resultado é 0?
        GOTO VERIFICA4              ; NAO: Pula para testar se era 4
        GOTO VALOR_TRES             ; SIM (era 3): Pula para a ação de VALOR_TRES

    ; Checa se leitura foi 4
    VERIFICA4: 
        DECFSZ BYTE_RECEBIDO, F     ; BYTE_RECEBIDO vira (BYTE_RECEBIDO - 1). O resultado é 0?
        GOTO VERIFICA5              ; NAO: Pula para testar se era 5
        GOTO VALOR_QUATRO           ; SIM (era 4): Pula para a ação de VALOR_QUATRO

    ; Checa se leitura foi 5
    VERIFICA5:
        DECFSZ BYTE_RECEBIDO, F     ; BYTE_RECEBIDO vira (BYTE_RECEBIDO - 1). O resultado é 0?
        GOTO RECEBE_BYTE            ; NAO (era > 5 ou 0): Ignora e volta a ler
        GOTO TRATAR_ADC             ; SIM (era 5): Pula para a rotina do ADC

    VALOR_UM:
        MOVLW D'15'           ; Carrega o valor decimal 15 em W (~0.125s)
        GOTO ATUALIZA_E_ENVIA

    VALOR_DOIS:
        MOVLW D'31'           ; Carrega o valor decimal 31 em W (~0.25s)
        GOTO ATUALIZA_E_ENVIA

    VALOR_TRES:
        MOVLW D'62'           ; Carrega o valor decimal 62 em W (~0.5s)
        GOTO ATUALIZA_E_ENVIA

    VALOR_QUATRO:
        MOVLW D'125'          ; Carrega o valor decimal 125 em W (~1s)
        GOTO ATUALIZA_E_ENVIA

    ATUALIZA_E_ENVIA:
        MOVWF TIQUES          ; Reinicia o contador atual
        MOVWF TIQUES_RECEBIDO ; Define o contador de TIQUES_RECEBIDO
        CALL ENVIA_W_SERIAL   ; Chama subrotina para enviar o valor em W
        GOTO RECEBE_BYTE      ; Volta ao laço principal

    ; Rotina para tratamento do ADC (Quando valor 5 foi recebido) ---
    TRATAR_ADC:
        ; Delay de Aquisição do byte
        MOVLW D'20'
        MOVWF DELAY_ADC

    LOOP_DELAY:
        DECFSZ DELAY_ADC, F
        GOTO LOOP_DELAY

        ; Inicia Conversão
        BANKSEL ADCON0
        BSF ADCON0, 2         ; Seta bit GO/DONE para iniciar conversão

    ESPERA_CONVERSAO:
        BTFSC ADCON0, 2       ; Testa bit GO/DONE. Se for 0, terminou
        GOTO ESPERA_CONVERSAO ; Se for 1, continua esperando

        ; Lê o resultado
        BANKSEL ADRESH
        MOVF ADRESH, W     ; Lê os 2 bits mais significativos
        MOVWF ADC_ALTO     ; Salva na variavel

        BANKSEL ADRESL
        MOVF ADRESL, W     ; Lê os 8 bits menos significativos
        BANKSEL ADC_BAIXO   ; Volta para o banco 0
        MOVWF ADC_BAIXO     ; Salva na variavel

        ; Define velocidade baseada no Byte Alto (ADRESH)
        ; Se Byte Alto = 0 - Testa se é Faixa 0 (0V a 1.25V / Valor 0-255)
        MOVF ADC_ALTO, W   ; Copia o valor da variável ADC_ALTO para W
        SUBLW D'0'         ; Operação: 0 - W
        BTFSC STATUS, Z    
        GOTO FAIXA_0       ; resultado da operação igual a 0, vai para FAIXA_0

        ; Se Byte Alto = 1 - Testa se é Faixa 1 (1.25V a 2.5V / Valor 256-511)
        MOVF ADC_ALTO, W   ; Copia o valor da variável ADC_ALTO para W
        SUBLW D'1'         ; Operação: 1 - W
        BTFSC STATUS, Z
        GOTO FAIXA_1       ; resultado da operação igual a 0, vai para FAIXA_1

        ; Se Byte Alto = 2 - Testa se é Faixa 2 (2.5V a 3.75V / Valor 512-767)
        MOVF ADC_ALTO, W   ; Copia o valor da variável ADC_ALTO para W
        SUBLW D'2'         ; Operação: 2 - W
        BTFSC STATUS, Z
        GOTO FAIXA_2       ; resultado da operação igual a 0, vai para FAIXA_2

        ; Senão, assume Byte Alto = 3 (3.75V a 5V / Valor 768-1023)
        GOTO FAIXA_3

    FAIXA_0:
        MOVLW D'12'           ; Carrega o valor 12 em W (12 * 8ms = ~0.10s)
        GOTO FINALIZA_ADC
    FAIXA_1:
        MOVLW D'20'           ; Carrega o valor 20 em W (20 * 8ms = ~0.16s)
        GOTO FINALIZA_ADC
    FAIXA_2:
        MOVLW D'30'           ; Carrega o valor 30 em W (30 * 8ms = ~0.24s)
        GOTO FINALIZA_ADC
    FAIXA_3:
        MOVLW D'40'           ; Carrega o valor 40 em W (30 * 8ms = ~0.32s)
        GOTO FINALIZA_ADC

    FINALIZA_ADC:
        MOVWF TIQUES          ; Atualiza TIQUES
        MOVWF TIQUES_RECEBIDO ; Atualiza variável de recarga

        ; Envia os 3 bytes (alto, baixo e Tiques)
        MOVF ADC_ALTO, W
        CALL ENVIA_W_SERIAL   ; Envia Byte Alto
        
        MOVF ADC_BAIXO, W
        CALL ENVIA_W_SERIAL   ; Envia Byte Baixo
        
        MOVF TIQUES_RECEBIDO, W
        CALL ENVIA_W_SERIAL   ; Envia novo valor de Tiques

        GOTO RECEBE_BYTE      ; Volta ao laço principal

    ; --- Subrotina para Enviar Byte ---
    ENVIA_W_SERIAL:
        BANKSEL PIR1          ; Seleciona o banco para acessar a flag de transmissão
        BTFSS PIR1, TXIF      ; Testa a flag TXIF. Se for 1 (livre), pula
        GOTO ENVIA_W_SERIAL   ; Se não (ocupado), espera
        
        BANKSEL TXREG         ; Seleciona o banco do registrador de transmissão
        MOVWF TXREG           ; Envia o byte que está em W
        
        BANKSEL PORTB         ; Garante retorno ao Banco 0
        RETURN                ; Retorna para quem chamou

        END