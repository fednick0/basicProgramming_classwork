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

//para archivo original
struct musica{
    char codigo[6];
    char album[30]; //Que se valida?
    char artista[20]; //Que se valida?
    char genero[15];
    int no_tracks;
    char duracion [7]; //999:99 <--- max

    char rt = '\r';
    char salto = '\n';
}; struct musica cd;

//para solo album
struct musica_al{
    char codigo[6];
    char album[30];

    char rt = '\r';
    char salto = '\n';
}; struct musica_al cd_al;

//para solo artista
struct musica_ar{
    char codigo[6];
    char artista[20];

    char rt = '\r';
    char salto = '\n';
}; struct musica_ar cd_ar;

//para solo genero
struct musica_ge{
    char codigo[6];
    char genero[15];

    char rt = '\r';
    char salto = '\n';
}; struct musica_ge cd_ge;

//funciones
void menu();
void limpiar();
char* abrir();
void ingresar(char*);
void mostrar(char*);
int consulta_al(char*, char*, bool);
int consulta_ar(char*, char*, bool);
int consulta_ge(char*, char*, bool);
void editar(char*, int, bool);
char* fcodigo(char*);
int busca_eli(char*);

void ordenar_al(char*); // <-- ojo
void ordenar_ar(char*);
void ordenar_ge(char*);

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
                cout<<endl;
                mostrar(arc_nomb);
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
                cout<<"\n[1] Album\n[2] Artista\n[3] Genero";
                fflush(stdin);
                opc = getch();

                if(opc > '0' && opc < '4'){
                    cout<<"\nBuscar: ";
                    fflush(stdin);
                    gets(palabra);
                    system("cls");

                    switch(opc){
                        case '1': consulta_al(arc_nomb, palabra, false); break;
                        case '2': consulta_ar(arc_nomb, palabra, false); break;
                        case '3': consulta_ge(arc_nomb, palabra, false); break;
                        default:
                            cout<<"\n\nOpcion incorrecta, regresando al menu principal\n";
                            system("pause");
                    }

                    cout<<endl;
                    system("pause");
                }
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
                cout<<"\n[1] Album\n[2] Artista\n[3] Genero";
                fflush(stdin);
                opc = getch();

                if(opc > '0' && opc < '4'){
                    cout<<"\nBuscar: ";
                    fflush(stdin);
                    gets(palabra);
                    system("cls");

                    switch(opc){
                        case '1': editar(arc_nomb, consulta_al(arc_nomb, palabra, true), true); break;
                        case '2': editar(arc_nomb, consulta_ar(arc_nomb, palabra, true), true); break;
                        case '3': editar(arc_nomb, consulta_ge(arc_nomb, palabra, true), true); break;
                        default:
                            cout<<"\n\nOpcion incorrecta, regresando al menu principal\n";
                            system("pause");
                    }

                    cout<<endl;
                    system("pause");
                }
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
                cout<<"\n[1] Album\n[2] Artista\n[3] Genero";
                fflush(stdin);
                opc = getch();

                if(opc > '0' && opc < '4'){
                    cout<<"\nBuscar: ";
                    fflush(stdin);
                    gets(palabra);
                    system("cls");

                    switch(opc){
                        case '1': editar(arc_nomb, consulta_al(arc_nomb, palabra, true), false); break;
                        case '2': editar(arc_nomb, consulta_ar(arc_nomb, palabra, true), false); break;
                        case '3': editar(arc_nomb, consulta_ge(arc_nomb, palabra, true), false); break;
                        default:
                            cout<<"\n\nOpcion incorrecta, regresando al menu principal\n";
                            system("pause");
                    }

                    cout<<endl;
                    system("pause");
                }
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
    char album[24] = "al_";
    strcat(album, nomb_file);
    FILE *archivo = fopen(album, "rb");

    char c[2];
    char numbc[4];

    if(archivo != NULL){
        while(!feof(archivo)){

            if(feof(archivo))
                break;

            limpiar();
            fread(&cd_al, 1, sizeof(cd_al), archivo);

            if(cd_al.codigo[0] == '*'){
                memset(numbc, '\0', 4);
                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = cd_al.codigo[x];
                    strcat(numbc, c);
                }

                fclose(archivo);
                return atoi(numbc);
            }
        }
    }
    else
        cout<<"\nError al abrir archivo\n";

    fclose(archivo);
    return -1;
}

