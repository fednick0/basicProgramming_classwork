#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(){
    int x;

    do{
        system("cls");
        cout<<"Ingrese un numero: ";
        cin>> x;
        cout<<"El facorial de " <<x <<" es: " <<factorial(x);

        cout<<"\n\n[!Esc] Repetir";
    } while(getch() != 27);
}


