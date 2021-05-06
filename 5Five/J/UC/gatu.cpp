#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
using namespace std;
void gotoxy(int x, int y) {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y = y;
      SetConsoleCursorPosition(hcon, dwPos);}
short menu();
void palabra();
void numero();
void gato(void);
short gato_pos(short, short);
void gato_setpos(short);
bool gato_wl(short estado[9], short contador);
short gato_f(short estado[9]);
short gato_n(short estado[9]);
short gato_d(short estado[9]);
short gato_select_dificultad();

int main() {
    short opc;

    system("color 03");

    do {
        system("cls");
        opc = menu();
        system("cls");

        switch(opc) {
            case '1':
                gato();
                gotoxy(7, 10);
                system("pause");
                break;

            case '2':
                palabra();
                gotoxy(7, 10);
                system("pause");
                break;

            case '3':
                numero();
                gotoxy(7, 10);
                system("pause");
                break;

            case '4':
                gotoxy(0, 0);
                //cout<<"Saliendo...";
                break;
        }
    } while(opc != '4');
}

///*******************************************************

void palabra() {
    //gotoxy(10, 1); cout<<"Adivinanza";

    // Seed
    srand( time(NULL) );

    short r = rand() % 6;
    string correcta[9], tip[9];

    switch(r) {

        case 0:
            gotoxy(2, 3); cout<<"Es un gran segnoron,";
            gotoxy(2, 4); cout<<"tiene verde sombrero";
            gotoxy(2, 5); cout<<"y pantalon marron.";
            correcta[0] = "arbol";
            tip[0] = "Da frutos";
            break;

        case 1:
            gotoxy(2, 3); cout<<"Con la tomate y con lechuga, que rica";
            gotoxy(2, 4); cout<<"ensalada; puedo ser algo picante y a muchos";
            gotoxy(2, 5); cout<<"hago llorar.";
            correcta[1] = "cebolla";
            tip[1] = "Cuando las cortas hacen llorar";
            break;

        case 2:
            gotoxy(2, 3); cout<<"Quieres te? Pues toma te!";
            gotoxy(2, 4); cout<<"Sabes ya que fruto es?";
            correcta[2] = "tomate";
            tip[2] = "Esta en la adivinanza";
            break;

        case 3:
            gotoxy(2, 3); cout<<"Parecen las persianas de una ventana.";
            correcta[3] = "parpados";
            tip[3] = "Estan en nuestro rostro";
            break;

        case 4:
            gotoxy(2, 3); cout<<"No hay ningun dia del agno en que pueda";
            gotoxy(2, 4); cout<<"descansar; en tu pecho cantando ando, con";
            gotoxy(2, 5); cout<<"mi ritmico tic-tac.";
            correcta[4] = "corazon";
            tip[4] = "Late en nuestro pecho";
            break;

        case 5:
            gotoxy(2, 3); cout<<"Mar te digo y no me entiendes mar te";
            gotoxy(2, 4); cout<<"repito y no me comprendes. Que sera?";
            correcta[5] = "marte";
            tip[5] = "Es un planeta";
            break;
    }

    char resp[100];
    short error = 3;
    short posy = 5;
    gotoxy(8, 7); cout<<"Ingrece: ";
    //gotoxy(50, 1); cout<<"Intentos: 3";
    //gotoxy(80, 4); cout<<"Palabras usadas: ";
    //gotoxy(80, 1); cout<<"Intente teclaer \"tip\"";

    //borrar
    gotoxy(0, 9); cout<<correcta[r];

    do {
        gotoxy(19, 7); gets(resp);

        if( correcta[r] == resp ) {
            gotoxy(7, 9); cout<<"CORRECTO !!";
            break;
        }
        else if( strcmp(resp, "tipooo") == 0) {
            gotoxy(81, 2); cout<<tip[r];
            gotoxy(19, 7); cout<<"                 ";
        }
        else {
            gotoxy(19, 7); cout<<"                 ";
            error--;
            gotoxy(60, 1); cout<<error;
            //gotoxy(81, posy); cout<<resp;
            posy++;
        }

        if(error == 0){
            gotoxy(7, 9); cout<<"Se ha quedado sin intentos";
            //gotoxy(50, 3); cout<<"Palabra correcta: ";
            //gotoxy(51, 4); cout<<correcta[r];
            break;
        }

    } while(true);
}

///*******************************************************

