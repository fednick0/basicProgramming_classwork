#include <iostream> //cout cin
#include <conio.h>  //getch()
#include <stdlib.h> //system()
#include <stdio.h> //gets()
#include <string.h> //memset()

#include "validar.h"

using namespace std;

int menu();
void ingresar();
char* mostrar(bool, char*); //mostrar y buscar
bool editar(int, bool); //editar y eliminar

int main(){

    int opc, cantidad, sn;
    char dato[50], posicion[20];

    do{
        memset(dato, '\0', 50);
        opc = menu();

        switch(opc){
        case '1': //ingresar
            system("cls");

            ingresar();
            break;

        //***********************

        case '2': //mostrar
            system("cls");

            mostrar(false, "\0");

            cout <<endl;
            system("pause");
            break;

        //***********************

        case '3': //buscar
            system("cls");
            cout<<"Buscar: ";
            gets(dato);
            cout<<endl;

            mostrar(true, dato);

            system("pause");
            break;

        //***********************

        case '4': //editar
            system("cls");
            cout<<"[4] Editar\nBuscar: ";
            gets(dato);
            cout<<endl;

            memset(posicion, '\0', 20);
            strcpy(posicion, mostrar(true, dato));

            cantidad = strlen(posicion);
            if(cantidad > 1){
                cout<<"\nSe encontraron varias coincidencias.";
                cout<<"\nPresione numero del contacto que desea editar.\n\n";

                opc = getch() - '1';
                if(opc >= 0 && opc <= cantidad){ //Habia un rror si ingresa una posicion que no existe
                    cout<<"\nSeguro que desea editar al usuario No. " <<opc + 1<<"? S/N\n";
                    sn = getch();

                    if(sn == 's' || sn == 'S'){
                        if(editar( posicion[opc] - '0', true))
                            cout<<"\nUsuario editado correctamente :D\n";
                    }
                }
                else
                    cout<<"\nOpcion incorrecta, regresando al menu principal. . .\n";
            }
            else if(cantidad == 1){
                cout<<"\nSeguro que desea editar al usuario? S/N\n";
                sn = getch();

                if(sn == 's' || sn == 'S'){
                    if(editar(posicion[0] - '0', true))
                        cout<<"\nUsuario editado correctamente :D\n";
                }
            }

            system("pause");
            break;

            //***********************

            case '5': //eliminar
            system("cls");
            cout<<"[5] Eliminar\nBuscar: ";
            gets(dato);
            cout<<endl;

            memset(posicion, '\0', 20);
            strcpy(posicion, mostrar(true, dato));

            cantidad = strlen(posicion);
            if(cantidad > 1){
                cout<<"\nSe encontraron varias coincidencias.";
                cout<<"\nPresione numero del contacto que desea eliminar.\n\n";

                opc = getch() - '1';
                if(opc >= 0 && opc <= cantidad){ //Habia un rror si ingresa una posicion que no existe
                    cout<<"\nSeguro que desea eliminar al usuario No. " <<opc + 1<<"? S/N\n";
                    sn = getch();

                    if(sn == 's' || sn == 'S'){
                        if(editar( posicion[opc] - '0', false))
                            cout<<"\nUsuario eliminado correctamente :D\n";
                    }
                }
                else
                    cout<<"\nOpcion incorrecta, regresando al menu principal. . .\n";
            }
            else if(cantidad == 1){
                cout<<"\nSeguro que desea eliminar al usuario? S/N\n";
                sn = getch();

                if(sn == 's' || sn == 'S'){
                    if(editar(posicion[0] - '0', false))
                        cout<<"\nUsuario eliminado correctamente :D\n";
                }
            }

            system("pause");
            break;

            //***********************

            case 27:
                cout<<"\nSaliendo . . .";
                break;

            //***********************

            default:
                cout<<"\nOpcion incorrecta\n";
                system("pause");
        }
    } while(opc != 27);
}

