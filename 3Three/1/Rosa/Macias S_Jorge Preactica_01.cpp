/*
Macias Sanchez Jorge oswaldo
13/08/2017

Realizar un programa que almacene en un registro los siguientes datos de un estudiante:
Matricula, nombre, domicilio, carrera, semestre, promedio. El programa deberá de almacenar
hasta 100 estudiantes, debe tener un menú de opciones:
i. Añadir estudiante
ii. Consulta general (mostrar todos los estudiantes en pantalla)
iii. Consulta por carrera (mostrara el nombre de la carrera que se está consultado y sólo
aparecerá en pantalla matricula, nombre, semestre, promedio).
iv. Buscar estudiante (Puede ser por matricula o nombre).
v. Salir
*/

#include <iostream> //cout cin
#include <stdlib.h> //system("cls/pause")
#include <conio.h> //getch()
#include <string.h> //strcmp()
#include <stdio.h> //gets()

using namespace std;

struct estudiante{ //Registro del restudiante y sus respectivas variables
    char matricula[30];
    char nombre[30];
    char domicilio[50];
    char carrera[20];
    char semestre[10];
    char promedio[10];

} estudi[100]; //Arreglo para el limite propuesto

//Declaracion de funciones
int menu(void);
int agregar(int);
void consulta(int, bool);

int main(){ //

    bool error = true; //Variable para controlar si se ingreso datos o no
    int opc, fin = 0; //opc controla switch, fin controla limite del arreglo
    char buscar[30]; //Variable para comparar y mostrar resultados

    do{ //Ciclo para repetir todo el programa
        opc = menu();
        system("cls");

        switch(opc){
        case 48: //Agregar
            fin = agregar(fin);
            error = false;
            break;

        //////////////////////////////////////////////////

        case 49: //Consultar todo
            if(!error) //Ha metido datos?¿
                for(int x = 0; x < fin; x++)
                    consulta(x, true);
            else
                cout<<"Aun no ha ingresado datos";
            break;

        //////////////////////////////////////////////////

        case 50: //Consultar por carrera
            if(!error){
                cout<<"Carrera a buscar: ";
                gets(buscar);

                for(int x = 0; x < fin; x++)
                    if( strcmp(buscar, estudi[x].carrera) == 0)
                        consulta(x, false);
            }
            else
                cout<<"Aun no ha ingresado datos";
            break;

        //////////////////////////////////////////////////

        case 51: //Consulta por nombre
            if(!error){
                cout<<"Nombre o matricula a buscar: ";
                gets(buscar);

                for(int x = 0; x < fin; x++)
                    if( strcmp(buscar, estudi[x].nombre) == 0 || strcmp(buscar, estudi[x].matricula) == 0)
                        consulta(x, false);
            }
            else
                cout<<"Aun no ha ingresado datos";
            break;

        //////////////////////////////////////////////////

        case 27:
            cout<<"Saliendo . . .";
            break;

        default:
            cout<<"Error";
        }

        cout<<"\n\n";
        system("pause");

    } while(opc != 27);
}

//********************************************************

void consulta(int x, bool carre){//Recibe posicion y bool...

    cout<<"Matricula: " <<estudi[x].matricula <<endl;
    cout<<"Nombre: " <<estudi[x].nombre <<endl;

    if(carre){ //...bool para controlar la consulta
        cout<<"Domicilio: " <<estudi[x].domicilio <<endl;
        cout<<"Carrera: " <<estudi[x].carrera <<endl;
    }

    cout<<"Semestre: " <<estudi[x].semestre <<endl;
    cout<<"Promedio: " <<estudi[x].promedio <<endl;

    cout<<"\n\n";
}

int agregar(int fin){//Recibe limite para agregar en dicha posicion
    int sn; //Controla si agrega otro usuario o no

    do{ //Ciclo para repetir en caso de quererlo
        cout<<"Matricula: ";
        gets(estudi[fin].matricula);
        cout<<"Nombre: ";
        gets(estudi[fin].nombre);
        cout<<"Domicilio: ";
        gets(estudi[fin].domicilio);
        cout<<"Carrera: ";
        gets(estudi[fin].carrera);
        cout<<"Semestre: ";
        gets(estudi[fin].semestre);
        cout<<"Promedio: ";
        gets(estudi[fin].promedio);

        fin++; //Incremento del limite
        cout<<"Agregar otro estudiante? S/N\n\n\n";
        sn = getch();
    } while(sn == 115 || sn == 83);

    return fin; //Se retorna la ultima posicion del arreglo
}

int menu(){ //Solo un menu
    system("cls");

    cout<<"[0] Agregar estudiante\n";
    cout<<"[1] Consulta general\n";
    cout<<"[2] Consulta por carrera\n";
    cout<<"[3] Consulta por estudiante\n";
    cout<<"[Esc] Agregar estudiante\n";

    return getch();
}