//busca_eli()
//////////////////////////////

void ordenar_al(char *nomb_file){
    //abro archivo album
    FILE *al = fopen(nomb_file, "rb");

    //posicion final
    fseek(al, 0, 2);

    //determino largo de un registro
    int largo = sizeof(cd_al);

    //determino cantidad de registros
    int registro = ftell(al) / largo;

    //declaro
    char arreglo[registro][largo];

    //genero arreglo
    fseek(al, 0, 0);
    for(int x = 0; x < registro; x++){
        fread(&cd_al, 1, largo, al);
        strcpy(arreglo[x], cd_al.codigo);
        strcat(arreglo[x], cd_al.album);
    }

    //cierro archivo
    fclose(al);

    //Burbuja mejorada
    bool ban = true;;
    char aux[largo];
    for(int x = 0; x < registro && ban; x++){
        ban = false;
        for(int y = 0; y < registro - 1; y++){
            if(arreglo[y][5] > arreglo[y + 1][5]){
                ban = true;
                strcpy(aux, arreglo[y]); //aux = arreglo[y];
                strcpy(arreglo[y], arreglo[y + 1]); //arreglo[y] = arreglo[y + 1];
                strcpy(arreglo[y + 1], aux); //arreglo[y + 1] = aux;
            }
        }
    }

    //creo nuevo archivo
    char album[24];
    memset(album, '\0', 24);
    strcpy(album, "new_");
    strcat(album, nomb_file);
    al = fopen(album, "ab");

    //guardo en nuevo archivo
    for(int x = 0; x < registro; x++){
        limpiar();
        for(int i = 0; i < strlen(arreglo[x]); i++){
            char c[2];
            memset(c, '\0', 2);
            c[0] = arreglo[x][i];
            if(i < 5)
                strcat(cd_al.codigo, c);
            else
                strcat(cd_al.album, c);
        }
        fwrite(&cd_al, sizeof(cd_al), 1, al);
    }

    //cierro archivo
    fclose(al);

    remove(nomb_file);
    rename(album, nomb_file);
}

void ordenar_ar(char *nomb_file){
    //abro archivo album
    FILE *al = fopen(nomb_file, "rb");

    //posicion final
    fseek(al, 0, 2);

    //determino largo de un registro
    int largo = sizeof(cd_ar);

    //determino cantidad de registros
    int registro = ftell(al) / largo;

    //declaro
    char arreglo[registro][largo];

    //genero arreglo
    fseek(al, 0, 0);
    for(int x = 0; x < registro; x++){
        fread(&cd_ar, 1, largo, al);
        strcpy(arreglo[x], cd_ar.codigo);
        strcat(arreglo[x], cd_ar.artista);
    }

    //cierro archivo
    fclose(al);

    //Burbuja mejorada
    bool ban = true;;
    char aux[largo];
    for(int x = 0; x < registro && ban; x++){
        ban = false;
        for(int y = 0; y < registro - 1; y++){
            if(arreglo[y][5] > arreglo[y + 1][5]){
                ban = true;
                strcpy(aux, arreglo[y]); //aux = arreglo[y];
                strcpy(arreglo[y], arreglo[y + 1]); //arreglo[y] = arreglo[y + 1];
                strcpy(arreglo[y + 1], aux); //arreglo[y + 1] = aux;
            }
        }
    }

    //creo nuevo archivo
    char album[24];
    memset(album, '\0', 24);
    strcpy(album, "new_");
    strcat(album, nomb_file);
    al = fopen(album, "ab");

    //guardo en nuevo archivo
    for(int x = 0; x < registro; x++){
        limpiar();
        for(int i = 0; i < strlen(arreglo[x]); i++){
            char c[2];
            memset(c, '\0', 2);
            c[0] = arreglo[x][i];
            if(i < 5)
                strcat(cd_ar.codigo, c);
            else
                strcat(cd_ar.artista, c);
        }
        fwrite(&cd_ar, sizeof(cd_ar), 1, al);
    }

    //cierro archivo
    fclose(al);

    remove(nomb_file);
    rename(album, nomb_file);
}

