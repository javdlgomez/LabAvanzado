/* 
 * persona.cpp: Imprementacion de la clase persona.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <iostream>
#include "persona.hpp"

/* Inicializacion del atributo de clase. En este
 * caso solo la declaracion es necesaria ya que
 * la inicializacion propiamente la hace el 
 * constructor de la clase vector. */

std::vector< persona* > persona::instancias;

/* Constructor por defecto */
persona::persona( )
{
    /* Coloca todos los punteros a cero para
     * indicar que no estan asignados */
    Nombre              = 0;
    Fecha_nacimiento    = 0;
    Lugar_nacimiento    = 0;
    DPI                 = 0;
    Anio = 0;
    Dia = 0;
    Mes = 0;
    

    /* Cada instancia de clase tiene un puntero
     * que apunta a ella misma llamado "this".
     * Aqui se aniade al vector de punteros instancias
     * la direccion de la clase que se esta creando
     * por la llamada de este constructor. */
    instancias.push_back(this);

}

/* Constructor con argumentos */
persona::persona( std::string    El_Nombre,
                  int            Anio_Nacimiento,
                  int            Mes_Nacimiento,
                  int            Dia_Nacimiento,
                  std::string    Lugar_Origen
            )
{
    /* Se asignan los valores de los argumentos a los
     * atributos respectivos */
    Nombre              = new std::string( El_Nombre );
    Lugar_nacimiento    = new std::string( Lugar_Origen );
    /* El DPI no figura entre los argumentos, por lo
     * que el puntero se asigna a cero para indicar
     * que no esta asignado */
    DPI                 = 0;


    /* El atributo "Fecha_nacimiento" es un puntero
     * a una estructura de tiempo tm de C. Aqui se asignan
     * los datos proporcionados a la estructura. */
    Fecha_nacimiento = new std::tm;
    Fecha_nacimiento->tm_year = Anio_Nacimiento - 1900;
    Fecha_nacimiento->tm_mon = Mes_Nacimiento - 1;
    Fecha_nacimiento->tm_mday = Dia_Nacimiento;
    /* Los campos que fijan la hora deben asignarse ya que 
     * son parte de la presicion con que se almacena el 
     * tiempo internamente. Recordar que internamente
     * el tiempo se almacena con un solo numero y este se
     * calcula a partir de todos los campos proporcionados. */
    Fecha_nacimiento->tm_sec = 0;
    Fecha_nacimiento->tm_min = 0;
    Fecha_nacimiento->tm_hour = 0;
    

    /* Se aniade la direccion de la instancia que esta
     * siendo creada al vector de punteros instancias. */
    instancias.push_back(this);

}

/* Destructor */
persona::~persona()
{
    /* Se remueve del vector de punteros instancias la direccion
     * de la instancia que esta siendo eliminada. Notese
     * el uso del iterador de la clase vector. */
    for( auto n = instancias.begin(); n != instancias.end(); n++ )
        if( *n == this )
        {
            instancias.erase( n );
            break;
        }
    
    delete Nombre;
    delete Fecha_nacimiento;
    delete Lugar_nacimiento;
    delete DPI;
}

/* Metodo para asignar el DPI (set method)
 * devuelve 0 si se realiza la asignacion;
 * 1 si no. */
int persona::Asignar_DPI( std::string Num_CUI )
{
    if( !DPI )
    {
        DPI = new std::string( Num_CUI );
        return 0;
    }
    
    std::cout << "El DPI ya fue asignado" << std::endl;
    return 1;
}


/* Metodo para obtener el DPI a una persona (get method)
 * devuelve un string con el numero de DPI */
std::string persona::Obtener_DPI( )
{
    if( DPI )
        return *DPI;
    return "DPI no asignado";
}

/* Metodo que indica a la instacia que debe imprimir su nombre. */
void persona::Decir_Nombre()
{
    if( Nombre )
        std::cout << "Mi nombre es: " << *Nombre << std::endl;
    else
        std::cout << "Nombre no asignado" << std::endl;
}

