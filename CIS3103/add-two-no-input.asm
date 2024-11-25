.MODEL SMALL
.STACK 200H
.DATA
    NUM1 DB 1
    NUM2 DB 21
    VAL  DW ?
    MSG1 DB "The sum is : "
    DECIMAL  DB "00000$"

.CODE
BEGIN PROC
    MOV AX, @DATA
    MOV DS, AX

    XOR AX, AX
    MOV AL, NUM1
    ADD AL, NUM2
    ADC AH, 0
    MOV VAL, AX

    MOV AX, VAL
    CALL AX_to_DEC

    LEA DX, MSG1
    MOV AH, 9
    INT 21H

    MOV AX, 4C00H
    INT 21H
BEGIN ENDP

AX_to_DEC PROC
        mov bx, 10              ; divisor
        xor cx, cx              ; CX=0 (number of digits)

    First_Loop:
        xor dx, dx              ; Attention: DIV applies also DX!
        div bx                  ; DX:AX / BX = AX remainder: DX
        push dx                 ; LIFO
        inc cx                  ; increment number of digits
        test  ax, ax            ; AX = 0?
        jnz First_Loop          ; no: once more

        mov di, OFFSET DECIMAL  ; target string DECIMAL
    Second_Loop:
        pop ax                  ; get back pushed digit
        or ax, 00110000b        ; to ASCII
        mov byte ptr [di], al   ; save AL
        inc di                  ; DI points to next character in string DECIMAL
        loop Second_Loop        ; until there are no digits left

        mov byte ptr [di], '$'  ; End-of-string delimiter for INT 21 / FN 09h
        ret
AX_to_DEC ENDP

END BEGIN