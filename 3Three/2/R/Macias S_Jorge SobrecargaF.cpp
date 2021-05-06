/*
    Macias S. Jorge Oswaldo
    29/09/2017

    1.- Modifica el programa para que solicite el numero y la potencia entere
(leer los datos desde consola), asi mismo el numero double y potencia entera
(leer los datos desde consla).

    2.- Debes mostrar la informacion en pantalla de acuerdo con los datos que
proporciono el usuario.
*/

#include <iostream> //cout cin
#include <stdio.h> //fflush()
using namespace std;

//Funciones que realizan la potencia
int Potencia(int Num, int Pot){
    int Res = 1;

    for(int i = 1; i <= Pot; i++)
        Res = Res * Num;

    return Res;
}

double Potencia(double Num, int Pot){
    double Res = 1;

    for(int i = 1; i <= Pot; i++)
        Res = Res * Num;

    return Res;
}

void UsaFuncionesSobrecargadas(){
    //Necesito una variable entera y otra double para el nubm que se va a elevar
    int e, numbi; //Tambien otra int que es para el exponente
    double numbb;

    //Pido datos int
    cout<<"Ingrese un dato int: ";
    fflush(stdin);
    cin>> numbi;
    cout<<"Exponente: ";
    fflush(stdin);
    cin>> e;

    //Muestra y manda a llamar a la funcion
    cout<<"El resultado de " <<numbi <<" elevado a la potencia " <<e <<" es: " <<Potencia(numbi, e);

    //Pido datos double y exponente int
    cout<<"\n\nIngrese un dato double: ";
    fflush(stdin);
    cin>> numbb;
    cout<<"Exponente: ";
    fflush(stdin);
    cin>> e;

    //Muestra y manda a llamar a la funcion
    cout<<"El resultado de " <<numbb <<" elevado a la potencia " <<e <<" es: " <<Potencia(numbb, e) <<endl;
}

int main(){ UsaFuncionesSobrecargadas();} //Mando a llamar la funcion
