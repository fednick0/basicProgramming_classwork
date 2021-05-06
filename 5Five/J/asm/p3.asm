
;Los numeros 13 10 en los textos son para dar saltos de linea
.MODEL small
.STACK 100 ;Tama?o de pila
.data 
m1 db 'Numero 1: ','$'
m2 db 13,10,'Numero 2: ','$'
m3 db 13,10,'=: ','$'
linea db 13,10,'$'

n1 db 0
n2 db 0

.code
.startup

CALL limpia
MOV ah,09h
LEA dx, m1 ;Desplegar texto numero 1 en pantalla
INT 21h

CALL leer ;Lee primer numero
SUB al,30h ;Resta el 30h para obtener primer numero
MOV n1, al ; Lo guardo en n1
MOV ah, 09h
LEA dx, m2 ;Desplegar texto numero 2
int 21h

CALL leer ;Lee segundo numero
SUB al,30h ;Resta el 30h para obtener segundo numero
MOV n2, al ; Lo guardo en n2
MOV bl, n2 ;Mover a bl

;*******************SUMA
ADD bl, n1 ;Realizo la suma de n1
MOV ah, 09h
LEA dx, m3 ;Imprimir suma 
INT 21h
MOV dl, bl ;Pongo en dl el numero a imprimir
ADD dl, 30h
MOV ah, 02h
INT 21H
.exit

;********************Procedimientos
salto PROC NEAR
MOV ah, 09h
LEA dx, linea
INT 21h
MOV dl, 00h
RET ;retorna
salto endp

leer PROC NEAR
MOV ah, 01h ;leer caracter desde el teclado
INT 21h ;Lee primer caracter
RET
leer endp

limpia PROC NEAR
MOV ah, 00h
MOV al, 03h
INT 10h
RET 
limpia endp

END

