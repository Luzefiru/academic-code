.model small
.stack 100h

.data
    msg db 'Hello World$'       ; Message string to display (terminated with '$')
    space db ' $'               ; Space character for clearing
    col db 0                    ; Column counter (starting at 0)
    delay_len dw 0FFFFh         ; Delay for animation (65535)

.code
main:
    ; Initialize data segment
    mov ax, @data
    mov ds, ax

; Main marquee loop
marquee_loop:
    ; Reset screen for each iteration
    call reset_screen

; Move across columns
next_col:
    ; Check if we've reached end of screen
    mov al, [col]
    cmp al, 80
    jae reset_col

    ; Set cursor and print message
    call set_cursor_pos

    ; Clear the previous character by overwriting it with a space
    lea dx, space      ; Load address of space
    mov ah, 09h        ; Print string DOS interrupt
    int 21h            ; Execute DOS interrupt

    call print_msg_at_cursor

    ; Delay to create animation effect
    call trigger_delay
    call trigger_delay

    ; Increment column and continue
    inc byte ptr [col]
    jmp next_col

; Reset column to 0 when reaching end of screen
reset_col:
    mov byte ptr [col], 0
    jmp marquee_loop

; Delay trigger for animation
trigger_delay:
    push cx
    mov cx, delay_len
delay_loop:
    dec cx
    jnz delay_loop
    pop cx
    ret

; Reset screen 
reset_screen:
    ; Set video mode to text (80 x 25 characters size)
    mov ah, 00h  ; Video Mode BIOS interrupt
    mov al, 03h  ; Text mode, 80x25 characters
    int 10h      ; Execute BIOS interrupt
    ret

; Set the cursor position based on column
set_cursor_pos:
    mov ah, 02h      ; Set cursor position BIOS interrupt
    mov bh, 0        ; Page number
    mov dh, 0        ; Fixed row (first row)
    mov dl, [col]    ; Column (from memory)
    int 10h          ; Execute BIOS interrupt
    ret

; Print message at current cursor position
print_msg_at_cursor:
    lea dx, msg      ; Load the address of the message
    mov ah, 09h      ; Print string DOS interrupt
    int 21h          ; Execute DOS interrupt
    ret

end main