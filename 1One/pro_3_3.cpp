#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int opc1, opc2;
string fig;

class cuadrado{
private:
    float dato_1, dato_2, resultado;

public:

    float area_cua(float dato_1, float dato_2){
        resultado = dato_1 * dato_2;
        return resultado;
    }

    float perimetro_cua(float dato_1, float dato_2){
        resultado = dato_1 * 4;
        return resultado;
    }

    float area_tri(float dato_1, float dato_2){
        resultado = (dato_1 * dato_2) / 2;
        return resultado;
    }

    float perimetro_tri(float dato_1, float dato_2){
        resultado = dato_1 * 3;
        return resultado;
    }

    float area_cil(float dato_1, float dato_2){
        resultado = 2 * 3.14159 * dato_1 * (dato_2 + dato_1);
        return resultado;
    }
    float perimetro_cil(float dato_1, float dato_2){
        resultado = 3.14159 * pow(dato_1, 2) * dato_2;
        return resultado;
    }

    float area_pir(float dato_1, float dato_2){
        resultado = dato_1 * (2 * dato_2 * dato_1);
        return resultado;
    }
    float perimetro_pir(float dato_1, float dato_2){
        resultado = (pow(dato_1, 2) * dato_2) / 3;
        return resultado;
    }
}obj;

void submenu(){
    do{
        system("cls");
        cout<<"Menu " <<fig <<endl;
        cout<<"1.- Area\n";
        if(opc1 == 1 || opc1 == 2)
            cout<<"2.- Perimetro\n";
        else
            cout<<"2.- Volumen\n";
        cout<<"3.- Volver al menu principal\n4.- Salir\n";
        cout<<"\nIngrese opcion: "; cin>>opc2;
        system("cls");

        float dat1, dat2;

        if(opc2 != 4 && opc2 != 3){
            cout<<"Ingrese primer dato: "; cin>> dat1;
            cout<<"Ingrese alto segundo dato: "; cin>> dat2;
        }

        if(opc2 == 4){
            opc1 = 5;
            cout<<"Saliendo...";
        }
        else if(opc1 == 1 && opc2 == 1)
            cout<< obj.area_cua(dat1, dat2);
        else if(opc1 == 1 && opc2 == 2)
            cout<< obj.perimetro_cua(dat1, dat2);
        else if(opc1 == 2 && opc2 == 1)
            cout<< obj.area_tri(dat1, dat2);
        else if(opc1 == 2 && opc2 == 2)
            cout<< obj.perimetro_tri(dat1, dat2);
        else if(opc1 == 3 && opc2 == 1)
            cout<< obj.area_cil(dat1, dat2);
        else if(opc1 == 3 && opc2 == 2)
            cout<< obj.perimetro_cil(dat1, dat2);
        else if(opc1 == 4 && opc2 == 1)
            cout<< obj.area_pir(dat1, dat2);
        else if(opc1 == 4 && opc2 == 2)
            cout<< obj.perimetro_pir(dat1, dat2);
        else if(opc2 == 3)
            cout<<"Regresando al menu principal";
        else
            cout<<"Opcion erronea D:";

        cout<<endl;
        system("pause");

    } while(opc2 != 3 && opc2 != 4);
}

main(){
    do{
        system("cls");
        cout<<"Menu figuras: \n";
        cout<<"1.- Cuadrado\n2.- Triangulo\n";
        cout<<"3.- Cilindro\n4.- Piramide\n";
        cout<<"5.- Salir";
        cout<<"\nIngrese opcion: ";
        cin>>opc1;
        switch(opc1){
        case 1:
            fig = "cuadrado";
            submenu();
            break;

        case 2:
            fig = "triangulo";
            submenu();
            break;

        case 3:
            fig = "cilindro";
            submenu();
            break;

        case 4:
            fig = "piramide";
            submenu();
            break;

        case 5:
            //nada
            break;

        default:
            cout<<"\nOpcion erronea D:\n";
            system("pause");
        } //switch
    } while(opc1 != 5);
} //main