void ordenar_ge(char *nomb_file){
    //abro archivo album
    FILE *al = fopen(nomb_file, "rb");

    //posicion final
    fseek(al, 0, 2);

    //determino largo de un registro
    int largo = sizeof(cd_ge);

    //determino cantidad de registros
    int registro = ftell(al) / largo;

    //declaro
    char arreglo[registro][largo];

    //genero arreglo
    fseek(al, 0, 0);
    for(int x = 0; x < registro; x++){
        fread(&cd_ge, 1, largo, al);
        strcpy(arreglo[x], cd_ge.codigo);
        strcat(arreglo[x], cd_ge.genero);
    }

    //cierro archivo
    fclose(al);

    //Burbuja mejorada
    bool ban = true;;
    char aux[largo];
    for(int x = 0; x < registro && ban; x++){
        ban = false;
        for(int y = 0; y < registro - 1; y++){
            if(arreglo[y][5] > arreglo[y + 1][5]){
                ban = true;
                strcpy(aux, arreglo[y]); //aux = arreglo[y];
                strcpy(arreglo[y], arreglo[y + 1]); //arreglo[y] = arreglo[y + 1];
                strcpy(arreglo[y + 1], aux); //arreglo[y + 1] = aux;
            }
        }
    }

    //creo nuevo archivo
    char album[24];
    memset(album, '\0', 24);
    strcpy(album, "new_");
    strcat(album, nomb_file);
    al = fopen(album, "ab");

    //guardo en nuevo archivo
    for(int x = 0; x < registro; x++){
        limpiar();
        for(int i = 0; i < strlen(arreglo[x]); i++){
            char c[2];
            memset(c, '\0', 2);
            c[0] = arreglo[x][i];
            if(i < 5)
                strcat(cd_ge.codigo, c);
            else
                strcat(cd_ge.genero, c);
        }
        fwrite(&cd_ge, sizeof(cd_ge), 1, al);
    }

    //cierro archivo
    fclose(al);

    remove(nomb_file);
    rename(album, nomb_file);
}

//////////////////////////////

int consulta_al(char *nomb_file, char *palabra, bool hacer){
    char album[24] = "al_";
    strcat(album, nomb_file);

    FILE *al = fopen(album, "rb+");
    FILE *archivo = fopen(nomb_file, "rb+");

    if(al != NULL){

        int pos;
        char c[2];
        char numbc[4];
        char codigo_aux[6];
        bool encontro = false;

        while(!feof(al)){

            limpiar();
            memset(numbc, '\0', 4);
            memset(codigo_aux, '\0', 6);

            fread(&cd_al, 1, sizeof(cd_al), al);
            strcpy(codigo_aux, cd_al.codigo);

            if(feof(al))
                break;

            if(strcmpi(cd_al.album, palabra) == 0 && cd_al.codigo[0] != '*'){
                encontro = true;

                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = codigo_aux[x];
                    strcat(numbc, c);
                }

                pos = atoi(numbc);

                fseek(archivo, sizeof(cd)*pos, 0);
                fread(&cd, 1, sizeof(cd), archivo);

                cout<<"\nCodigo: " <<cd.codigo;
                cout<<"\nAlbum: " <<cd.album;
                cout<<"\nArtista: " <<cd.artista;
                cout<<"\nGenero: " <<cd.genero;
                cout<<"\nNo. de tracks: " <<cd.no_tracks;
                cout<<"\nDuracion: " <<cd.duracion;
                cout<<endl;

                if(hacer){
                    cout<<"Desea modificar este usuario? S/N\n\n";

                    if(getch() == 's')
                        return pos;
                }
            }
        }

        fclose(archivo);
        fclose(al);

        if(!encontro)
            cout<<"\nNo hay coincidencias";

    }
    else
        cout<<"\nError al abrir archivo";

    fclose(archivo);
    fclose(al);

    return -1;
}

//////////////////////////////