//main()
////////////////////////////////////
//editar()

bool editar(int pos, bool edita){
    FILE *auxi = fopen("auxi.bin", "wb");
    FILE *archivo = fopen("a_binario.bin", "rb");

    int vueltas = 0, dato = 0;
    char nombre[50], telefono[50], domicilio[50], correo[50];
    char clongi[2];
    int longi;

    if(auxi != NULL && archivo != NULL){
        while(!feof(archivo)){

            memset(clongi, '\0', 2);
            fread(clongi, 1, 1, archivo); //longitud
            longi = clongi[0];

            if(clongi[0] == '|'){
                if(vueltas == pos){

                    if(edita){ //ingresa()
                        do{
                            memset(nombre, '\0', 50);
                            cout<<"Nombre: ";
                            gets(nombre);
                        } while(validar.nombre(nombre));
                        clongi[0] = strlen(nombre);
                        fwrite(clongi, 1, 1, auxi);
                        fwrite(nombre, strlen(nombre), 1, auxi);

                        do{
                            memset(telefono, '\0', 50);
                            cout<<"Telefono: ";
                            gets(telefono);
                        } while(validar.telefono(telefono));
                        clongi[0] = strlen(telefono);
                        fwrite(clongi, 1, 1, auxi);
                        fwrite(telefono, strlen(telefono), 1, auxi);

                        do{
                            memset(domicilio, '\0', 50);
                            cout<<"Domicilio: ";
                            gets(domicilio);
                        } while(validar.domicilio(domicilio));
                        clongi[0] = strlen(domicilio);
                        fwrite(clongi, 1, 1, auxi);
                        fwrite(domicilio, strlen(domicilio), 1, auxi);

                        do{
                            memset(correo, '\0', 50);
                            cout<<"Correo: ";
                            gets(correo);
                        } while(validar.correo(correo));
                        clongi[0] = strlen(correo);
                        fwrite(clongi, 1, 1, auxi);
                        fwrite(correo, strlen(correo), 1, auxi);
                        fwrite("|", 1, 1, auxi);
                    }

                    else{ //ignora_datos()
                        //necesito eliminar este else{}
                    }

                } //if(vueltas == pos)

                else{ //copiar
                    clongi[0] = strlen(nombre);
                    fwrite(clongi, 1, 1, auxi);
                    fwrite(nombre, strlen(nombre), 1, auxi);

                    clongi[0] = strlen(telefono);
                    fwrite(clongi, 1, 1, auxi);
                    fwrite(telefono, strlen(telefono), 1, auxi);

                    clongi[0] = strlen(domicilio);
                    fwrite(clongi, 1, 1, auxi);
                    fwrite(domicilio, strlen(domicilio), 1, auxi);

                    clongi[0] = strlen(correo);
                    fwrite(clongi, 1, 1, auxi);
                    fwrite(correo, strlen(correo), 1, auxi);
                    fwrite("|", 1, 1, auxi);
                }

                vueltas++;
                dato = 0;
            }
            else{
                switch(dato){
                case 0:
                    memset(nombre, '\0', 50);
                    fread(nombre, 1, longi, archivo);
                    break;
                case 1:
                    memset(telefono, '\0', 50);
                    fread(telefono, 1, longi, archivo);
                    break;
                case 2:
                    memset(domicilio, '\0', 50);
                    fread(domicilio, 1, longi, archivo);
                    break;
                case 3:
                    memset(correo, '\0', 50);
                    fread(correo, 1, longi, archivo);
                    break;
                }

                dato++;
            } //else
        } //while()

        fclose(auxi);
        fclose(archivo);

        if(remove("a_binario.bin") != 0){
            cout<<"\nError 001\n";
            return false;
        }
        if(rename("auxi.bin", "a_binario.bin") != 0){
            cout<<"\nError 002\n";
            return false;
        }

        return true;
    }
    else
        cout<<"\nError 003\n";

    fclose(auxi);
    fclose(archivo);

    return false;
}

