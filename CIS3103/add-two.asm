; From: https://stackoverflow.com/a/23682807

.model small
.stack 200h
.data
    num1 db ?               ; Placeholder for the first number
    num2 db ?               ; Placeholder for the second number
    val  dw ?               ; Result of addition
    msg1 db "The sum is: $"
    decimal db "00000$"     ; Buffer for decimal representation
    prompt1 db "Enter first number: $"
    prompt2 db "Enter second number: $"

.code
begin proc
    mov ax, @data
    mov ds, ax

    ; prompt and scan first number
    lea dx, prompt1
    mov ah, 9
    int 21h
    call scan_num
    mov num1, al

    ; prompt and scan second number
    lea dx, prompt2
    mov ah, 9
    int 21h
    call scan_num
    mov num2, al

    ; add the numbers
    xor ax, ax
    mov al, num1
    add al, num2
    adc ah, 0
    mov val, ax

    ; convert result to decimal
    mov ax, val
    call ax_to_dec

    ; display result
    lea dx, msg1
    mov ah, 9
    int 21h

    lea dx, decimal
    mov ah, 9
    int 21h

    ; exit program
    mov ax, 4c00h
    int 21h
begin endp

; procedure to scan a number (up to two digits)
scan_num proc
    xor bx, bx             ; clear bx (to store result)
    mov dl, 10             ; base 10 multiplier

scan_loop:
    mov ah, 1              ; get a character
    int 21h

    cmp al, 13             ; check for enter (ascii 13)
    je scan_exit           ; if enter, exit loop

    sub al, '0'            ; convert ascii to number
    mov cl, al
    mov al, bl             ; load previous result
    mul dl                 ; multiply previous result by 10
    add al, cl             ; add new digit
    mov bl, al             ; update result
    jmp scan_loop          ; repeat

scan_exit:
    mov al, bl             ; return final result in al
    ret
scan_num endp

; procedure to convert ax to decimal
ax_to_dec proc
    mov bx, 10             ; divisor
    xor cx, cx             ; digit count

first_loop:
    xor dx, dx             ; clear dx
    div bx                 ; ax / bx -> ax remainder dx
    push dx                ; store remainder
    inc cx                 ; increment digit count
    test ax, ax            ; check if ax is 0
    jnz first_loop         ; if not, repeat

    mov di, offset decimal ; destination buffer
second_loop:
    pop ax                 ; retrieve digit
    or al, '0'             ; convert to ascii
    mov [di], al           ; store in buffer
    inc di                 ; advance pointer
    loop second_loop       ; repeat for all digits

    mov byte ptr [di], '$' ; null terminator
    ret
ax_to_dec endp

end begin
