/*
    char
    short
    int
    signed
    unsigned
    long
    double
    float
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

    char sn;
    string nomb, mes;
    unsigned short dia, agno, op;
    int reg;
    bool ingreso = true;

void pow_agno(){
    long cuad;
    cuad = pow(agno, 2);
    cout<<"Agno ingresado: "<< agno;
    cout<<"\nCuadrado del agno de nacimiento: "<< cuad;
}

void fact_dia(){
    double factorio = 1;
    for(short x = 1; x <= dia; x++)
        factorio *= x;
    cout<<"Dia ingresado: "<< dia;
    cout<<"\nFactorial del dia de nacimiento: "<< factorio;
}

void raiz_reg(){
    float raiz;
    raiz = sqrt(reg);
    cout<<"Registro ingresado: "<< reg;
    cout<<"\nRaiz del registro es: "<< raiz;
}

int main(){
    do{
        sn = 'n';
        system("cls");

        if(ingreso){

            cout<<"Fecha de nacimiento\n\tDia: "; cin>> dia;
            cout<<"\tMes: "; cin>> mes;
            cout<<"\tAgno: "; cin>> agno;
            cout<<"\nDatos\n\tNombre: "; cin>> nomb;
            cout<<"\tRegistro: "; cin>> reg;

            ingreso = false;
            system("cls");
        }

        cout<<"1.- Raiz de mi registro\n";
        cout<<"2.- Factorial de mi dia de nacimiento\n";
        cout<<"3.- Cuadrado de mi agno\n4.- Ingresar datos otravez\n5.- Salir\n--> ";
        cin>> op;

        cout<<endl<<endl;

        switch(op){
        case 1:
            raiz_reg();
            break;
        case 2:
            fact_dia();
            break;
        case 3:
            pow_agno();
            break;
        case 4:
            ingreso = true;
            break;
        case 5:
            cout<<"Saliendo...";
            break;
        default:
            cout<<"Opcion incorrecta D:";
        }

        if(op != 5 && op != 4){
            cout<<"\n\nDesea reiniciar? s/n\n--> ";
            cin>> sn;
        }
    } while(sn == 's' || sn == 'S' || op != 5);
    //system("pause");
}
