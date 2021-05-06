#include <string.h>
#include <iostream>
using namespace std;
class{
    public:

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
            : 58
    */

    //*************************************************

    char* trim(char* v){
        short i = 0, f = strlen(v) - 1;

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            if(asc == 32)
                i++;
            else
                break;
        }

        for(short x = f; x >= 0; x--){
            short asc = v[x];

            if(asc == 32)
                f--;
            else
                break;
        }

        static char reg[20];
        char caracter[2];

        memset(reg, '\0', 20);
        memset(caracter, '\0', 2);

        for(short x = i; x <= f; x++){
            caracter[0] = v[x];
            strcat(reg, caracter);
        }

        return reg;
    }

    //*************************************************

    bool nombre(char* v){
        bool error = false;

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            //Solo letras y espacios
            if(asc < 32 || asc > 32 && asc < 65 || asc > 90 && asc < 97 || asc > 122){
                error = true;
                break;
            }
        }

        if(strlen(v) == 0)
            error = true;

        return error;
    }

    //*************************************************

    //bool edad(char* v){

    //}

    //*************************************************

    bool telefono(char* v){
        bool error = false;

        //Solo 8 o 10 caracteres numericos para un telefono
        if(strlen(v) == 10 ||strlen(v) == 8)
            for(short x = 0; x < strlen(v); x++){
                short asc = v[x];

                //Solo numeros
                if(asc < 48 || asc > 57){
                    error = true;
                    break;
                }
            }
        else
            error = true;

        if(strlen(v) == 0)
            error = true;

        return error;
    }

    //*************************************************

    bool domicilio(char* v){
        bool error = false;
        short numb = 0;

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            //Almenos un numero
            if(asc > 47 && asc < 58)
                numb++;

            //Solo letras, espacios, numeros, '.', '-' y '#'
            if(asc < 32 || asc > 32 && asc < 35 || asc > 35 && asc < 45 || asc > 46 && asc < 48 ||
               asc > 57 && asc < 65 || asc > 90 && asc < 97 || asc > 122) {

                error = true;
                break;
            }
        }

        if(strlen(v) == 0 || numb == 0)
            error = true;

        return error;
    }

    //*************************************************

    bool correo(char* v){
        short can_arroba, can_punto_desp, can_des_punto;
        bool punto_despues, error;

        error = false;
        punto_despues = false;
        can_arroba = 0;
        can_punto_desp = 0;
        can_des_punto = 0;

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            //Solo letras, numeros, '_', '.', '-' y '@'
            if(asc < 45 || asc > 46 && asc < 48 || asc > 57 && asc < 64 ||
                asc > 90 && asc < 95 || asc > 95 && asc < 97 || asc > 122){
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

        //Otro tipo de errores
        if(strlen(v) < 6 || can_arroba != 1 || strstr(v, "..") != NULL || strstr(v, "__") != NULL ||
           can_punto_desp < 1 || can_des_punto < 2 || can_des_punto > 4)
           error = true;

        return error;
    }

    //*************************************************

    bool no_track(char* v){

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            //Solo numeros
            if(asc < 48 || asc > 57)
                return true;
        }

        if(strlen(v) == 0 || atoi(v) <= 0 || atoi(v) > 60)
            return true;

        return false;
    }

    //*************************************************

    char* punto_bin(char* v){
        static char reg[20];
        char punto_d[5];
        char c[2];
        bool ban = false;

        memset(reg, '\0', 20);
        memset(punto_d, '\0', 5);
        memset(c, '\0', 2);

        if(strlen(v) >= 4){
            for(short x = strlen(v) - 1; x > strlen(v) - 5; x--){
                c[0] = v[x];
                strcat(punto_d, c);
            }

            if(strcmpi(punto_d, "nib.") != 0 && strcmpi(v, ".bin") != 0){
                strcpy(reg, v);
                strcat(reg, ".bin");
                return reg;
            }
            else{
                strcpy(reg, v);
                return reg;
            }
        }
        else{
            strcpy(reg, v);
            strcat(reg, ".bin");
            return reg;
        }

        strcpy(reg, v);
        return reg;
    }

    //*************************************************

    bool duracion(char* v){
        int dos_puntos = 0;
        char antes[20], despues[20], c[2];

        memset(antes, '\0', 20);
        memset(despues, '\0', 20);
        memset(c, '\0', 2);

        for(short x = 0; x < strlen(v); x++){
            short asc = v[x];

            //Solo numeros y ':'
            if(asc < 48 || asc > 58)
                return true;

            if(asc == 58)
                dos_puntos++;

            else if(dos_puntos == 0){
                c[0] = v[x];
                strcat(antes, c);
            }
            else{
                c[0] = v[x];
                strcat(despues, c);
            }

            if(strlen(antes) > 3 || strlen(despues) > 2)
                return true;
        }

        if(strlen(v) == 0 || strstr(v, "::") != NULL || dos_puntos > 1 || dos_puntos == 0 || strlen(antes) == 0
           || strlen(despues) == 0 || strlen(despues) > 2 || strlen(v) > 6)
            return true;

        return false;
    }

}validar;
