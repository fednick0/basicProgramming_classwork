                #include <iostream> //cout cin
                #include <conio.h> //getch()
                #include <stdlib.h> //system("")
                #include <stdio.h> //gets()
                #include <string.h> //strcat()

                #include "validar.h"

                using namespace std;

                int menu(void);
                void ingresar(void);
                void mostrar(char*, bool);
                char* buscar(void);
                void editar(int, bool);
                //void eliminar(void); No utilizo
                void copiar(void);

                int main(){

                    int opc, cantidad;
                    char busca[50], posicion[20];

                    do{
                        system("cls");
                        opc = menu();

                        switch(opc){
                        case '1': //[1] Ingresar
                            do{
                                system("cls");
                                cout<<"[1] Ingresar\n";

                                ingresar();

                                cout<<"\n\n[!Esc] Repetir";
                            } while(getch() != 27);
                            break;

                        //***************************************

                        case '2': //[2] Mostrar
                            system("cls");
                            cout<<"[2] Mostrar\n\n";
                            mostrar("\0", true);

                            system("pause");
                            break;

                        //***************************************

                        case '3': //[3] Buscar
                            system("cls");
                            cout<<"[3] Buscar\nBuscar: ";

                            mostrar( buscar(), false);
                            system("pause");
                            break;

                        //***************************************

                        case '4': //[4] Editar
                            system("cls");
                            cout<<"[4] Editar\nBuscar: ";

                            memset(posicion, '\0', 20);
                            strcpy(posicion, buscar());
                            mostrar( posicion, false);

                            cantidad = strlen(posicion);

                            if(cantidad > 1){
                                cout<<"\nSe encontraron varias coincidencias.";
                                cout<<"\nPresione numero del contacto que desea editar.\n";

                                editar( posicion[getch() - '1'] - '0', true);
                            }
                            else if(cantidad == 1)
                                editar(posicion[0] - '0', true);

                            system("pause");
                            break;

                        //***************************************

                        case '5': //[5] Eliminar
                            system("cls");
                            cout<<"[5] Eliminar\nBuscar: ";

                            memset(posicion, '\0', 20);
                            strcpy(posicion, buscar());
                            mostrar(posicion, false);

                            cantidad = strlen(posicion);

                            if(cantidad > 1){
                                cout<<"\nSe encontraron varias coincidencias.";
                                cout<<"\nPresione numero del contacto que desea editar.\n";

                                editar( posicion[getch() - '1'] - '0', false);
                            }
                            else if(cantidad == 1)
                                editar(posicion[0] - '0', false);

                            system("pause");
                            break;

                        //***************************************

                        case 27: //[Esc] salir
                            cout<<"\nSaliendo . . .";
                            break;

                        default:
                            cout<<"Opcion incorrecta\n";
                            system("pause");
                        }
                    }while(opc != 27);
                }

                /////////////////////////////////////////////////

                void copiar(){
                    FILE *archivoc = fopen("agenda.txt", "r");
                    FILE *auxc = fopen("auxi.txt", "w");

                    //aux probablemente sea palabra reservada

                    char caracter;

                    if(archivoc != NULL && auxc != NULL){
                        do{
                            caracter = fgetc(archivoc);

                            if(caracter != EOF)
                                fputc(caracter, auxc);
                        } while(caracter != EOF);
                    }
                    else
                        cout<<"Error No. 1\n";

                    fclose(archivoc);
                    fclose(auxc);

                    if(remove("agenda.txt") != 0)
                        cout<<"Error No. 2\n";
                }

                /////////////////////////////////////////////////

                void editar(int pos, bool edita){
                    copiar();

                    FILE *archivoe = fopen("agenda.txt", "a");
                    FILE *auxe = fopen("auxi.txt", "r");

                    int vueltas = 0;
                    char caracter, dato[50];
                    bool ban = true;

                    if(archivoe != NULL && auxe != NULL){
                        do{
                            caracter = fgetc(auxe);

                            if(pos != vueltas && caracter != EOF)
                                fputc(caracter, archivoe);
                            else if(ban && edita){
                                ban = false;
                                //ingresar();

                                do{
                                    cout<<"Nombre: ";
                                    gets(dato);
                                    strcpy(dato, validar.trim(dato));
                                } while(validar.nombre(dato));
                                strcat(dato, "*");
                                fputs(dato, archivoe);

                                do{
                                    cout<<"Telefono: ";
                                    gets(dato);
                                    strcpy(dato, validar.trim(dato));
                                } while(validar.telefono(dato));
                                strcat(dato, "*");
                                fputs(dato, archivoe);

                                do{
                                    cout<<"Direccion: ";
                                    gets(dato);
                                    strcpy(dato, validar.trim(dato));
                                } while(validar.domicilio(dato));
                                strcat(dato, "*");
                                fputs(dato, archivoe);

                                do{
                                    cout<<"E-mail: ";
                                    gets(dato);
                                    strcpy(dato, validar.trim(dato));
                                } while(validar.correo(dato));
                                strcat(dato, "|");
                                fputs(dato, archivoe);
                            }

                            if(caracter == '|')
                                vueltas++;

                        } while(caracter != EOF);
                    }
                    else
                        cout<<"Error al leer el archivo\n";

                    fclose(auxe);
                    fclose(archivoe);

                    if(remove("auxi.txt") != 0)
                        cout<<"Error No. 3\n";
                }

                /////////////////////////////////////////////////

                char* buscar(){
                    char caracter[2], dato[100], concat[2], busca[100];
                    int usuario = 0;
                    bool ban = false;

                    static char regreso[20];

                    memset(dato, '\0', 100);
                    memset(caracter, '\0', 2);
                    memset(regreso, '\0', 20);
                    memset(concat, '\0', 2);

                    FILE *busc = fopen("agenda.txt", "r");

                    gets(busca);
                    cout<<"\n";

                    strcpy(busca, validar.trim(busca));

                    for(int x = 0; x < strlen(busca); x++)
                        busca[x] = tolower(busca[x]);

                    if(busc != NULL){
                        do{
                            caracter[0] = fgetc(busc);

                            if(caracter[0] != '*' && caracter[0] != '|')
                                strcat(dato, caracter);

                            else{
                                for(int x = 0; x < strlen(dato); x++)
                                    dato[x] = tolower(dato[x]);
                                //cout <<dato <<" " <<busca <<endl; system("pause");

                                if(strcmp(busca, dato) == 0){
                                    ban = true;
                                    itoa(usuario, concat, 10);
                                    strcat(regreso, concat);
                                }

                                memset(dato, '\0', 100);

                                if(caracter[0] == '|')
                                    usuario++;
                            }
                        } while(caracter[0] != EOF);
                        fclose(busc);

                        if(ban)
                            return regreso;
                        else{
                            cout<<"Ninguna coincidencia D:\n";
                            return "\0";
                        }
                    }
                    else
                        cout<<"Error al leer el archivo\n";

                    fclose(busc);
                    return "\0";
                }

                /////////////////////////////////////////////////

                void mostrar(char *usuario, bool busca){
                    FILE *archivo;
                    char caracter;
                    int vuelta = 0, indice = 0, compara;
                    bool ban = true, if_indice = true;

                    archivo = fopen("agenda.txt", "r");

                    if(archivo != NULL){
                        compara = usuario[indice] - '0';

                        do{
                            caracter = fgetc(archivo);

                            if(if_indice && vuelta == compara){
                                if_indice = false;
                                cout <<"(" <<indice+1 <<") ";
                            }

                            if(caracter == '*' && busca || caracter == '*' && vuelta == compara)
                                cout<<"\n";
                            else if(caracter == '|' && busca || caracter == '|' && vuelta == compara)
                                cout<<"\n\n";
                            else if(vuelta == compara || busca)
                                cout<<caracter;

                            if(caracter == '|' && vuelta == compara){
                                indice++;
                                compara = usuario[indice] - '0';
                                if_indice = true;
                            }

                            if(caracter == '|')
                                vuelta++;

                        } while(caracter != EOF);
                    }
                    else
                        cout<<"Error al leer el archivo\n";

                    fclose(archivo);
                }

                /////////////////////////////////////////////////

                void ingresar(){
                    FILE *archivo;
                    char dato[50];

                    archivo = fopen("agenda.txt", "a");

                    if(archivo != NULL){

                        do{
                            cout<<"Nombre: ";
                            gets(dato);
                            strcpy(dato, validar.trim(dato));
                        } while( validar.nombre(dato));
                        strcat(dato, "*");
                        fputs(dato, archivo);

                        do{
                            cout<<"Telefono: ";
                            gets(dato);
                            strcpy(dato, validar.trim(dato));
                        } while(validar.telefono(dato));
                        strcat(dato, "*");
                        fputs(dato, archivo);

                        do{
                            cout<<"Direccion: ";
                            gets(dato);
                            strcpy(dato, validar.trim(dato));
                        } while(validar.domicilio(dato));
                        strcat(dato, "*");
                        fputs(dato, archivo);

                        do{
                            cout<<"E-mail: ";
                            gets(dato);
                            strcpy(dato, validar.trim(dato));
                        } while(validar.correo(dato));
                        strcat(dato, "|");
                        fputs(dato, archivo);

                        fclose(archivo);
                    }

                    else
                        cout<<"Error al abrir o crear el archivo\n";
                }

                /////////////////////////////////////////////////

                int menu(){
                    cout<<"Agenda\n";
                    cout<<"\t[1] Ingresar contacto\n";
                    cout<<"\t[2] Mostrar contacto\n";
                    cout<<"\t[3] Buscar contacto\n";
                    cout<<"\t[4] Editar contacto\n";
                    cout<<"\t[5] Eliminar contacto\n";
                    cout<<"\t[Esc] Salir\n";

                    return getch();
                }
