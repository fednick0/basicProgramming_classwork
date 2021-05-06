#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int estado, moneda, otro;

    do{
        estado = 0;

        do{
            system("cls");
            cout<<"Precio del refresco: $15\nDinero ingresado: $" <<estado;
            cout<<"\n\n[1] $1\n[2] $2\n[3] $5\n[4] $10\n";
            moneda = getch();

            /*  $1 -> 49
                $2 -> 50
                $5 -> 51
                $10 -> 52 */

            switch(estado){
            case 0:
                if(moneda == 49)
                    estado = 1;
                else if(moneda == 50)
                    estado = 2;
                else if(moneda == 51)
                    estado = 5;
                else if(moneda == 52)
                    estado = 10;
                break;

            case 1:
                if(moneda == 49)
                    estado = 2;
                else if(moneda == 50)
                    estado = 3;
                else if(moneda == 51)
                    estado = 6;
                else if(moneda == 52)
                    estado = 11;
                break;

            case 2:
                if(moneda == 49)
                    estado = 3;
                else if(moneda == 50)
                    estado = 4;
                else if(moneda == 51)
                    estado = 7;
                else if(moneda == 52)
                    estado = 12;
                break;

            case 3:
                if(moneda == 49)
                    estado = 4;
                else if(moneda == 50)
                    estado = 5;
                else if(moneda == 51)
                    estado = 8;
                else if(moneda == 52)
                    estado = 13;
                break;

            case 4:
                if(moneda == 49)
                    estado = 5;
                else if(moneda == 50)
                    estado = 6;
                else if(moneda == 51)
                    estado = 9;
                else if(moneda == 52)
                    estado = 14;
                break;

            case 5:
                if(moneda == 49)
                    estado = 6;
                else if(moneda == 50)
                    estado = 7;
                else if(moneda == 51)
                    estado = 10;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 6:
                if(moneda == 49)
                    estado = 7;
                else if(moneda == 50)
                    estado = 8;
                else if(moneda == 51)
                    estado = 11;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 7:
                if(moneda == 49)
                    estado = 8;
                else if(moneda == 50)
                    estado = 9;
                else if(moneda == 51)
                    estado = 12;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 8:
                if(moneda == 49)
                    estado = 9;
                else if(moneda == 50)
                    estado = 10;
                else if(moneda == 51)
                    estado = 13;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 9:
                if(moneda == 49)
                    estado = 10;
                else if(moneda == 50)
                    estado = 11;
                else if(moneda == 51)
                    estado = 14;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 10:
                if(moneda == 49)
                    estado = 11;
                else if(moneda == 50)
                    estado = 12;
                else if(moneda == 51)
                    estado = 15;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 11:
                if(moneda == 49)
                    estado = 12;
                else if(moneda == 50)
                    estado = 13;
                else if(moneda == 51)
                    estado = 15;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 12:
                if(moneda == 49)
                    estado = 13;
                else if(moneda == 50)
                    estado = 14;
                else if(moneda == 51)
                    estado = 15;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 13:
                if(moneda == 49)
                    estado = 14;
                else if(moneda == 50)
                    estado = 15;
                else if(moneda == 51)
                    estado = 15;
                else if(moneda == 52)
                    estado = 15;
                break;

            case 14:
                if(moneda == 49)
                    estado = 15;
                else if(moneda == 50)
                    estado = 15;
                else if(moneda == 51)
                    estado = 15;
                else if(moneda == 52)
                    estado = 15;
                break;
            }
        } while(estado != 15);

        system("cls");
        cout<<"Precio del refresco: $15\nDinero ingresado: $" <<estado;
        cout<<"\n\n[1] $1\n[2] $2\n[3] $5\n[4] $10\n";

        if(estado == 15)
                cout<<"\nPrecio completado, recoger refresco en ventanilla 5";

        cout<<"\n\n[!Esc] Repetir";
        otro = getch();
    } while(otro != 27);
}
