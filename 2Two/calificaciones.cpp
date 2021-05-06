#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    short cantidad;
    float mayor, promedio;
    char sn;

    do{

        do{
            system("cls");
            cout<<"Cuantos alumnos va a calificar? (5 - 30)\n--> "; cin>> cantidad;
            if(cantidad < 5 || cantidad > 30) {
                cout<<"\nSolo de 5 a 30 alumnos\n";
                system("pause");
            }
        } while(cantidad < 5 || cantidad > 30);

        float calif[cantidad];
        promedio = 0;

        for(short x = 0; x < cantidad; x++){
            do{
                system("cls");
                cout<<"Calificacion alumno "<< x+1<< " --> "; cin>> calif[x];
                if(calif[x] < 0 || calif[x] > 100){
                    cout<<"\nError\n";
                    system("pause");
                }
            } while(calif[x] < 0 || calif[x] > 100);

            promedio += calif[x];
            if(x == 0)
                mayor = calif[x];
            else if(calif[x] > mayor && x > 0)
                mayor = calif[x];
        }

        system("cls");
        promedio /= cantidad;
        cout<<"Mayor: "<< mayor<<endl;
        cout<<"Promedio:"<< promedio;

        cout<<"\n\nDesea reiniciar? s/n\n--> "; cin>> sn;
    } while(sn == 'S' || sn == 's');

    return 0;
}
