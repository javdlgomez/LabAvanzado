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