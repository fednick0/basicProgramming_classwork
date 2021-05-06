#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 5

using namespace std;

void ingreso();
void eliminar();

int main(){

    int cola[max];
    int fre = -1, fin = -1, opc;

    for(int x = 0; x < max; x++)
        cola[x] = 0;

    do{
        system("cls");
        cout<<".Cola\n1.- Ingresar\n2.- Eliminar\n3.- Salir";
        opc = getch();
        system("cls");

        switch(opc){
        case 49: //Ingresar
            if(fin == max -1) {
                cout<<"Cola llena";
                system("pause");
            }
            else {

                if(fin != -1)
                    for(int x = 0; x <= fin; x++)
                        cout<<cola[x] <<" ";
                else
                    cout<<"Cola vacia";

                fin++;
                cout<<"\nIngrese dato: ";
                cin>> cola[fin];
            }
            break;

        case 50: //Eliminar
            if(fin == -1)
                cout<<"Cola vacia\n";
            else{

                for(int x = 0; x <= fin; x++)
                    cout<<cola[x] <<" ";

                cout<<endl;
                system("pause");
                system("cls");

                for(int x = 0; x < fin; x++)
                    cola[x] = cola[x+1];
                fin--;

                if(fin != -1){
                    for(int x = 0; x <= fin; x++)
                        cout<<cola[x] <<" ";
                    cout<<endl;
                }
                else
                    cout<<"Cola vacia\n";
            }
            system("pause");

            break;

        case 51:
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion incorreta\n";
            system("pause");
        }
    } while(opc != 51);
}
