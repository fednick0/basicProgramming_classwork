#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int main(){
    int op;
    char palabra1[50], palabra2[50];

    gotoxy(28, 0); cout<<"Ingrese una palabra/frase: ";
    gets(palabra1);
    gotoxy(28, 1); cout<<"Ingrese otra palabra/frase: ";
    gets(palabra2);

    do{
        system("cls");

        gotoxy(28, 0); cout<<"--> " <<palabra1;
        gotoxy(28, 1); cout<<"--> " <<palabra2;

        gotoxy(26, 4);cout<<"[F1] Concatenar";
        gotoxy(26, 5);cout<<"[F2] Copiar";
        gotoxy(26, 6);cout<<"[F3] Longitud";
        gotoxy(26, 7);cout<<"[F4] Mayusculas";
        gotoxy(26, 8);cout<<"[F5] Minusculas";
        gotoxy(26, 9);cout<<"[F6] Comparar";
        gotoxy(26, 10);cout<<"[F7] asd";
        gotoxy(26, 11);cout<<"[F8] asd";
        gotoxy(26, 12);cout<<"[Esc] Salir";

        op = getch();
        if(op == 0)
            op = getch();
        system("cls");

        switch(op){
        case 59:
            gotoxy(28, 0); cout<<"Concatenar p1, p2";
            strcat(palabra1, palabra2);
            gotoxy(28, 1); cout<<"--> " <<palabra1;
            break;

        case 60:
            gotoxy(28, 0); cout<<"Copiar p1, p2";
            strcpy(palabra1, palabra2);
            gotoxy(28, 1); cout<<"--> " <<palabra1;
            break;

        case 61:
            gotoxy(28, 0); cout<<"Longitud p1";
            gotoxy(28, 1); cout<<"--> " <<strlen(palabra1);
            break;

        case 62:
            gotoxy(28, 0); cout<<"Mayusculas p1";
            gotoxy(28, 1); cout<<"--> " <<strupr(palabra1);
            break;

        case 63:
            gotoxy(28, 0); cout<<"Minusculas p1";
            gotoxy(28, 1); cout<<"--> " <<strlwr(palabra1);
            break;

        case 64:
            gotoxy(28, 0); cout<<"Comparar p1, p2";
            gotoxy(28, 1); cout<<"--> " <<strcmp(palabra1, palabra2);
            break;

        case 27:
            gotoxy(28, 0); cout<<"Saliendo...";
            break;

        default:
            cout<<"Opcion erronea";
        }

        gotoxy(28, 4); system("pause");
    }while(op != 27);
}
