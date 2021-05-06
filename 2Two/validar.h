#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class{
public:

    char *muestra(char a[]){

        char* l = NULL;
        l = a;
        return l;
    }

    int entero(){
        char comprobar[20];
        short ascii;
        bool error;

        do{
            error = false;

            gets(comprobar);

            for(short x = 0; x < strlen(comprobar); x++){
                ascii = comprobar[x];
                if(ascii < 48 || ascii > 57){
                    error = true;
                    break;
                }
            }

            if(error || strlen(comprobar) == 0){
                cout<<"Introduzca dato valido: ";
                error = true;
            }

        } while(error);
        return atoi(comprobar);
    }

}ob;
