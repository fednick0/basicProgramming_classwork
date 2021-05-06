#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 20

using namespace std;

int main(){

    int opc;
    int numb[max];
    int temp, menor, primero, ultimo, entera, central;

    for(int x = 0; x < max; x++)
        numb[x] = rand() % 100 + 1;

    do{
        system("cls");

        cout<<"Ordenamiento\n[1.-] Insercion binaria\n[2.-] Seleccion directa\n[3.-] Generar nuevo arreglo\n[Esc] Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 49: //[1.-] Insercion binaria
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");

            for(int k = 2; k < max; k++){
                temp = numb[k];
                primero = 0;
                ultimo = k - 1;

                while(primero <= ultimo){
                    entera = (primero + ultimo)/2;
                    central = entera;

                    if(temp <= numb[central])
                        ultimo = central -1;
                    else
                        primero = central +1;
                }
                for(int i = k -1; i >= primero; i--)
                    numb[i +1] = numb[i];
                numb[primero] = temp;
            }

            cout<<"\n\nOrdenado\n";
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");
            break;

        case 50: //[2.-] Seleccion directa
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");

            for(int x = 0; x < max; x++){
                menor = x;

                for(int y = x + 1; y < max; y++)
                    if(numb[y] < numb[menor])
                        menor = y;

                temp = numb[menor];
                numb[menor] = numb[x];
                numb[x] = temp;
            }

            cout<<"\n\nOrdenado\n";
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");
            break;

        case 51: //[3.-] Generar nuevo arreglo
            for(int x = 0; x < max; x++)
                numb[x] = rand() % 100 + 1;
            break;

        case 27: //[Esc] Salir
            cout<<"Saliendo . . .\n";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);
}

