#include <iostream> // cin cout
#include <conio.h> // getch
#include <stdlib.h> // system
#include <stdio.h> // gets
#include <string.h> // strlen

using namespace std;

int main() {

    short t;
    char f[100];

    do {
        system("cls");

        cout<<"Introduzca frase: ";
        gets(f);

        for (short i = 0; i < strlen(f); i++) {
            t = f[i];
            cout<<"\n" <<f[i] <<" = " <<t;
        }

        cout<<"\n\n[Esc] Salir\n[Enter] Repetir";
        t =  getch();
    } while(t != 27);
}
