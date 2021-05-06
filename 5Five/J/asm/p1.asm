; HOLA.ASM
; Programa cl?sico de ejemplo. Despliega una leyenda en pantalla.
STACK     SEGMENT STACK                        ; Segmento de pila
          DW     64 DUP (?)                    ; Define espacio en la pila
STACK     ENDS
                
DATA      SEGMENT                              ; Segmento de datos
SALUDO    DB    "Hola mundo!!",13,10,"$"       ; Cadena
DATA      ENDS

CODE      SEGMENT                              ; Segmento de C?digo
          ASSUME CS:CODE, DS:DATA, SS:STACK

INICIO:                                        ; Punto de entrada al programa
          MOV  AX,DATA                         ; Pone direcci?n en AX
          MOV  DS,AX                           ; Pone la direcci?n en los registros
          MOV  DX,OFFSET SALUDO                ; Obtiene direcci?n del mensaje
          MOV  AH,09H                          ; Funci?n: Visualizar cadena
          INT     21H                          ; Servicio: Funciones alto nivel DOS
          MOV  AH,4CH                          ; Funci?n: Terminar
          INT     21H
CODE      ENDS
          END  INICIO                          ; Marca fin y define INICIO
