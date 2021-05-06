/*
    Macias S. Jorge Oswaldo
    29/09/2017

    1.- Modifica el programa para solicitar nuevamente (leer los
datos desde consola) los datos al usuario que se modificaran en
(altura y area).

    2.- Debes mostrar la informacion en pantalla de acuerdo con
lls datos que dio de alta el usuario.
*/

#include <iostream> //cout cin
#include <stdio.h> //gets()
using namespace std;

class Alumno{
    protected:
        int Edad;
        double Altura;
        char Nombre[100];

    public:
        Alumno();
        void ModificaEdad(int);
        void ModificaAltura(float);

        friend istream &operator>> (istream &, Alumno &);
        friend ostream &operator<< (ostream &, Alumno &);
}; Alumno::Alumno(){ } //Constructor que aun no entiendo


//Estas funciones solo modifican edad y altura
void Alumno::ModificaEdad(int NuevaE){ Edad = NuevaE;}
void Alumno::ModificaAltura(float NuevaA){ Altura = NuevaA;}

istream &operator>>(istream &Lee, Alumno &ObjAlumno){
    cout<<"Ingrese nombre del alumno: ";
    //Lee>> ObjAlumno.Nombre;   <--- Con Lee o cin no guarda espacios, por eso utilizo gets()
    fflush(stdin);
    gets(ObjAlumno.Nombre);

    cout<<"Ingrese altura del alumno: ";
    fflush(stdin); //Tengo que limpiar el buffer porque me da problemas con cin o lee
    Lee>> ObjAlumno.Altura;

    cout<<"Ingrese edad del alumno: ";
    fflush(stdin);
    Lee>> ObjAlumno.Edad;

    return Lee;
}

ostream &operator<<(ostream &Escribe, Alumno &ObjAlumno){
    cout<<"Alumno" <<endl; //Pequeña modificacion para que se vea mejor
    Escribe<<"Nombre: " <<ObjAlumno.Nombre <<endl;
    Escribe<<"Altura: " <<ObjAlumno.Altura <<endl;
    Escribe<<"Edad: " <<ObjAlumno.Edad <<endl;

    return Escribe;
}

void UsaSobreCarga(){
    Alumno Alm;

    cin>> Alm; //Pide datos

    cout<<"\n\nDatos ingresados del ";
    cout<< Alm; //Imprime

    //Si no mando a llamar, no modifica
    Alm.ModificaAltura(12.5);
    Alm.ModificaEdad(3);

    cout<<"\n\nDatos modificados del ";
    cout<< Alm;
}

int main(){ UsaSobreCarga();}
