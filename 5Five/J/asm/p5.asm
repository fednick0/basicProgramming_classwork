.model small
.stack 100

.data
    c db 0
    d db 0
    u db 0
    n db 0
    nn db 0
    salto db " ", 13, 10, '$'
    r db "Resultado: ", 13, 10, '$'
    m1 db "1 - Suma", 13, 10, '$'
    m2 db "2 - Resta", 13, 10, '$'
    m3 db "3 - Multiplicacion", 13, 10, '$'
    m4 db "4 - Divicion", 13, 10, '$'
    m5 db "5 - Salir", 13, 10, '$'
    m6 db "Ingrese opcion: ", '$'
    opc db 0
    pn1 db "Primer numero: ", '$'
    pn2 db "Segundo numero: ", '$'
    
.code
.startup
    jmp menu
    
    
    
    ; ********************************
    capt:
        ; pido numero 1
        mov ah, 09h
        lea dx, salto
        int 21h
        lea dx, salto
        int 21h
        lea dx, pn1
        int 21h
    
        ;1 capturo centenas
        mov ah, 01h
        int 21h
        sub al, 30h
        mov c, al
        
        ;1 capturo decenas
        mov ah, 01h
        int 21h
        sub al, 30h
        mov d, al
        
        ;1 capturo unidades
        mov ah, 01h
        int 21h
        sub al, 30h
        mov u, al
        
        ;1 junto los datos en unos solo
        mov al, c
        mov bl, 100
        mul bl
        mov n, al
        mov al, d
        mov bl, 10
        mul bl
        add al, n
        add al, u
        mov n, al
        
        ; pido numero 2
        mov ah, 09h
        lea dx, salto
        int 21h
        lea dx, pn2
        int 21h
        
        ;2 capturo centenas
        mov ah, 01h
        int 21h
        sub al, 30h
        mov c, al
        
        ;2 capturo decenas
        mov ah, 01h
        int 21h
        sub al, 30h
        mov d, al
        
        ;2 capturo unidades
        mov ah, 01h
        int 21h
        sub al, 30h
        mov u, al
        
        ;2 junto los datos en unos solo
        mov al, c
        mov bl, 100
        mul bl
        mov nn, al
        mov al, d
        mov bl, 10
        mul bl
        add al, nn
        add al, u
        mov nn, al
        
        cmp opc, 1
        je suma_c
        cmp opc, 2
        je resta_c
        cmp opc, 3
        je multi_c
        cmp opc, 4
        je divi_c
        
        
    
    ; ********************************        
    suma:
        jmp capt
        suma_c:
        mov al, n
        mov bl, nn
        add al, bl 
        mov n, al
        jmp mostr
        
        
    
    ; ********************************        
    resta:
        jmp capt
        resta_c:
        mov al, n
        mov bl, nn
        sub al, bl 
        mov n, al
        jmp mostr
    
    
        
    ; ********************************        
    r_cmp:
        ; comparo
        cmp opc, 1
        je suma
        cmp opc, 2
        je resta
        cmp opc, 3
        je multi
        cmp opc, 4
        je divi
        
        
        
    ; ********************************        
    multi:
        jmp capt
        multi_c:
        mov al, n
        mov bl, nn
        mul bl 
        mov n, al
        jmp mostr
        
        
        
    ; ********************************        
    divi:
        jmp capt
        divi_c:
        mov al, n
        mov bl, nn
        div bl 
        mov n, al
        jmp mostr
    
        
        
    ; ********************************        
    mostr:
        ; muestro numero (1/2)
        mov al, n
        aam
        mov u, al
        mov al, ah
        aam
        mov d, al
        mov c, ah
        
        ; Resultado
        mov ah, 09h
        lea dx, salto
        int 21h
        lea dx, r
        int 21h
        
        ; muestro numero (2/2)
        mov ah, 02h ; no entiendo
        mov dl, c
        add dl, 30h
        int 21h
        mov dl, d
        add dl, 30h
        int 21h
        mov dl, u
        add dl, 30h
        int 21h
        
        ; Presione pa continuar
        mov ah, 01h
        int 21h
        jmp menu

    
        
    ; ********************************        
    menu:
        ; limpia pantalla
        mov ah, 00h
        mov al, 03h
        int 10h
    
        ; muestro mensaje
        mov ah, 09h
        lea dx, m1
        int 21h
        lea dx, m2
        int 21h
        lea dx, m3
        int 21h
        lea dx, m4
        int 21h
        lea dx, m5
        int 21h
        lea dx, m6
        int 21h
        
        ; capturo opcion
        mov ah, 01h
        int 21h
        sub al, 30h
        mov opc, al
        
        cmp opc, 5
        je salir
        jmp r_cmp
        
    salir:
        .exit
end

    