//editar()
////////////////////////////////////
//mostrar()

char* mostrar(bool busca, char *pbusca){
    FILE *archivo = fopen("a_binario.bin", "rb");

    int dato = 0, vueltas = 0;
    char nombre[50], telefono[50], domicilio[50], correo[50];
    char clongi[2], concat[2];;
    int longi, numb = 1;

    static char regreso[20];

    memset(regreso, '\0', 20);
    memset(concat, '\0', 2);

    if(archivo != NULL){
        while(!feof(archivo)){

            memset(clongi, '\0', 2);
            fread(clongi, 1, 1, archivo); //longitud
            longi = clongi[0];

            if(clongi[0] == '|'){
                if(!busca || strcmpi(pbusca, nombre) == 0 || strcmpi(pbusca, telefono) == 0
                    || strcmpi(pbusca, domicilio) == 0 || strcmpi(pbusca, correo) == 0){

                    if(busca){
                        cout <<"(" <<numb <<") ";
                        numb++;
                    }

                    cout <<nombre <<endl;
                    cout <<telefono <<endl;
                    cout <<domicilio <<endl;
                    cout <<correo <<endl;
                    cout <<endl;

                    itoa(vueltas, concat, 10);
                    strcat(regreso, concat);
                } //if (comparaciones)

                vueltas++;
                dato = 0;
            } //if '|'

            else{
                switch(dato){
                case 0:
                    memset(nombre, '\0', 50);
                    fread(nombre, 1, longi, archivo);
                    break;
                case 1:
                    memset(telefono, '\0', 50);
                    fread(telefono, 1, longi, archivo);
                    break;
                case 2:
                    memset(domicilio, '\0', 50);
                    fread(domicilio, 1, longi, archivo);
                    break;
                case 3:
                    memset(correo, '\0', 50);
                    fread(correo, 1, longi, archivo);
                    break;
                }

                dato++;
            } //else

        } //while()
    }
    else
        cout<<"Error abrir archivo";

    fclose(archivo);

    if(busca && strlen(regreso) == 0){
        cout<<"Ninguna coincidencia D:\n";
        return regreso;
    }

    return regreso;
}

//mostrar()
////////////////////////////////////
//ingresar()

void ingresar(){
    FILE *archivo = fopen("a_binario.bin", "ab");

    char dato[50], longi[2];

    memset(dato, '\0', 50);
    memset(longi, '\0', 2);

    do{
        cout<<"Nombre: ";
        gets(dato);
    } while(validar.nombre(dato));
    longi[0] = strlen(dato);
    fwrite(longi, 1, 1, archivo);
    fwrite(dato, strlen(dato), 1, archivo);

    do{
        cout<<"Telefono: ";
        gets(dato);
    } while(validar.telefono(dato));
    longi[0] = strlen(dato);
    fwrite(longi, 1, 1, archivo);
    fwrite(dato, strlen(dato), 1, archivo);

    do{
        cout<<"Domicilio: ";
        gets(dato);
    } while(validar.domicilio(dato));
    longi[0] = strlen(dato);
    fwrite(longi, 1, 1, archivo);
    fwrite(dato, strlen(dato), 1, archivo);

    do{
        cout<<"Correo: ";
        gets(dato);
    } while(validar.correo(dato));
    longi[0] = strlen(dato);
    fwrite(longi, 1, 1, archivo);
    fwrite(dato, strlen(dato), 1, archivo);
    fwrite("|", 1, 1, archivo);

    fclose(archivo);
}

////////////////////////////////////

int menu(){
    system("cls");
    cout<<"Agenda binaria\n";
    cout<<"[1] Ingresar\n";
    cout<<"[2] Mostrar\n";
    cout<<"[3] Buscar\n";
    cout<<"[4] Editar\n";
    cout<<"[5] Eliminar\n";
    cout<<"[Esc] Salir\n";

    return getch();
}
