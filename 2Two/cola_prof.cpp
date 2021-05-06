#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 5

using namespace std;

int main(){

    int numb[max];
    int opc, fre = 0, fin = 0, acum = 0;

    do{
        system("cls");

        cout<<"1.- Ingresar\n2.- Eliminar\n3.- Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 49: //Ingresar
            if(acum == max){ //Lleno
                cout<<"Cola llena\n";
                system("pause");
            }
            else{
                if(acum > 0) //No vacio
                    for(int x = fre, y = 0; y < acum; y++){
                        cout<<numb[x] <<" ";
                        x++;
                        if(x == max)
                            x = 0;
                    }
                else
                    cout<<"Cola vacia";
                cout<<endl;

                acum++;

                if(fin == max)
                    fin = 0;

                cout<<"Ingrese dato: ";
                cin>> numb[fin];

                fin++;
            }
            break;

        case 50: //Eliminar
            if(acum == 0){ //Vacio
                cout<<"Cola vacia\n";
                system("pause");
            }
            else{
                for(int x = fre, y = 0; y < acum; y++){
                    cout<<numb[x] <<" ";
                    x++;
                    if(x == max)
                        x = 0;
                }

                cout<<endl;
                system("pause");
                system("cls");

                acum--;
                fre++;

                if(fre == max)
                    fre = 0;

                if(acum > 0) //No vacio
                    for(int x = fre, y = 0; y < acum; y++){
                        cout<<numb[x] <<" ";
                        x++;
                        if(x == max)
                            x = 0;
                    }
                else
                    cout<<"Cola vacia";
                cout<<endl;

                system("pause");
            }
            break;

        case 51:
            cout<<"Saliendo...";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 51);
}
