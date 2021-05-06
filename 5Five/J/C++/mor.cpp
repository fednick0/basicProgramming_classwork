#include <iostream> //cout
#include <windows.h> //Beep
#include <stdio.h> //gets
#include <conio.h> //getch
#include <string.h> //strlen

#include "rlutil.h" //libreria para color

#define frecuencia 1000 //37-32767
#define d_corta 200 //t
#define d_larga 600 //t*3

#define a ".- "
#define b "-... "
#define c "-.-. "
#define d "-.. "
#define e ". "
#define f "..-. "
#define g "--. "
#define h ".... "
#define i_ ".. "
#define j ".--- "
#define k "-.- "
#define l ".-.. "
#define m "-- "
#define n "-. "
#define o "--- "
#define p ".--. "
#define q "--.- "
#define r ".-. "
#define s "... "
#define t "- "
#define u "..- "
#define v "...- "
#define w ".-- "
#define x "-..- "
#define y "-.-- "
#define z "--.. "

#define m_1 ".---- "
#define m_2 "..--- "
#define m_3 "...-- "
#define m_4 "....- "
#define m_5 "..... "
#define m_6 "-.... "
#define m_7 "--... "
#define m_8 "---.. "
#define m_9 "----. "
#define m_0 "----- "

using namespace std;

int main() {

    char fra[100], morse[100];
    short opc, ascii;
    bool valido;

    do {
        valido = true;
        system("cls");

        cout<<"Codigo Morse" <<endl;
        cout<<"A " <<a <<"\tJ " <<j <<"\tS " <<s <<"\t2 " <<m_2 <<endl;
        cout<<"B " <<b <<"\tK " <<k <<"\tT " <<t <<"\t3 " <<m_3 <<endl;
        cout<<"C " <<c <<"\tL " <<l <<"\tU " <<u <<"\t4 " <<m_4 <<endl;
        cout<<"D " <<d <<"\tM " <<m <<"\tV " <<v <<"\t5 " <<m_5 <<endl;
        cout<<"E " <<e <<"\tN " <<n <<"\tW " <<w <<"\t6 " <<m_6 <<endl;
        cout<<"F " <<f <<"\tO " <<o <<"\tX " <<x <<"\t7 " <<m_7 <<endl;
        cout<<"G " <<g <<"\tP " <<p <<"\tY " <<y <<"\t8 " <<m_8 <<endl;
        cout<<"H " <<h <<"\tQ " <<q <<"\tZ " <<z <<"\t9 " <<m_9 <<endl;
        cout<<"I " <<i_ <<"\tR " <<r <<"\t1 " <<m_1 <<"0 " <<m_0 <<endl;

        cout<<"\nIngrese frase\n--> ";
        gets(fra);

        //A mayusculas todo
        for(short i = 0; i < strlen(fra); i++)
            fra[i] = toupper( fra[i] );

        //Validar solo caracteres validos: A-Z && 0-9 && espacio
        for(short i = 0; i < strlen(fra); i++) {
            ascii = fra[i];

            if(ascii < 32 || ascii > 32 && ascii < 48 || ascii > 57 && ascii < 65 || ascii > 90) {
                valido = false;
                break;
            }
        }

        if(valido) {
            memset(morse, '\0', strlen(morse));

            //Concateno palabra en morse
            for(short i = 0; i < strlen(fra); i++) {
                ascii = fra[i];

                switch(ascii) {
                    case 'A': strcat(morse, a); break;
                    case 'B': strcat(morse, b); break;
                    case 'C': strcat(morse, c); break;
                    case 'D': strcat(morse, d); break;
                    case 'E': strcat(morse, e); break;
                    case 'F': strcat(morse, f); break;
                    case 'G': strcat(morse, g); break;
                    case 'H': strcat(morse, h); break;
                    case 'I': strcat(morse, i_); break;
                    case 'J': strcat(morse, j); break;
                    case 'K': strcat(morse, k); break;
                    case 'L': strcat(morse, l); break;
                    case 'M': strcat(morse, m); break;
                    case 'N': strcat(morse, n); break;
                    case 'O': strcat(morse, o); break;
                    case 'P': strcat(morse, p); break;
                    case 'Q': strcat(morse, q); break;
                    case 'R': strcat(morse, r); break;
                    case 'S': strcat(morse, s); break;
                    case 'T': strcat(morse, t); break;
                    case 'U': strcat(morse, u); break;
                    case 'V': strcat(morse, v); break;
                    case 'W': strcat(morse, w); break;
                    case 'X': strcat(morse, x); break;
                    case 'Y': strcat(morse, y); break;
                    case 'Z': strcat(morse, z); break;

                    case '0': strcat(morse, m_0); break;
                    case '1': strcat(morse, m_1); break;
                    case '2': strcat(morse, m_2); break;
                    case '3': strcat(morse, m_3); break;
                    case '4': strcat(morse, m_4); break;
                    case '5': strcat(morse, m_5); break;
                    case '6': strcat(morse, m_6); break;
                    case '7': strcat(morse, m_7); break;
                    case '8': strcat(morse, m_8); break;
                    case '9': strcat(morse, m_9); break;
                }
            }

            cout<<endl <<morse <<"\r"; //"\r" va al inicio de la linea y sobrescribe

            //Reproduce beep
            for(short i = 0; i < strlen(morse); i++) {
                ascii = morse[i];

                rlutil::setColor(2);

                cout<<morse[i];

                if(ascii == '.') {
                    Beep(frecuencia, d_corta);
                    Sleep(d_corta);
                }
                else if(ascii == '-') {
                    Beep(frecuencia, d_larga);
                    Sleep(d_larga);
                }
                else
                    Sleep(1500);
            }

            system("color 0F");
        }
        else
            cout<<"\nPalabra ingresada no valida D:";

        cout<<"\n\n[Esc] Salir\n[Enter] Repetir\n";
        opc = getch();
    } while(opc != 27);
}
