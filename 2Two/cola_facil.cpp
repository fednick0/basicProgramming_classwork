#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 5

using namespace std;

    int numb[max];
    int opc, fre = 0, fin = -1;


void ingresar(){
    if(fin == max - 1) //Lleno
        cout<<"Cola llena\n";
    else{
        if(fin != fre - 1) //No vacio
            for(int x = fre; x <= fin; x++)
                cout<<numb[x] <<" ";
        else
            cout<<"Cola vacia";
        cout<<endl;

        fin++;
        cout<<"Ingrese dato: ";
        cin>> numb[fin];
    }
}

void eliminar(){
    if(fin == fre - 1) //Vacio
        cout<<"Cola vacia\n";
    else{
        for(int x = fre; x <= fin; x++)
            cout<<numb[x] <<" ";

        cout<<endl <<"Presione una tecla para eliminar . . .";
        getch();
        system("cls");
        cout<<"Elemento eliminado" <<endl;

        fre++;

        if(fin != fre - 1) //No vacio
            for(int x = fre; x <= fin; x++)
                cout<<numb[x] <<" ";
        else{
            cout<<"Cola vacia";
            fre = 0;
            fin = -1;
        }
    }
}

void mostrar(){
    if(fin != fre - 1) //No vacio
        for(int x = fre; x <= fin; x++){
            if(x == fre && x == fin)
                cout<<numb[x] <<"*+ ";
            else if(x == fre)
                cout<<numb[x] <<"* ";
            else if(x == fin)
                cout<<numb[x] <<"+ ";
            else
                cout<<numb[x] <<" ";
        }
    else{
        cout<<"Cola vacia";
        fre = 0;
        fin = -1;
    }
}

int main(){
    do{
        system("cls");

        cout<<"[1.-] Ingresar\n[2.-] Eliminar\n[3.-] Mostrar\n[Esc] Salir\n";
        opc = getch();

        system("cls");

        switch(opc){
        case 49: //Ingresar
            do{
                system("cls");
                ingresar();
                cout<<"\n\n[Esc] Regresar al menu";
            } while(getch() != 27);
            break;

        case 50: //Eliminar
            do{
                system("cls");
                eliminar();
                cout<<"\n\n[Esc] Regresar al menu";
            } while(getch() != 27);
            break;

        case 51: //Mostrar
            mostrar();
            cout<<endl;
            system("pause");
            break;

        case 27:
            cout<<"Saliendo...";
            break;

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);
}
