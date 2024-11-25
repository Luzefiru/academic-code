; From: https://stackoverflow.com/questions/40060076/how-can-i-input-2-digit-number-in-assembly-emu8086

.model small
.data
.code

mov ax, @data
mov ds, ax 

mov dl, 10  
mov bl, 0         

scanNum:

      mov ah, 01h
      int 21h

      cmp al, 13   ; Check if user pressed ENTER KEY
      je  exit 

      mov ah, 0  
      sub al, 48   ; ASCII to DECIMAL

      mov cl, al
      mov al, bl   ; Store the previous value in AL

      mul dl       ; multiply the previous value with 10

      add al, cl   ; previous value + new value ( after previous value is multiplyed with 10 )
      mov bl, al

      jmp scanNum    

exit:

      mov ah, 04ch   
      int 21h

 end