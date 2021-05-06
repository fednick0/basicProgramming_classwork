#include <iostream>

using namespace std;

main(){

    int n1, n2, r, e;

    cout<<"Ingrese primer valor: "; cin>>n1;
    cout<<"Ingrese segundo valor: "; cin>>n2;
    cout<<"\n1.- Resta\n2.- Multiplicacion\nIngrese opcion: "; cin>>e;

    if(e == 1)
        r = n1 - n2;
    else if(e == 2)
        r = n1 * n2;
    else
        cout<<"Ingreso opcion erronea";

    cout<<"\n\n"<<r<<" es el resultado\n\n\n";


}
