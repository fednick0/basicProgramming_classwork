#include <iostream> //cout<<
#include <stdlib.h> //system()
#include <stdio.h> //gets()
#include <conio.h> //getch()
#include <string.h> //memset()

#include "validar.h"

//tamaño_total / sizeof(cd) = cantidad
//sizeof(cd) * 0 = primer_reg
//sizeof(cd) * 1 = segundo_reg

using namespace std;

typedef struct musica{
    char codigo[6];
    char album[30]; //Que se valida?
    char artista[20]; //Que se valida?
    char genero[15];
    int no_tracks;
    char duracion [7]; //999:99 <--- max

    char rt = '\r';
    char salto = '\n';
}; //No entiendo porque no funciona poner aqui el obj

struct musica cd;

//funciones
void menu();
void limpiar();
char* abrir();
void ingresar(char*);
char* mostrar(char*, bool, char*);
bool editar(char*, int, bool);
char* fcodigo(char*);
int busca_eli(char*);

//int main()
int main(){
    int opc, sn;
    int cantidad;
    char arc_nomb[20];
    char palabra[20];
    char pos[20];
    bool abrir_b = false;

    memset(arc_nomb, '\0', 20);
    memset(palabra, '\0', 20);
    memset(pos, '\0', 20);

    do{
        menu();

        opc = getch();
        if(opc == 0)
            opc = getch();

        switch(opc){
        case 59: //[F1] Seleccionar archivo
            //si no existe, lo crea, por lo que no habra error nunca
            strcpy( arc_nomb, abrir() );
            abrir_b = true;

            cout<<"\nArchivo abierto\n";
            system("pause");
            break;

        //**********************************

        case 60: //[F2] Alta
            do{
                system("cls");

                if(!abrir_b){
                    cout<<"[F2] Alta";
                    cout<<"\n\nNo se ha seleccionado ningun archivo\n";
                    system("pause");
                }
                else{
                    cout<<"[F2] Alta";

                    ingresar(arc_nomb);

                    cout<<"\nDesea ingresar mas? S/N\n";
                    opc = getch();
                }

            } while(opc == 's' && abrir_b || opc == 'S' && abrir_b);
            break;

        //**********************************

        case 61: //[F3] Mostrar
            system("cls");
            cout<<"[F3] Mostrar";

            if(!abrir_b){
                cout<<"\n\nNo se ha seleccionado ningun archivo\n";
                system("pause");
            }
            else{
                cout<<endl;
                mostrar(arc_nomb, false, " ");
                cout<<endl;
                system("pause");
            }
            break;

        //**********************************

        case 62: //[F4] Consulta
            system("cls");
            cout<<"[F4] Consulta";

            if(!abrir_b){
                cout<<"\n\nNo se ha seleccionado ningun archivo\n";
                system("pause");
            }
            else{
                cout<<"\nBuscar: ";
                fflush(stdin);
                gets(palabra);
                mostrar(arc_nomb, true, palabra);
                cout<<endl;
                system("pause");
            }
            break;

        //**********************************

        case 63: //[F5] Edicion
            system("cls");
            cout<<"[F5] Edicion";

            if(!abrir_b){
                cout<<"\n\nNo se ha seleccionado ningun archivo\n";
                system("pause");
            }
            else{
                cout<<"\nBuscar: ";
                fflush(stdin);
                gets(palabra);
                strcpy(pos, mostrar(arc_nomb, true, palabra));
                cout<<endl;

                cantidad = strlen(pos);
                if(cantidad > 1){
                    cout<<"Se encontraron varias coincidencias.";
                    cout<<"\nPresione numero del contacto que desea editar.\n\n";

                    opc = getch() - '1';
                    if(opc >= 0 && opc <= cantidad){ //Habia un error si ingresa una posicion que no existe
                        cout<<"Seguro que desea editar al usuario No. " <<opc + 1<<"? S/N\n";
                        sn = getch();

                        if(sn == 's' || sn == 'S'){
                            if(editar(arc_nomb, pos[opc] - '0', true))
                                cout<<"\nUsuario editado correctamente :D\n";
                        }
                    }
                    else
                        cout<<"Opcion incorrecta, regresando al menu principal. . .\n";
                }
                else if(cantidad == 1){
                    cout<<"Seguro que desea editar al usuario? S/N\n";
                    sn = getch();

                    if(sn == 's' || sn == 'S'){
                        if(editar(arc_nomb, pos[0] - '0', true))
                            cout<<"\nUsuario editado correctamente :D\n";
                    }
                }

                system("pause");
            }
            break;

        //**********************************

        case 64: //[F6] Baja
            system("cls");
            cout<<"[F6] Baja";

            if(!abrir_b){
                cout<<"\n\nNo se ha seleccionado ningun archivo\n";
                system("pause");
            }
            else{
                cout<<"\nBuscar: ";
                fflush(stdin);
                gets(palabra);
                strcpy(pos, mostrar(arc_nomb, true, palabra));
                cout<<endl;

                cantidad = strlen(pos);
                if(cantidad > 1){
                    cout<<"Se encontraron varias coincidencias.";
                    cout<<"\nPresione numero del contacto que desea eliminar.\n\n";

                    opc = getch() - '1';
                    if(opc >= 0 && opc <= cantidad){ //Habia un error si ingresa una posicion que no existe
                        cout<<"Seguro que desea eliminar al usuario No. " <<opc + 1<<"? S/N\n";
                        sn = getch();

                        if(sn == 's' || sn == 'S'){
                            if(editar(arc_nomb, pos[opc] - '0', false))
                                cout<<"\nUsuario eliminado correctamente :D\n";
                        }
                    }
                    else
                        cout<<"Opcion incorrecta, regresando al menu principal. . .\n";
                }
                else if(cantidad == 1){
                    cout<<"Seguro que desea eliminar al usuario? S/N\n";
                    sn = getch();

                    if(sn == 's' || sn == 'S'){
                        if(editar(arc_nomb, pos[0] - '0', false))
                            cout<<"\nUsuario eliminar correctamente :D\n";
                    }
                }

                system("pause");
            }
            break;

        //**********************************

        case 27: //[Esc] Salir
            cout<<"\nSaliendo . . .\n";
            break;

        default:
            cout<<"\n\nOpcion incorrecta\n";
            system("pause");
        }

    } while(opc != 27);
}

