







#include <cstdlib>
#include <iostream>
#include <cmath>

#include "headers/VecR3.hpp"

using namespace std;

// En 3D tienen que ser esfericas


bool VecR3::Spherical = false;

//Para el resto de metodos vamos a utilizar
//la misma estrctura que el ejemplo


// Asignamos una coordenada extra 
VecR3::VecR3( )
{
    Xcor = 0;
    Ycor = 0;
	Zcor = 0;
}
VecR3::VecR3( float valor_x, float valor_y, float valor_z )
{
    Xcor = valor_x;
    Ycor = valor_y;
	Zcor = valor_z;
}

VecR3::~VecR3(){}

void VecR3::Asignar_x( float valor_x ){
    Xcor = valor_x;
}

void VecR3::Asignar_y( float valor_y ){
    Ycor = valor_y;
}

void VecR3::Asignar_z( float valor_z ){
    Zcor = valor_z;
}

void VecR3::Asignar_xyz( float valor_x, float valor_y, float valor_z ){
    Xcor = valor_x;
    Ycor = valor_y;
    Zcor = valor_z;
}

float VecR3::Obtener_x( ) const{
    return Xcor;
}

float VecR3::Obtener_y( ) const{
    return Ycor;
}

float VecR3::Obtener_z( ) const{
    return Zcor;
}

float VecR3::Magnitud() const{
    return std::sqrt( Xcor*Xcor + Ycor*Ycor + Zcor*Zcor);
}

/* Sobrecarga de operadores */

//Vamos a ir en el orden de la lista de la tarea

/* Calcula la suma de dos vectores */

VecR3 VecR3::operator+( const VecR3 &avec) const{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR3 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a él por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se está dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;
	tmp.Zcor = this->Zcor + avec.Zcor;

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Calcula la resta de dos vectores */

VecR3 VecR3::operator-( const VecR3 &avec) const{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR3 tmp;
    /* Uno de los vectores a resta es el que llama el operador,
     * por lo que se accede a él por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se está dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor - avec.Xcor;
    tmp.Ycor = this->Ycor - avec.Ycor;
	tmp.Zcor = this->Zcor - avec.Zcor;

    /* Se devuelve resta de vectores */
    return tmp;
}

/* Calcula la negacion de vector */

VecR3 VecR3::operator--() const {  
    return VecR3(-Xcor, -Ycor, -Zcor);
}


/* Calcula el producto punto de dos tres vectores */

float VecR3::operator*( const VecR3 &avec ) const{
   /* Ver los comentarios de operator+ */
    float tmp;
    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor + this->Zcor * avec.Zcor;
    return tmp;
}

/* Calcula el producto vector y flotante */

//esto es directo pero debemos agregar el flotante por el que multiplicamos
VecR3 VecR3::operatormulf( float mult)  {  
    return VecR3(mult*Xcor, mult*Ycor, mult*Zcor);
}

/* Calcula la division vector y flotante */
//esto es directo pero debemos agregar el flotante por el que dividimos
//esta funcion no protege si el usuario coloca 0

VecR3 VecR3::operatordivf( float mult)  {  
    return VecR3(Xcor/mult, Ycor/mult, Zcor/mult);
}


/* Calcula el producto cruz de dos tres vectores */
//cuidado con las componentes, la de Y debe estar cruzada

VecR3 VecR3::operator%( const VecR3 &avec ) const{
    /* Ver los comentarios de operator+ */
    VecR3 tmp;
    tmp.Xcor = this->Ycor * avec.Zcor - this->Zcor * avec.Ycor;
	tmp.Ycor = this->Zcor * avec.Xcor - this->Xcor * avec.Zcor;
	tmp.Zcor = this->Xcor * avec.Ycor - this->Ycor * avec.Xcor;

    return tmp;
}

/* Operador de asignacion */
VecR3 VecR3::operator=( const VecR3 &avec){
    /* El vector que llama el operador es el que 
     * esta al lado izquierdo de este, y el que
     * esta al lado derecho se pasa como argumento
     * por lo que a "this" se le debe asignar el 
     * valor del argumento */
    this->Xcor = avec.Xcor;
    this->Ycor = avec.Ycor;
	this->Zcor = avec.Zcor;

    return (*this);
}

/* Operador de comparacion */
//tira true o false si es igual el vector completo

bool VecR3::operator==(const VecR3 &avec)const{
    if  ((this->Xcor == avec.Xcor) && (this->Ycor == avec.Ycor) && 
(this->Zcor == avec.Zcor)){
    return 1;
    }

    return 0;
}

/* Metodo de clase: Fija el valor del flag para que
 * el despliege del vector sea en esferico (true) o
 * cartesiano (false) */
void VecR3::Mostar_Spherical( bool valor ){
    Spherical = valor;
}
/* Funciones amigas. 
 * Estas funciones fueron declarada como amigas (friend) en la 
 * definicion de la clase. Las funciones amigas no son metodos 
 * de los objetos, pero pueden acceder a los atributos privados de
 * estos.*/

/* Despliega un vector con cout */

std::ostream &operator<<( std::ostream &salida, const VecR3 &avec ){

     /*Se decide el tipo de salida en función del valor del atributo de clase esferica*/

    if( VecR3::Spherical )
    {
         /*Se calcula calculan los valores azimutales y angulares obteniendolas de las 
         formulas ya conocidas y las variables necesarias se calculan con nuestros
         metodos ya implementados */

        float phi = std::acos( avec.Zcor/avec.Magnitud());

        //el 2 es para los signos, podemos usar tambien
        //atan2f pero lo dejo asi por cualquier cosa

        float theta = std::atan2( avec.Ycor,avec.Xcor);

        // vector = (rho, theta, phi)
        //estamos usando phi como azimutal esto es importante de tener en cuenta
       
        salida << "( "<< avec.Magnitud()<<" | "<<theta<<" | "<<phi<<")";
    }

    //utilizamos else para solo necesitar 1 variable de regreso

    else
        salida << "( " << avec.Xcor << ", " << avec.Ycor << ",  " << avec.Zcor << "  )";
    
    return salida;
}

/* Esta funcion sobrecarga el operador* para permitir
 * la multiplicacion de un escalar por un vector
 * de la forma aesc*avec. Es importante hacer notar
 * que el orden de la multiplicacion NO ES CONMUTATIVO,
 * es decir, esta funcion no es llamada si el orden
 * escalar * vector es invertido. */
 VecR3 operator*( const float &aesc, const VecR3 &avec ){
    VecR3 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;
	tmp.Zcor = aesc*avec.Zcor;

    return tmp;
 } 

//iguql hacemos la amiga que divide solo que permutamos el orden para que quede facil
//de escribir los argumentos ya que no conmutan

 VecR3 operator/( const VecR3 &avec, const float &aesc){
    VecR3 tmp;
    tmp.Xcor = avec.Xcor/aesc;
    tmp.Ycor = avec.Ycor/aesc;
	tmp.Zcor = avec.Zcor/aesc;

    return tmp;
 }













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