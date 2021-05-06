#include <iostream> // cout
#include <windows.h> // gotoxy
#include <conio.h> // system
#include <time.h> // seed
#include <stdlib.h> // rand
#include <string.h> // strlen

using namespace std;

void gotoxy(short x, short y) {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y = y;
      SetConsoleCursorPosition(hcon, dwPos);
}

void ahorcado(short);
short categorias();
void mono(short);

///**************************

int main() {
    short opc;

    do {
        system("cls");
        opc = categorias() - 3;
        system("cls");

        if(opc < 5)
            ahorcado(opc);

    } while(opc < 5);
}

///**************************

short categorias() {
    gotoxy(5, 1); cout<<"Menu del dia";
    gotoxy(8, 3); cout<<" Ciudad";
    gotoxy(8, 4); cout<<" Comida";
    gotoxy(8, 5); cout<<" Postres";
    gotoxy(8, 6); cout<<" Animales";
    gotoxy(8, 7); cout<<" Computacion";
    gotoxy(8, 8); cout<<" Salir";

    short flecha;
    short posy = 3;

    do {
        gotoxy(3, posy); cout<<"-->";

        flecha = getch();
        if(flecha == 224)
            flecha =  getch();

        switch(flecha) {
            // enter
            case 13:
                return posy;
                break;

            // arriba
            case 72:
                gotoxy(3, posy); cout<<"   ";
                if(posy > 3)
                    posy--;
                else
                    posy = 8;
                break;

            // abajo
            case 80:
                gotoxy(3, posy); cout<<"   ";
                if(posy < 8)
                    posy++;
                else
                    posy = 3;
                break;
        }
    } while(flecha != 13);
}

///**************************

void mono(short error) {
    switch(error) {
        case 1:
            gotoxy(33, 1); cout<<" ________";
            gotoxy(33, 2); cout<<" |      |";
            gotoxy(33, 3); cout<<" |       ";
            gotoxy(33, 4); cout<<" |       ";
            gotoxy(33, 5); cout<<" |       ";
            gotoxy(33, 6); cout<<" |       ";
            gotoxy(33, 7); cout<<" |       ";
            gotoxy(33, 8); cout<<"/ \\     ";
            break;

        case 2:
            gotoxy(33, 3); cout<<" |      o";
            break;

        case 3:
            gotoxy(33, 4); cout<<" |    /HHH\\";
            break;

        case 4:
            gotoxy(33, 5); cout<<" |      H";
            break;

        case 5:
            gotoxy(33, 6); cout<<" |     / \\";
            break;
    }
}

///**************************

void ahorcado(short cat) {
    char palabra[5][20][50] = {
            {"Venecia", "Sevilla", "Nueva york", "Rio de janeiro", "Londres", "Roma", "Florencia", "Kyoto", "Paris", "Beijing", "Granada", "Atenas", "Lisboa", "Tokio", "Estambul", "Amsterdam", "Berlin", "Lyon", "Viena", "Cuzco"},
            {"Fresa", "Lasagna", "Pizza", "Sandwich", "Lonche", "Manzana", "Broccoli", "Ensalada", "Hotdog", "Hamburguesa", "Pescado", "Camaron", "Carne asada", "Tacos", "Kiwi", "Elote", "Tamal", "Pozole", "Sopa", "Pollo"},
            {"Pastel", "Dona", "Concha", "Negrito", "Gansito", "Chocorroles", "Pay", "Flan", "Jericaya", "Gelatina", "Nieve", "Rosca", "Bugnuelos", "Chocolate", "Galletas", "Paleta", "Muffin", "Macarrones", "Palomitas", "Malteada"},
            {"Gato", "Perro", "Cisne", "Oruga", "Cocodrilo", "Leon", "Jirafa", "Lobo", "Pollo", "Gallina", "Perico", "Tucan", "Tigre", "Pantera", "Zorro", "Pelicano", "Serpiente", "Cangrejo", "Conejo", "Cerdo"},
            {"Cout>>\"\";", "Mouse", "Teclado", "Monitor", "Procesador", "Gabinete", "Motherboard", "Ram", "Disco duro", "Disipador", "Tarjeta de video", "Fuente de poder", "Programacion", "Java", "Compilador", "Software", "Hardware", "Base de datos", "Servidores", "Internet"}
        };

    // Seed
    srand( time(NULL) );

    // Random
    short r = rand() % 20;

    // Trampa maestra
    gotoxy(0, 0); cout<<palabra[cat][r];

    gotoxy(7, 1); cout<<"Juego del ahorcado";

    // Categoria
    gotoxy(2, 4);
    switch(cat) {
        case 0: cout<<"Ciudad:"; break;
        case 1: cout<<"Comida:"; break;
        case 2: cout<<"Postres:"; break;
        case 3: cout<<"Animales:"; break;
        case 4: cout<<"Computacion:"; break;
    }

    // Guiones
    char revelada[50] = "";
    for(short i = 0; i < strlen( palabra[cat][r] ); i++)
        strcat(revelada, "-");
    gotoxy(2, 5); cout<<revelada;

    gotoxy(2, 8); cout<<"Letras usadas:";

    short error = 0;
    char usadas[50] = "";
    char letra[2] = "";
    bool esta;

    do{
        letra[0] = toupper( getch() );
        esta = false;

        for(short i = 0; i < strlen( palabra[cat][r] ); i++) {
            if(letra[0] == toupper( palabra[cat][r][i] )){
                if(i == 0)
                    revelada[i] = letra[0];
                else
                    revelada[i] = tolower( letra[0] );
                esta = true;
            }
        }

        if(esta) {
            gotoxy(2, 5); cout<<revelada;
        }
        else {
            for(short i = 0; i < strlen( usadas ); i++){
                if(tolower( letra[0] ) == usadas[i]) {
                    esta = true;
                    break;
                }
            }
            if(!esta) {
                letra[0] = tolower( letra[0] );
                strcat(usadas, letra);
                gotoxy(2, 9); cout<<usadas;
                error++;
                mono( error );
            }
        }


    } while( strcmp(palabra[cat][r], revelada) && error < 5);

    gotoxy(0, 12);
    if( error < 5 )
        cout<<"GANADOR!!";
    else
        cout<<"PERDEDOR D:";

    gotoxy(0, 13); system("pause");
}
