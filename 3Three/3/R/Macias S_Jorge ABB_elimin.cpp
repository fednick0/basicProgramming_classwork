/**
    Macias S Jorge Oswaldo
    31/10/2017

    El programa de Arboles binarios de búsqueda, deberá:
        a. Dar de alta un árbol
        b. Consultar el árbol
            i. La impresión puede ser libre albedrio
            ii. O colocando la raíz, después los hijos izquierdos, hijos derechos
        c. Eliminar un nodo.
*/

//Maestra, hay muchas cosas que no entiendo, son algoritmo sacado de internet
//y muchos de los comentarios que pongo es posible que me equivoque
//tambien es posible que contenga errores, lo probe muy superficialmente
//Y cuando muestra, no logre que mostrara como el programa anterior, ahora solo muestra en recorrido de profundidad

#include <iostream> //cout<<
#include <stdlib.h> //system()
#include <conio.h> //getch()

using namespace std;

//class principal
class ArbolABB{
    private:

    //class donde se declara los atributos izquierdo y derecho
    class Nodo {
        public:
        Nodo(const int dat, Nodo *izq = NULL, Nodo *der = NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}

        int dato;
        Nodo *izquierdo;
        Nodo *derecho;
    };

    Nodo *raiz;
    Nodo *actual;
    int contador;
    int altura;

    //Declaracion de todo los metodos
    public:
    ArbolABB() : raiz(NULL), actual(NULL) {}
    ~ArbolABB() { Podar(raiz); }
    void Insertar(const int dat);
    void Borrar(const int dat);
    bool Buscar(const int dat);
    bool Vacio(Nodo *r) { return r==NULL; }
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(const int dat);
    int &ValorActual() { return actual->dato; }
    void Raiz() { actual = raiz; }
    void InOrden(void (*func)(int&) , Nodo *nodo = NULL, bool r = true);
    void PreOrden(void (*func)(int&) , Nodo *nodo = NULL, bool r = true);
    void PostOrden(void (*func)(int&) , Nodo *nodo = NULL, bool r = true);

    private:
    void Podar(Nodo* &);
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
};

//borra nodos, pero no es la funcion de borrar
void ArbolABB::Podar(Nodo* &nodo){
   if(nodo){
      Podar(nodo->izquierdo);
      Podar(nodo->derecho);
      delete nodo;
      nodo = NULL;
   }
}

//Inserta nodos
void ArbolABB::Insertar(const int dat){
    Nodo *padre = NULL;

    actual = raiz;
    while(!Vacio(actual) && dat != actual->dato) {
        padre = actual;
        if(dat > actual->dato)
            actual = actual->derecho;
        else if(dat < actual->dato)
            actual = actual->izquierdo;
    }

    if(!Vacio(actual))
        return;

    if(Vacio(padre))
        raiz = new Nodo(dat);
    else if(dat < padre->dato)
        padre->izquierdo = new Nodo(dat);
    else if(dat > padre->dato)
        padre->derecho = new Nodo(dat);
}

//Esta es la funcion de borrar
void ArbolABB::Borrar(const int dat){
    Nodo *padre = NULL;
    Nodo *nodo;
    int aux;

    actual = raiz;
    while(!Vacio(actual)) {
        if(dat == actual->dato) {
            if(EsHoja(actual)) {
                if(padre)
                    if(padre->derecho == actual)
                        padre->derecho = NULL;
                    else if(padre->izquierdo == actual)
                        padre->izquierdo = NULL;
                delete actual;
                actual = NULL;
                return;
            }
            else {
                padre = actual;
                if(actual->derecho){
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                else{
                    nodo = actual->izquierdo;
                    while(nodo->derecho){
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }

                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else{
            padre = actual;
            if(dat > actual->dato)
                actual = actual->derecho;
            else if(dat < actual->dato)
                actual = actual->izquierdo;
        }
    }
}

//Inorden
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r){
    if(r)
        nodo = raiz;

    if(nodo->izquierdo)
        InOrden(func, nodo->izquierdo, false);

    func(nodo->dato);

    if(nodo->derecho)
        InOrden(func, nodo->derecho, false);
}

//Preorden
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r){
    if(r)
        nodo = raiz;

    func(nodo->dato);

    if(nodo->izquierdo)
        PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho)
        PreOrden(func, nodo->derecho, false);
}

//Postorden
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r){
    if(r)
        nodo = raiz;

    if(nodo->izquierdo)
        PostOrden(func, nodo->izquierdo, false);

    if(nodo->derecho)
        PostOrden(func, nodo->derecho, false);

    func(nodo->dato);
}

