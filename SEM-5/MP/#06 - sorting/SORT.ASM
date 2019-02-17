.model small
.data
    a db 8,3,5,1,7,2
    b db 5
    c db 4

.code
    mov ax,@data
    mov ds,ax
    lea bx,a
    mov cl,b
    mov ch,c

    lp1:
        mov al,[bx]
        mov dl,[bx+1]

        cmp al,dl
        jnc swap
        jc lp2

    swap:
        mov [bx],dl
        mov [bx+1],al
        jmp lp2

    lp2:
        inc bx
        dec cl
        jnz lp1

        lea bx,a
        mov cl,b
        dec ch
        jnz lp1

    mov cl,6
    lea bx,a
    disp:
        mov dl,[bx]
        add dl,30h
        mov ah,02h
        int 21h
        inc bx
        dec cl
        jnz disp

    mov ah,4ch
    int 21h

end
                


                

