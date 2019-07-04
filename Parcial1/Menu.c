#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Validaciones.h"

int pedirMenu()
{
    int opcion;
    printf("Parcial de laboratorio de computacion 1.\n\n\n");
    opcion = getInt(" 1.Alta  \n 2.Baja(de pelis)\n 3.Modificacion(de pelis)\n 4.Mostrar(con filtros)\n 5.Exit\n");
    return opcion;

}
int pedirPelicula()
{
    int opcionAmodificar;
    printf("%10s - %10s - %10s \n", "1.Titulo", "2.Anio de estreno", "3.Actor");
    opcionAmodificar = getInt("\nIntroduzca una opcion a modificar: \n");

    while(opcionAmodificar != 1 && opcionAmodificar != 2 && opcionAmodificar != 3)
    {
        opcionAmodificar = getInt("Error. Ingrese una de las opciones que habian en pantalla.\n");
    }

    return opcionAmodificar;
}

int mostrar()
{
    int optionShow;
    printf("%s %s %s %s %s %s %s %s %s %s %s %s \n"," 1.Mostrar las Peliculas sin actores\n", "2.Mostrar las Peliculas sin actores\n", "3.Mostrar peliculas por anio de estreno\n", "4.Mostrar Actores por pais de origen\n", "5.Mostrar todas las peliculas con genero y actor. \n", "6.Mostrar las peliculas cuya nacionalidad del actor sea de EEUU. \n","7.Mostrar peliculas cuya nacionalidad del actor ingresada por consola. \n","8.Mostrar peliculas agrupadas en su genero. \n", "9.Mostrar la cantidad de peliculas que hay en cada genero. \n", "10.Mostrar actores que mas peliculas protagonizaron. \n","11.Mostrar generos con menos peliculas.\n", "12.Mostrar Actores que no trabajaron en ninguna pelicula.\n");
    optionShow = getInt("");

    return optionShow;
}

int mostrar2()
{
    int optionShow;
    printf("%s\n","1-Mostrar pelicuas y actores\n2-Solo actores con edad organizada de mayor a menor");
    optionShow = getInt("");

    return optionShow;
}


int pedirNacionalidad()
{
    int optionShow;
    printf("%s","                   Ingrese nacionalidad:                 \n");
    optionShow = getInt("1.EEUU \n 2.Argentina \n 3.Australia\n 4.Uruguay\n");

    return optionShow;
}

int pedirOrden()
{
    int opcion;
    printf("%s","             Ingrese el sentido de ordenamiento          \n");
    opcion = getInt(" 1.Ascendente \n 2.Descendente \n ");

    while(opcion != 1 && opcion != 2)
    {
        opcion = getInt("ERROR. 1.Ascendente \n 2.Descendente \n ");
    }

    return opcion;
}