int consulta_ar(char *nomb_file, char *palabra, bool hacer){
    char artista[24] = "ar_";
    strcat(artista, nomb_file);

    FILE *ar = fopen(artista, "rb+");
    FILE *archivo = fopen(nomb_file, "rb+");

    if(ar != NULL){

        int pos;
        char c[2];
        char numbc[4];
        char codigo_aux[6];
        bool encontro = false;

        while(!feof(ar)){

            limpiar();
            memset(numbc, '\0', 4);
            memset(codigo_aux, '\0', 6);

            fread(&cd_ar, 1, sizeof(cd_ar), ar);
            strcpy(codigo_aux, cd_ar.codigo);

            if(feof(ar))
                break;

            if(strcmpi(cd_ar.artista, palabra) == 0 && cd_ar.codigo[0] != '*'){
                encontro = true;

                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = codigo_aux[x];
                    strcat(numbc, c);
                    }

                pos = atoi(numbc);

                fseek(archivo, sizeof(cd)*pos, 0);
                fread(&cd, 1, sizeof(cd), archivo);

                cout<<"\nCodigo: " <<cd.codigo;
                cout<<"\nAlbum: " <<cd.album;
                cout<<"\nArtista: " <<cd.artista;
                cout<<"\nGenero: " <<cd.genero;
                cout<<"\nNo. de tracks: " <<cd.no_tracks;
                cout<<"\nDuracion: " <<cd.duracion;
                cout<<endl;

                if(hacer){
                    cout<<"Desea modificar este usuario? S/N\n\n";

                    if(getch() == 's')
                        return pos;
                }
            }
        }

        fclose(archivo);
        fclose(ar);

        if(!encontro)
            cout<<"\nNo hay coincidencias";

    }
    else
        cout<<"\nError al abrir archivo";

    fclose(archivo);
    fclose(ar);

    return -1;
}

//////////////////////////////

int consulta_ge(char *nomb_file, char *palabra, bool hacer){
    char genero[24] = "ge_";
    strcat(genero, nomb_file);

    FILE *ge = fopen(genero, "rb+");
    FILE *archivo = fopen(nomb_file, "rb+");

    if(ge != NULL){

        int pos;
        char c[2];
        char numbc[4];
        char codigo_aux[6];
        bool encontro = false;

        while(!feof(ge)){

            limpiar();
            memset(numbc, '\0', 4);
            memset(codigo_aux, '\0', 6);

            fread(&cd_ge, 1, sizeof(cd_ge), ge);
            strcpy(codigo_aux, cd_ge.codigo);

            if(feof(ge))
                break;

            if(strcmpi(cd_ge.genero, palabra) == 0 && cd_ge.codigo[0] != '*'){
                encontro = true;

                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = codigo_aux[x];
                    strcat(numbc, c);
                    }

                pos = atoi(numbc);

                fseek(archivo, sizeof(cd)*pos, 0);
                fread(&cd, 1, sizeof(cd), archivo);

                cout<<"\nCodigo: " <<cd.codigo;
                cout<<"\nAlbum: " <<cd.album;
                cout<<"\nArtista: " <<cd.artista;
                cout<<"\nGenero: " <<cd.genero;
                cout<<"\nNo. de tracks: " <<cd.no_tracks;
                cout<<"\nDuracion: " <<cd.duracion;
                cout<<endl;

                if(hacer){
                    cout<<"Desea modificar este usuario? S/N\n\n";

                    if(getch() == 's')
                        return pos;
                }

            }
        }

        fclose(archivo);
        fclose(ge);

        if(!encontro)
            cout<<"\nNo hay coincidencias";

    }
    else
        cout<<"\nError al abrir archivo";

    fclose(archivo);
    fclose(ge);

    return -1;
}

