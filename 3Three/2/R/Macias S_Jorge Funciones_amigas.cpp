/*
    Macias S. Jorge Oswaldo
    22/09/2017

    i. Analiza, pasa y completa el programa: Funciones_Amigas
    1. (se anexa el PDF correspondiente al programa)
    ii. Modifica el programa para que solicite los nuevos valores
a sumar.

*/

//El programa, en su mayoria, es directamente del pdf

#include <iostream>

using namespace std;

class ejemplo{
    private:
        int atrib1, atrib2;

    public:
        ejemplo();
        ejemplo(int, int);
        void imprime();
        friend int suma(int, ejemplo);
}; ejemplo::ejemplo(){}

ejemplo::ejemplo(int n1, int n2){
    atrib1 = n1;
    atrib2 = n2;
}

void ejemplo::imprime(){
    cout <<"\nValor del primer atributo: " <<atrib1;
    cout <<"\nValor del segundo atributo: " <<atrib2;
}

int suma(int dato, ejemplo valor){
    return (dato + valor.atrib1 +valor.atrib2);
}

void usarfuncionamigas(){
    int resultado, d1, d2;

    cout<<"Ingrese primer dato: ";
    cin>> d1;
    cout<<"Ingrese segundo dato: ";
    cin>> d2;

    ejemplo objejemplo(d1, d2);
    resultado = suma(10, objejemplo); //aparte de sumar los dos digitos, suma un 10, tal cual en el pdf

    cout<<"\nResultado de la suma es: " <<resultado;
}

int main(){
    usarfuncionamigas();
    cout<<endl;
}

