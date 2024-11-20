.model small
.stack 100h

.data
    ; No data needed
    
.code
main:
    mov ax, 0B800h
    mov ds, ax

start:
    mov di, 0          
    mov bx, 25         

scroll_rows:
    push di            
    mov si, di         
    add si, 158        

    mov al, [ds:si]    
    mov ah, [ds:si+1]  
    push ax            

    mov cx, 79         

shift_left:
    mov ax, [ds:si-2]  
    mov [ds:si], ax    
    sub si, 2          
    loop shift_left    

    pop ax             
    mov [ds:di], ax    

    pop di             
    add di, 160        
    dec bx             
    jnz scroll_rows    

    mov cx, 0FFFFh
    
delay:
    dec cx             
    jnz delay         

    jmp start          

end main
