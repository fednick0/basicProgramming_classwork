#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){

    do{
        int a;
        int *p = &a;

        system("cls");
        cout<<"Ingrese valor de 'a': ";
        cin>> a;

        cout<<"Valor de 'p': " <<*p <<endl;
        cout<<"Direccion de 'a':" <<&a <<endl;

        cout<<"\nIngrese nuevo valor: ";
        cin>> *p;

        cout<<"Valor de 'a': " <<a <<endl;
        cout<<"Valor de 'p': " <<*p <<endl;

        cout<<"\n[!Esc] Repetir";
    } while(getch() != 27);

    return 0;
}
