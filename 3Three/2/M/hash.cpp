#include <iostream> //cout<<
#include <stdlib.h> //system()
#include <stdio.h> //gets()
#include <conio.h> //getch()
#include <string.h> //memset()

#include "validar.h"
using namespace std;

typedef struct musica{
    char artista[30];
    char album[30];
    char genero[30];
    int no_tracks;
    char duracion [7];

    char rt = '\r';
    char salto = '\n';
}; struct musica cd;

//struct auxiliar para determinar colision
typedef struct musica_aux{
    char artista[30];
    char album[30];
    char genero[30];
    int no_tracks;
    char duracion [7];

    char rt = '\r';
    char salto = '\n';
}; struct musica_aux cd_aux; //obj

//funciones
void menu();
void limpiar_cd();
void limpiar_cd_aux();
char* abrir();
void ingresar(char*);
int consulta(char*);
void edicion(char*, int, bool);
void mostrar(char*);

//int hasherino()
int hasherino(){
    char palabra[60];
    int numb = 0;
    int r;

    memset(palabra, '\0', 60);
    strcat(palabra, cd.artista);
    strcat(palabra, cd.album);

    for(int x = 0; x < strlen(palabra); x++)
        numb += palabra[x];

    r = numb % 100;

    return r;
}

//int main()
int main(){
    int opc;
    char arc_nomb[30];
    bool abrir_b = false;

    memset(arc_nomb, '\0', 30);

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
                    fflush(stdin);
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
                mostrar(arc_nomb);
                cout<<"\n\n";
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
                cout<<"\n\nPara realizar una consulta correctamente\nnecesita ingresar Artista y Album.\n";
                consulta(arc_nomb);
                cout<<"\n\n";
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
                cout<<"\n\nPara realizar una edicion correctamente\nnecesita primero ingresar Artista y Album.\n";
                edicion(arc_nomb, consulta(arc_nomb), true);
                cout<<"\n";
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
                cout<<"\n\nPara realizar una eliminacion correctamente\nnecesita primero ingresar Artista y Album.\n";
                edicion(arc_nomb, consulta(arc_nomb), false);
                cout<<"\n";
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
//mostrar()

void mostrar(char *nomb_file){
    FILE *archivo = fopen(nomb_file, "r+b");

    if(archivo != NULL){
        while(!feof(archivo)){

            if(feof(archivo))
                break;

            limpiar_cd_aux();
            fread(&cd_aux, 1, sizeof(cd_aux), archivo);

            if(strlen(cd_aux.album) != 0){
                cout<<"\n\nArtista: " <<cd_aux.artista;
                cout<<"\nAlbum: " <<cd_aux.album;
                cout<<"\nGenero: " <<cd_aux.genero;
                cout<<"\nNo. tracks: " <<cd_aux.no_tracks;
                cout<<"\nDuracion: " <<cd_aux.duracion;
            }
        }
    }
    else
        cout<<"\n\nError al abrir archivo\n";
    fclose(archivo);
}

//mostrar()
//////////////////////////////
//edicion()

void edicion(char *nomb_file, int pos, bool edita){
    FILE *archivo = fopen(nomb_file, "r+b");
    char dato[30];

    if(archivo != NULL && pos != -1){
        if(edita){
            cout<<"\n\n\tOpciones de edicion:\n";
            cout<<"[1] Artista\n";
            cout<<"[2] Album\n";
            cout<<"[3] Genero\n";
            cout<<"[4] No. tracks\n";
            cout<<"[5] Duracion\n";
            cout<<"[6] Todo\n";

            switch(getch()){
                case '1':
                    memset(cd_aux.artista, '\0', 20);
                    cout<<"\nArtista: ";
                    fflush(stdin);
                    gets(cd_aux.artista);
                    break;

                case '2':
                    memset(cd_aux.album, '\0', 30);
                    cout<<"\nAlbum: ";
                    fflush(stdin);
                    gets(cd_aux.album);
                    break;

                case '3':
                    memset(cd_aux.genero, '\0', 15);
                    cout<<"\n  (1) Clasica      (4) Blues     (7) Pop";
                    cout<<"\n  (2) Jazz         (5) Reggae    (8) Electronica";
                    cout<<"\n  (3) Rock & Roll  (6) Hip Hop   (9) Heavy Metal";
                    fflush(stdin);
                    switch(getch()){
                        case '1': strcpy(cd_aux.genero, "Clasica"); break;
                        case '2': strcpy(cd_aux.genero, "Jazz"); break;
                        case '3': strcpy(cd_aux.genero, "Rock & Roll"); break;
                        case '4': strcpy(cd_aux.genero, "Blues"); break;
                        case '5': strcpy(cd_aux.genero, "Reggae"); break;
                        case '6': strcpy(cd_aux.genero, "Hip Hop"); break;
                        case '7': strcpy(cd_aux.genero, "Pop"); break;
                        case '8': strcpy(cd_aux.genero, "Electronica"); break;
                        case '9': strcpy(cd_aux.genero, "Heavy Metal"); break;
                    default:
                        cout<<"\nOpcion incorrecta";
                        strcpy(cd_aux.genero, "Clasica");
                    }
                    cout<<"\nGenero: " <<cd_aux.genero <<endl;
                    break;

                case '4':
                    do{
                        memset(dato, '\0', 30);
                        cout<<"\nNo. de tracks: ";
                        fflush(stdin);
                        gets(dato);
                    } while(validar.no_track(dato));
                    cd_aux.no_tracks = atoi(dato);
                    break;

                case '5':
                    memset(cd_aux.duracion, '\0', 7);
                    do{
                        memset(dato, '\0', 30);
                        cout<<"\nDuracion: ";
                        fflush(stdin);
                        gets(dato);
                    } while(validar.duracion(dato));
                    strcpy(cd_aux.duracion, dato);
                    break;

                case '6':
                    limpiar_cd();
                    limpiar_cd_aux();

                    cout<<"\nArtista: ";
                    fflush(stdin);
                    gets(cd_aux.artista);

                    cout<<"Album: ";
                    fflush(stdin);
                    gets(cd_aux.album);

                    cout<<"  (1) Clasica      (4) Blues     (7) Pop";
                    cout<<"\n  (2) Jazz         (5) Reggae    (8) Electronica";
                    cout<<"\n  (3) Rock & Roll  (6) Hip Hop   (9) Heavy Metal";
                    fflush(stdin);
                    switch(getch()){
                        case '1': strcpy(cd_aux.genero, "Clasica"); break;
                        case '2': strcpy(cd_aux.genero, "Jazz"); break;
                        case '3': strcpy(cd_aux.genero, "Rock & Roll"); break;
                        case '4': strcpy(cd_aux.genero, "Blues"); break;
                        case '5': strcpy(cd_aux.genero, "Reggae"); break;
                        case '6': strcpy(cd_aux.genero, "Hip Hop"); break;
                        case '7': strcpy(cd_aux.genero, "Pop"); break;
                        case '8': strcpy(cd_aux.genero, "Electronica"); break;
                        case '9': strcpy(cd_aux.genero, "Heavy Metal"); break;
                    default:
                        cout<<"\nOpcion incorrecta";
                        strcpy(cd_aux.genero, "Clasica");
                    }
                    cout<<"\nGenero: " <<cd_aux.genero <<endl;

                    do{
                        memset(dato, '\0', 30);
                        cout<<"No. de tracks: ";
                        fflush(stdin);
                        gets(dato);
                    } while(validar.no_track(dato));
                    cd_aux.no_tracks = atoi(dato);

                    do{
                        memset(dato, '\0', 30);
                        cout<<"Duracion: ";
                        fflush(stdin);
                        gets(dato);
                    } while(validar.duracion(dato));
                    strcpy(cd_aux.duracion, dato);
                    break;

                default:
                    cout<<"\nOpcion incorrecta, regresando al menu principal.";
                    fclose(archivo);
                    return;
            }

            limpiar_cd();
            fseek(archivo, sizeof(cd) * pos, 0);
            fwrite(&cd, sizeof(cd), 1, archivo);

            strcpy(cd.artista, cd_aux.artista);
            strcpy(cd.album, cd_aux.album);

            fseek(archivo, sizeof(cd_aux) * hasherino(), 0);
            fwrite(&cd_aux, sizeof(cd_aux), 1, archivo);

            cout<<"\nSe han guardado los cambios\n";
        }
        else{ //eliminar
            cout<<"\n\nRealmente desa eliminar este registro? s/n";

            if (getch() == 's'){
                limpiar_cd();
                limpiar_cd_aux();

                fseek(archivo, sizeof(cd) * pos, 0);
                fwrite(&cd, sizeof(cd), 1, archivo);

                cout<<"\n\nRegistro eliminado\n";
            }
            else
                cout<<"\n\nRegresando al menu principal.";
        }
    }
    else if(archivo == NULL)
        cout<<"\n\nError al abrir archivo\n";
    fclose(archivo);
}

//edicion()
//////////////////////////////
//consulta()

int consulta(char *nomb_file){
    limpiar_cd();
    limpiar_cd_aux();

    cout<<"Artista: ";
    gets(cd.artista);
    cout<<"Album: ";
    gets(cd.album);

    int pos = hasherino();
    FILE *archivo = fopen(nomb_file, "r+b");

    if(archivo != NULL){
        fseek(archivo, sizeof(cd) * pos, 0);
        fread(&cd_aux, 1, sizeof(cd_aux), archivo);

        if(strlen(cd_aux.artista) != 0){
            cout<<"\nArtista: " <<cd_aux.artista;
            cout<<"\nAlbum: " <<cd_aux.album;
            cout<<"\nGenero: " <<cd_aux.genero;
            cout<<"\nNo. tracks: " <<cd_aux.no_tracks;
            cout<<"\nDuracion: " <<cd_aux.duracion;

            fclose(archivo);
            return pos;
        }
        else
            cout<<"\nSin coincidencias";
    }
    else
        cout<<"\n\nError al abrir archivo\n";

    fclose(archivo);
    return -1;
}

//consulta()
//////////////////////////////
//ingresar()

void ingresar(char *nomb_file){
    FILE *archivo = fopen(nomb_file, "r+b");
    char dato[30];

    if(archivo != NULL){
        limpiar_cd();
        limpiar_cd_aux();
        fseek(archivo, 0, 2);

        if(ftell(archivo) == 0){
            for(int x = 0; x < 100; x++)
                fwrite(&cd, sizeof(cd), 1, archivo);
        }

        cout<<"\n\nArtista: ";
        fflush(stdin);
        gets(cd.artista);

        cout<<"Album: ";
        fflush(stdin);
        gets(cd.album);

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

        int pos = hasherino();

        fseek(archivo, sizeof(cd) * pos, 0);
        fread(&cd_aux, 1, sizeof(cd_aux), archivo);
        fseek(archivo, sizeof(cd) * pos, 0);

        cout<<"\n --> " <<pos; //borrar esto

        if(strlen(cd_aux.artista) == 0){
            fwrite(&cd, sizeof(cd), 1, archivo);
            cout<<"\n--> Registro guardado\n";
        }
        else{
            cout<<"\n\tColision! D:\n";
            cout<<"Desea remplasar el registo? S/N\n";

            if(getch() == 's'){
                fwrite(&cd, sizeof(cd), 1, archivo);
                cout<<"--> Registro guardado\n";
            }
            else
                cout<<"--> No se guardo ningun registro\n";
        }
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
    char arc_nomb[30];
    static char reg[30];

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
//limpiar_cd()

void limpiar_cd(){
    memset(cd.artista, '\0', 30);
    memset(cd.album, '\0', 30);
    memset(cd.genero, '\0', 30);
    cd.no_tracks = 0;
    memset(cd.duracion, '\0', 7);
}

//limpiar_cd()
//////////////////////////////
//limpiar_cd_aux()

void limpiar_cd_aux(){
    memset(cd_aux.artista, '\0', 30);
    memset(cd_aux.album, '\0', 30);
    memset(cd_aux.genero, '\0', 30);
    cd_aux.no_tracks = 0;
    memset(cd_aux.duracion, '\0', 7);
}

//limpiar_cd_aux()
//////////////////////////////
//menu()

void menu(){
    system("cls");

    cout<<"\tRegistro de CD - Hash";
    cout<<"\n[F1] Seleccionar archivo";
    cout<<"\n[F2] Alta";
    cout<<"\n[F3] Mostrar*";
    cout<<"\n[F4] Consulta";
    cout<<"\n[F5] Edicion";
    cout<<"\n[F6] Baja";
    cout<<"\n[Esc] Salir";
    cout<<endl;
}

