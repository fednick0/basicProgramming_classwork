#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char ident[20];
    char entrada;
    int estado;

    do{
        entrada = '\0';
        estado = 0;

        system("cls");
        cout<<"Ingrese identificador: ";
        gets(ident);

        for(int x = 0; x < strlen(ident); x++) {
            if(isalpha(ident[x]))
                entrada = 'l'; //Letra
            else if(isdigit(ident[x]))
                entrada = 'd'; //Digito
            else
                entrada = 'e'; //Error

            //Matriz
            if(estado == 0 && entrada == 'd' || entrada == 'e'){ //Solo si esta en q^0 y la entra es digito = error
                estado = 1;
                break;
            }
            else //Todo lo demas = aceptado
                estado = 2;
        } //for

        if(entrada == 'e' || estado == 1)
            cout<<"\nNo aceptado";
        else
            cout<<"\nAceptado";

        cout<<"\n\n[!Esc] Repetir";
    } while(getch() != 27);
}