//busca, retorna true si existe nodo
bool ArbolABB::Buscar(const int dat){
    actual = raiz;

    while(!Vacio(actual)) {
        if(dat == actual->dato)
            return true;
        else if(dat > actual->dato)
            actual = actual->derecho;
        else if(dat < actual->dato)
            actual = actual->izquierdo;
    }
    return false;
}

//Determina la altura de un nodo
int ArbolABB::Altura(const int dat){
    int altura = 0;
    actual = raiz;

    while(!Vacio(actual)){
        if(dat == actual->dato)
            return altura;
        else{
            altura++;
            if(dat > actual->dato)
                actual = actual->derecho;
            else if(dat < actual->dato)
                actual = actual->izquierdo;
        }
    }

    return -1;
}

//Determina la cantidad de nodos en el ABB
const int ArbolABB::NumeroNodos(){
    contador = 0;

    auxContador(raiz);
    return contador;
}

//Contador auxiliar para determinar la altura de un nodo
void ArbolABB::auxContador(Nodo *nodo){
    contador++;

    if(nodo->izquierdo)
        auxContador(nodo->izquierdo);

    if(nodo->derecho)
        auxContador(nodo->derecho);
}

//Determina la altura de todo un arbol
const int ArbolABB::AlturaArbol(){
    altura = 0;

    auxAltura(raiz, 0);
    return altura;
}

//Metodo auxiliar para determinar la altura de un arbol
void ArbolABB::auxAltura(Nodo *nodo, int a){
    if(nodo->izquierdo)
        auxAltura(nodo->izquierdo, a+1);

    if(nodo->derecho)
        auxAltura(nodo->derecho, a+1);

    if(EsHoja(nodo) && a > altura)
        altura = a;
}

//Muestra
void Mostrar(int &d){
   cout << d << ",";
}

//main()
int main(){
    //obj pra ArbolABB
    ArbolABB ArbolInt;

    int opc, n;

    do{
        system("cls");
        cout<<"[1] Insertar nodo\n";
        cout<<"[2] Mostrar arbol\n";
        cout<<"[3] Eliminar nodo\n";
        cout<<"[4] Otros deatos del arbol\n";
        cout<<"[Esc] Salir\n";

        opc = getch();

        switch(opc){
        case '1':
            do{
                system("cls");
                cout<<"Ingrese numero: ";
                cin>> n;

                ArbolInt.Insertar(n);

                cout<<"\n\nDesea ingresar otro? s/n\n--> ";
            } while(getch() == 's');
            break;

        case '2':
            system("cls");
            cout<<"Inorden: ";
            ArbolInt.InOrden(Mostrar);
            cout<<"\nPreOrden: ";
            ArbolInt.PreOrden(Mostrar);
            cout<<"\nPostOrden: ";
            ArbolInt.PostOrden(Mostrar);

            cout<<"\n\n";
            system("pause");
            break;

        case '3':
            system("cls");
            cout<<"Nodo a borrar: ";
            cin>> n;

            ArbolInt.Borrar(n);

            cout<<"\n\nNodo borrado\n";
            system("pause");
            break;

        case '4':
            system("cls");
            cout<<"Altura de arbol: " <<ArbolInt.AlturaArbol();
            cout<<"\nNumero de nodos: " <<ArbolInt.NumeroNodos();

            //Ojo que tambien se pude saber la altura de un nodo
            //ArbolInt.Altura(n) << endl;

            cout<<"\n\n";
            system("pause");
            break;

        case 27:
            cout<<"\n\nSaliendo . . .";
            break;

        default:
            cout<<"\n\nOpcion incorrecta . . .\n";
            system("pause");
        }
    } while(opc != 27);
}
