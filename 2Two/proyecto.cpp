/*
    Una agencia de venta de veh�culos autom�viles, distribuye 8 modelos diferentes y tiene en su plantilla 5 vendedores.
    Se desea un programa que:

    a)	Escriba un informe mensual de las unidades vendidas por vendedor y modelo.
    b)	Numero de Autom�viles vendidos por cada vendedor.
    c)	N�mero total de unidades vendidas por cada modelo.
    h)	El programa deber� felicitar al mejor vendedor del mes. (Una pantalla limpia a modo de felicitaci�n).
    d)	Cada vez que se ejecute el programa los datos ser�n llenados de manera aleatoria, cada dato debe
    estar dentro del dominio 0-100.
    e)	El programa deber� ser lo m�s presentable posible, (Muy importante para la calificaci�n y a
    consideraci�n de docente).
    f)	Si el programa carece de alguno de los anteriores puntos no ser� considerado para calificaci�n.
    g)	Para considerar como valido el proyecto el alumno deber� responder a todas las preguntas que el docente
    le formule durante la entrega del mismo, de no hacerlo no se tendr� en cuenta para su calificaci�n
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void sonido();
void rostro_yisus(int x, int y);
void gotoxy(int x,int y);

int main(){
    int vendedor[5][10], total[5];
    int mayor, x, y;
    string nombres[5] = {"Isaac", "Cain ", "Abel ", "Noe  ", "Yisus"};
    string carros[10] = {"Mercedes", "Ferrari", "Toyota", "Lobo", "Bocho", "Tsuru", "Audi", "BMW", "Chevrolet", "Ford"};

    do{
        mayor = 0;
        x = 48; y = 2;
        system("cls");

        for(int i = 0; i < 5; i++) {
            if(i != 0)
                y += 4;
            gotoxy(x-4, y); cout<<"_____ Vendedor No. " <<i+1 <<" " <<nombres[i] <<"_____";
            total[i] = 0;

            for(int j = 0; j < 10; j++) {
                vendedor[i][j] = rand() % 101;
                total[i] += vendedor[i][j];
                y++; gotoxy(x+4, y); cout <<carros[j] <<": " <<vendedor[i][j];
            }
            y++; gotoxy(x, y); cout<<"--> Total vendidos: " <<total[i];
        }

        //Encuentra el mayor
        for(int k = 1; k < 5; k++)
            if(total[mayor] <  total[k])
                mayor = k;

        y += 4; gotoxy(x-8, y); cout<<"**********************************************";
        y++;    gotoxy(x-8, y); cout<<"*                                            *";
        y++;    gotoxy(x-8, y); cout<<"*    El que vendio mas fue vendedor No. " <<mayor+1 <<"    *";
        y++;    gotoxy(x-8, y); cout<<"*                                            *";
        y++;    gotoxy(x-8, y); cout<<"*                    " <<nombres[mayor] <<"                   *";
        y++;    gotoxy(x-8, y); cout<<"*         con " <<total[mayor] <<" unidades vendidas          *";
        y++;    gotoxy(x-8, y); cout<<"*                                            *";
        y++;    gotoxy(x-8, y); cout<<"*                Felicidades!                *";
        y++;    gotoxy(x-8, y); cout<<"*                                            *";
        y++;    gotoxy(x-8, y); cout<<"**********************************************";

        cout<<"\n\n[!Esc] Repetir";
    } while(getch() != 27);

    return 0;
}

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
