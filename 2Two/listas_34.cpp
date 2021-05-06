#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct elemento{
	char info[50];
	struct elemento *ptr;
} nodo;

nodo * crear();
void mostrar(nodo*);

int main(){

    nodo *inicio = NULL, *nuevo, *fin, *temp;
    int opc;

    do{
        system("cls");

        cout<<"\tLista colas\n";
        cout<<"\n\t[F1] Ingresar\n\t[F2] Eliminar\n\t[F3] Mostrar\n\t[Esc] Salir\n";

        opc = getch();
        if(opc == 0)
            opc = getch();

        system("cls");

        switch(opc){
        case 59: //Ingresar
            do{
                system("cls");
                if(inicio == NULL){
                    inicio = crear();
                    fin = inicio;
                }
                else{
                    nuevo = crear();
                    fin -> ptr = nuevo;
                    fin = nuevo;
                }
                cout<<"\n\n[!Esc] Repetir";
            } while(getch() != 27);
            break;


        case 60: //Eliminar
            if(inicio == NULL)
                cout<<"Lista vacia\n";
            else if(inicio == fin){
                free(inicio);
                fin = NULL;
                inicio = NULL;
            }
            else{
                temp = inicio;
                inicio = inicio ->ptr;
                free(temp);
            }

            cout<<"Elemente eliminado\n";
            system("pause");
            break;


        case 61: //Mostrar
            if(inicio == NULL)
                cout<<"Lista vacia\n";
            else{
                mostrar(inicio);
                cout<<"\nInicio: " <<inicio -> info <<"\nFin: " <<fin -> info <<endl;
            }
            system("pause");
            break;


        case 27: //Salir
            cout<<"Saliendo . . .\n";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);

    return 0;
}

nodo * crear(){
    nodo *aux = NULL;
    aux = (nodo*) malloc(sizeof(nodo));

    cout<<"Ingrese cualquier informacion: ";
    gets(aux -> info);
    aux -> ptr = NULL;

    return aux;
}

void mostrar(nodo *aux){
    while(aux != NULL){
        cout<<"Info: " <<aux -> info <<"\n";

        aux = aux -> ptr;
    }
}


