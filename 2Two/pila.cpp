#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define max 5

using namespace std;

int main(){
    int numb[max];
    int tope = -1, opc;

    do{
        system("cls");

        cout<<".Pila\n1.- Ingresar\n2.- Eliminar\n3.- Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 49:
            if(tope == max - 1) {
                cout<<"Pila llena\n";
                system("pause");
            }
            else{
                if(tope != -1){
                    for(int x = 0; x <= tope; x++)
                        cout<<numb[x] <<" ";
                    cout<<endl;
                }
                else
                    cout<<"Pila vacia\n";

                tope++;

                cout<<"Ingrese dato: ";
                cin>> numb[tope];
            }
            break;

        case 50:
            if(tope == -1){
                cout<<"Pila vacia\n";
                system("pause");
            }
            else{
                for(int x = 0; x <= tope; x++)
                    cout<<numb[x] <<" ";

                cout<<endl;
                system("pause");
                system("cls");
                tope--;

                if(tope != -1)
                    for(int x = 0; x <= tope; x++)
                        cout<<numb[x] <<" ";
                else
                    cout<<"Pila vacia";

                cout<<endl;
                system("pause");
            }
            break;

        case 51:
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 51);
}
