#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    int arr[2][3];

    for(short x = 0; x < 2; x++)
        for(short y = 0; y < 3; y++){
            if(y == 0 && x != 0)
                cout<<endl;
            cout<<"Ingrese valor["<<x<<"]["<<y<<"]: ";
            cin>>arr[x][y];
        }

    system("cls");

    for(short x = 0; x < 2; x++)
        for(short y = 0; y < 3; y++) {
            if(y == 0 && x != 0)
                cout<<endl;
            cout<<arr[x][y] <<" ";
            }

}
