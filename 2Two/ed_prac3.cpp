#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define max 20

using namespace std;

int arreglo[max];

void metodo_1();
void metodo_2();
void mostrar();
void rnd();

int main(){

    int opc;
    rnd();

    do{
        system("cls");
        cout<<"[1.-] Shacker sort\n[2.-] Deck of cards sort\n[3.-] Mostrar\n[4.-] Generar numeros random\n[Esc] Salir";
        opc = getch();

        system("cls");

        switch(opc){
        case 49: //[1.-] Metodo_1
            break;

        case 50: //[2.-] Metodo_2
            break;

        case 51: //[3.-] Mostrar
            mostrar();
            cout<<endl;
            system("pause");
            break;

        case 52: //[4.-] Generar
            rnd();
            cout<<"Nuevos numeros generados Aleatoriamente" <<endl;
            mostrar();
            cout<<endl;
            system("pause");
            break;

        case 27: //[Esc]
            cout<<"Saliendo . . .";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);
}

void metodo_1(){

}

void metodo_2(){

}

void mostrar(){
    for(int x = 0; x < max; x++){
        if(x % 10 == 0 && x != 0)
            cout<<endl;
        cout<<arreglo[x] <<" ";
    }
}

void rnd(){
    for(int x = 0; x < max; x++)
        arreglo[x] = rand() % max;
}
