#include <iostream> //cout cin
#include <string.h> //strcpy()
#include <stdlib.h> //system()
#include <conio.h> //geth()

using namespace std;

template <class T>
class ArbolBinario;

template <class T>
class NodoArbol{
	private:
		T Info;
		NodoArbol<T> *HijoIzq;
		NodoArbol<T> *HijoDer;

	public:
		NodoArbol(); //constructor
		T RegresaInfo();
		void ActualizaInfo(T);
		friend class ArbolBinario<T>;
}; //fin de la clase

//Constructor por omision. Inicializa las ligas a los
//subdrbotes con et vaLor de NULL, indicando que eston vacias
template <class T>
NodoArbol<T>::NodoArbol(){
	HijoIzq = NULL;
	HijoDer = NULL;
}

//Permite conocer la informacion almacenada en el nodo
template <class  T>
T NodoArbol<T>::RegresaInfo(){
	return Info;
} //finaliza regresaInfo

template<class  T>
void NodoArbol<T>::ActualizaInfo(T Dato){
	Info = Dato;
}  //finaliza ActualizaInfo

//class ArbolBinario
template <class  T>
class ArbolBinario{
	private:
		NodoArbol<T> *Raiz;

	public:
		ArbolBinario();
		NodoArbol<T> *RegresaRaiz();
		void  CrearArbol(NodoArbol<T> *);
		void  ImprimeIzq(NodoArbol<T> *);
}; //finaliza class

//Constructor. Inicializa el puntero a la raiz con el valor NULL, indicado que el arbol
//esta vacio (no tiene nodos)
template <class  T>
ArbolBinario<T>::ArbolBinario(){
	Raiz = NULL;
} //finaLizo constructor

//Regresa Raiz
template <class  T>
NodoArbol<T> *ArbolBinario<T>::RegresaRaiz(){
	return  Raiz;
}

template <class  T>
void ArbolBinario<T>::CrearArbol(NodoArbol <T> *Apunt){
	char resp;

	//Se crea un nodo
	Apunt = new  NodoArbol<T>;
	cout<<"Ingresa el dato a almacenar: ";
	cin>> Apunt->Info;
	cout<<"\n\n\t " <<Apunt->Info <<endl;
	cout<<" Tiene hljo izquierdo (S/N)?  ";
	cin>> resp;
	resp = toupper(resp);
	if(resp == 's'){
        CrearArbol(Apunt->HijoIzq);
        Apunt->HijoIzq = Raiz;
	} //fin del if

    cout<<"\n\n\t " <<Apunt->Info <<endl;
    cout<<" Tlene hijo derecho (S/N)?  ";
    cin>> resp;
    resp = toupper(resp);
    if(resp == 's'){
        CrearArbol(Apunt->HijoDer);
        Apunt->HijoDer = Raiz;
    } //fin del if

    Raiz = Apunt;
} //finaliza CrearArbol

template <class T>
void ArbolBinario<T>::ImprimeIzq(NodoArbol<T> *Apunt){
    if(Apunt){
        if(Apunt->HijoIzq){
            cout<<Apunt->HijoIzq->Info;
            ImprimeIzq(Apunt->HijoIzq);
        }
        ImprimeIzq(Apunt->HijoDer);
    }
}

//Definicidn de la clase Persona
class Persona{
    private:
        char NomPers[100];

    public:
        Persona(); //Constructor
        Persona(char[]);
        friend istream & operator>>(istream &, Persona &);
        friend ostream & operator<<(ostream &, Persona &);
}; //finaliza la class persona

//Constructor
Persona::Persona(){}

//Constructor con parametros
Persona::Persona(char NomP[]){
    strcpy(NomPers, NomP);
} //finaliza el constructor

//Sobrecarga del operador >> para lectura de objetos tipo Persona
istream & operator  >> (istream & Lee, Persona & ObjPers){
    cout<<"\n\n  Ingrese nombre de la persona: ";
    Lee>> ObjPers.NomPers;
    return Lee;
} //Finaliza sobrecarga de operador

//Sobrecarga del operador << para permitir La escritura de objetos tipo Persona
ostream & operator  <<  (ostream  &  Escribe, Persona  &  ObjPers){
    Escribe<<ObjPers.NomPers<<endl;
    return Escribe;
} //Finaliza sobrecarga de operador

int main(){
    ArbolBinario<Persona> Genealogico;
    Persona Individuo;
    NodoArbol<Persona> *Ap;

    Ap = Genealogico.RegresaRaiz();
    Genealogico.CrearArbol(Ap);
    Ap = Genealogico.RegresaRaiz();
    Individuo = Ap->RegresaInfo();

    cout<<"     Descendientes de: ";
    cout<<Individuo<<endl;
    Genealogico.ImprimeIzq(Ap);
    system("pause");
} //main
