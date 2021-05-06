#include <iostream> //cout cin
#include <stdlib.h> //system("")
#include <conio.h> //getch()
#include <string.h> //strcat(,)

using namespace std;

//Funciones que voy a utilizar
void binario(int);
void parimpar(int);

int main(){

    int opc, numb;

    do{ //Ciclo principal
        system("cls");

        cout<<"[1] Binario\n";
        cout<<"[2] Par, Impar\n";
        cout<<"[Esc] Salir\n";

        opc = getch();
        system("cls");

        switch(opc){
        case 49: //Numero entero positivo a binario
            cout<<"Ingrese numero: ";
            cin>> numb;

            if(numb > 0)
                binario(numb); //itoa() lo hace directamente y tambien a octal y hexadecimal
            else
                cout<<"Error, solo enteros positivos";
            break;

        //**********************************************

        case 50: //Par, Impar
            cout<<"Ingrese numero: ";
            cin>> numb;

            if(numb > 0)
                parimpar(numb);
            else
                cout<<"Error, solo enteros positivos";
            break;

        //**********************************************

        case 27:
            cout<<"Saliendo. . .";
            break;

        //**********************************************

        default:
            cout<<"Opcion incorrecta D:";
        }

        cout<<endl;
        system("pause");
    } while(opc != 27);
}

//////////////////////////////////////////////

void parimpar(int numb){ //Funcion para determinar cantidad de par/impar
    char caracter[100]; //Necesito un arreglo de caracteres para su manipulacion
    int par = 0, impar = 0; //Acumuladores

    itoa(numb, caracter, 10); //Convierto int a char[]

    for(int x = 0; x < strlen(caracter); x++){
        int y = caracter[x] - '0'; //Dice internet que asi convierto de char a int

        if(y % 2 == 0) //Si es par...
            par++;
        else //... sino es par, osea, impar
            impar++;
    }

    cout<<"\nCantidad de No. pares: " <<par;
    cout<<"\nCantidad de No. impares: " <<impar;
}

//////////////////////////////////////////////

void binario(int numb){ //Algoritmo Decimal a Binario
    char bina[100]; //Almaceno el binario
    int entre = numb; //Variable para dividir entre dos

    do{ //Parte principal
        if(entre % 2 == 0)
            strcat(bina, "0");
        else
            strcat(bina, "1");

        entre = entre /2;
    } while(entre != 0);

    //Almacena el numero binario inversamente...

    cout<<"\nBinario: ";

    //... por lo que tengo que mostrarlo del final al principio
    for(int x = strlen(bina); x > 0; x--)
        cout<<bina[x];
}
