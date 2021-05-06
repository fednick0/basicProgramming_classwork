#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int calificacion;

    do{
        system("cls");

        cout<<"Calificacion: ";
        cin>> calificacion;

        if(calificacion >= 0 && calificacion < 60)
            cout<<"Reprobado";
        else if(calificacion >= 60 && calificacion <= 100)
            cout<<"Aprobado";
        else
            cout<<"Error";

        cout<<"\n\n\n[Into] Repetir\n[Esc] Salir";
    } while(getch() != 27);
}
