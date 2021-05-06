#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){

    int opc;

    do{
        system("cls");
        opc = getch();
        cout<<opc <<endl;
        system("pause");

    } while(opc != 27);
}
