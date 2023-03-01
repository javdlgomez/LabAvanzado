#include <cstdlib>
#include <iostream>

#include "headers/VecR3.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR3
   y se llaman los métodos. */
int main()
{
    VecR3 v1(1,0,1);
    VecR3 v2(0,1,-1);


    cout<<  " v1 = " <<  v1 << endl;

    cout<<  "magnitud de v1: " << v1.Magnitud() << endl;

    VecR3 v3;

    v3 = v1 + v2;

    cout << "v3 = v1 + v2 = " << v3 << endl;

	VecR3 v4;

    v4 = v1 - 2*v2;

    cout << "v4=v1 - 2*v2 = " << v4 << endl;

    cout<< "negacion v1:" << --v1 << endl;

    cout << "multiplicacion" << endl;
    cout << "2*v1 = " << 2*v1 << endl;
    cout << "division" << endl;
    cout << "v1/2 = " << v1/2 << endl;

    cout << "producto int" << endl;
    cout << "v1cdotv2 = " << v1*v2 << endl;

    cout << "producto cruz" << endl;
    cout << "v1crossv2 = " << v1%v2 << endl;


    cout << "comparar vectores" << endl;
    cout << "v1=v2 es " << (v1 == v2) << endl;
    cout << "v1=v1 es " << (v2 == v2) << endl;


    VecR3::Mostar_Spherical(true);
    cout<< "cc esfericas" << endl;
    cout<<  "v1 = " <<  v1 << endl;

    return 0;
}