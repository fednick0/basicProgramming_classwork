/*
    Macias S. Jorge Oswaldo
    20/10/2017

    i. Creación de árboles binarios con plantillas.

    ii. Analiza, el programa: Arboles binarios con plantilla.
        1. (se anexa el PDF correspondiente, si deseas puedes basarte en el).

    iii. El programa de Arboles binarios, deberá:
        a. Dar de alta un árbol
        b. Consultar el árbol
            i. La impresión puede ser libre albedrio
            ii. O colocando la raíz, después los hijos izquierdos, hijos derechos
        c. Recorridos (Debe ir el nombre del recorrido y los elementos, según el recorrido)
            i. Preorden
            ii. Inorden
            iii. Postorden
			
	Espero no se moleste maestra, saque los algoritmos de internet
	http://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html
*/

#include <iostream> //cout<< cin>>
#include <cstdlib> //ojo que no la conozco
#include <conio.h> //getch()
#include <stdlib.h> //system()

using namespace std;

struct nodo{
    int nro;
    struct nodo *izq, *der;
}; typedef struct nodo *ABB;

ABB crearNodo(int x) {
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ABB &arbol, int x) {
    if(arbol == NULL) {
        arbol = crearNodo(x);
    }

    else if(x < arbol->nro)
        insertar(arbol->izq, x);
    else if(x > arbol->nro)
        insertar(arbol->der, x);
}

void preOrden(ABB arbol) {
    if(arbol != NULL) {
        cout<<arbol->nro <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(ABB arbol) {
    if(arbol != NULL) {
        inOrden(arbol->izq);
        cout<<arbol->nro << " ";
        inOrden(arbol->der);
    }
}

void postOrden(ABB arbol) {
    if(arbol!=NULL) {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->nro << " ";
    }
}

void verArbol(ABB arbol, int n) {
    if(arbol == NULL)
        return;
    verArbol(arbol->der, n+1);

    for(int i=0; i<n; i++)
        cout<<"   ";
    cout<< arbol->nro <<endl;

    verArbol(arbol->izq, n+1);
}

int main() {
    ABB arbol = NULL;

    int n, x, opc;

    do{
        system("cls");
        cout<<"\tArbol binario" <<endl;
        cout<<"[1] Insertar datos" <<endl;
        cout<<"[2] Mostrar arbol binario" <<endl;
        cout<<"[3] Recorridos" <<endl;
        cout<<"[4] Eliminar arbol binario" <<endl;
        cout<<"[Esc] Salir" <<endl;

        opc = getch();

        switch(opc){
        case '1':
            system("cls");
            cout<<"Cuantos datos va a ingresar?\n--> ";
            cin>> n;
            cout<<endl;

            for(int i = 0; i < n; i++) {
                cout<<"Dato No." <<i << ": ";
                cin>> x;
                insertar(arbol, x);
            }

            cout<<"\nSe han guardado\n";
            system("pause");
            break;

        case '2':
            system("cls");
            cout<<"Arbol binario:\n";
            verArbol( arbol, 0);

            cout<<"\n\n";
            system("pause");
            break;

        case '3':
            system("cls");
            cout<<"Recorridos del arbol binario\n";
            verArbol( arbol, 0);

            cout<<"\nPreorden:  ";
            preOrden(arbol);

            cout<<"\nInorden:   ";
            inOrden(arbol);

            cout<<"\nPostorden: ";
            postOrden(arbol);

            cout<<"\n\n";
            system("pause");
            break;

        case '4':
            arbol = NULL;
            cout<<"\nSe ha eliminado arbol binario\n";
            system("pause");
            break;

        case 27:
            cout<<"\nSaliendo . . .\n";
            break;
        default:
            cout<<"\nOpcion incorrecta\n";
            system("pause");
        }
    } while(opc != 27);
}