void editar(char *nomb_file, int pos, bool edita){
    char album[24] = "al_";
    char artista[24] = "ar_";
    char genero[24] = "ge_";

    strcat(album, nomb_file);
    strcat(artista, nomb_file);
    strcat(genero, nomb_file);

    FILE *archivo = fopen(nomb_file, "r+b");
    FILE *al = fopen(album, "r+b");
    FILE *ar = fopen(artista, "r+b");
    FILE *ge = fopen(genero, "r+b");

    char codigo_aux[6];
    char dato[30];
    char numbc[4];
    char c[2];

    memset(codigo_aux, '\0', 6);

    limpiar();

    if(archivo != NULL){
        fseek(archivo, sizeof(cd)*pos, 0);
        fread(&cd, 1, sizeof(cd), archivo);
        fseek(archivo, sizeof(cd)*pos, 0);

        //Album
        do{
            fread(&cd_al, 1, sizeof(cd_al), al);

            memset(numbc, '\0', 4);
            for(int x = 2; x < 5; x++){
                memset(c, '\0', 2);
                c[0] = cd_al.codigo[x];
                strcat(numbc, c);
            }
        } while(atoi(numbc) != pos);
        fseek(al, -sizeof(cd_al), 1);

        //Artista
        do{
            fread(&cd_ar, 1, sizeof(cd_ar), ar);

            memset(numbc, '\0', 4);
            for(int x = 2; x < 5; x++){
                memset(c, '\0', 2);
                c[0] = cd_ar.codigo[x];
                strcat(numbc, c);
            }
        } while(atoi(numbc) != pos);
        fseek(ar, -sizeof(cd_ar), 1);

        //Genero
        do{
            fread(&cd_ge, 1, sizeof(cd_ge), ge);

            memset(numbc, '\0', 4);
            for(int x = 2; x < 5; x++){
                memset(c, '\0', 2);
                c[0] = cd_ge.codigo[x];
                strcat(numbc, c);
            }
        } while(atoi(numbc) != pos);
        fseek(ge, -sizeof(cd_ge), 1);

        strcpy(codigo_aux, cd.codigo);

        if(edita){
            cout<<"\n\tOpciones de edicion:\n";
            cout<<"[1] Album\n";
            cout<<"[2] Artista\n";
            cout<<"[3] Genero\n";
            cout<<"[4] Todo\n";

            switch(getch()){
                case '1':
                    memset(cd.album, '\0', 30);
                    cout<<"\nAlbum: ";
                    fflush(stdin);
                    gets(cd.album);
                    break;

                case '2':
                    memset(cd.artista, '\0', 20);
                    cout<<"Artista: ";
                    fflush(stdin);
                    gets(cd.artista);
                    break;

                case '3':
                    memset(cd.genero, '\0', 15);
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
                    break;

                case '4':
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
                    break;
            }

            fwrite(&cd, sizeof(cd), 1, archivo);

            //Album
            strcpy(cd_al.codigo, cd.codigo);
            strcpy(cd_al.album, cd.album);
            fwrite(&cd_al, sizeof(cd_al), 1, al);

            //Artista
            strcpy(cd_ar.codigo, cd.codigo);
            strcpy(cd_ar.artista, cd.artista);
            fwrite(&cd_ar, sizeof(cd_ar), 1, ar);

            //Genero
            strcpy(cd_ge.codigo, cd.codigo);
            strcpy(cd_ge.genero, cd.genero);
            fwrite(&cd_ge, sizeof(cd_ge), 1, ge);
        }
        else{
            fread(&cd, 1, sizeof(cd), archivo);
            fseek(archivo, sizeof(cd)*pos, 0);

            cd.codigo[0] = '*';
            fwrite(&cd, sizeof(cd), 1, archivo);

            //Album
            strcpy(cd_al.codigo, cd.codigo);
            fwrite(&cd_al, sizeof(cd_al), 1, al);

            //Artista
            strcpy(cd_ar.codigo, cd.codigo);
            fwrite(&cd_ar, sizeof(cd_ar), 1, ar);

            //Genero
            strcpy(cd_ge.codigo, cd.codigo);
            fwrite(&cd_ge, sizeof(cd_ge), 1, ge);
        }

        fclose(archivo);
    }
    else
        cout<<"\nError al abrir archivo\n";

    fclose(archivo);
}

//editar()
//////////////////////////////
//mostrar()

void mostrar(char *nomb_file){
    FILE *archivo = fopen(nomb_file, "rb+");

    if(archivo != NULL){
        while(!feof(archivo)){

            limpiar();
            fread(&cd, 1, sizeof(cd), archivo);

            if(feof(archivo))
                break;

            if(cd.codigo[0] != '*'){
                cout<<"\nCodigo: " <<cd.codigo;
                cout<<"\nAlbum: " <<cd.album;
                cout<<"\nArtista: " <<cd.artista;
                cout<<"\nGenero: " <<cd.genero;
                cout<<"\nNo. de tracks: " <<cd.no_tracks;
                cout<<"\nDuracion: " <<cd.duracion;
                cout<<endl;
            }
        }
    }
    else
        cout<<"\nError al abrir archivo";
}

