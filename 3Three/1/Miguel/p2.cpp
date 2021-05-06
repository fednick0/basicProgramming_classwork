#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int menu(void);
int suma(int, int);
int rest(int, int);
int mult(int, int);
int divi(int, int);

int main(){

    char opc;
    int dato1, dato2;
    bool error = true;

    do{
        opc = menu();
        system("cls");

        switch(opc){
        case '0':
            cout<<"Introduzca primer dato: ";
            cin>> dato1;
            cout<<"Introduzca segundo dato: ";
            cin>> dato2;
            error = false;
            break;

        case '1':
            if(!error)
                cout<<"La suma es: " <<suma(dato1, dato2);
            else
                cout<<"No ha ingresado datos aun";
            break;

        case '2':
            if(!error)
                cout<<"La resta es: " <<rest(dato1, dato2);
            else
                cout<<"No ha ingresado datos aun";
            break;

        case '3':
            if(!error)
                cout<<"La multiplicacion es: " <<mult(dato1, dato2);
            else
                cout<<"No ha ingresado datos aun";
            break;

        case '4':
            if(!error && dato2 != 0)
                cout<<"La divicion es: " <<divi(dato1, dato2);
            else
                cout<<"No ha ingresado datos aun o segundo dato es 0";
            break;

        case '5':
            cout<<"Saliendo . . .";
            break;

        default:
            cout<<"Error";
        }

        cout<<"\n\n";
        system("pause");
    } while(opc != '5');
}

///////////////////////////////////

int menu(){
    system("cls");

    cout<<"[0] Agregar datos\n";
    cout<<"[1] Sumar\n";
    cout<<"[2] Restar\n";
    cout<<"[3] Multiplicar\n";
    cout<<"[4] Dividir\n";
    cout<<"[5] Salir\n";

    return getch();
}

int suma(int d1, int d2){   return (d1 + d2);}
int rest(int d1, int d2){   return (d1 - d2);}
int mult(int d1, int d2){   return (d1 * d2);}
int divi(int d1, int d2){   return (d1 / d2);}
