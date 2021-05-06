/*
    Macias S. Jorge Oswaldo
    22/09/2017

    i. Analiza, pasa y completa el programa: Clases_Amigas.
    1. (se anexa el PDF correspondiente al programa)
    ii. Modifica el programa para que solicite nuevamente
(leer los datos desde consola) para que solicite el nombre,
edad y padecimiento del paciente.

*/

//El programa, en su mayoria, es directamente del pdf

#include <iostream> //cout
#include <stdio.h> //gets()
#include <string.h> //strcpy()
#include <stdlib.h> //system()

using namespace std;

class medico{

    private:
        char nomb_compl[100];
        char especial[100];

    public:
        //nunca entendi para que funcionan los contructores
        medico();
        medico(char*, char*);
        void imprimir();
        friend class paciente;
}; medico::medico(){}

medico::medico(char *nc, char *e){
    strcpy(nomb_compl, nc);
    strcpy(especial, e);
}

void medico::imprimir(){
    cout <<"\nNombre del medico: " <<nomb_compl;
    cout <<"\nEspecialidad: " <<especial;
}

class paciente{

    private:
        char nomb_compl[100];
        int edad;
        char padecim[100];
        medico *medico_esp;

    public:
        paciente();
        paciente(char*, int, char*);
        void asociar_med();
        void imprimir();
}; paciente::paciente(){}

paciente::paciente(char *nc, int e, char *p){
    strcpy(nomb_compl, nc);
    edad = e;
    strcpy(padecim, p);
}

void paciente::asociar_med(){
    medico_esp = new medico();

    cout<<"\nNombre del medico: ";
    gets(medico_esp->nomb_compl);
    cout<<"Especialidad del medico: ";
    gets(medico_esp->especial);
}

void paciente::imprimir(){
    cout <<"\nNombre del paciente: " <<nomb_compl;
    cout <<"\nEdad: "<<edad;
    cout <<"\nPadecimiento: " <<padecim <<endl;
    medico_esp->imprimir();
}

void usar(){
    char n_paciente[100], pad[100];
    int ed;

    cout<<"Nombre del paciente A: ";
    fflush(stdin);
    gets(n_paciente);
    cout<<"Edad: ";
    fflush(stdin);
    cin>> ed;
    cout<<"Padecimiento: ";
    fflush(stdin);
    gets(pad);

    paciente a(n_paciente, ed, pad);

    a.asociar_med();
    cout<<"\nMostrar Datos del paciente A";
    a.imprimir();

    cout <<endl;
    system("pause");
    system("cls");

    cout<<"Nombre del paciente B: ";
    fflush(stdin);
    gets(n_paciente);
    cout<<"Edad: ";
    fflush(stdin);
    cin>> ed;
    cout<<"Padecimiento: ";
    fflush(stdin);
    gets(pad);

    paciente b(n_paciente, ed, pad);

    b.asociar_med();
    cout<<"\nMostrar Datos del paciente B";
    b.imprimir();
}

int main(){
    usar();
    cout <<endl;
}

