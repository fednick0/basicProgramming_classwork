#include <iostream>
#include <stdlib.h>

#define max 10

using namespace std;

int main(){

    int numb[max];

    for(int x = 0; x < max; x++){
        numb[x] = rand() % 100 + 1;
        cout<<numb[x] <<" ";
    }
    cout<<endl;
    system("pause");
    cout<<endl;

    int n_entre = max;
    int temp, atras;
    bool ordenado;

    do{
        n_entre = n_entre / 2;
        ordenado = true;

        for(int x = 0; x < max - n_entre; x++){
            if(numb[x] > numb[x + n_entre]){
                ordenado = false;
                temp = numb[x];
                numb[x] = numb[x + n_entre];
                numb[x + n_entre] = temp;

                for(int y = 1; x - n_entre*y >= 0 && numb[x - n_entre*y] > numb[x - n_entre*(y - 1)]; y++){
                    temp = numb[x - n_entre*y];
                    numb[x - n_entre*y] = numb[x - n_entre*(y - 1)];
                    numb[x - n_entre*(y - 1)] = temp;

                } //for
            } //if
        } //for
    } while(!ordenado);

    for(int x = 0; x < max; x++)
        cout<<numb[x] <<" ";


} //main