void numero() {
    short mini, maxi, posy;

    //gotoxy(8, 1); cout<<"Minimo < rand() < Maximo";
    //gotoxy(14, 2); cout<<" <   ?    < ";
    gotoxy(9, 2); cout<<"Minimo: "; cin>>mini;
    gotoxy(27, 2); cout<<"Maximo: "; cin>>maxi;

    if (mini < maxi) {
        // Seed
        srand( time(NULL) );

        //imite_inferior + rand() % (limite_superior +1 - limite_inferior)
        short r = mini + rand() % (maxi+1 - mini);

        //borrar
        gotoxy(0, 0); cout<<r;

        gotoxy(40, 1); cout<<"Numero generado!";
        gotoxy(37, 2); cout<<"Intentos restantes: 5";

        gotoxy(8, 4); cout<<"Adivina el numero: ";

        maxi = 5;
        posy = 3;

        do {
            gotoxy(27, 4); cin>>mini;

            if(mini == r) {
                gotoxy(8, 6); cout<<"Has GANADO!!";
                break;
            }
            else if(mini < r) {
                gotoxy(40, posy); cout<<"menor";
                maxi--;
                gotoxy(57, 2); cout<<maxi;
            }
            else if(mini > r) {
                gotoxy(40, posy); cout<<"mayor";
                maxi--;
                gotoxy(57, 2); cout<<maxi;
            }

            if(maxi == 0) {
                gotoxy(8, 6); cout<<"PIERDES !!";
                gotoxy(8, 7); cout<<"numb = " <<r;
                break;
            }

            gotoxy(27, 4); cout<<"         ";

            posy++;
        } while(true);
    }
    else {
        gotoxy(8, 6); cout<<"Rango erroneo";
    }
}

///*******************************************************

short gato_select_dificultad() {
    //gotoxy(0, 0); cout<<" Juego del gato";
    gotoxy(0, 3); cout<<"   |   |   ";
    gotoxy(0, 4); cout<<" --------- ";
    gotoxy(0, 5); cout<<"   |   |   ";
    gotoxy(0, 6); cout<<" --------- ";
    gotoxy(0, 7); cout<<"   |   |   ";

    //gotoxy(15, 2); cout<<"Dificultad:";
    gotoxy(0, 0); cout<<" 1.- Facil";
    gotoxy(0, 1); cout<<" 2.- Normal";
    gotoxy(0, 2); cout<<" 3.- Dificil";

    short r;
    short posy = 3;

    do {
        gotoxy(15, posy); cout<<"   ";

        r = getch();
        if(r == 224)
            r = getch();

        switch(r) {
            // Enter
            case '1':
                return 3;
                break;

            case '2':
                return 4;
                break;

            case '3':
                return 5;
                break;

            // Arriba
            case 72:
                gotoxy(15, posy); cout<<"   ";
                if(posy > 3)
                    posy--;
                else
                    posy = 5;
                break;

            // Abajo
            case 80:
                gotoxy(15, posy); cout<<"   ";
                if(posy < 5)
                    posy++;
                else
                    posy = 3;
                break;
        }
    } while(r != 13);
}

///*******************************************************

short menu() {
    gotoxy(7, 1); cout<<"Menu del dia";
    gotoxy(11, 3); cout<<"1 - Gato";
    gotoxy(11, 4); cout<<"2 - Adivinanza";
    gotoxy(11, 5); cout<<"3 - Numero";
    gotoxy(11, 6); cout<<"4 - Salir";

    short r;
    short posy = 3;

    do {

        gotoxy(8, posy); cout<<"   ";

        r = getch();
        if(r == 224)
            r = getch();

        return r;

        gotoxy(8, posy); cout<<"   ";

        switch(r) {
            // Enter
            case 13:
                //return posy;
                break;

            // Arriba
            case 72:
                if(posy > 3)
                    posy--;
                else
                    posy = 6;
                break;

            // Abajo
            case 80:
                if(posy < 6)
                    posy++;
                else
                    posy = 3;
                break;
        }

    } while(r != 13);
}

///*******************************************************

