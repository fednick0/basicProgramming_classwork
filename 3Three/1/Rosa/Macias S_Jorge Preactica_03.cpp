/*
    Macias Sanchez Jorge Oswaldo
    01/09/2017

    Escribir un programa, que muestre en pantalla un menú, con los diferentes ordenamientos
    (burbuja mejorada, inserción, selección, Shell, QuickSort), los cuales deberán de ordenar un
    vector unidimensional de 10 elementos de manera ascendente. El vector deberá ser generado
    aleatoriamente.

    El programa debe mostrar el nombre del ordenamiento, como se realiza este paso a paso en
    pantalla (de acuerdo con el ordenamiento que seleccionó el usuario). Así mismo el programa
    debe mostrar en pantalla el vector generado por la computadora (él desordenado) y como
    queda al ordenarlo. El programa debe estar presentable, es decir con un acomodo agradable y
    entendible a la vista del usuario. Toma en cuenta las validaciones que sean necesarias.*/

#include <iostream> //cin cout
#include <stdlib.h> //rand() system()
#include <conio.h> //getch()
#include <time.h> //time()

#define max 10000

using namespace std;

//Funciones que utilizo, todas reciben el arreglo
void burbuja_m(int*);
void insercion(int*);
void seleccion(int*);
void shell(int*);
void quicksort(int*, int, int); //Esta recibe el arreglo, primera posicion y la ultima

