#include <iostream>

using namespace std;

void puntero (){
	int a = 10, b = 20, *p = &b, aux;
	cout<<"Valor de a antes: "<<a <<"\nValor de b antes: " <<*p;
	aux = a;
	a = *p;
	*p = aux;
	cout<<"\n\nValor de a: " <<a <<"\nValor de b: " <<*p;
}
int main(){
	puntero();
}
