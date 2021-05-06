; HOLA.ASM
; Programa cl?sico de ejemplo. Despliega una leyenda en pantalla.
STACK     SEGMENT STACK                        ; Segmento de pila
          DW     64 DUP (?)                    ; Define espacio en la pila
STACK     ENDS
                
DATA      SEGMENT                              ; Segmento de datos
    pala1    DB    "1.- Camaron se lo lleva la corriente",13,10,"$"       ; Cadena
    pala2    DB    "2.- Al nopal solo se le arriman cuando tienen tunas",13,10,"$"
    pala3    DB    "3.- Botellita de jerez, todo lo que digas sera alrevez",13,10,"$"
    pala4    DB    "4.- Chocolate que no tigne, claro esta",13,10,"$"
    pala5    DB    "5.- Al raton le gusta el queso, y a tus nalgas mi pescuezo",13,10,"$"
    pala6    DB    "6.- Dando y dando, pajaro volando",13,10,"$"
    pala7    DB    "7.- Dar el alon y comerse el pechigon",13,10,"$"
    pala8    DB    "8.- A darle que es mole de olla",13,10,"$"
DATA      ENDS

CODE      SEGMENT                              ; Segmento de C?digo
          ASSUME CS:CODE, DS:DATA, SS:STACK

INICIO:                                        ; Punto de entrada al programa
          MOV  AX,DATA                         ; Pone direcci?n en AX
          MOV  DS,AX                           ; Pone la direcci?n en los registros
          
          mov ah, 09h
          lea dx, pala1
          int 21h
          
          mov ah, 09h
          lea dx, pala2
          int 21h
          
          mov ah, 09h
          lea dx, pala3
          int 21h
          
          mov ah, 09h
          lea dx, pala4
          int 21h
          
          mov ah, 09h
          lea dx, pala5
          int 21h
          
          mov ah, 09h
          lea dx, pala6
          int 21h
          
          mov ah, 09h
          lea dx, pala7
          int 21h
          
          mov ah, 09h
          lea dx, pala8
          int 21h
          
          MOV  AH,4CH                          ; Funci?n: Terminar
          INT     21H
CODE      ENDS
          END  INICIO                          ; Marca fin y define INICIO
