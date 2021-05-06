#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define max 5

using namespace std;
int cola[max];
int fre = -1, fin = -1;
int dato;

void ingresar(){
    if(fin == max - 1 && fre == 0 || fin == fre - 1)
        cout<<"Desbordamiento - Cola llena\n";
    else{
        if(fin == max - 1)
            fin = 0;
        else
            fin++;

        cout<<"Ingrese dato: ";
        cin>> cola[fin];

        if(fre == -1)
            fre = 0;
    }
}

void eliminar(){
    if(fre == -1)
        cout<<"Subdesbordamiento - Cola vacia\n";
    else{
        if(fre == fin){
            fre = -1;
            fin = -1;
        }
        else{
            if(fre == max - 1)
                fre = 0;
            else
                fre++;
        }
        cout<<"Dato en porisicion frente, ELIMINADO\n";
    }
}

void mostrar(){
    if(fre != -1){
        for(int x = fre; x != fin; x++){
            cout<<cola[x] <<" ";
            if(x == max - 1)
                x = -1;
        }
        cout<<cola[fin] <<endl;
        system("pause");
    }
    else{
        cout<<"Subdesbordamiento - Cola vacia\n";
        system("pause");
    }
}

int main(){
    int opc;
    do{
        system("cls");

        cout<<"[1] Ingresar\n[2] Eliminar\n[3] Mostrar\n[Esc] Salir\n";
        opc = getch();

        switch(opc){
        case 49:
            do{
                system("cls");
                ingresar();
                cout<<"[Esc] Menu principal";
            } while(getch() != 27);
            break;
        case 50:
            do{
                system("cls");
                eliminar();
                cout<<"[Esc] Menu principal";
            } while(getch() != 27);
            break;
        case 51:
            system("cls");
            mostrar();
            break;
        case 27:
            system("cls");
            cout<<"Saliendo...";
            break;

        default:
            system("cls");
            cout<<"Opcion incorrecta\n";
            system("pause");
        }
    } while(opc != 27);
}
