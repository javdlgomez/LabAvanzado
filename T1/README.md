
###### Laboratorio de instrumentación
###### Javier de León Gómez
###### 201603068


# Documentación de las Tareas 1.II.1 y 1.II.2

## Tarea 1.II.1:

Se nos pide realizar cambios a la clase simple añadiendo la instancia ID, hacerlo igual a otra variable ya creada, crear un método que nos permita ver el ID y agregar el método en la clase.

El procedimiento de estos cambios es directo y nos apoyamos en el script proporcionado en clase, ahora vamos a mostrar los cambios realizados a los archivos pedidos.

En el archivo simple.cpp agregamos la instancia ID, cambiamos el valor de la variable y definimos el método:

    /*Definimos la variable ID*/
    int simple::ID = 0;
    /*La hacemos igual a Numero*/
      ID = Numero;
    
    /*Metodo de clase que muestra el ID*/
    void simple::ShowID(){
        cout << "ID: " << ID << endl;
      }
    
En el header agregamos la variable ID y llamamos al método showID:

    /* Cambio de la tarea */
    int ID;

En el archivo class.cpp realizamos la llamada del método showID:
    
        /* Se llaman los metodos de los objetos. Estos deben
         * ser llamados desde una instancia e interactuan
         * con los atributos de cada instancia. */ 
        primero.Decir_Frase();
        primero.showID();
        segundo.Decir_Frase();
        segundo.showID();
        tercero->Decir_Frase();
        tercero->showID();

## Tarea 1.II.2:
Nos piden crear varios métodos que asignan y obtienen distintos valores de la persona, para ello debemos llamar a los métodos en el header agregando también las variables respectivas y basarnos en las funciones ya creadas en el script proporcionado en clase para obtener el DPI. Vamos a utilizar la misma estructura que ha sido proporcionada en clase para faciliar la escritura del código.

En el header agregamos los pointers de año, mes, dia y además llamamos a las funciones para agregar y obtener las características pedidas de la persona:

    /* variables agregadas */
    std::string* Anio;
    std::string* Dia;
    std::string* Mes;

    /* Metodos de la tarea para Asignar Valores*/
    int Asignar_Nombre(std::string elNombre);
    int Asignar_Fecha_Nacimiento(std::string anio, std::string mes, std::string dia);
    int Asignar_Lugar_origen(std::string Lugar);

    /* Metodos de la tarea para Obtener Valores */
    std::string Obtener_Nombre();
    std::string Obtener_Anio_Nacimiento();
    std::string Obtener_Mes_Nacimiento();
    std::string Obtener_Dia_Nacimiento();
    std::string Obtener_Lugar_Origen();

Ahora en el cpp vamos a crear nuestras nuevas funciones utilizando la misma estructura que para pedir el DPI, aquí solo debemos tener cuidado de ver como se llaman nuestros indicadores y los asignamos a 0 también. Además de que las funciones esten vinculadas a la persona, tomando esto en consideración nuestras funciones se escriben de la siguiente manera:

    /* Asignamos estas variables a 0 analogamente a lo que se hacia
    con el valor del DPI*/
    Anio = 0;
    Dia = 0;
    Mes = 0;


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

