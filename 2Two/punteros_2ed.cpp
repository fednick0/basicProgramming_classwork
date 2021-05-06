#include <iostream>
#include <stdlib.h>

using namespace std;

void func (string *x);

int main(){
    string a, *p = &a;

    cout<<"Nombre: ";
    cin>> *p;

    cout<<endl;
    //system("cls");
    func(p);
}

void func(string *x){
    *x = "Juanito";
    cout<<"Su nombre ha sido modificada por: " <<*x;
}