int main(){
    int A[max]; //Arreglo principal y unico
    int opc; //Manipula el switch del menu

    do{ //Ciclo principal
        system("cls");

        srand( time(NULL) ); //Dice internet que asi se hacer para mejorar el random

        cout<<"Algoritmos de ordenamientos\n";
        cout<<"[1] Burbuja mejorada\n";
        cout<<"[2] Insercion\n";
        cout<<"[3] Seleccion\n";
        cout<<"[4] Shell\n";
        cout<<"[5] QuickSort\n";
        cout<<"[Esc] Salir\n";

        opc = getch();
        switch(opc){

        /*  Todos los case son iguales, lo unico que cambia es
            es el metodo que utiliza, por lo que voy a decir que
            hace cada cosa el primero.

            TODOS SON IGUALES*/

        case '1': //Burbuja mejorada
            system("cls");
            cout<<"[1] Burbuja mejorada\n"; //Nombre el metodo

            cout<<"Es un algoritmo que trabaja sobre un arreglo de numeros, tomando el ultimo\n"; //Descripcion
            cout<<"elemento y comparandolo con su anterior y si hubiese cambio los ordena.\n";
            cout<<"Se le llama mejorado porque utiliza una bandera que rompe los ciclos cuendo\n";
            cout<<"el arreglo ya esta ordenado.\n\n";

            cout<<"Arreglo desordenado:\n";
            for(int x = 0; x < max; x++){ //Ciclo para manipular el arreglo
                A[x] = rand() % (100 + 1); //Genero arreglo aleatoria con 10 numeros entre el 0 y el 100
                cout <<A[x] <<" "; //Muestro x posicion
            }
            cout<<"\n\nPasos:\n";

            burbuja_m(A); //Esto es lo que cambia entre cada case

            cout<<"\nArreglo ordenado:\n"; //Muestro
            for(int x = 0; x < max; x++)
                cout <<A[x] <<" ";

            cout <<"\n\n";
            system("pause");
            break;

        //***********************************

        case '2': //Insercion
            system("cls");
            cout<<"[2] Insercion\n";

            cout<<"Este algoritmo toma cada elemento y se inserta en la posicion\n";
            cout<<"apropiada con respecto al resto de valores ya ordenados.\n\n";

            cout<<"Arreglo desordenado:\n";
            for(int x = 0; x < max; x++){
                A[x] = rand() % (100 + 1);
                cout <<A[x] <<" ";
            }
            cout<<"\n\nPasos:\n";

            insercion(A);

            cout<<"\nArreglo ordenado:\n";
            for(int x = 0; x < max; x++)
                cout <<A[x] <<" ";

            cout <<"\n\n";
            system("pause");
            break;

        //***********************************

        case '3': //Seleccion
            system("cls");
            cout<<"[3] Seleccion\n";

            cout<<"Buscar el mínimo elemento entre una posicion i y el final\n";
            cout<<"de la lista con el fin de intercambiar el minimo con el\n";
            cout<<"elemento de la posicion i\n\n";

            cout<<"Arreglo desordenado:\n";
            for(int x = 0; x < max; x++){
                A[x] = rand() % (100 + 1);
                cout <<A[x] <<" ";
            }
            cout<<"\n\nPasos:\n";

            seleccion(A);

            cout<<"\nArreglo ordenado:\n";
            for(int x = 0; x < max; x++)
                cout <<A[x] <<" ";

            cout <<"\n\n";
            system("pause");
            break;

        //***********************************

        case '4': //Shell
            system("cls");
            cout<<"[4] Shell\n";

            cout<<"Este ordenamiento determina primero un numero entero que es la\n";
            cout<<"mitad del total de posiciones del arreglo, en este caso 10/2=5\n";
            cout<<"Luego compara la primera posicion con posicion mas mitad, A[0] > A[5]\n";
            cout<<"Ordena de ser necesario y para la segunda vuelta, la mitad, ahora sera\n";
            cout<<"otra vez la mitad 5/2=2\n";
            cout<<"Por lo que es uno de los algoritmos mas eficientes.\n\n";

            cout<<"Arreglo desordenado:\n";
            for(int x = 0; x < max; x++){
                A[x] = rand() % (100 + 1);
                cout <<A[x] <<" ";
            }
            cout<<"\n\nPasos:\n";

            shell(A);

            cout<<"\nArreglo ordenado:\n";
            for(int x = 0; x < max; x++)
                cout <<A[x] <<" ";

            cout <<"\n\n";
            system("pause");
            break;

        //***********************************

        case '5': //QuickSort
            system("cls");
            cout<<"[5] QuickSort\n";

            cout<<"- Elegir un elemento de la lista de elementos a ordenar, al que llamaremos pivote.\n";
            cout<<"- Resituar los demas elementos de la lista a cada lado del pivote, de manera que a\n";
            cout<<"un lado queden todos los menores que el, y al otro los mayores. Los elementos\n";
            cout<<"iguales al pivote pueden ser colocados tanto a su derecha como a su izquierda,\n";
            cout<<"dependiendo de la implementacion deseada. En este momento, el pivote ocupa\n";
            cout<<"exactamente el lugar que le correspondera en la lista ordenada.\n";
            cout<<"- La lista queda separada en dos sublistas, una formada por los elementos a la\n";
            cout<<"izquierda del pivote, y otra por los elementos a su derecha.\n";
            cout<<"Repetir este proceso de forma recursiva para cada sublista mientras estas\n";
            cout<<"contengan mas de un elemento. Una vez terminado este proceso todos los elementos\n";
            cout<<"estaran ordenados.\n\n";

            cout<<"Arreglo desordenado:\n";
            for(int x = 0; x < max; x++){
                A[x] = rand() % (100 + 1);
                cout <<A[x] <<" ";
            }
            cout<<"\n\nPasos:\n";

            quicksort(A, 0, max - 1);

            cout<<"\nArreglo ordenado:\n";
            for(int x = 0; x < max; x++)
                cout <<A[x] <<" ";

            cout <<"\n\n";
            system("pause");
            break;

            //***********************************

            case 27:
                cout<<"\nSaliendo. . .\n";
                break;

            //***********************************

            default:
            cout<<"\nOpcion Incorrecta\n";
            system("pause");
        }
    } while(opc != 27);
}

////////////////////////////////////////////////

void burbuja_m(int A[]){
    bool ban = true; //Bandera para romper ciclo
    int auxi; //Auxiliar para intercambiar valores de posicion

    for(int x = 0; x < max && ban; x++){ //Determina las vueltas a todo el arreglo
        ban = false;

        for(int y = 0; y < max - 1; y++){ //Determina las comparaciones
            if(A[y] > A[y + 1]){ //Compara
                ban = true; //Si no entra, ban == false y rompe cilo, indicando que ya esta ordenado

                auxi = A[y]; //Cambia posiciones
                A[y] = A[y + 1];
                A[y + 1] = auxi;
            }
        }

        for(int x = 0; x < max; x++) //Muestro cada vuelta el ordenamiento
            cout <<A[x] <<" ";
        cout<<"\n";
    }
}

