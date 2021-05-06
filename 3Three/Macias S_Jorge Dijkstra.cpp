/**
    Equipo
    Luis Ernesto Rivera Leon    0620160081
    Jorge Oswaldo Macias S.     0620160084

    Programa. Implementación del algoritmo Dijkstra, en encontrar la ruta más corta de un punto a otro.
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

// Una función  para encontrar el vértice con un valor mínimo de distancia, desde
// el conjunto de vértices aún no incluidos en el árbol de ruta más corta
int minDistance(int dist[], bool sptSet[]){
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

//Una función para imprimir la matriz de distancia construidq
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

// Función que implementa el algoritmo de ruta más corta de de Dijkstra
void dijkstra(int graph[V][V], int src)
{
     int dist[V];


     bool sptSet[V];


     // Inicialice todas las distancias como INFINITO y stpSet [] como falso
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // La distancia del vértice de origen desde sí misma siempre es 0
     dist[src] = 0;

     // Encuentra la ruta más corta para todos los vértices
     for (int count = 0; count < V-1; count++)
     {
       // Elija el vértice de distancia mínima del conjunto de vértices que no
       // aún procesado. u siempre es igual a src en la primera iteración.
       int u = minDistance(dist, sptSet);

       //Marcar el vértice elegido como procesado
       sptSet[u] = true;

       // Actualiza el valor dist de los vértices adyacentes del vértice seleccionado.
       for (int v = 0; v < V; v++)

         // Actualizar dist [v] solo si no está en sptSet, hay una ventaja de
         // u a v, y el peso total de la ruta de src a v a través de u
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
