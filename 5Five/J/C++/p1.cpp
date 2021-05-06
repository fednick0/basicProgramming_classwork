#include <iostream> //cout cin
#include <string.h> //strlen
#include <stdio.h> //gets
#include <conio.h> //getch
#include <stdlib.h> //system

#define a 255 //Cantidad de caracteres ascii

using namespace std;

int main() {
    short letras[a];
    short ascii, opc;
    char frase[100];
    char r;

    do {
        system("cls");

        for(short x = 0; x < a; x++)
            letras[x] = 0;

        cout<<"Introduzca frase: ";
        gets(frase);

        cout<<"\nFrase es: " <<frase;
        cout<<"\nSin espacios: ";

        //Contar y mostrar sin espacios
        for(short y = 0; y < a; y++) {
            for(short x = 0; x < strlen(frase); x++) {
                ascii = frase[x];
                if( ascii == y )
                    letras[y]++;
                if( y == 0 && ascii != 32 )
                    cout<<frase[x];
            }
        }

        //Mostrar cuantos de cada
        for(short x = 0; x < a; x++) {
            r = x;
            if(letras[x] != 0)
                cout<<"\n" <<r <<": " <<letras[x];
        }

        cout<<"\n\n[Esc] Salir\n[Enter] Repetir\n";
        opc = getch();
    } while(opc != 27);
}
