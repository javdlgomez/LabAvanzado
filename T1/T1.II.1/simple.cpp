/* 
 * simple.cpp: Implementacion de la clase simple
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <iostream>

#include "simple.hpp"

/* El atributo de clase debe ser inicializado como si fuera
 * una variable global. */

int simple::Numero = 0;
/*definimos la nueva variable*/
int simple::ID = 0;

/* Constructor sin argumentos (defecto) */
simple::simple( )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor SIN argumentos" << std::endl;
    /* Se asigna un valor por defecto al atributo Frase */
    Frase = "No hay";
    /* Se incrementa el valor del atributo de clase. */
    Numero++;
}

/* Constructor con argumentos */
simple::simple( std::string La_Frase )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor CON argumento" << std::endl;
    /* Se asigna al atributo Frase el valor del argumento */
    Frase = La_Frase;

    /* Hacemos igual el valor del id al numero*/
    ID = Numero;
    /* Se incrementa el valor del atributo de clase. */
    Numero++;
}

/* Destructor */
simple::~simple()
{
    /* Cada vez que se llame este destructor se mostrara este mensaje. */
    std::cout<< "Soy el destructor" << std::endl;
    /* Se decrementa el valor del atributo de clase. */
    Numero--;
}

/* Implementacion del metodo Decir_Frase: Se llama a traves de las 
 * instancias de la clase */
void simple::Decir_Frase()
{
    std::cout << "La frase es: " << Frase << std::endl;
}

/* Metodo de clase: indica cuantas instancias van de la clase */
void simple::Cuantos()
{
    std::cout << "Van " << Numero << " instancias de simple" << std::endl;
}
/*Metodo de clase que muestra el ID*/
void simple::ShowID(){


    cout << "ID: " << ID << endl;

}