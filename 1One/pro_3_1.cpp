#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void pro_1(){
    int a, b, acum = 0, temp_a, temp_b;

    cout<<"Introduzca primer numero: "; cin>>a;
    cout<<"Introduzca segundo numero: "; cin>>b;
    cout<<endl;

    if(a > 0 && b > 0){
        if(a > b){
            temp_a = a;
            temp_b = b;
            a = temp_b;
            b = temp_a;
        }

        for(int x = b; x >= a; x--){
            if(x % 5 == 0){
                if(x == b)
                    cout<<"Multiplos de cinco: ";
                cout<< x << ' ';
                acum += x;
            }
        }
        cout<<"\nSuma de multiplos: " << acum;
    }
    else
        cout<<"Error";
}

void pro_2(){
    int dia, mes, ano, tarot, x, n = 0;

    cout<<"Introdusca su fecha de nacimeinto con numeros enteros\n";
    cout<<"Dia: "; cin>>dia;
    cout<<"Mes: "; cin>>mes;
    cout<<"Año: "; cin>>ano;
    cout<<endl;

    if(mes == 1 && dia > 0 && dia <= 31 ||
       ano % 4 == 0 && mes == 2 && dia > 0 && dia <= 29 ||
       mes == 2 && dia > 0 && dia <= 28 ||
       mes == 3 && dia > 0 && dia <= 31 ||
       mes == 4 && dia > 0 && dia <= 30 ||
       mes == 5 && dia > 0 && dia <= 31 ||
       mes == 6 && dia > 0 && dia <= 30 ||
       mes == 7 && dia > 0 && dia <= 31 ||
       mes == 8 && dia > 0 && dia <= 31 ||
       mes == 9 && dia > 0 && dia <= 30 ||
       mes == 10 && dia > 0 && dia <= 31 ||
       mes == 11 && dia > 0 && dia <= 30 ||
       mes == 12 && dia > 0 && dia <= 31){

            tarot = dia + mes + ano;
            x = 0;
            cout<< tarot << " --> ";

            while(tarot > 0){
                n += tarot % 10;
                if(x == 0)
                    cout<<tarot % 10;
                else
                    cout<<" + " << tarot % 10;
                tarot = tarot / 10;
                x++;
            }
            cout<< " = " << n;

            tarot = n;

            if(tarot >= 10){
                x = 0;
                n = 0;
                cout<< endl << tarot << " --> ";
                while(tarot > 0){
                    n += tarot % 10;
                    if(x == 0)
                        cout<<tarot % 10;
                    else
                        cout<<" + " << tarot % 10;
                    tarot = tarot / 10;
                    x++;
                }
                cout<< " = " << n;
            }
            cout<<"\nSu numero del tarot es: " << n;
       }
       else
            cout<<"Fecha introducida no existe D:";
}

void pro_3(){
    double euler = 1, expon, factor;

    cout<<"Introdusca exponente para euler: "; cin>>expon;
    cout<<endl;
    for(int x = 1; x <= 32; x++){
            factor = 1;
        if(x == 1)
            cout<< "e^" << expon << " = 1";
        else{
            for(int y = 1; y <= x - 1; y++)
                factor *= y;
            euler += pow(expon,x - 1) / factor;
            cout<<  " + " << pow(expon,x - 1) << "/" << factor;
        }
    }
    cout<<"\n\n" << euler;
}

main(){
    char sino;
    int program;

    do{
        system("cls");
        cout<<"Que programa desea ejecutar?";
        cout<<"\n1.- Multiplos de 5 y suma de estos";
        cout<<"\n2.- Numero del tarot";
        cout<<"\n3.- e^x";
        cout<<"\n---> "; cin>>program;
        system("cls");

        switch(program){
        case 1:
            pro_1();
            break;
        case 2:
            pro_2();
            break;
        case 3:
            pro_3();
            break;
        default:
            cout<<"Opcion incorrecta";
        }

        cout<<"\n\nDesea reiniciar? s/n\n--->"; cin>>sino;
    } while(sino == 's' || sino == 'S');
}
