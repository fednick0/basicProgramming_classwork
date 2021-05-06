/**
    Equipo
    Luis Ernesto Rivera Leon    0620160081
    Jorge Oswaldo Macias S.     0620160084

    Crea 1 programa en C/C++, en donde apliques la estructura de un ABB realizado en la clase
    anterior, para resolver un problema.
        i. La estructura del nodo debe contener un mínimo de tres campos, es decir la clave y
        otros dos campos de acuerdo con lo que realizará tu aplicación.
        ii. La aplicación para el árbol binario de búsqueda deberá contar con un menú principal:
            1. Ingresar
            2. Dar de baja
            3. Reporte de elementos ordenados por clave
            4. Buscar por clave
            5. Salir
        iii. Debe estar bien validado de acuerdo con los datos que maneje su aplicación
        iv. Recordar que la aplicación es libre albedrio por lo cual no puede haber programas
        iguales.

        12/11/2017 --> Creacion de aplicacion con un arbol el clual realiza 4 operaciones (suma) (resta) (Multiplicaion) y (divicion)
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>

using namespace std;

struct Nodo{
	int campo;
	int clave;
	int num;

	Nodo *izq;
	Nodo *der;
};

Nodo *arbol=NULL;  //inicializamos el arbol

void menu();
void pedirDatos(Nodo *&, int clave, int num, int i);
void mostrar(Nodo *arbol);
void eliminar(Nodo *arbol, int num);
void buscar(Nodo *arbol, int clave, int num);
void buscar2(Nodo *arbol, int clave, int num);
void valida(Nodo *arbol, int num);

int Sban = 0;


void menu(){
	int i = 0;
	int num;
	int opc, opc2;
	int clave;
	int campo;

	cout<<"\n\t *** MENU ***\n"<<endl;
	cout<<"[F1] Ingresar datos"<<endl;
	cout<<"[F2] Mostrar Ordenados"<<endl;
	cout<<"[F3] Dar de baja"<<endl;
	cout<<"[F4] Buscar por calve"<<endl;
	cout<<"[F5] Operaciones"<<endl;
	cout<<"[Esc] Salir"<<endl;
	cout<<" Opcion : ";

	opc = getch();

	if(opc == 0)
		opc = getch();

	switch(opc){
		case 59:
			system("cls");
			cout<<"[F1] INGRESAR DATOS ";
			do{
				cout<<"\n\nCAMPO: [" <<i <<"] ";
				campo = i;
				cout<<"\nIngrse la clave: ";
				cin>>clave;

				cout<<"\nNumero: ";
				cin>> num;

				valida(arbol, num);
				if(Sban == 1)
					menu();
				else
					pedirDatos(arbol, clave, num, i);

				cout<<"\nPrecione 1 para insertar u otro numero para volver al menu: ";
				cin>> opc2;

				if(opc2 == 1)
					i++;

			} while(opc2==1);

			system("cls");
			break;

		case 60:
			system("cls");
			cout<<"[F2] MOSTRAR DATOS ORDENADOS";
			cout<<"Datos Ingresados" <<endl;

			mostrar(arbol);
			getch();

			system("cls");
			break;

		case 61:
			system("cls");
			cout<<"[F3] BAJA / ELIMINAR";
			cout<<"\n\nQue dato desea dar de baja: ";
			cin>> num;

			eliminar(arbol,num);
			system("cls");
			break;

		case 62:
			system("cls");
			cout<<"[F4] Buscar Clave";
			cout<<"\n\nIngrese el Clave y numero a buscar: "<<endl;

			cout<<"CLAVE: ";
			cin>> clave;
			cout<<"NUMERO: ";
			cin>> num;

			system("cls");
			buscar(arbol, clave, num);

			system("cls");
			break;

		case 63:
			system("cls");
			cout<<"[F5] SUMA";
			cout<<"\n\nIngrese el Clave y numero : "<<endl;

			cout<<"CLAVE: ";
			cin>> clave;
			cout<<"NUMERO: ";
			cin>> num;

			system("cls");
			buscar2(arbol, clave, num);

			system("cls");
			break;

		case 27:
		    exit(0);
			break;

		default:
			cout<<"Ingrese dato correcto ";
			Sleep(950);
			system("cls");
			menu();
	}

	system("cls");
	menu();
}

void pedirDatos(Nodo *& arbol, int clave, int num, int i){
	Nodo *nuevo_nodo=new Nodo();

	nuevo_nodo->clave = clave;
	nuevo_nodo->num = num;

	Nodo *aux1 = arbol;
	Nodo* aux2;

	while((aux1 != NULL) && (aux1->clave < clave)){

		aux2 = aux1;   //movemos a aux1 una posicion
		aux1 = aux1->izq;
	}

	if(arbol == aux1)//para saber si el elemento va al principio
        arbol = nuevo_nodo;
	else
		aux2->izq = nuevo_nodo;

	nuevo_nodo->izq=aux1;
    cout<<"\n\nCAMPO: [" <<i <<"] ";
	cout<<"\n\nClave: "<<clave<<" Agregada Correctamente"<<endl;
	cout<<"\nNumero:  "<<num<<" Agregada Correctamente"<<endl;
}

void mostrar(Nodo *arbol){
	Nodo *nuevo_mostrar = new Nodo();  //creamos un nuevo nodo puntero
	nuevo_mostrar = arbol;   // igualamos el nuevo nod a lista

    while(nuevo_mostrar!=NULL){   //recorremos todos los nodos y los imprimimos
        cout<<"\nCLAVE: "<<nuevo_mostrar->clave;
        cout<<"\nNumero: "<<nuevo_mostrar->num;
        cout<<"\n";

        nuevo_mostrar=nuevo_mostrar->izq;
    }

	cout<<"\n FIN";
}

void eliminar(Nodo *arbol, int num){
	if(arbol != NULL){
		Nodo *aux_borrar;   //creamos dos nodos auxiliares
		Nodo *anterior = NULL;
		aux_borrar = arbol;  //igualamos aux_borrar a lista o a la primera posicion

        while(aux_borrar != NULL && aux_borrar->num !=num){    //recorremos
            anterior=aux_borrar;
            aux_borrar = aux_borrar->izq;  //si no esta en el primer elemento del arbol
        }

        if(aux_borrar == NULL){    //si aux_borra recorrio todos los nuemeros y no loe encontro
            cout<<"El dato : "<<num <<" No se encuentra en la lista"<<endl;

            getch();
            system("cls");
            menu();
        }

        else if(anterior == NULL){   //si nuevo nodo es igual a null osea esta en el primer dato aun y ya lo encontro
            arbol = arbol->izq;  //avanzamos una posicion toda la lista

            delete aux_borrar;   //borramos aux_borrar;
            cout<<"\nDato borrado"<<endl;
            getch();
        }

        else{  //si el dato esta e la lista pro no es el primero
            anterior->izq = aux_borrar->izq;   //hacemos avanzar a nevo_nodo una posicion adelante de donde encontro el dato
            delete aux_borrar;  //borramos el dato encontrado
            cout<<"\nDato borrado"<<endl;
            getch();
        }
    }
}

void buscar(Nodo *arbol, int clave, int num){
	bool band = false;  //declaramos una bandera
	Nodo *nuevo_nodo3 = new Nodo();   //cremos un nuevo nodo
	nuevo_nodo3 = arbol;    //igualamos el nuevo nodo al arbol

	while(nuevo_nodo3 != NULL && nuevo_nodo3->clave <= clave){ //cremos el condicional mientras nuevo_nodo3 no sea NULL y uevo_nodo3 ->dato sea igual o menor al dato del ususario entra
		if(nuevo_nodo3->clave==clave)      //este condicion es para saber si esta el dato
			band=true;

		nuevo_nodo3 = nuevo_nodo3->izq;     //si no entra en la primera pasada lo manda a la siguiente posicion
	}

    if(band==true){   //si ban == verdadero imprime el dato
		cout<<"El dato: " <<clave <<" si ha sido encontrado" <<endl;
		cout<<"Numero: " <<num <<endl;
		getch();
	}
	else{ // si no dice que el dato no ha sido encontrado
		cout<<"El dato : " <<clave <<" no ha sido encontrado " <<endl;
		getch();
	}
}


void buscar2(Nodo *arbol, int clave, int num){
	int dato;
	int opc;
	int rep;
	int resu = 0;
	bool band = false;  //declaramos una bandera

	Nodo *nuevo_nodo3 = new Nodo();   //cremos un nuevo nodo
	nuevo_nodo3 = arbol;    //igualamos el nuevo nodo al arbol

	while((nuevo_nodo3 != NULL) && (nuevo_nodo3 ->clave <= clave) && (nuevo_nodo3 ->num<=num )){ //cremos el condicional mientras nuevo_nodo3 no sea NULL y uevo_nodo3 ->dato sea igual o menor al dato del ususario entra
		if(nuevo_nodo3->clave == clave && nuevo_nodo3->num == num)      //este condicion es para saber si esta el dato
			band = true;

		nuevo_nodo3 = nuevo_nodo3->izq;     //si no entra en la primera pasada lo manda a la siguiente posicion
	}

	if(band){   //si ban == verdadero imprime el dato
		cout<<"El dato: " <<clave <<" si ha sido encontrado"<<endl;
		cout<<"Numero: " <<num <<endl;

		do{
            cout<<"\n\n! OPERACIONES !" <<endl;
            cout<<"\n\n1.- SUMA" <<endl;
            cout<<"2.- RESTA" <<endl;
            cout<<"3.- MULTIPLICACION" <<endl;
            cout<<"4.- DIVICION" <<endl;
            cout<<"5.- Menu Principal" <<endl;
            cout<<"Opcion : ";
            cin>>opc;

            switch(opc){
                case 1:
                    system("cls");
                    cout<<"\n[F1] SUMA\n";
                    cout<<"\nEl dato: " <<clave <<" si ha sido encontrado"<<endl;
                    cout<<"\nNumero: " <<num <<endl;
                    cout<<"\nLa ingrese un dato a sumar:";
                    cin>> dato;
                    resu = num + dato;
                    cout<<"La suma es: "<<resu;
                    resu = 0;
                    getch();
                    system("cls");
                    break;

                case 2:
                    system("cls");
                    cout<<"\n[F2] RESTA\n";

                    cout<<"\nEl dato: " <<clave <<" si ha sido encontrado"<<endl;
                    cout<<"\nNumero: " <<num <<endl;

                    cout<<"\nIngrese el dato a restar: ";
                    cin>> dato;

                    resu = num - dato;

                    cout<<"La resta es: "<<resu;
                    resu = 0;
                    getch();

                    system("cls");
                    break;

                case 3:
                    system("cls");
                    cout<<"\n[F3] MULTIPLICACION\n";

                    cout<<"\nEl dato: " <<clave <<" si ha sido encontrado" <<endl;
                    cout<<"\nNumero: " <<num <<endl;

                    cout<<"\nIngrese el dato a Multiplicar: ";
                    cin>> dato;

                    resu = num * dato;

                    cout<<"La multiplicaion es: " <<resu;
                    resu = 0;
                    getch();
                    system("cls");
                    break;

                case 4:
                    system("cls");
                    cout<<"\n[F4] DIVICION\n";

                    cout<<"\nEl dato: " <<clave <<" si ha sido encontrado" <<endl;
                    cout<<"\nNumero : " <<num <<endl;

                    cout<<"\nIngrese el dato a Dividir: ";
                    cin>> dato;

                    resu = num / dato;

                    cout<<"La Divicion es: " <<resu;
                    resu = 0;
                    getch();
                    system("cls");
                    break;

                case 5:
                    cout<<"Regresando al menu Principal....";
                    Sleep(900);
                    menu();
                    break;

                default:
                    cout<<"Ingrese  dato correcto";
                    Sleep(700);
                    system("cls");
                    menu();
            }

            cout<<"\nDesea hacer otra operacion? ";
            cout<<"\n SI = 1 ";
            cout<<"\n NO = 2 ";
            cin>> rep;
            system("cls");

        } while(rep == 1);
	}
	else{    // si no dice que el dato no ha sido encontrado
		cout<<"El dato : "<< clave <<" no ha sido encontrado "<<endl;
		cout<<"Numero : "<< num <<endl;
		getch();
	}
}

void valida(Nodo *arbol,int num){

    if(arbol!=NULL){
		Nodo *aux_borrar;   //creamos dos nodos auxiliares
		Nodo *anterior=NULL;
		aux_borrar = arbol;  //igualamos aux_borrar a arbol

        while(aux_borrar != NULL && aux_borrar->num != num){    //recorremos
            anterior = aux_borrar;
            aux_borrar = aux_borrar->izq;  //si no esta en el primer elemento del arbol
        }

        if(aux_borrar == NULL){    //si aux_borra recorrio todos los nuemeros y no loe encontro
            Sban = 0;
            getch();
        }
        else if(anterior == NULL){   //si nuevo nodo es igual a null osea esta en el primer dato aun y ya lo encontro
            arbol = arbol->izq;  //avanzamos una posicion
            cout<<"\nEl dato ya existe";
            Sban = 1;
            Sleep(800);
            system("cls");
        }
        else{  //si el dato esta pero no es el primero

            //anterior->izq = aux_borrar->izq;   //hacemos avanzar a nevo_nodo una posicion adelante de donde encontro el dato
            cout<<"El dato ya existe";
            //delete aux_borrar;  //borramos el dato encontrado
            Sban = 1;
            Sleep(800);
            system("cls");
        }
    }
}

int main(){	menu(); }



