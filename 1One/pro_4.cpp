#include <iostream>
#include <stdlib.h>

using namespace std;

void zodiaco(){

    int dia, mes;

    cout<<"Ingrese con numeros enteros lo que se le pide"<<endl;
    cout<<"Dia: "; cin>>dia;
    cout<<"Mes: "; cin>>mes;

    switch (mes){

			case 1:
				if(dia >= 1 && dia <= 19)
					cout<<"Capricornio";
				else if(dia >=20 && dia <= 31)
					cout<<"Acuario";
				else
					cout<<"Dia no existe";
				break;

			case 2:
				if(dia >= 1 && dia <= 18)
					cout<<"Acuario";
				else if(dia >=19 && dia <= 29)
					cout<<"Piscis";
				else
					cout<<"Dia no existe";
				break;

			case 3:
				if(dia >= 1 && dia <= 20)
					cout<<"Piscis";
				else if(dia >=21 && dia <= 31)
					cout<<"Aries";
				else
					cout<<"Dia no existe";
				break;

			case 4:
				if(dia >= 1 && dia <= 19)
					cout<<"Aries";
				else if(dia >= 20 && dia <= 30)
					cout<<"Tauro";
				else
					cout<<"Dia no existe";
				break;

			case 5:
				if(dia >= 1 && dia <= 20)
					cout<<"Tauro";
				else if(dia >= 21 && dia <= 31)
					cout<<"Geminis";
				else
					cout<<"Dia no existe";
				break;

			case 6:
				if(dia >= 1 && dia <= 20)
					cout<<"Geminis";
				else if(dia >= 21 && dia <= 30)
					cout<<"Cancer";
				else
					cout<<"Dia no existe";
				break;

			case 7:
				if(dia >= 1 && dia <= 22)
					cout<<"Cancer";
				else if(dia >= 23 && dia <= 31)
					cout<<"Leo";
				else
					cout<<"Dia no existe";
				break;

			case 8:
				if(dia >= 1 && dia <= 22)
					cout<<"Leo";
				else if(dia >= 23 && dia <= 31)
					cout<<"Virgo";
				else
					cout<<"Dia no existe";
				break;

			case 9:
				if(dia >= 1 && dia <= 22)
					cout<<"Virgo";
				else if(dia >= 23 && dia <= 30)
					cout<<"Libra";
				else
					cout<<"Dia no existe";
				break;

			case 10:
				if(dia >= 1 && dia <= 22)
					cout<<"Libra";
				else if(dia >= 23 && dia <= 31)
					cout<<"Escorpio";
				else
					cout<<"Dia no existe";
				break;

			case 11:
				if(dia >= 1 && dia <= 21)
					cout<<"Escorpio";
				else if(dia >= 22 && dia <= 30)
					cout<<"Sagitario";
				else
					cout<<"Dia no existe";
				break;

			case 12:
				if(dia >= 1 && dia <= 21)
					cout<<"Sagitario";
				else if(dia >= 22 && dia <= 31)
					cout<<"Capricornio";
				else
					cout<<"Dia no existe";
				break;

			default:
				cout<<"Mes no existe";
		} //switch
		cout<<endl;
}

int main(){

   char rei;
   do {
        system("cls");
        zodiaco();
        cout<<"\nDesea reiniciar? S/N\n--->"; cin>>rei;
   } while(rei == 's' || rei == 'S');
} //main
