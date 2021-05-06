#include <iostream>

using namespace std;

void uno();

long int x = 0;

int main(){
    uno();
}

void uno(){
    x++;
    cout<<x;
    uno();
}
