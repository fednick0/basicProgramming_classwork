#include <iostream>
#include <stdlib.h>

#define max 10

using namespace std;

int main(){

    int arreglo[max];
    int dato;
    bool ban = true;

    for(int x = 0; x < max; x++){
        arreglo[x] = rand() % 100 + 1;
        cout<<arreglo[x] <<" ";
    }

    cout<<endl;
    system("pause");

    for(int x = 0; x < max && ban; x++){
        ban = false;

        for(int y = 0; y < max - 1; y++){
            if(arreglo[y] > arreglo[y + 1]){
                ban = true;
                dato = arreglo[y];
                arreglo[y] = arreglo[y + 1];
                arreglo[y + 1] = dato;
            }
        }
    }

    cout<<"\n\n";
    for(int x = 0; x < max; x++)
        cout<<arreglo[x] <<" ";

}
