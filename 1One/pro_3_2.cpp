#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class figuras{
    public:

    float radio, area;

    void area_circulo(){
        cout<<"Ingrese radio: "; cin>>radio;
        area = pow(radio, 2) * 3.14159;
        cout<<"\nArea del circulo: " << area <<endl;
    }

    void perimetro_c(){
        area = pow(3.14159, 2) * radio;
        cout<<"Perimetro del circulo: " << area <<endl;
    }

    void volumen_e(){
        area = (4 * 3.14159 * pow(radio, 3)) / 3;
        cout<<"Volumen de la esfera: " << area <<endl;
    }
};

main(){
    figuras fig_1, fig_2;

    fig_1.area_circulo();
    fig_1.perimetro_c();
    fig_1.volumen_e();

    fig_2.area_circulo();
    fig_2.perimetro_c();
    fig_2.volumen_e();
}
