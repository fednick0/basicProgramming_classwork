#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

    short numb[10];

    for(short x = 9; x >= 0; x--){
        cout<<"Ingrese numero en la posicion "<< x<< ": ";
        cin>>numb[x];
    }

    system("cls");
    for(short x = 0; x < 10; x++)
        cout<<"Posicion "<< x<<": " << numb[x]<<endl;

    return 0;
}
