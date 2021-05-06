#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

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

}x;

int main(){

    char pala[20] = "   hola   ";

    cout <<strlen( x.trim(pala) )<< " funciona";

}
