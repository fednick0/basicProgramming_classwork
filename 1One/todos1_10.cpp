#include <iostream>
#include <stdlib.h>

using namespace std;

void uno(){
    int x = 1, y = 1;
    if(x = y * 5)
        x = 0;
    else
        x = -1;
    cout<< x;
}

//*******************************************

void dos(){
    int x = 1, y = 1;
    if(x == 1)
        if(y == 0)
            x = 10;
    else
        x = -1;
    cout<< x;
}

//*******************************************

void tres(){
    int x = 1;
    switch(x){
    case 1:
        x++;
    case 2:
        x++;
    }
    cout<< x;
}

//*******************************************

void cuatro(){
    int x = 1;
    while(x <= 5)
        cout<< ++x << ' ';
}

//*******************************************

void cinco(){
    int x = 0;
    for(x = 'a'; x <= 'z'; x += 10)
        cout<< x << ' ';
}

//*******************************************

void seis(){
    int x = 0, y = 0;
    for(x = 6; x > 0; x -= 2)
        for(y = 0; y < 2; y ++)
            cout<< x-y << ' ';
}

//*******************************************

void siete(){
    int x = 0, y = 1;
    for(x = 6; x > 0; x -= 2)
        if(x < y * 3) continue;
            cout<< x << ' ';
}

//*******************************************

void fnx_8(int x){
    if(x) cout<< x << ' ';
}

void ocho(){
    int i, a = 1234;
    for(i = 0; i < 4; i++)
        fnx_8(a = a / 10);
}

//*******************************************

void fnx_9(int x){
    int i = 0;
    for(i = x; i > 0; i--)
        cout<< i << ' ';
}

void nueve(){
    int x;
    for(x = 0; x <3; x++)
        fnx_9(x);
}

//*******************************************

void fnx_10(int x){
    cout<< static_cast<char>(x) << ' ';
}

void diez(){
    int i, x = 65;
    for(i = 0; i < 3; i++)
        fnx_10(x++);
}

//*******************************************

main(){
    int programa;
    char sino;

    do{
        system("cls");
        cout<<"Programa: "; cin>>programa;

        switch(programa){
        case 1:
            uno();
            break;

        case 2:
            dos();
            break;

        case 3:
            tres();
            break;

        case 4:
            cuatro();
            break;

        case 5:
            cinco();
            break;

        case 6:
            seis();
            break;

        case 7:
            siete();
            break;

        case 8:
            ocho();
            break;

        case 9:
            nueve();
            break;

        case 10:
            diez();
            break;

        default:
            cout<<"Error";
        } //switch
        cout<<"\n\nDesea reinciar? s/n\n--->"; cin>>sino;
    } while(sino == 's' || sino == 'S');

} //main
