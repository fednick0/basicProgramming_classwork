#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//ofstream ifstream

using namespace std;

int main(){

    FILE *archivo, *copia;

    char dir_archivo[50];
    char nuevo_nombre[70] = "copia_";

        char caracter = '\0';

        cout<<"Nombre del archivo a copiar: ";
        cin>> dir_archivo;

        strcat(nuevo_nombre, dir_archivo);

        archivo = fopen(dir_archivo, "r");
        copia = fopen(nuevo_nombre, "w");

        if(archivo == NULL || copia == NULL){
            cout<<"Error encontrado\n";
            system("exit");
        }

        do{
            caracter = fgetc(archivo);
            if(caracter != EOF)
                fputc(caracter, copia);
        } while(caracter != EOF);

        fclose(copia);
        fclose(archivo);

        cout<<"Archivo copiado satisfactoriamente.\n\n";
}
