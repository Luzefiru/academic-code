.model small 
.stack 200h 
 
.data 
    ; Mouse interrupt return values 
    mouse_x     dw ?       ; Current mouse X coordinate 
    mouse_y     dw ?       ; Current mouse Y coordinate 
    mouse_stat  dw ?       ; Mouse button status 
    last_x      dw 0FFFFh  ; Last X position to avoid redundant updates 
    last_y      dw 0FFFFh  ; Last Y position to avoid redundant updates 
    drawing     db 0        ; Flag to track if we're currently drawing 
 
.code 
main PROC 
    ; Initialize data segment 
    mov ax, @data 
    mov ds, ax 
 
    ; Initialize video mode (3h = 80x25 text mode) 
    mov ah, 0 
    mov al, 3h 
    int 10h 
 
    ; Initialize mouse 
    mov ax, 0   ; Sub-function 0: Initialize mouse 
    int 33h 
 
    ; Check if mouse is installed 
    test ax, ax 
    jz no_mouse 
 
    ; Show mouse cursor 
    mov ax, 1 
    int 33h 
 
main_loop: 
    ; Get mouse position and status 
    mov ax, 3   ; Sub-function 3: Get mouse position and button status 
    int 33h 
 
    ; Check left mouse button (bit 0 in BX)
    test bx, 1
    jnz start_drawing
    mov drawing, 0  ; Not drawing if left button not pressed
    jmp check_pos

start_drawing:
    mov drawing, 1  ; Set drawing flag

check_pos:
    ; Convert mouse coordinates to screen position 
    ; CX is divided by 8 for X, DX is divided by 8 for Y 
    push cx
    push dx
    shr cx, 3   ; Divide X by 8 
    shr dx, 3   ; Divide Y by 8 
 
    ; Calculate video memory offset 
    ; offset = (Y * 80 + X) * 2 
    mov ax, dx 
    mov bx, 80 
    mul bx 
    add ax, cx 
    shl ax, 1   ; Multiply by 2 (each cell is 2 bytes: character + attribute) 
 
    ; Point to video memory 
    mov di, ax 
    mov ax, 0B800h 
    mov es, ax  ; Video memory segment for text mode 
 
    ; Check if we should draw 
    cmp drawing, 1
    jne skip_draw

    ; Draw color (preserve character, change attribute)
    mov al, es:[di]        ; Keep original character
    mov byte ptr es:[di], al      ; Restore original character
    mov byte ptr es:[di+1], 4Ch   ; Set color to bright red background 

skip_draw:
    ; Restore original coordinates 
    pop dx
    pop cx

    ; Check for ESC key to exit 
    mov ah, 1   ; Check keyboard status 
    int 16h 
    jz main_loop  ; No key pressed, continue 
 
    ; Check if ESC was pressed 
    mov ah, 0   ; Read key 
    int 16h 
    cmp al, 27  ; ESC key 
    jne main_loop 
 
    ; Restore original video mode 
    mov ah, 0 
    mov al, 3h 
    int 10h 
 
    ; Return to DOS 
    mov ax, 4C00h 
    int 21h 
 
no_mouse: 
    ; Display error message if no mouse 
    mov ah, 9 
    mov dx, offset no_mouse_msg 
    int 21h 
 
    ; Return to DOS 
    mov ax, 4C01h 
    int 21h 
 
no_mouse_msg db "Mouse not detected.$" 
 
main ENDP 
 
END main