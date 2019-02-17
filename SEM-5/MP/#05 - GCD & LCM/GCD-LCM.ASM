.model small
.data
    a db 2h
    b db 8h
    msg db 10,13,"$"

.code
    mov ax, @data
    mov ds, ax
    mov dl, a
    mov dh, b
    call gcd

    gcd proc
    start:
        cmp dl,dh
        jg gtr
        jl lsr 
        jz rt
        ret
    gtr:
        sub dl,dh
        jmp start
    lsr:
        sub dh,dl
        jmp start
    rt:
        add dl,30h
        mov ah,02h
        int 21h
    endp

    lcm:
        mov ah,00h
        mov al,a
        mov dl,b
        mul dl
        div dh
        mov cl,al
        add cl,30h

        lea dx,msg
        mov ah,09h
        int 21h

        mov dl,cl
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h

end
