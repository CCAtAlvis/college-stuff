.model small
.data
    string db 'chinmay$'

.code
    mov ax,@data
    mov ds,ax
    lea di,string
    mov cl,00

    compare_loop:
        mov al,[di]
        cmp al,'$'
        jz moveToAL
        inc cl
        inc di
        jmp compare_loop

    display:
        mov dl,cl
        add dl,30H
        mov ah,02
        int 21H

    mov ah,4CH
    int 21H

end
