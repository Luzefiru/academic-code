.model small
.stack 100h

.data
    msg db 'Hello World$'       ; Message string to display (terminated with '$')
    space db ' $'               ; Space character for clearing
    row db 0                    ; Row counter (starting at 0)
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
    call reset_screen_and_set_cursor

; Move across columns
next_col:
    ; Check if we've reached end of screen
    mov al, [col]
    cmp al, 80
    jae next_row

    ; Set cursor and print message
    call set_cursor_pos_by_row_col

    ; Clear the previous character by overwriting it with a space
    lea dx, space      ; Load address of space
    mov ah, 09h        ; Print string DOS interrupt
    int 21h            ; Execute DOS interru 

    call print_msg_at_cursor

    ; Delay to create animation effect
    call trigger_delay
    call trigger_delay

    ; Increment column and continue
    inc byte ptr [col]
    jmp next_col

; Move to next row when column is exhausted
next_row:
    ; Reset column to 0
    mov byte ptr [col], 0

    ; Increment row
    inc byte ptr [row]

    ; Check if we've reached bottom of screen
    mov al, [row]
    cmp al, 25
    jb marquee_loop

    ; Reset program when screen is filled
    mov byte ptr [row], 0
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

; Clear screen and reset cursor
reset_screen_and_set_cursor:
    ; Set video mode to text (80 x 25 characters size)
    mov ah, 00h  ; Video Mode BIOS interrupt
    mov al, 03h  ; Text mode, 80x25 characters
    int 10h      ; Execute BIOS interrupt

    ; Set cursor position to current row and column
    call set_cursor_pos_by_row_col
    ret

; Set the cursor position to the row & col offset
set_cursor_pos_by_row_col:
    mov ah, 02h      ; Set cursor position BIOS interrupt
    mov bh, 0        ; Page number
    mov dh, [row]    ; Row (from memory)
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