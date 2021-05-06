#include <iostream>

using namespace std;

main() {

    int n1, r, e;

    cout<<"Ingrese numero: "; cin>>n1;
    cout<<"\n1.- Cuadrado\n2.- Cubico\nIngrese opcion: "; cin>>e;

    if(e == 1)
        r = n1*n1;
    else if(e == 2)
        r = n1*n1*n1;
    else
        cout<<"Ingreso opcion erronea";

    cout<<"\n\n"<<r<<" es el resultado\n\n";


/*  int n1 = 1, n2 = 2, n3 = 3;

    if(n1 > n2 && n1 > n2)
        cout<<n1<<"es el mayor";
    else if(n2 > n1 && n2 > n3)
        cout<<n2<<"es el mayor";
    else if(n3 > n1 && n3 > n2)
        cout<<n3<<"es el mayor";
    else
        cout<<"No existe numero mayor D:"; */

}

