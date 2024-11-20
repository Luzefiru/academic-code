.model small
.stack 100h

.data
    ; No data needed for this example

.code
main:
    ; Initialize the data segment to point to the video memory segment (0xB800)
    mov ax, 0B800h
    mov ds, ax         ; Set DS to point to video memory

start:
    mov di, 0          ; Starting at the beginning of video memory
    mov bx, 25         ; Set row counter to 25 (number of rows)

row_loop:
    push di            ; Save current position in DI
    mov si, di         ; Set SI to the current position
    add si, 158        ; SI = DI + 158 (to point to 80th column of the row)

    ; Get the character and attribute (2 bytes) for current position
    mov al, [ds:si]    ; Load character byte into AL
    mov ah, [ds:si+1]  ; Load attribute byte into AH
    push ax            ; Save the character and attribute

    ; Shift the screen left by 2 bytes (move character + attribute)
    mov cx, 79         ; Number of columns - 1 (since we shift left)

shift_loop:
    mov ax, [ds:si-2]  ; Copy the previous character + attribute
    mov [ds:si], ax    ; Move it to the current position
    sub si, 2          ; Move SI back by 2 bytes (to the previous character)
    loop shift_loop    ; Repeat until CX is zero

    ; Restore the original character and attribute, and place it at the current position
    pop ax             ; Retrieve the saved character and attribute
    mov [ds:di], ax    ; Store it back at the current position

    pop di             ; Restore DI
    add di, 160        ; Move DI to the next row (160 bytes = 80 characters)
    dec bx             ; Decrement row counter
    jnz row_loop       ; Continue looping through rows if BX != 0

    ; Introduce delay
    mov cx, 0FFFFh
    
delay_loop:
    dec cx             ; Decrement delay counter
    jnz delay_loop     ; Repeat until CX reaches zero

    jmp start          ; Jump back to start to repeat the process

end main
