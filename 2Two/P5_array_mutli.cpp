#include <iostream> //cout<< cin>>
#include <stdlib.h> //system()
#include <conio.h> //getch()
#include <stdio.h> //gets()

using namespace std;

int main(){

    char opc;
    int can_alumnos = 0;
    int alumnos[50][5];
    int buscar, editar;
    float promedio;

    do{
        system("cls");

        cout<<"1.- Asignar\n2.- Leer\n3.- Buscar\n4.- Modificar\n5.- Salir\n--> ";
        opc = getch();

        system("cls");

        switch(opc){
        case '1': //Asignar guardar
            cout<<"Cuantos alumnos va a ingresar? ";
            cin>>can_alumnos;

            system("cls");

            for(short x = 0; x < can_alumnos; x++){
                if(x != 0)
                    cout<<endl;
                for(short y = 0; y < 5; y++){
                    cout<<"Alumno No. " <<x+1 <<" calificacion " <<y+1 <<": ";
                    cin>> alumnos[x][y];
                }
            }
            break;

        //****************************************************************

        case '2': //Leer mostrar
            if(can_alumnos != 0) {
                promedio = 0;
                for(short x = 0; x < can_alumnos; x++)
                    for(short y = 0; y < 5; y++){
                        promedio += alumnos[x][y];
                        if(y == 0)
                            cout<<"Alumno No. " <<x+1 <<": " ;
                        cout<<alumnos[x][y] <<" ";
                        if(y == 4){
                            promedio = promedio / 5;
                            cout<<"Promedio: " <<promedio;
                            cout<<endl;
                        }
                    }
            }
            else
                cout<<"No ha ingresado datos";

            cout<<endl;
            system("pause");
            break;

        //****************************************************************

        case '3': //Buscar
            if(can_alumnos != 0){
                cout<<"Ingrese numero del alumno a buscar: ";
                cin>> buscar;

                if(buscar <= can_alumnos) {
                    cout<<"Alumno No. " <<buscar <<":";
                    for(int y = 0; y < 5; y++)
                        cout<<" " <<alumnos[buscar - 1][y];
                }
                else
                    cout<<"Opcion incorrecta";
            }
            else
                cout<<"No ha ingresado datos";

            cout<<"\n\n";
            system("pause");
            break;

        //****************************************************************

        case '4': //Modificar editar
            if(can_alumnos != 0){
                cout<<"Ingrese numero del alumno a buscar: ";
                cin>> buscar;

                if(buscar <= can_alumnos) {
                    system("cls");
                    cout<<"Alumno No. " <<buscar <<":";
                    for(int y = 0; y < 5; y++)
                        cout<<" " <<alumnos[buscar - 1][y];

                    cout<<"\nQue calificacion desea modificar? (1-5)\n--> ";
                    cin>> editar;
                    cout<<endl;

                    if(editar > 0 && editar < 6){
                        cout<<"Nueva calificacion: ";
                        cin>> alumnos[buscar - 1][editar - 1];
                    }
                    else
                        cout<<"Opcion incorrecta";
                }
                else
                    cout<<"Opcion incorrecta";
            }
            else
                cout<<"No ha ingresado datos";

            cout<<"\n\n";
            system("pause");
            break;

        //****************************************************************

        case '5': //Salir
            cout<<"Saliendo...";
            break;

        //****************************************************************

        default:
            cout<<"Opcion incorrecta\n";
            system("pause");
        }

    } while(opc != '5');
}
