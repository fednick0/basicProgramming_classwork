#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

char* funcion(void);
int* entero(void);

int main (){
    char new_nombre[20];
    strcpy(new_nombre, funcion());

    cout <<new_nombre <<endl;

    char gato[20], concat[2];
    memset(gato, '\0', 20);
    memset(concat, '\0', 2);

    for(int i = 0; i < 5; i++){
        itoa(i, concat, 10);
        strcat(gato, concat);
    }

    cout <<gato;

}

char* funcion(){
    static char nombre[20] = "Hola mundo\0";

    return nombre;
}
