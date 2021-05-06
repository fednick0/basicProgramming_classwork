#include <iostream>
using namespace std;

int* funcion(){
    static int a[1] = {42};

    return a;
}

int main(){
    int *e;

    e = funcion();

    for(int x = 0; x < 1; x++)
        cout<<e[x] <<" ";
}
