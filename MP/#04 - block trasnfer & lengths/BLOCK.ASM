.model small
.data
    a db 01H,02H,03H,04H,05H
    b db 05H

.code
    mov ax,@data
    mov ds,ax
    LEA si,a
    LEA di,b
    mov cx,05H

    loop1:
        mov al,[si]
        mov [di],al
        inc si
        inc di
        dec cx
        jnz loop1

    lea di,b
    mov cx,05H

    display_data:
        mov al,[di]
        add al,30h
        mov dl,al
        mov ah,02h
        int 21h
        inc di
        dec cx
        jnz display_data

    mov ah,4ch
    int 21h

end
