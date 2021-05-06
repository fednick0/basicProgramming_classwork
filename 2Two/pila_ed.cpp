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

        /*
         ctrl + n = 14
         ctrl + z = 26
         ctrl + m = 13
         Esc = 27
        */

        cout<<"\t.Pila\n[ctrl + n] Ingresar\n[ctrl + z] Eliminar\n[ctrl + m] Mostra\n[Esc] Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 14: //ctrl + n - Ingresar
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

        case 26: //ctrl + z - Eliminar
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

        case 13: //ctrl + m - Mostrar
            if(tope == -1){
                cout<<"Pila vacia";
            }
            else{
                for(int x = 0; x <= tope; x++)
                    cout<<numb[x] <<" ";
            }
            cout<<endl;
            system("pause");
            break;

        case 27: //Esc - Salir
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);
}
