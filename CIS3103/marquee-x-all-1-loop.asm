.model small
.stack 100h

.data
    ; No data section needed

.code
main:
    mov ax, 0B800h      ; Point to video memory segment
    mov ds, ax          ; Set DS to point to video memory

    mov cx, 81          ; Set loop counter to 81 for scrolling columns

scroll_cols:
    dec cx
    jz exit_program      ; Exit if counter reaches 0

    mov di, 0            ; Start of the screen
    mov bx, 25           ; Row counter (25 rows)

ready_row_loop:
    mov si, di
    add si, 158          ; Move to the attribute byte of the row

    mov al, [ds:si]
    mov ah, [ds:si+1]
    push ax              ; Save original character + attribute to stack

    mov ax, 80           ; Set loop counter for characters in row

shift_row_chars:
    mov dx, [ds:si-2]
    mov [ds:si], dx
    sub si, 2
    dec ax
    jnz shift_row_chars  ; Continue if there are more chars to shift

    pop ax
    mov [ds:di], ax
    add di, 160          ; Move to the next row (video memory width)
    dec bx
    jnz ready_row_loop   ; Continue if there are more rows

    mov ax, 0FFFFh        ; Set delay timer

delay_tick:
    dec ax
    jnz delay_tick

    jmp scroll_cols      ; Loop back for continuous scrolling

exit_program:
    mov ah, 4Ch 
    int 21h 

end main
