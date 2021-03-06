; suma, resta, multiplicacion y division sin tomar en cuenta el acarreo
; el 13,10 es un salto de linea

.model small
.stack 100
.data
msj1 db 'Ingrese primer numero: ','$'
msj2 db 13,10,'Ingrese sengundo numero: ','$'
msj3 db 13,10,'Suma: ','$'
msj4 db 13,10,'Resta: ','$'
msjn db 13,10,'Resta: -','$'
msj5 db 13,10,'Multiplicacion: ','$'
msj6 db 13,10,'Division: ','$'
linea db 13,10,'$'
var1 db 0
var2 db 0
.code
.startup

call limpia
mov ah, 09h
lea dx, msj1 ;desplegar numero 1:
int 21h

call leer ;lee primer numero
sub al, 30h ;restar 30h para obtener el numero
mov var1, al ;lo guardo en var1
mov ah, 09h
lea dx, msj2 ;desplegar numero 2:
int 21h

call leer ;lee segundo numero
sub al, 30h ;restar 30h para obtener segundo valor
mov var2, al ;guardar en var2
mov bl, var2 ;mover a bl

;******************* SUMA
    add bl, var1 ; realizo la suma de var2(bl) y var1 y el resultado queda en bl
    mov ah, 09h
    lea dx, msj3 ;imprimir suma
    int 21h
    mov dl, bl ;pongo en dl el numero a imprimir var2(bl)
    add dl, 30h ; agrego 30h para obtener el caracter    
    mov ah, 02h ;imprime un caracter
    int 21h

;Resta
    mov bl, var1
    sub bl, var2
    mov ah, 09h
    lea dx, msj4
    int 21h
    
    mov bl, var2
    sub bl, var1
    mov ah, 09h
    lea dx, msjn
    int 21h
    
    mov dl, bl
    add dl,30h
    mov ah, 02h
    int 21h

;Multiplicacion
    mov ah, 09h
    lea dx, msj5
    int 21h

    mov al, var1 
    mov bl, var2
    mul bl
    mov dl, al
    add dl, 30h
    mov ah, 02h
    int 21h

;Divicion
    mov ah, 09h
    lea dx, msj6
    int 21h
    xor ax, ax
    mov al, var2
    mov bl, al
    mov al, var1
    div bl
    mov bl, al
    mov dl, bl
    add dl, 30h
    mov ah, 02h
    int 21h
    .exit

; ****************PROCEDIMIENTOS
salto proc near
mov ah, 09h
lea dx, linea
int 21h
mov dl, 00h
ret
salto endp

leer proc near
mov ah, 01h ;leer caracter desde el teclado
int 21h ;lee primer caracter
ret
leer endp

limpia proc near
mov ah, 00h
mov al, 03h
int 10h
ret
limpia endp
end