; Trabalho 1 - Programa Timer e Serial
; Integrantes: Fernando Hiroshi Murusaki e Igor dos Reis Gomes

; FUNCIONAMENTO E OBJETIVO
; O objetivo deste programa é controlar a velocidade do piscar de um LED (conectado ao pino RB7) através de 
; comandos numéricos enviados pela comunicação serial. O programa opera em duas partes principais:
; 1. Interrupção (Timer0): O Timer0 gera interrupções 125 vezes por segundo que decrementam o contador TIQUES e, quando TIQUES chega a 0, o LED tem seu estado invertido
; 2. Laço Principal (Serial): O programa fica em um laço infinito (RECEBE_BYTE) monitorando a porta serial. Ao receber o byte,
; verifica se é o valor 1, 2, 3 ou 4. Se for algum desses numeros, ele atualiza as variáveis TIQUES e TIQUES_RECEBIDO para um novo valor (15, 31, 62 ou 125),
; mudando assim a velocidade em que o LED pisca: 0.125s, 0.25s, 0.5s ou 1s, respectivamente.
; Após a atualização, o programa envia de volta pela serial o valor numérico que acabou de configurar

; Configuracoes iniciais do PIC
#INCLUDE <P16F873A.INC>    
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _BOREN_ON & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF

; Definição de variaveis usadas no programa
TIQUES EQU 0x20 ; Variavel TIQUES que realiza o controle do LED ao entrar na interrupção (contador decrementa)
TIQUES_RECEBIDO EQU 0x21 ; Valor total de TIQUES que foi recebido. Usado para recarregar TIQUES quando chega em 0
BYTE_RECEBIDO EQU 0x22 ; Variavel para armazenar o byte recebido da porta serial


ORG 0x0000
    	
    GOTO INICIO

ORG 0x0004		        ; Tratamento da interrupção
    BCF INTCON, T0IF    ; Limpa a flag de interrupção do Timer0
    MOVLW D'131'
    MOVWF TMR0          ; Recarrega o Timer0

    ; --- Lógica para piscar o LED em RB7 (Controlado via Serial) ---

        DECFSZ TIQUES, F    ; Decrementa TIQUES
        GOTO FIM_INT        ; Se TIQUES não for 0, vai para o fim

        ; Se TIQUES for 0, o LED pisca:
        BANKSEL PORTB
        MOVLW B'10000000'   ; Máscara para o LED RB7
        XORWF PORTB, F      ; Inverte o LED

        MOVF TIQUES_RECEBIDO, W    ; Carrega o valor variável de TIQUES_RECEBIDO em W
        MOVWF TIQUES               ; Reinicia TIQUES com o valor recebido

    FIM_INT:
        RETFIE              ; Retorna da interrupção

INICIO:
    ; --- Configuração de Entrada/Saída ---
    BANKSEL TRISB         ; Seleciona o banco de memória 1 para acessar o registrador TRISB
    CLRF TRISB            ; Limpa o TRISB, configurando todos os pinos do PORTB como saída

    BANKSEL TRISC         ; Seleciona o banco de memória 1 para acessar o registrador TRISC
    MOVLW B'10000000'     ; Carrega em W a configuração (RC7 = RX e RC6 = TX)
    MOVWF TRISC           ; Move a configuração de W para o TRISC
    
    BANKSEL PORTB         ; Seleciona o banco de memória 0 para acessar o registrador PORTB
    CLRF PORTB            ; Limpa o PORTB, garantindo que todos os pinos de saída iniciem desligados

    ; --- Configuração da Comunicação Serial ---
    BANKSEL TXSTA         ; Seleciona o banco de memória 1 para acessar TXSTA
    MOVLW b'00100100'     ; Carrega em W a config (TXEN = 1, BRGH  1, ASYNC)
    MOVWF TXSTA           ; Move a configuração de W para o TXSTA
    
    BANKSEL RCSTA         ; Seleciona o banco de memória 0 para acessar RCSTA
    MOVLW b'10010000'     ; Carrega em W a config (SPEN = 1, CREN = 1)
    MOVWF RCSTA           ; Move a configuração de W para o RCSTA

    BANKSEL SPBRG         ; Seleciona o banco de memória 1 para acessar SPBRG
    MOVLW d'25'           ; Carrega em W o valor 25
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
    
    ; --- Inicialização das variaveis de contagem (de inicio LED pisca a cada 0.125 s) - 15 tiques * 8ms por tique = 120 ms = 0.125s ---
    MOVLW D'15'           ; Carrega o valor inicial 15 em W
    MOVWF TIQUES_RECEBIDO ; Inicializa a variável que define TIQUES com 15
    MOVWF TIQUES          ; Inicializa a variável de contagem atual com 15

    ; --- Laço de espera de recebimento de um byte ---
    RECEBE_BYTE:
        BANKSEL PIR1          ; Seleciona o banco para acessar a flag de recepção
        BTFSS PIR1, RCIF      ; Testa a flag RCIF. Se for 1, o byte chegou
        GOTO RECEBE_BYTE      ; Se não chegou (0), salta para a linha anterior e testa de novo

        ; Quando o byte é recebido:
        BANKSEL RCREG         ; Seleciona o banco do registrador de recepção
        MOVF RCREG, W         ; Lê o byte recebido para W
        MOVWF BYTE_RECEBIDO            ; Salva o byte na variável auxiliar

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
        GOTO RECEBE_BYTE            ; NAO (era > 4 ou 0): Ignora e volta a ler
        GOTO VALOR_QUATRO           ; SIM (era 4): Pula para a ação de VALOR_QUATRO

    VALOR_UM:
        MOVLW D'15'           ; Carrega o valor decimal 15 em W (~0.125s)
        MOVWF TIQUES          ; Reinicia o contador atual
        MOVWF TIQUES_RECEBIDO ; Define o contador de TIQUES_RECEBIDO em 0.125s
        GOTO TRANSMITIR_BYTE  ; Pula para a rotina de transmissão do byte de volta

    VALOR_DOIS:
        MOVLW D'31'           ; Carrega o valor decimal 31 em W (~0.25s)
        MOVWF TIQUES
        MOVWF TIQUES_RECEBIDO
        GOTO TRANSMITIR_BYTE

    VALOR_TRES:
        MOVLW D'62'           ; Carrega o valor decimal 62 em W (~0.5s)
        MOVWF TIQUES
        MOVWF TIQUES_RECEBIDO
        GOTO TRANSMITIR_BYTE

    VALOR_QUATRO:
        MOVLW D'125'          ; Carrega o valor decimal 125 em W (~1s)
        MOVWF TIQUES
        MOVWF TIQUES_RECEBIDO
        GOTO TRANSMITIR_BYTE

    ; --- Enviar o Byte de Confirmação ---
    TRANSMITIR_BYTE:
        BANKSEL PIR1          ; Seleciona o banco para acessar a flag de transmissão
        BTFSS PIR1, TXIF      ; Testa a flag TXIF. Se estiver for 1 (buffer vazio), pula
        GOTO TRANSMITIR_BYTE  ; Se não (ocupado), espera
        
        MOVF TIQUES_RECEBIDO, W ; Carrega o valor (15, 31, 62 ou 125) em W (Carrega o valor que foi recebido anteriormente)
        BANKSEL TXREG         ; Seleciona o banco do registrador de transmissão
        MOVWF TXREG           ; Envia o byte
        GOTO RECEBE_BYTE     ; Volta ao laço principal para esperar o próximo byte

        END