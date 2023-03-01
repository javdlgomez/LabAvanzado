
###### Laboratorio de instrumentación
###### Javier de León Gómez
###### 201603068


# Documentación Tarea 1.II.3


Se nos pide crear la versión 3D de los métodos para la clase de vectores que fue proporcionada por el script en clase y agregar algunas funcionalidades extra como el producto cruz. Para ello se modifica el header y los 2 archivos cpps proporcionados y se muestran los cambios más adelante.


El procedimiento y metodología detrás de estos nuevos métodos es solamente la extensión a 3D de los ya proporcionados se mantiene la misma estructura que el script de clase, para compilar se utilizo un json local por lo cual se combinaron los archivos cpp proporcionados en un main pero los scripts respectivos pueden consultarse por separado.


Código del header:

        /* 
         * VecR3.hpp: Definicion de la clase VecR3
         * 
         * Ejemplo para la parte III del curso introductorio
         * de ROOT.
         * 
         * Hector Perez, abril 2020
         * 
         */

        #ifndef __VECR3_HPP__
        #define __VECR3_HPP__

        #include <iostream>
        #include <string>

        //uso exactamente la misma estructura que el script
        // de ejemplo

        /* Clase VecR3: Vectores en R3. Internamente
         * se representa en forma cartesiana. */ 

        class VecR3
        {
        private:
            /* Coordenada x */
            float Xcor;
            /* Coordenada x */
            float Ycor;
            /* Coordenada z */
            float Zcor;

            /* Atributo de clase: Indica si el despliege del
             * vector serán en coordenas esféricas. */

            //lo voy a poner en ingles
            static bool Spherical;

        public:

            /* Constructor sin argumentos */
            VecR3();
            /* Constructor con argumentos */
            VecR3( float valor_x, float valor_y, float valor_z );


            /* Destructor */
            ~VecR3();

            /* Métodos de asignación (set methods) */

            /* Asigna la coordenada x */
            void Asignar_x( float valor_x );
            /* Asigna la coordenada y */
            void Asignar_y( float valor_y );
            /* Asigna la coordenada z */
          void Asignar_z( float valor_z );
            /* Asigna las coordenadas x, y */
            void Asignar_xyz( float valor_x, float valor_y, float valor_z );


            /* Métodos de obtención (get methods)
             * El calificador constante al final del prototipo
             * indica que estos métodos no van a alterar
             * los valores de la instancia que los llama. */

            /* Obtener la coordenada x */
            float Obtener_x( ) const;
            /* Obtener la coordenada y */
            float Obtener_y( ) const;

          /* Obtener la coordenada */
            float Obtener_z( ) const;

            /* Otros métodos */

            /* Devuelve la magnitud del vector */
            float Magnitud() const;

            /* Sobrecarga de operadores
             * El calificador const en el argumento impide 
             * que el argumento del operador pueda ser modificado
             * dentro del metodo. */

            /* Calcula la suma de dos vectores */
            VecR3 operator+( const VecR3 & ) const;
            /* Calcula resta de dos vectores */
            VecR3 operator-( const VecR3 & ) const;
          /*Calcula negación de vector*/
            VecR3 operator--() const;
            /*Calcula producto punto de dos vectores */
            float operator*( const VecR3 & ) const;
            float operator/( const VecR3 & );


            /* calcula productos de escalar vector*/
            VecR3 operatormulf( float mult);
            VecR3 operatordivf( float mult); 
          /* Calcula producto cruz*/ 
            VecR3 operator%( const VecR3 & ) const;
            /*asignacion*/
            VecR3 operator=( const VecR3 & );
          /*comparacion*/ 
            bool operator==( const VecR3 & ) const; 

            /* Método de clase: Fija el valor del flag para que
             * el despliege del vector sea en esférica (true) o
             * cartesiano (false) */
            static void Mostar_Spherical( bool valor );
            /* Despliega un vector con cout */
            friend std::ostream &operator<<( std::ostream &, const VecR3 & );


            /* Funciones amigas */


            /* multiplcacion con amigas */
            friend VecR3 operator*( const float &, const VecR3 & );
            /*  division con amigas */
            friend VecR3 operator/( const VecR3 &, const float & );

        };

        #endif /* __VECR3_HPP__ */


Código del archivo VecR3 cpp donde definimos todos nuestros métodos:


                  /* 
               * VecR3.cpp: Implementacion de la clase VecR3
               * 
               * Ejemplo para la parte III del curso introductorio
               * de ROOT.
               * 
               * Hector Perez, abril 2020
               * 
               */

              #include <iostream>
              #include <cmath>

              #include "headers/VecR3.hpp"


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


Se omitirá el código en el que se llaman los métodos y se piden la impresión de los mismos ya que se proporciona el archivo del output en consola al realizar la ejecución y mandarlo por medio de >> a un archivo de texto.


Output en consola:


 v1 = ( 1, 0,  1  )
 
 v2 = ( 1, 0, -1 )
 
magnitud de v1: 1.41421

v3 = v1 + v2 = ( 1, 1,  0  )

v4=v1 - 2*v2 = ( 1, -2,  3  )

negacion v1:( -1, -0,  -1  )

multiplicacion

2*v1 = ( 2, 0,  2  )

division

v1/2 = ( 0.5, 0,  0.5  )

producto int

v1cdotv2 = -1

producto cruz

v1crossv2 = ( -1, 1,  1  )

comparar vectores

v1=v2 es 0

v1=v1 es 1

cc esfericas

v1 = ( 1.41421 | 0 | 0.785398)

