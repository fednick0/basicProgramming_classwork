class{
    public:

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

    bool edad(char* v){

    }

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

}validar;
