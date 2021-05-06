#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 20

using namespace std;

int main(){

    int opc;
    int numb[max];
    bool ban;
    int temp;

    for(int x = 0; x < max; x++)
        numb[x] = rand() % 100 + 1;

    do{
        system("cls");

        cout<<"Ordenamiento\n[1.-] Shaker\n[2.-] Baraja\n[3.-] Generar nuevo arreglo\n[Esc] Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 49: //[1.-] Shaker
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");

            for(int i = 0; i < max / 2; i++){
                ban = false;
                for(int j = i; j < max -i -1; j++){
                    if(numb[j] < numb[j + 1]){
                        temp = numb[j];
                        numb[j] = numb[j + 1];
                        numb[j + 1] = temp;
                        ban = true;
                    }
                }

                for(int j = max -2 -i; j > i; j--){
                    if(numb[j] > numb[j - 1]){
                        temp = numb[j];
                        numb[j] = numb[j - 1];
                        numb[j - 1] = temp;
                        ban = true;
                    }
                }
                if(!ban) break;
            }

            cout<<"\n\nOrdenado:\n";
            for(int x = max - 1; x >= 0; x--)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");
            break;

        case 50: //[2.-] Baraja
            for(int x = 0; x < max; x++)
                cout<<numb[x] <<" ";
            cout<<endl;
            system("pause");

            for(int x = 1; x < max; x++){
                for(int y = x; y - 1 >= 0; y--){
                    if(numb[y] < numb[y - 1]){
                        temp = numb[y];
                        numb[y] = numb[y - 1];
                        numb[y - 1] = temp;
                    }
                }
            }

            cout<<"\n\nOrdenado:\n";
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
