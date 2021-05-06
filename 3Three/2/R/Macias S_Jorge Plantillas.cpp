/*
    Macias S. Jorge Oswaldo
    06/10/2017

    i. Analiza, pasa y completa el programa: Plantilla de clases.
(Programa 3.7. Pag. 91. Del libro de Estructura de datos orientada a objetos).
    ii. Modifica el programa para que lea los datos de consola, después debe presentar dichos
datos.
    iii. Después deberá pedir los datos para modificar volviendo a ingresar datos y de nuevo
deberá mostrar los nuevos datos.

*/

#include <iostream>
using namespace std;

template <class T1, class T2>
class EjemploPlantilla{
    private:
        T1 Dato1;
        T2 Dato2;

    public:
        EjemploPlantilla();
        EjemploPlantilla(T1, T2);

        void ModificaDato1(T1);
        void ModificaDato2(T2);

        T1 ObtieneDato1();
        T2 ObtieneDato2();

        void ImprimeDatos();
};

//Ojo que aun no entiendo para que funciona el contructor porque
//puedo hacer un class con obj, metodos, atributos y sin contructor, y es funcional.
template <class T1, class T2>
EjemploPlantilla<T1, T2> :: EjemploPlantilla(){ }

template <class T1, class T2>
EjemploPlantilla<T1, T2> :: EjemploPlantilla(T1 D1, T2 D2){
    Dato1 = D1;
    Dato2 = D2;
}

template <class T1, class T2>
void EjemploPlantilla<T1, T2> :: ModificaDato1(T1 NuevoDato){
    Dato1 = NuevoDato;
}

template <class T1, class T2>
void EjemploPlantilla<T1, T2> :: ModificaDato2(T2 NuevoDato){
    Dato2 = NuevoDato;
}

template <class T1, class T2>
T1 EjemploPlantilla<T1, T2> :: ObtieneDato1(){
    return Dato1;
}

template <class T1, class T2>
T2 EjemploPlantilla<T1, T2> :: ObtieneDato2(){
    return Dato2;
}

template <class T1, class T2>
void EjemploPlantilla<T1, T2> :: ImprimeDatos(){
    cout <<"Dato 1: " <<Dato1 <<endl;
    cout <<"Dato 2: " <<Dato2 <<endl;
}

void UsaPlantilla(){

    //Datos que necesito
    int di;
    float df;

    //Pido datos
    cout<<"Ingrese dato int: "; cin>> di;
    cout<<"Ingrese dato float: "; cin>> df;

    //Se definen el tipo de dato para class
    EjemploPlantilla<int, float> ObjPlantilla(di, df); // <--- Envio datos
    ObjPlantilla.ImprimeDatos();

    //Pido nuevos datos
    cout<<"\nModificar\n";
    cout<<"Ingrese dato int: "; cin>> di;
    cout<<"Ingrese dato float: "; cin>> df;

    //Modifico los datos originales
    ObjPlantilla.ModificaDato1(di);
    ObjPlantilla.ModificaDato2(df);

    cout <<"Dato 1 modificado: " <<ObjPlantilla.ObtieneDato1() <<endl;
    cout <<"Dato 2 modificado: " <<ObjPlantilla.ObtieneDato2() <<endl;
}

int main(){UsaPlantilla();} //main() chiquito para que no moleste
