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
nodo * buscar_f(nodo*, string);

//**********************************************************************

int main(){
    nodo *inicio = NULL, *nuevo, *fin, *ande;
    int opc;
    string buscar_t;

    do{
        system("cls");
        cout<<"[#1] Crea nodo (pila)\n[#2] Crea nodo (cola)\n[#3] Mostrar lista";
        cout<<"\n[#4] Insertar nodo despues (WIP)\n[#5] Insertar nodo antes (WIP)\n";
        cout<<"[#6] Eliminar nodo\n[Esc] Salir";

        opc = getch();
        system("cls");

        switch(opc){
        case 49: //[#1] Crea nodo (pila)
            if(inicio == NULL){
                inicio = crear();
                fin = inicio;
            }
            else{
                nuevo = crear();
                nuevo -> ptr = inicio;
                inicio = nuevo;
            }
            break;///////////////////////////////////////////////////////

        case 50: //[#2] Crea nodo (cola)
            if(inicio == NULL){
                inicio = crear();
                fin = inicio;
            }
            else{
                nuevo = crear();
                fin -> ptr = nuevo;
                fin = nuevo;
            }
            break;///////////////////////////////////////////////////////

        case 51: //[#3] Mostrar lista
            if(inicio == NULL)
                cout<<"Lista vacia\n";
            else{
                mostrar(inicio);
                cout<<"\nInicio: " <<inicio -> info <<"\nFin: " <<fin -> info <<endl;
            }
            system("pause");
            break;///////////////////////////////////////////////////////

        case 52: //[#4] Insertar nodo despues
            if(true)//if(inicio == NULL)
                cout<<"Sin funcionar\n"; //Lista vacia
            else{
                mostrar(inicio);

                cout<<"\nBuscar: ";
                cin>> buscar_t;

                nuevo = buscar_f(inicio, buscar_t);
                ande = crear();

                if(nuevo != NULL){
                    if(nuevo == inicio && nuevo -> ptr != NULL){
                        if(nuevo -> ptr -> info == buscar_t && nuevo -> ptr -> ptr == NULL){ //Segundo, solo dos datos
                            fin -> ptr = ande;
                            fin = ande;
                        }
                        else if(nuevo -> ptr -> info == buscar_t){ //Segundo
                            ande -> ptr = nuevo -> ptr;
                            nuevo -> ptr = ande;
                        }
                        else{ //Primero
                            inicio = inicio -> ptr;
                            free(nuevo);
                        }
                    }
                    else if(nuevo == inicio){ //Solo un dato
                        inicio = NULL;
                        fin = NULL;
                        free(nuevo);
                    }
                    else if(nuevo -> ptr == fin){ //Ultimo
                        fin = nuevo;
                        fin -> ptr = NULL;
                        free(nuevo -> ptr);
                    }
                    else{ //En medio
                        free(nuevo -> ptr);
                        nuevo -> ptr = nuevo -> ptr -> ptr;
                    }
                }
            }
            system("pause");
            break;///////////////////////////////////////////////////////

        case 53: //[#5] Insertar nodo antes
            if(true)//if(inicio == NULL)
                cout<<"Sin funcionar\n"; //Lista vacia
            else{

            }
            system("pause");
            break;///////////////////////////////////////////////////////

        case 54: //[#6] Eliminar Nodo
            if(inicio != NULL){
                mostrar(inicio);

                cout<<"\nBuscar: ";
                cin>> buscar_t;

                nuevo = buscar_f(inicio, buscar_t);

                if(nuevo != NULL){
                    if(nuevo == inicio && nuevo -> ptr != NULL){
                        if(nuevo -> ptr -> info == buscar_t && nuevo -> ptr -> ptr == NULL){ //Segundo, solo dos datos
                            inicio -> ptr = inicio -> ptr -> ptr;
                            fin = inicio;
                            free(nuevo -> ptr);
                        }
                        else if(nuevo -> ptr -> info == buscar_t){ //Segundo
                            inicio -> ptr = inicio -> ptr -> ptr;
                            free(nuevo -> ptr);
                        }
                        else{ //Primero
                            inicio = inicio -> ptr;
                            free(nuevo);
                        }
                    }
                    else if(nuevo == inicio){ //Solo un dato
                        inicio = NULL;
                        fin = NULL;
                        free(nuevo);
                    }
                    else if(nuevo -> ptr == fin){ //Ultimo
                        fin = nuevo;
                        fin -> ptr = NULL;
                        free(nuevo -> ptr);
                    }
                    else{ //En medio
                        free(nuevo -> ptr);
                        nuevo -> ptr = nuevo -> ptr -> ptr;
                    }
                }
            }
            else
                cout<<"Lista vacia\n";

            system("pause");
            break;///////////////////////////////////////////////////////

        case 27: //[Esc] Salir
            cout<<"Saliendo . . .";
            break;///////////////////////////////////////////////////////

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }
    } while(opc != 27);

	return 0;
}

//**********************************************************************

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

//**********************************************************************

nodo * buscar_f(nodo *aux, string buscar_c){
    nodo *aux2 = aux;
    int i = 0;

    while(aux != NULL){
        if(buscar_c == aux -> info && i == 0)
            return aux;
        else if(buscar_c == aux -> info)
            return aux2;

        aux = aux -> ptr;
        if(i != 0)
            aux2 = aux2 -> ptr;
        i++;
    }

    cout<<"\nInfo no encontrada\n";
    return NULL;
}