//int main()
//////////////////////////////
//busca_eli()

int busca_eli(char *nomb_file){
    FILE *archivo = fopen(nomb_file, "rb");

    int reg = 0;

    if(archivo != NULL){
        while(!feof(archivo)){

            if(feof(archivo))
                break;

            limpiar();
            fseek(archivo, sizeof(cd)*reg, 0);
            fread(&cd, 1, sizeof(cd), archivo);

            if(cd.codigo[0] == '*'){
                fclose(archivo);
                return reg;
            }

            reg++;
        }
    }
    else
        cout<<"\nError al abrir archivo\n";

    fclose(archivo);
    reg = -1;
    return reg;
}

//busca_eli()
//////////////////////////////
//editar()

bool editar(char *nomb_file, int pos, bool edita){
    FILE *archivo = fopen(nomb_file, "r+b");

    char codigo_aux[6];
    char dato[30];

    memset(codigo_aux, '\0', 6);

    limpiar();

    if(archivo != NULL){
        fseek(archivo, sizeof(cd)*pos, 0);
        fread(&cd, 1, sizeof(cd), archivo);
        fseek(archivo, sizeof(cd)*pos, 0);

        strcpy(codigo_aux, cd.codigo);

        if(edita){
            limpiar();
            strcpy(cd.codigo, codigo_aux);

            cout<<"\nCodigo: " <<cd.codigo;

            cout<<"\nAlbum: ";
            fflush(stdin);
            gets(cd.album);

            cout<<"Artista: ";
            fflush(stdin);
            gets(cd.artista);

            cout<<"  (1) Clasica      (4) Blues     (7) Pop";
            cout<<"\n  (2) Jazz         (5) Reggae    (8) Electronica";
            cout<<"\n  (3) Rock & Roll  (6) Hip Hop   (9) Heavy Metal";
            fflush(stdin);
            switch(getch()){
                case '1': strcpy(cd.genero, "Clasica"); break;
                case '2': strcpy(cd.genero, "Jazz"); break;
                case '3': strcpy(cd.genero, "Rock & Roll"); break;
                case '4': strcpy(cd.genero, "Blues"); break;
                case '5': strcpy(cd.genero, "Reggae"); break;
                case '6': strcpy(cd.genero, "Hip Hop"); break;
                case '7': strcpy(cd.genero, "Pop"); break;
                case '8': strcpy(cd.genero, "Electronica"); break;
                case '9': strcpy(cd.genero, "Heavy Metal"); break;
            default:
                cout<<"\nOpcion incorrecta";
                strcpy(cd.genero, "Clasica");
            }
            cout<<"\nGenero: " <<cd.genero <<endl;

            do{
                memset(dato, '\0', 30);
                cout<<"No. de tracks: ";
                fflush(stdin);
                gets(dato);
            } while(validar.no_track(dato));
            cd.no_tracks = atoi(dato);

            do{
                memset(dato, '\0', 30);
                cout<<"Duracion: ";
                fflush(stdin);
                gets(dato);
            } while(validar.duracion(dato));
            strcpy(cd.duracion, dato);

            fwrite(&cd, sizeof(cd), 1, archivo);
        }

        else{
            fread(&cd, 1, sizeof(cd), archivo);
            fseek(archivo, sizeof(cd)*pos, 0);

            cd.codigo[0] = '*';
            fwrite(&cd, sizeof(cd), 1, archivo);
        }

        fclose(archivo);
        return true;
    }
    else
        cout<<"\nError al abrir archivo\n";

    fclose(archivo);
    return false;
}

