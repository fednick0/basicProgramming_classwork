#include <iostream> //cout<<""
#include <stdlib.h> //system()
#include <conio.h> //getch()
#include <stdio.h> //gets()
#include <string.h> //strlen()

using namespace std;

int main(){

    char numb[20];
    int estado;

    do{
        system("cls");
        estado = 0;

        cout<<"Ingrese numero: ";
        gets( numb );

        for(int x = 0; x < strlen(numb) && estado != 1; x++){
            switch(estado){
            case 0:
                if( numb[x] == '+' || numb[x] == '-' )
                    estado = 2;
                else if( isdigit(numb[x]) )
                    estado = 3;
                else
                    estado = 1;
                break;

            case 2:
                if( isdigit(numb[x]) )
                    estado = 3;
                else
                    estado = 1;
                break;

            case 3:
                if( isdigit(numb[x]) )
                    estado = 3;
                else
                    estado = 1;
            }
        }

        if(estado == 3)
            cout<<"\nAceptado";
        else
            cout<<"\nNo aceptado";

        cout<<"\n\n[Esc] Salir\n[Enter] Reiniciar\n";
    } while(getch() != 27);
} //main
