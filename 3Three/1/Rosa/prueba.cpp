//Heap Sort
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define max 100000

using namespace std;
long double Cont;

void filtrado_desc (int A[], int i, int N){
  /* queremos que se respete el orden MAX del montículo */
  int tmp = A[i];
  int hijo = 2 * i;
  if ((hijo < N) && (A[hijo + 1] > A[hijo]))
      hijo++;
  while ((hijo <= N) && (tmp < A[hijo])){
      /* elijo bien el hijo */
      Cont++;
      if ((hijo < N) && (A[hijo + 1] > A[hijo]))
          hijo++;
      A[i] = A[hijo];
      i = hijo;
      hijo = 2 * i;
  }
  A[i] = tmp;
}

void intercambiar (int A[], int i, int j){
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void ordenarHeapsort (int A[], int N){
  int i;
  /* meto los datos en el montículo (ordeno) */
  for (i = N / 2; i >= 0; i--){
      Cont++;
      filtrado_desc (A, i, N);
  }
  /* saco los datos y los meto al final para obtener el array ordenado */
  for (i = N - 1; i > 0; i--){
      Cont++;
      intercambiar (A, 0, i);
      filtrado_desc (A, 0, i - 1);
  }
}

int main() {
    int A[max], j, item, temp, i, k, n;
    srand( time(NULL) );

     cout<<"[1] Burbuja mejorada\n"; //Nombre el metodo

            cout<<"Es un algoritmo que trabaja sobre un arreglo de numeros, tomando el ultimo\n"; //Descripcion
            cout<<"elemento y comparandolo con su anterior y si hubiese cambio los ordena.\n";
            cout<<"Se le llama mejorado porque utiliza una bandera que rompe los ciclos cuendo\n";
            cout<<"el arreglo ya esta ordenado.\n\n";

            cout<<"Arreglo desordenado:\n";

    for(int x = 0; x < max; x++){
        A[x] = rand() % (100 + 1);
        //cout <<A[x] <<" ";
    }

    cout<<endl<<endl;
    ordenarHeapsort(A, max);

    //for(int x = 0; x < max; x++)
        //cout <<A[x] <<" ";

} //main