//editar()
//////////////////////////////
//mostrar()

char* mostrar(char *nomb_file, bool buscar, char *palabra){
    FILE *archivo = fopen(nomb_file, "ab+");

    int n = 0;
    int numb = 1;
    char pos[2];
    bool eliminado;
    bool ban = true;
    static char reg[20];

    memset(pos, '\0', 2);
    memset(reg, '\0', 20);

    if(archivo != NULL){
        while(!feof(archivo)){
            limpiar();
            fread(&cd, 1, sizeof(cd), archivo);
            eliminado = false;

            if(feof(archivo))
                break;

            if(cd.codigo[0] == '*')
                eliminado = true;

            if(buscar && !eliminado && strcmpi(palabra, cd.codigo) == 0 ||
               buscar && !eliminado && strcmpi(palabra, cd.album) == 0 ||
               buscar && !eliminado && strcmpi(palabra, cd.artista) == 0 ||
               buscar && !eliminado && strcmpi(palabra, cd.genero) == 0 ||
               buscar && !eliminado && atoi(palabra) == cd.no_tracks ||
               buscar && !eliminado && strcmpi(palabra, cd.duracion) == 0 ||
               !buscar && !eliminado){

                ban = false;

                if(buscar){
                    cout<<"\n(" <<numb <<") Codigo: ";
                    numb++;
                }
                else
                    cout<<"\nCodigo: ";

                cout<<cd.codigo;
                cout<<"\nAlbum: " <<cd.album;
                cout<<"\nArtista: " <<cd.artista;
                cout<<"\nGenero: " <<cd.genero;
                cout<<"\nNo. de tracks: " <<cd.no_tracks;
                cout<<"\nDuracion: " <<cd.duracion;
                cout<<endl;

                if(!buscar){ // <--- No me gusta como queda
                    if(numb % 4 == 0){
                        system("pause");
                        system("cls");
                    }
                    numb++;
                }

                itoa(n, pos, 10);
                strcat(reg, pos);
            }

            n++;
        }
    }
    else
        cout<<"\nError al abrir archivo";

    if(ban)
        cout<<"\nNinguna coincidencia";

    fclose(archivo);
    return reg;
}

//mostrar()
//////////////////////////////
//fcodigo() <-- Campo llave

char* fcodigo(char *nomb_file){
    static char codigo_aux[6];
    char numbc[4];
    char c[2];
    int numbi;

    limpiar();
    memset(codigo_aux, '\0', 6);
    memset(numbc, '\0', 4);

    FILE *archivo = fopen(nomb_file, "ab+");

    fseek(archivo, -sizeof(cd), 2);
    fread(&cd, 1, sizeof(cd), archivo);

    strcpy(codigo_aux, cd.codigo);

    if(strlen(codigo_aux) == 0)
        strcpy(codigo_aux, "CD000");

    else{
        for(int x = 2; x < 5; x++){
            memset(c, '\0', 2);
            c[0] = codigo_aux[x];
            strcat(numbc, c);
        }

        numbi = atoi(numbc) + 1;
        memset(numbc, '\0', 4);
        itoa(numbi, numbc, 10);
        memset(codigo_aux, '\0', 6);

        if(strlen(numbc) == 1){
            strcpy(codigo_aux, "CD00");
            strcat(codigo_aux, numbc);
        }
        else if(strlen(numbc) == 2){
            strcpy(codigo_aux, "CD0");
            strcat(codigo_aux, numbc);
        }
        else if(strlen(numbc) == 3){
            strcpy(codigo_aux, "CD");
            strcat(codigo_aux, numbc);
        }
        else
            cout<<"\nerror";
    }

    fclose(archivo);
    limpiar();
    return codigo_aux;
}