//mostrar()
//////////////////////////////
//fcodigo()

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
    FILE *archivo, *al, *ar, *ge;

    int elimin = busca_eli(nomb_file); //Compruebo si hay algun eliminado
    char numbc[4];
    char codigo_aux[6];
    char dato[30];
    char c[2];

    char album[24] = "al_";
    char artista[24] = "ar_";
    char genero[24] = "ge_";

    strcat(album, nomb_file);
    strcat(artista, nomb_file);
    strcat(genero, nomb_file);

    if(elimin != -1){
        archivo = fopen(nomb_file, "r+b");
        al = fopen(album, "r+b");
        ar = fopen(artista, "r+b");
        ge = fopen(genero, "r+b");
    }
    else{
        archivo = fopen(nomb_file, "ab+");
        al = fopen(album, "ab+");
        ar = fopen(artista, "ab+");
        ge = fopen(genero, "ab+");
    }

    if(archivo != NULL){

        //if()else codigo
        if(elimin != -1){
            limpiar();

            //Archivo original
            fseek(archivo, sizeof(cd)*elimin, 0);
            fread(&cd, 1, sizeof(cd), archivo);
            fseek(archivo, sizeof(cd)*elimin, 0);

            //Album
            do{
                fread(&cd_al, 1, sizeof(cd_al), al);

                memset(numbc, '\0', 4);
                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = cd_al.codigo[x];
                    strcat(numbc, c);
                }
            } while(atoi(numbc) != elimin);
            fseek(al, -sizeof(cd_al), 1);

            //Artista
            do{
                fread(&cd_ar, 1, sizeof(cd_ar), ar);

                memset(numbc, '\0', 4);
                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = cd_ar.codigo[x];
                    strcat(numbc, c);
                }
            } while(atoi(numbc) != elimin);
            fseek(ar, -sizeof(cd_ar), 1);

            //Genero
            do{
                fread(&cd_ge, 1, sizeof(cd_ge), ge);

                memset(numbc, '\0', 4);
                for(int x = 2; x < 5; x++){
                    memset(c, '\0', 2);
                    c[0] = cd_ge.codigo[x];
                    strcat(numbc, c);
                }
            } while(atoi(numbc) != elimin);
            fseek(ge, -sizeof(cd_ge), 1);

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

        //Todo en el archivo original
        fwrite(&cd, sizeof(cd), 1, archivo);

        //Album
        strcpy(cd_al.codigo, cd.codigo);
        strcpy(cd_al.album, cd.album);
        fwrite(&cd_al, sizeof(cd_al), 1, al);

        //Artista
        strcpy(cd_ar.codigo, cd.codigo);
        strcpy(cd_ar.artista, cd.artista);
        fwrite(&cd_ar, sizeof(cd_ar), 1, ar);

        //Genero
        strcpy(cd_ge.codigo, cd.codigo);
        strcpy(cd_ge.genero, cd.genero);
        fwrite(&cd_ge, sizeof(cd_ge), 1, ge);

        fclose(archivo);
        fclose(al);
        fclose(ar);
        fclose(ge);

        ordenar_al(album);
        ordenar_ar(artista);
        ordenar_ge(genero);
    }
    else
        cout<<"\n\nError al abrir archivo\n";

    fclose(archivo);
    fclose(al);
    fclose(ar);
    fclose(ge);
}

//ingresar()
//////////////////////////////
//abrir()

char* abrir(){
    FILE *archivo;
    char arc_nomb[20];
    static char reg[20];

    char album[24] = "al_";
    char artista[24] = "ar_";
    char genero[24] = "ge_";

    memset(arc_nomb, '\0', 20);

    system("cls");
    cout<<"[F1] Seleccionar archivo\n\n";
    cout<<"Ingrese nombre o direccion del archivo:\n--> ";
    fflush(stdin);
    gets(arc_nomb);

    strcpy(arc_nomb, validar.punto_bin(arc_nomb));
    archivo = fopen(arc_nomb, "ab");
    fclose(archivo);

    strcat(album, arc_nomb);
    archivo = fopen(album, "ab");
    fclose(archivo);

    strcat(artista, arc_nomb);
    archivo = fopen(artista, "ab");
    fclose(archivo);

    strcat(genero, arc_nomb);
    archivo = fopen(genero, "ab");
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

    memset(cd_al.codigo, '\0', 6);
    memset(cd_al.album, '\0', 30);

    memset(cd_ar.codigo, '\0', 6);
    memset(cd_ar.artista, '\0', 20);

    memset(cd_ge.codigo, '\0', 6);
    memset(cd_ge.genero, '\0', 15);
}

//limpiar()
//////////////////////////////
//menu()

void menu(){
    system("cls");

    cout<<"\tRegistro de CD";
    cout<<"\n[F1] Seleccionar archivo";
    cout<<"\n[F2] Alta";
    cout<<"\n[F3] Mostrar";
    cout<<"\n[F4] Consulta";
    cout<<"\n[F5] Edicion";
    cout<<"\n[F6] Baja";
    cout<<"\n[Esc] Salir";
    cout<<endl;
}