////////////////////////////////////////////////

void insercion(int A[]){
    int temp, primero, ultimo, central;

    for(int k = 2; k < max; k++){
        temp = A[k]; //Elemento que se va a insertar
        primero = 0;
        ultimo = k - 1;

        while(primero <= ultimo){
            central = (primero + ultimo) / 2; //Determino centro

            if(temp <= A[central]) //Si valor a insertar es menor o igual al valor central
                ultimo = central - 1; //Ultimo camvia de posicion
            else //Si no...
                primero = central + 1; //... primero cambia de posicion
        }

        for(int i = k - 1; i >= primero; i--) //Aqui realiza el ordenamiento segun el cambio de posiciones
            A[i + 1] = A[i];
        A[primero] = temp;

        for(int x = 0; x < max; x++) //Muestro cada vuelta el ordenamiento
            cout <<A[x] <<" ";
        cout<<"\n";
    }
}

////////////////////////////////////////////////

void seleccion(int A[]){
    int menor, temp; //Variables que utilizo

    for(int x = 0; x < max; x++){ //Ciclo que controla las vueltas
        menor = x; //Determino por default que el menor es la primera posicion en la primera vuelta

        for(int y = x + 1; y < max; y++) //Ciclo que controla las comparaciones
            if(A[y] < A[menor]) //Si el menor (determinado arriba) es mayor a la segunda posicion
                menor = y; //Entonces el menor no era la primera posicion, sino la segunda

        temp = A[menor]; //Aqui se hace el intercambio
        A[menor] = A[x];
        A[x] = temp;

        for(int x = 0; x < max; x++) //Muestro cada vuelta el ordenamiento
            cout <<A[x] <<" ";
        cout<<"\n";
    }
}

////////////////////////////////////////////////

void shell(int A[]){
    int n_entre = max;  //Variables que utilizo
    int temp, atras;
    bool ordenado; //Controla el ciclo principal

    do{ //Ciclo principal, controla si esta ordenado o no
        n_entre = n_entre / 2; //Determina la separacion para la comparacion
        ordenado = true; //Digo que por default esta ordenado, si no, mas adelante cambia a false

        for(int x = 0; x < max - n_entre; x++){ //Controla las comparaiones que debe hacer
            if(A[x] > A[x + n_entre]){
                ordenado = false; //Si entra, aun no esta ordenado

                temp = A[x]; //Aqui hace el intercambio
                A[x] = A[x + n_entre];
                A[x + n_entre] = temp;

                for(int y = 1; x - n_entre*y >= 0 && A[x - n_entre*y] > A[x - n_entre*(y - 1)]; y++){ //Compara otraves para realizar mas cambios antes de disminuir la separacion entre las comparaciones
                    temp = A[x - n_entre*y]; //Aqui hace el intercambio otravez
                    A[x - n_entre*y] = A[x - n_entre*(y - 1)];
                    A[x - n_entre*(y - 1)] = temp;

                } //fin for
            } //fin if
        } //fin for

        for(int x = 0; x < max; x++) //Muestro cada vuelta el ordenamiento
            cout <<A[x] <<" ";
        cout<<"\n";
    } while(!ordenado);
}

////////////////////////////////////////////////

void quicksort(int A[], int izq, int der){ //Algoritmo sacado completamente de internet, el mio no lo encontre
    //Nunca me quedo claro como funciona este algoritmo gracias a la recursividad que es demaciado compleja de entender

    int i, j, x , aux;

    i = izq;
    j = der;
    x = A[(izq + der) / 2];

    do{
        while(A[i] < x && j <= der)
            i++;

        while(x < A[j] && j > izq)
            j--;

        if(i <= j){
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i++;
            j--;
        }

    } while(i <= j);

    for(int x = 0; x < max; x++) //Muestro cada vuelta el ordenamiento
        cout <<A[x] <<" ";
    cout<<"\n";

    if(izq < j)
        quicksort(A, izq, j);
    if(i < der)
        quicksort(A, i, der);
}
