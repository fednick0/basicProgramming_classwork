/**
    Equipo
    Luis Ernesto Rivera Leon    0620160081
    Jorge Oswaldo Macias S.     0620160084

    Programa. Implementaci�n del algoritmo Dijkstra, en encontrar la ruta m�s corta de un punto a otro.
*/

//Ojo, el siguiente enlace muestra el grafo.
//  https://drive.google.com/file/d/12-xkVsSzT83Ck9Anejf5P2Qj98nBBHHR/view?usp=sharing

#include <stdio.h>
#include <limits.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

// Numero de vertices en el grafo
#define V 9

// Una funci�n  para encontrar el v�rtice con un valor m�nimo de distancia, desde
// el conjunto de v�rtices a�n no incluidos en el �rbol de ruta m�s corta
int minDistance(int dist[], bool sptSet[]){
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

//Una funci�n para imprimir la matriz de distancia construidq
int printSolution(int dist[], int n)
{
	printf("\nESPERE MIENTRAS ENCUETRA EL CAMINO MAS CORTO........\n");
	Sleep(2000);

   printf("\n\n\nVertices  | Distancia mas cercana\n");
   for (int i = 0; i < V; i++){
       Sleep(100);
      printf("   %d --------------> %d\n", i, dist[i]);
}
getch();
}

// Funci�n que implementa el algoritmo de ruta m�s corta de de Dijkstra
void dijkstra(int graph[V][V], int src)
{
     int dist[V];


     bool sptSet[V];


     // Inicialice todas las distancias como INFINITO y stpSet [] como falso
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // La distancia del v�rtice de origen desde s� misma siempre es 0
     dist[src] = 0;

     // Encuentra la ruta m�s corta para todos los v�rtices
     for (int count = 0; count < V-1; count++)
     {
       // Elija el v�rtice de distancia m�nima del conjunto de v�rtices que no
       // a�n procesado. u siempre es igual a src en la primera iteraci�n.
       int u = minDistance(dist, sptSet);

       //Marcar el v�rtice elegido como procesado
       sptSet[u] = true;

       // Actualiza el valor dist de los v�rtices adyacentes del v�rtice seleccionado.
       for (int v = 0; v < V; v++)

         // Actualizar dist [v] solo si no est� en sptSet, hay una ventaja de
         // u a v, y el peso total de la ruta de src a v a trav�s de u
         // es menor que el valor actual de dist [v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // imprime la matriz de distancia
     printSolution(dist, V);
}

// driver program to test above function
int main(){

   /* uso el grafo de arriva */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
