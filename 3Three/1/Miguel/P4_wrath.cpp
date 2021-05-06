#include <iostream> //cout<< cin>>
#include <stdlib.h> //system()
#include <stdio.h> //gets()
#include <string.h> //funciones con string

using namespace std;

        /*
            ASCII

            Letras minusculas 97 - 122
            Letras mayusculas 65 - 90
            Numeros 48 - 57
            # 35
            . 46
            - 45
            _ 95
            @ 64
        */

int main(){ //main principal
    char edad [4], nombre[50], domicilio[50], telefono[10], email[20]; //Declaracion de variables
    bool error; //Variable del error
    short asc; //La utilizo para ver el caro ascii de cada caracter

//***************************************************************
//Edad

    do{
        error = false; //Inicializo en falso

        system("cls");

        cout<<"Edad: ";
        gets(edad);

        for(short x = 0; x < strlen(edad); x++){ //Compruebo caracter por caracter
            asc = edad[x]; //Convierto a valor ascii
            if(asc < 48 || asc > 57){  //Si no es numero
                error = true;
                break;
            }
        }

        if(error || atoi(edad) < 1 || atoi(edad) > 120 || strlen(edad) == 0){ //Ultima comprobacion
            cout<<"\nSolo ingrese caracteres valido\n";
            error = true;
            system("pause");
        }

    } while(error); //Repetir solo si encuentra error

//***************************************************************
//Nombre

    do{
        error = false;

        system("cls");
        cout<<"Edad: " <<edad;

        cout<<"\nNombre: ";
        gets(nombre);

        for(short x = 0; x < strlen(nombre); x++){
            asc = nombre[x];
            if(asc < 32 || asc > 32 && asc < 65 || asc > 90 && asc < 97 || asc > 122){ //Solo letras y espacios
                error = true;
                break;
            }
        }

        if(error || strlen(nombre) == 0){
            cout<<"\nSolo ingrese caracteres valido\n";
            error = true;
            system("pause");
        }

    } while(error);

//***************************************************************
//Domicilio

    do{
        error = false;

        system("cls");
        cout<<"Edad: " <<edad;
        cout<<"\nNombre: " <<nombre;

        cout<<"\nDomicilio: ";
        gets(domicilio);

        for(short x = 0; x < strlen(domicilio); x++){
            asc = domicilio[x];

            if(asc < 32 || asc > 32 && asc < 35 || asc > 35 && asc < 45 || asc > 46 && asc < 48 ||
               asc > 57 && asc < 65 || asc > 90 && asc < 97 || asc > 122) { //Solo letras, espacios, numeros, '.', '-' y '#'

                error = true;
                break;
            }
        }

        if(error || strlen(domicilio) == 0){
            cout<<"\nSolo ingrese caracteres valido\n";
            error = true;
            system("pause");
        }

    } while(error);

//***************************************************************
//Telefono

    do{
        error = false;

        system("cls");
        cout<<"Edad: " <<edad;
        cout<<"\nNombre: " <<nombre;
        cout<<"\nDomicilio: " <<domicilio;

        cout<<"\nTelefono: ";
        gets(telefono);

        if(strlen(telefono) == 10 ||strlen(telefono) == 8) //Solo 8 o 10 caracteres numericos para un telefono
            for(short x = 0; x < strlen(telefono); x++){
                asc = telefono[x];
                if(asc < 48 || asc > 57){ //Solo numeros
                    error = true;
                    break;
                }
            }
        else
            error = true;

        if(error || strlen(telefono) == 0){
            cout<<"\nSolo ingrese caracteres valido\n";
            error = true;
            system("pause");
        }

    } while(error);

//***************************************************************
//Correro

    short can_arroba, can_punto_desp, can_des_punto; //Variables extras que utilizo
    bool punto_despues;

    do{
        error = false; //Inicializacion de variables
        punto_despues = false;
        can_arroba = 0;
        can_punto_desp = 0;
        can_des_punto = 0;

        system("cls");
        cout<<"Edad: " <<edad;
        cout<<"\nNombre: " <<nombre;
        cout<<"\nDomicilio: " <<domicilio;
        cout<<"\nTelefono: " <<telefono;

        cout<<"\nCorreo: ";
        gets(email);

        for(short x = 0; x < strlen(email); x++){
            asc = email[x];
            if(asc < 45 || asc > 46 && asc < 48 || asc > 57 && asc < 64 ||
               asc > 90 && asc < 95 || asc > 95 && asc < 97 || asc > 122){ //Solo letras, numeros, '_', '.', '-' y '@'
                error = true;
                break;
            }
            else if(asc == 64){ //Si encuentra '@'
                can_arroba++; //Cantidad de '@'
                punto_despues = true; //Para que el sifuiente if cuente los puntos
            }
            else if(asc == 46 && punto_despues){ //Si encuentra un punto
                can_punto_desp++; //Cantidad de puntos despues del '@'
                can_des_punto = 0; //Cantidad de caracteres despues del ultimo punto encontrado
            }
            else
                can_des_punto++; //+1 caracter despues del ultimo punto
        }

        /*
            a@b.cd
            123456

            Minimo dos caracteres despues del ultimo punto
            Maximo 4 caracteres despues de la '@'
            Minimo un punto despues de la '@'
            Obligatoriamente una '@'
            No se puede doble punto '..' ni doble guion bajo '__'
            Longitud minima permitida es seis
        */

        if(error || strlen(email) < 6 || can_arroba != 1 || strstr(email, "..") != NULL || strstr(email, "__") != NULL || can_punto_desp < 1 || can_des_punto < 2 || can_des_punto > 4){
            cout<<"\nSolo ingrese caracteres valido\n";
            error = true;
            system("pause");
        }

    } while(error);

//***************************************************************

    system("cls");
    cout<<"Edad: " <<atoi(edad);
    cout<<"\nNombre: " <<nombre;
    cout<<"\nDomicilio: " <<domicilio;
    cout<<"\nTelefono: " <<telefono;
    cout<<"\nCorreo: " <<email;

}

//***************************************************************


