#include <iostream>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

FILE *pf;
char cadena[1000];
char nombre[100];

int main(){

    memset(cadena, 0, sizeof(cadena));
    memset(nombre, 0, sizeof(nombre));

    cout<<"Ingrese ubicacion y nombre del archivo: ";
    gets(nombre);

    pf = fopen(nombre, "ab"); //"r"

    if(pf == NULL){
        cout<<"No fue posible crear el archivo";
        system("exit");
    }

    cout<<"Ingrese texto a guardar: ";
    gets(cadena);

    strcat(cadena, "\n");
    strcat(cadena, "hola");

    fputs(cadena, pf);
    fclose(pf);

    /*
        fgets(cadena, 1000, pf);
        fgetc
        cout <<cadena;


    */
}