//fcodigo()
//////////////////////////////
//ingresar()

void ingresar(char *nomb_file){
    FILE *archivo;

    int elimin = busca_eli(nomb_file);
    char codigo_aux[6];
    char dato[30];

    if(elimin != -1)
        archivo = fopen(nomb_file, "r+b");
    else
        archivo = fopen(nomb_file, "ab+");

    if(archivo != NULL){
        if(elimin != -1){
            limpiar();
            fseek(archivo, sizeof(cd)*elimin, 0);
            fread(&cd, 1, sizeof(cd), archivo);
            fseek(archivo, sizeof(cd)*elimin, 0);

            memset(codigo_aux, '\0', 6);
            strcpy(codigo_aux, cd.codigo);
            codigo_aux[0] = 'C';

            limpiar();
            strcpy(cd.codigo, codigo_aux);
        }
        else
            strcpy(cd.codigo, fcodigo(nomb_file));

        cout<<"\nCodigo: " <<cd.codigo;

        cout<<"\nAlbum: ";
        fflush(stdin);
        gets(cd.album);

        cout<<"Artista: ";
        fflush(stdin);
        gets(cd.artista);

        cout<<"  (1) Clasica      (4) Blues     (7) Pop";
        cout<<"\n  (2) Jazz         (5) Reggae    (8) Electronica";
        cout<<"\n  (3) Rock & Roll  (6) Hip Hop   (9) Heavy Metal";
        fflush(stdin);
        switch(getch()){
        case '1': strcpy(cd.genero, "Clasica"); break;
        case '2': strcpy(cd.genero, "Jazz"); break;
        case '3': strcpy(cd.genero, "Rock & Roll"); break;
        case '4': strcpy(cd.genero, "Blues"); break;
        case '5': strcpy(cd.genero, "Reggae"); break;
        case '6': strcpy(cd.genero, "Hip Hop"); break;
        case '7': strcpy(cd.genero, "Pop"); break;
        case '8': strcpy(cd.genero, "Electronica"); break;
        case '9': strcpy(cd.genero, "Heavy Metal"); break;
        default:
            cout<<"\nOpcion incorrecta";
            strcpy(cd.genero, "Clasica");
        }
        cout<<"\nGenero: " <<cd.genero <<endl;

        do{
            memset(dato, '\0', 30);
            cout<<"No. de tracks: ";
            fflush(stdin);
            gets(dato);
        } while(validar.no_track(dato));
        cd.no_tracks = atoi(dato);

        do{
            memset(dato, '\0', 30);
            cout<<"Duracion: ";
            fflush(stdin);
            gets(dato);
        } while(validar.duracion(dato));
        strcpy(cd.duracion, dato);

        fwrite(&cd, sizeof(cd), 1, archivo);
    }
    else
        cout<<"\n\nError al abrir archivo\n";

    fclose(archivo);
}

//ingresar()
//////////////////////////////
//abrir()

char* abrir(){
    FILE *archivo;
    char arc_nomb[20];
    static char reg[20];

    memset(arc_nomb, '\0', 20);

    system("cls");
    cout<<"[F1] Seleccionar archivo\n\n";
    cout<<"Ingrese nombre o direccion del archivo:\n--> ";
    fflush(stdin);
    gets(arc_nomb);

    strcpy(arc_nomb, validar.punto_bin(arc_nomb));
    archivo = fopen(arc_nomb, "ab");

    fclose(archivo);
    memset(reg, '\0', 20);
    strcpy(reg, arc_nomb);

    return reg;
}

//abrir()
//////////////////////////////
//limpiar()

void limpiar(){
    memset(cd.codigo, '\0', 6);
    memset(cd.album, '\0', 30);
    memset(cd.artista, '\0', 20);
    memset(cd.genero, '\0', 15);
    memset(cd.duracion, '\0', 6);
}

//limpiar()
//////////////////////////////
//menu()

void menu(){
    system("cls");

    cout<<"\tRegistro de cd";
    cout<<"\n[F1] Seleccionar archivo";
    cout<<"\n[F2] Alta";
    cout<<"\n[F3] Mostrar";
    cout<<"\n[F4] Consulta";
    cout<<"\n[F5] Edicion";
    cout<<"\n[F6] Baja";
    cout<<"\n[Esc] Salir";
    cout<<endl;
}