void gato() {
    short diff = gato_select_dificultad();

    short posx = 1;
    short posy = 3;

    short flecha;
    short contador = 0;

    short estado[9];
    short estado_esp;
    short estado_pos;

    // Inicializo estado
    for(short i = 0; i < 9; i++)
        estado[i] = 0;

    do {
        // Se mueve
        gotoxy(posx, posy); cout<<"X";

        // Compruebo si gana
        if( gato_wl(estado, contador) )
            break;

        // Para manipular flechas
        flecha = getch();
        if(flecha == 224)
            flecha = getch();

        // Determino posicion y estado especifico
        estado_pos = gato_pos(posx, posy);
        estado_esp = estado[estado_pos];

        // Compruebo que caracter poner
        if( estado_esp  == 0 ) {
            gotoxy(posx, posy); cout<<" ";
        } else if( estado_esp == 1 ) {
            gotoxy(posx, posy); cout<<"x";
        } else if( estado_esp == 2 ) {
            gotoxy(posx, posy); cout<<"o";
        }

        switch(flecha) {
            // Enter
            case 13:
                if(estado_esp == 0) {
                    estado[estado_pos] = 1;
                    contador++;

                    // Compruebo si gana
                    if( gato_wl(estado, contador) == 1)
                        break;

                    // Para poner circulo
                    switch(diff) {
                        case 3: estado[ gato_f(estado) ] = 2; break;
                        case 4: estado[ gato_n(estado) ] = 2; break;
                        case 5: estado[ gato_d(estado) ] = 2; break;
                    }
                    cout<<"o";
                    contador++;
                }
                break;

            // Arriba
            case 72:
                if(posy > 3)
                    posy -= 2;
                else
                    posy = 7;
                break;

            // Izquierda
            case 75:
                if(posx > 1)
                    posx -= 4;
                else
                    posx = 9;
                break;

            // Derecha
            case 77:
                if(posx < 9)
                    posx += 4;
                else
                    posx = 1;
                break;

            // Abajo
            case 80:
                if(posy < 7 )
                    posy += 2;
                else
                    posy = 3;
                break;
        }
    } while(flecha != 27);

    gotoxy(0, 10);
}

///*******************************************************

bool gato_wl(short estado[9], short contador) {
    if(contador >= 3) {
        if(estado[0] == 1 && estado[1] == 1 && estado[2] == 1 ||
               estado[3] == 1 && estado[4] == 1 && estado[5] == 1 ||
               estado[6] == 1 && estado[7] == 1 && estado[8] == 1 ||
               estado[0] == 1 && estado[3] == 1 && estado[6] == 1 ||
               estado[1] == 1 && estado[4] == 1 && estado[7] == 1 ||
               estado[2] == 1 && estado[5] == 1 && estado[8] == 1 ||
               estado[0] == 1 && estado[4] == 1 && estado[8] == 1 ||
               estado[2] == 1 && estado[4] == 1 && estado[6] == 1 ) {

            gotoxy(7, 9); cout<<"Ganaste :D";
            return true;
        }
        else if(estado[0] == 2 && estado[1] == 2 && estado[2] == 2 ||
                    estado[3] == 2 && estado[4] == 2 && estado[5] == 2 ||
                    estado[6] == 2 && estado[7] == 2 && estado[8] == 2 ||
                    estado[0] == 2 && estado[3] == 2 && estado[6] == 2 ||
                    estado[1] == 2 && estado[4] == 2 && estado[7] == 2 ||
                    estado[2] == 2 && estado[5] == 2 && estado[8] == 2 ||
                    estado[0] == 2 && estado[4] == 2 && estado[8] == 2 ||
                    estado[2] == 2 && estado[4] == 2 && estado[6] == 2 ) {

            gotoxy(7, 9); cout<<"Perdiste D:";
            return true;
        }
        else if( contador == 9) {
            gotoxy(7, 9); cout<<"Empate";
            return true;
        }
    }
    return false;
}

///*******************************************************

short gato_pos(short x, short y) {
         if( x == 1 && y == 3 ) return 0;
    else if( x == 5 && y == 3 ) return 1;
    else if( x == 9 && y == 3 ) return 2;
    else if( x == 1 && y == 5 ) return 3;
    else if( x == 5 && y == 5 ) return 4;
    else if( x == 9 && y == 5 ) return 5;
    else if( x == 1 && y == 7 ) return 6;
    else if( x == 5 && y == 7 ) return 7;
    else if( x == 9 && y == 7 ) return 8;
}

///*******************************************************

void gato_setpos(short i) {
    switch(i) {
        case 0: gotoxy(1, 3); break;
        case 1: gotoxy(5, 3); break;
        case 2: gotoxy(9, 3); break;
        case 3: gotoxy(1, 5); break;
        case 4: gotoxy(5, 5); break;
        case 5: gotoxy(9, 5); break;
        case 6: gotoxy(1, 7); break;
        case 7: gotoxy(5, 7); break;
        case 8: gotoxy(9, 7); break;
    }
}

///*******************************************************

short gato_f(short estado[9]) {

    for(short i = 0; i < 9; i++) {
        if( estado[i] == 0 ) {

            gato_setpos(i);

            return i;
        }
    }
}

///*******************************************************

short gato_n(short estado[9]) {
    // Seed
    srand( time(NULL) );

    short r;

    do{
        r = rand() % 9;
    } while(estado[r] != 0);

    gato_setpos(r);
    return r;
}

///*******************************************************

