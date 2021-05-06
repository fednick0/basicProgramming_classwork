#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

using namespace std;

typedef struct elemento{
    int edad;
    char nombre[50];
    struct elemento *puntero;
} nodo;

char menu();
nodo * crear_nodo();
void mostrar_listad(nodo*);
int vedad(int, int);
char* nombre(int, int);

int main(){
    char opc;
    nodo *inicio = NULL, *nuevo, *fin;

    do{
        opc = menu();

        switch(opc){
        char o;

        case 59:
            system("cls");
            if(inicio == NULL)
                cout<<"LISTA VACIA\n";
            else
                mostrar_listad(inicio);

            cout<<"\nPresione cualquier tecla para continuar";
            o = getch();
            break;

        case 60:
            system("cls");
            if(inicio == NULL){
                inicio = crear_nodo();
                fin = inicio;
            }
            else{
                nuevo = crear_nodo();
                fin -> puntero = nuevo;
                fin = nuevo;
            }

            cout<<"\nPresione cualquier boton para continuar";
            o = getch();
            break;

        case 27:
            system("cls");
            cout<<"GRACIAS POR PASAR";
            break;

        default:
            if(opc != 27)
                Beep(500, 1000);
        }
    } while(opc != 27);
} //main()

char menu(){
    char opc1 = '\0';
    system("cls");

    cout<<"\tMenu Lista Simple Enlazada\n";
    cout<<"[F1] Mostrar nodos\n";
    cout<<"[F2] Agregar nodo al final\n";
    //cout<<"[F3] Agregar nodo al inicio\n";
    //cout<<"[F4] Agregar nodo en cualquier parte\n";
    //cout<<"[F5] Eliminar primer nodo\n";
    //cout<<"[F6] Eliminar ultimo nodo\n";
    //cout<<"[F7] Eliminar cualquier nodo\n";
    //buscar, borrar todo
    cout<<"[Esc] Salr\n";
    opc1 = getch();

    if(opc1 == 0)
        opc1 = getch();

    return opc1;
}

nodo * crear_nodo(){
    nodo *aux = NULL;
    aux = (nodo*) malloc(sizeof(nodo));

    if(aux != NULL){
        char *pnombre;
        fflush(stdin);
        memset(&aux -> nombre, 0, sizeof(aux -> nombre));
        cout<<"Ingrese nombre: ";
        pnombre = nombre(16, 0);
        strcpy(aux -> nombre, pnombre);

        cout<<"Ingrese edad: ";
        aux -> edad = vedad(14, 1);
        aux -> puntero = NULL;
        }
    return aux;
}

void mostrar_listad(nodo *aux){
    int numero = 1;

    while(aux != NULL){
        cout<<"Numero: " <<numero;
        cout<<"\nNombre: " <<aux -> nombre;
        cout<<"\nEdad: " <<aux -> edad <<"\n\n";

        aux = aux -> puntero;
        numero++;
    }
}

int vedad(int x, int y){///////////////////////////////////
    int valor = -1, ban = 0;
    do{
        int lon = 0;
        char entero[12];
        memset(entero, 0, sizeof(entero));
        gets(entero);
        ban = 0;
        lon = strlen(entero);

        for(int c = 0; c < lon; c++)
            if(isdigit(entero[c]) == '\0')
                ban = 1;

        if(lon == 0)
            ban = 1;

        valor = atoi(entero);
        if(valor < 0 || valor > 120)
            ban = 1;

        if(ban == 1){
            Beep(1000, 100);
            cout<<"              ";
        }
    } while(ban != 0);
    return valor;
}

char* nombre(int x, int y){/////////////////////////////////////////
    static char nombre[50];
    int lon, ban;

    do{
        lon = 0;
        ban = 0;
        memset(nombre, 0, sizeof(nombre));

        gets(nombre);

        lon = strlen(nombre);

        if(lon > 50){
            ban = 1;
            cout<<"Nombre demaciado largo";
            Beep(1000, 100);
            Sleep(500);
            cout<<"                      ";
        }

        int c = 0;
        do{
            if(isalpha(nombre[c]) == 0 && nombre[c] != 32)
                ban = 2;
            c++;
        } while(c < lon);

        if(ban == 2){
            cout<<"No se permiten caracteres especiales";
            Beep(1000, 100);
            Sleep(500);
            cout<<"             ";
        }
    } while(ban != 0);

    return nombre;
}

