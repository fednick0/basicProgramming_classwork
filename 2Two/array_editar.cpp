#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

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

    bool ingr = false, encontrado = false;
    short enter, cant = 8;
    string arreglo[cant], busc;

    for(int x = 0; x < cant; x++)
        arreglo[x] = "";

    do{
        system("cls");
        gotoxy(36, 0); cout<<"Menu lista ordenada";
        gotoxy(32, 2); cout<<"[F1] Agregar elementos a la lista";
        gotoxy(32, 3); cout<<"[F2] Mostrar la lista";
        gotoxy(32, 4); cout<<"[F3] Buscar un elemento en la lista";
        gotoxy(32, 5); cout<<"[F4] Sustituir un elemento de la lista";
        gotoxy(32, 6); cout<<"[F5] Eliminar un elemento de la lista";
        gotoxy(32, 7); cout<<"[Esc] Salir";
        gotoxy(32, 8);

        enter = getch();
        if(enter == 0)
            enter = getch();
        system("cls");
        encontrado = false;

        switch(enter){
        case 59:
            gotoxy(30, 1); cout<<"Ingrese valores enteros";
            for(short x = 0; x < cant; x++) {
                gotoxy(32, x + 2);
                cout<<"--> "; cin>> arreglo[x];
            }
            ingr = true;
            break;

        case 60:
            if(ingr){
                gotoxy(30, 1); cout<<"Valores ingresados";
                for(short x = 0; x < cant; x++){
                    gotoxy(32, x + 2);
                    cout<< "--> "<< arreglo[x];
                }
            }
            else {
                gotoxy(30, 1);
                cout<<"No ha ingresado datos aun";
            }
            break;

        case 61:
            if(ingr){
                gotoxy(30, 1); cout<<"Buscar elemento";
                gotoxy(30, 2); cout<<"Buscar: ";
                cin>> busc;
                for(short x = 0; x < cant; x++)
                    if(arreglo[x] == busc){
                        gotoxy(32, 3);
                        cout<< "Posicion --> "<< x;
                        encontrado = true;
                        break;
                    }
                if(!encontrado){
                    gotoxy(32, 3);
                    cout<<"Elemento no encontrado";
                }

            }
            else {
                gotoxy(30, 1);
                cout<<"No ha ingresado datos aun";
            }
            break;

        case 62:
            if(ingr){
                gotoxy(30, 1); cout<<"Sustituir elemento";
                gotoxy(30, 2); cout<<"Buscar: ";
                cin>> busc;
                for(short x = 0; x < cant; x++)
                    if(arreglo[x] == busc){
                        gotoxy(32, 3); cout<<"Posicion --> "<< x;
                        gotoxy(32, 4); cout<<"Sustituir por: ";
                        cin>> arreglo[x];
                        encontrado = true;
                        break;
                    }
                if(!encontrado){
                    gotoxy(32, 3);
                    cout<<"Elemento no encontrado";
                }
            }
            else {
                gotoxy(30, 1);
                cout<<"No ha ingresado datos aun";
            }
            break;

        case 63:
            if(ingr){
                gotoxy(30, 1); cout<<"Eliminar elemento";
                gotoxy(30, 2); cout<<"Buscar: ";
                cin>> busc;
                for(short x = 0; x < cant; x++)
                    if(arreglo[x] == busc){
                        gotoxy(32, 3); cout<<"Posicion --> "<< x;
                        gotoxy(32, 4); cout<<"Seguro que desea eliminar? s/n";
                        if(getch() == 115) {
                            arreglo[x] = "";
                            gotoxy(32, 6); cout<<"Elemento eliminado";
                            }
                        else {
                            gotoxy(32, 6); cout<<"Elemento NO eliminado";
                        }
                        encontrado = true;
                        break;
                    }
                if(!encontrado){
                    gotoxy(32, 3);
                    cout<<"Elemento no encontrado";
                }
            }
            else {
                gotoxy(30, 1);
                cout<<"No ha ingresado datos aun";
            }
            break;

        case 27:
            cout<<"Saliendo...";
            break;

        default:
            cout<<"Opcion incorrecta";
        }

        if(enter != 27) {
            cout<<"\n\n\t";
            system("pause");
        }

    } while(enter != 27);

}