/* Metodo que indica a la instacia que debe imprimir su edad
 * en anios. */
void persona::Decir_edad()
{
    if( Fecha_nacimiento )
    {
        std::time_t now;
        float Edad;

        std::time(&now);

        /* La funcion difftime devuelve la diferencia de tiempo 
         * en segundos. Se convierte a anios. Notese que no sera 
         * la edad calendario. */
        Edad = std::difftime(now,std::mktime(Fecha_nacimiento))/31556925.9747;

        std::cout<< "Mi edad es: " << Edad << " anios" << std::endl;
    }
    else
        std::cout << "Fecha de nacimiento no asignada" << std::endl;
    
}

/* Metodo que indica a la instacia que debe imprimir su lugar de origen. */
void persona::Decir_origen()
{
    if( Lugar_nacimiento )
        std::cout << "Soy de: " << *Lugar_nacimiento << std::endl;
    else
        std::cout << "Lugar de origen no asignado" << std::endl;
}

/* Metodo de clase. Se utiliza el vector de punteros instancias
 * para llamar al metodo Decir_Nombre de todas las instancias. */
void persona::LLamar_Todos()
{
    /* Primero se verifica que existan instancias por medio del
     * tamanio del vector instancias */
    if( instancias.size() != 0 )
        /* Se usa el iterador de la case vector para llamar al
         * metodo Decir_Nombre de cada instancia. */
        for( auto n = instancias.begin(); n != instancias.end(); n++)
            (*n)->Decir_Nombre();
    else
        std::cout << "No hay instancias aun" << std::endl;
    
}




/* Metodos pedidos por la tarea, realizamos el mismo procedimiento teniendo cuidado con los indicadores
y utilizando la misma estructura anterior*/



int persona::Asignar_Nombre( std::string elNombre )
{
    if( !Nombre )
    {
        Nombre = new std::string( elNombre );
        return 0;
    }
    
    std::cout << "El Nombre  ya fue asignado" << std::endl;
    return 1;
}


/* Metodo para obtener el Nombre de a una persona (get method)
 * devuelve un string con el Nombre */
std::string persona::Obtener_Nombre( )
{
    if( Nombre )
        return *Nombre;
    return "DPI no asignado";
}



int persona::Asignar_Lugar_origen( std::string Lugar )
{
    if( !Lugar_nacimiento )
    {
        Lugar_nacimiento = new std::string( Lugar );
        return 0;
    }
    
    std::cout << "El Lugar  ya fue asignado" << std::endl;
    return 1;
}


/* Metodo para obtener el Lugar a una persona (get method)
 * devuelve un string con el Lugar */
std::string persona::Obtener_Lugar_Origen( )
{
    if( Lugar_nacimiento )
        return *Lugar_nacimiento;
    return "Lugar no asignado";
}


/* Aqui cambie los outputs para saber cuando tenemos cada caso de variable faltante*/


int persona::Asignar_Fecha_Nacimiento( std::string anio, std::string mes, std::string dia )
{
    if( !Anio )
    {
        Anio = new std::string( anio );
        return 0;
    }
        if( !Dia )
    {
        Dia = new std::string( dia );
        return 1;
    }
        if( !Mes )
    {
        Mes = new std::string( mes );
        return 2;
    }
    
    std::cout << "La fecha  ya fue asignada" << std::endl;
    return 3;
}


/* Metodo para obtener el Anio de a una persona (get method)
 * devuelve un string con el Anio */
std::string persona::Obtener_Anio_Nacimiento( )
{
    if( Anio )
        return *Anio;
    return "Anio no asignado";
}


/* Metodo para obtener el Mes de a una persona (get method)
 * devuelve un string con el Mes */
std::string persona::Obtener_Mes_Nacimiento( )
{
    if( Mes )
        return *Mes;
    return "Mes no asignado";
}

/* Metodo para obtener el Dia de a una persona (get method)
 * devuelve un string con el Dia */

std::string persona::Obtener_Dia_Nacimiento( )
{
    if( Dia )
        return *Dia;
    return "Dia no asignado";
}
