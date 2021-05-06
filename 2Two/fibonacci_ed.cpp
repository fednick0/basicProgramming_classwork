#include <iostream>

using namespace std;

int fibo(int n) {
    if(n == 0 || n == 1)
        return n;
    else
       return fibo(n - 2) + fibo(n - 1);
}

int main(){
    int dato;

    cout<<"Cuantos datos desea mostrar? ";
    cin>>dato;

    for(int x = 0; x < dato; x++)
        cout<< fibo(x)<< " ";

    cout<<endl;
}
