; ATIVIDADE DE AULA - TIMER
; NOME: IGOR DOS REIS GOMES
; RA: 241025265

; O programa utiliza o Timer0 para controlar o piscar de três 
; LEDs conectados ao PORTB:
;  RB0 pisca a cada ~0,2 segundos
;  RB1 pisca a cada ~1 segundo
;  RB2 pisca a cada ~1 minuto

; O Timer0 gera interrupções periódicas que decrementam contadores 
; independentes (FLASH, TIQUES e CSEG). Quando cada contador chega 
; a zero, o LED correspondente tem seu estado invertido


#INCLUDE <P16F628A.INC>
__CONFIG _BODEN_ON & _CP_OFF & _PWRTE_ON & _WDT_OFF & _LVP_OFF & _MCLRE_ON & _XT_OSC

TIQUES EQU 0X20             ; variável TIQUES no endereço 0x20
FLASH  EQU 0X21             ; variável FLASH no endereço 0x21
CSEG   EQU 0X22             ; variável CSEG no endereço 0x22


ORG 0X0000

    GOTO INICIO

ORG 0X4                     ; Tratamento da interrupção

    BCF INTCON, T0IF        ; Limpa a flag de interrupção do Timer0 mostrando que ela foi tratada
    MOVLW D'131'            ; Load o valor para TMR0
    MOVWF TMR0              ; Carrega o TMR0 com 131 

    ; --- Lógica para piscar o LED em RB0 ---
    DECFSZ FLASH, F         ; Decrementa o valor de FLASH
    GOTO FIM_T0             ; Se FLASH não for 0, vai para FIM_T0
    
    MOVLW B'00000001'       ; Carrega literal em W para colocar em RB0
    XORWF PORTB, F          ; Realiza um XOR entre W e PORTB (inverte o estado do bit)
    MOVLW D'25'             ; Carrega o valor decimal 25 em W
    MOVWF FLASH             ; Reincia FLASH com o valor de 25

FIM_T0:
    ; --- Lógica para piscar o LED em RB1 ---
    DECFSZ TIQUES, F        ; Decrementa o valor de TIQUES
    GOTO FIM_T1             ; Se FLASH não for 0, vai para FIM_T1

    MOVLW B'00000010'       ; Carrega literal em W para colocar em RB1
    XORWF PORTB, F          ; Realiza um XOR entre W e PORTB (inverte o estado do bit)
    MOVLW D'125'            ; Carrega o valor decimal 125 em W
    MOVWF TIQUES            ; Reincia TIQUES com o valor de 125

    ; --- Lógica para piscar o LED em RB2 ---
    DECFSZ CSEG, F          ; Decrementa o valor de CSEG
    GOTO FIM_T1             ; Se 'CSEG' não for 0, vai para FIM_T1
    
    MOVLW B'00000100'       ; Carrega literal em W para colocar em RB2
    XORWF PORTB, F          ; Realiza um XOR entre W e PORTB (inverte o estado do bit)
    MOVLW D'60'             ; Carrega o valor decimal 60 em W
    MOVWF CSEG              ; Reinicia CSEG com o valor de 60

FIM_T1:
    RETFIE                  ; Retorna da rotina de interrupção

INICIO:
    ; --- Configurações Iniciais ---
    BANKSEL OPTION_REG      ; Seleciona o banco de memória 1 para acessar o registrador OPTION_REG
    MOVLW B'10000101'       ; Carrega em W o valor para configurar o Timer0 com prescaler de 1:64
    MOVWF OPTION_REG        ; Move a configuração de W para o OPTION_REG

    BANKSEL TMR0            ; Seleciona o banco de memória 0 para acessar o registrador TMR0
    MOVLW D'131'            ; Carrega o valor inicial do timer (131) em W
    MOVWF TMR0              ; Move o valor de W para o TMR0
    
    BANKSEL INTCON          ; Seleciona o banco de memória onde está o registrador INTCON
    MOVLW B'10100000'       ; Carrega em W o valor para habilitar a interrupção global e a interrupção do Timer0
    MOVWF INTCON            ; Move a configuração de W para o INTCON

    BANKSEL TRISB           ; Seleciona o banco de memória 1 para acessar o registrador TRISB
    CLRF TRISB              ; Limpa o TRISB, configurando todos os pinos do PORTB como saída
    
    BANKSEL PORTB           ; Seleciona o banco de memória 0 para acessar o registrador PORTB
    BSF PORTB, 0            ; Seta o bit 0 (RB0), deixando o LED inicialmente ligado
    BSF PORTB, 1            ; Seta o bit 1 (RB1), deixando o LED inicialmente ligado
    BSF PORTB, 2            ; Seta o bit 2 (RB2), deixando o LED inicialmente ligado

    ; --- Inicialização das variáveis de contagem ---
    MOVLW D'125'            ; Carrega o valor inicial 125 em W
    MOVWF TIQUES            ; Inicializa a variável TIQUES com 125

    MOVLW D'25'             ; Carrega o valor inicial 25 em W
    MOVWF FLASH             ; Inicializa a variável FLASH com 25

    MOVLW D'60'             ; Carrega o valor inicial 60 em W
    MOVWF CSEG              ; Inicializa a variável 'CSEG' com 60

    ; --- Laço Principal ---
    GOTO $                  ; Cria um laço infinito, fazendo o programa saltar para a própria linha.

    END