short gato_d(short estado[9]) {

    /// Pa ganar
    if(estado[0] == 0 && estado[1] == 2 && estado[2] == 2 ||
            estado[0] == 0 && estado[3] == 2 && estado[6] == 2 ||
            estado[0] == 0 && estado[4] == 2 && estado[8] == 2) {

        gato_setpos(0);
        return 0;
    }
    else if(estado[0] == 2 && estado[1] == 0 && estado[2] == 2 ||
            estado[1] == 0 && estado[4] == 2 && estado[7] == 2) {

        gato_setpos(1);
        return 1;
    }
    else if(estado[0] == 2 && estado[1] == 2 && estado[2] == 0 ||
            estado[2] == 0 && estado[5] == 2 && estado[8] == 2 ||
            estado[2] == 0 && estado[4] == 2 && estado[6] == 2) {

        gato_setpos(2);
        return 2;
    }
    else if(estado[3] == 0 && estado[4] == 2 && estado[5] == 2 ||
            estado[0] == 2 && estado[3] == 0 && estado[6] == 2) {

        gato_setpos(3);
        return 3;
    }
    else if(estado[3] == 2 && estado[4] == 0 && estado[5] == 2 ||
            estado[1] == 2 && estado[4] == 0 && estado[7] == 2 ||
            estado[0] == 2 && estado[4] == 0 && estado[8] == 2 ||
            estado[2] == 2 && estado[4] == 0 && estado[6] == 2) {

        gato_setpos(4);
        return 4;
    }
    else if(estado[3] == 2 && estado[4] == 2 && estado[5] == 0 ||
            estado[2] == 2 && estado[5] == 0 && estado[8] == 2) {

        gato_setpos(5);
        return 5;
    }
    else if(estado[6] == 0 && estado[7] == 2 && estado[8] == 2 ||
            estado[0] == 2 && estado[3] == 2 && estado[6] == 0 ||
            estado[2] == 2 && estado[4] == 2 && estado[6] == 0) {

        gato_setpos(6);
        return 6;
    }
    else if(estado[6] == 2 && estado[7] == 0 && estado[8] == 2 ||
            estado[1] == 2 && estado[4] == 2 && estado[7] == 0) {

        gato_setpos(7);
        return 7;
    }
    else if(estado[6] == 2 && estado[7] == 2 && estado[8] == 0 ||
            estado[2] == 2 && estado[5] == 2 && estado[8] == 0 ||
            estado[0] == 2 && estado[4] == 2 && estado[8] == 0) {

        gato_setpos(8);
        return 8;
    }

    /// Pa no perder
    else if(estado[0] == 0 && estado[1] == 1 && estado[2] == 1 ||
            estado[0] == 0 && estado[3] == 1 && estado[6] == 1 ||
            estado[0] == 0 && estado[4] == 1 && estado[8] == 1) {

        gato_setpos(0);
        return 0;
    }
    else if(estado[0] == 1 && estado[1] == 0 && estado[2] == 1 ||
            estado[1] == 0 && estado[4] == 1 && estado[7] == 1) {

        gato_setpos(1);
        return 1;
    }
    else if(estado[0] == 1 && estado[1] == 1 && estado[2] == 0 ||
            estado[2] == 0 && estado[5] == 1 && estado[8] == 1 ||
            estado[2] == 0 && estado[4] == 1 && estado[6] == 1) {

        gato_setpos(2);
        return 2;
    }
    else if(estado[3] == 0 && estado[4] == 1 && estado[5] == 1 ||
            estado[0] == 1 && estado[3] == 0 && estado[6] == 1) {

        gato_setpos(3);
        return 3;
    }
    else if(estado[3] == 1 && estado[4] == 0 && estado[5] == 1 ||
            estado[1] == 1 && estado[4] == 0 && estado[7] == 1 ||
            estado[0] == 1 && estado[4] == 0 && estado[8] == 1 ||
            estado[2] == 1 && estado[4] == 0 && estado[6] == 1) {

        gato_setpos(4);
        return 4;
    }
    else if(estado[3] == 1 && estado[4] == 1 && estado[5] == 0 ||
            estado[2] == 1 && estado[5] == 0 && estado[8] == 1) {

        gato_setpos(5);
        return 5;
    }
    else if(estado[6] == 0 && estado[7] == 1 && estado[8] == 1 ||
            estado[0] == 1 && estado[3] == 1 && estado[6] == 0 ||
            estado[2] == 1 && estado[4] == 1 && estado[6] == 0) {

        gato_setpos(6);
        return 6;
    }
    else if(estado[6] == 1 && estado[7] == 0 && estado[8] == 1 ||
            estado[1] == 1 && estado[4] == 1 && estado[7] == 0) {

        gato_setpos(7);
        return 7;
    }
    else if(estado[6] == 1 && estado[7] == 1 && estado[8] == 0 ||
            estado[2] == 1 && estado[5] == 1 && estado[8] == 0 ||
            estado[0] == 1 && estado[4] == 1 && estado[8] == 0) {

        gato_setpos(8);
        return 8;
    }

    else
        return gato_n(estado);
}
