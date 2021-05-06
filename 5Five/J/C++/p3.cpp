#include <iostream>
#include <typeinfo>
#include <stdio.h>

using namespace std;

int main() {

    auto x = 0;

    do {
        fflush(stdin);
        cin>> x;
        cout << typeid(x).name() << endl;
    } while(true);

    return 0;
}
