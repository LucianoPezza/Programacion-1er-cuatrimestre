#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include "Actores.h"
#define CANT 5

/*
Desarrollar en ANSI C:
Se desea construir una aplicación capaz de almacenar y administrar las fichas técnicas de
películas. De cada película, se necesita un identificador unívoco, su código de película ,su
título, fecha de estreno, genero (accion , comedia ,terror y otro) y un actor
principal(estructura). De los 5 actores se almacena: el id, el nombre y su país de origen.
estos son:
1- julieta roberto , EEUU
2- Roberto deniro, EEUU
3- Richar darin,Argentina
4-tita merelo,Argentina
5 -sandro, Argentina
1. ALTAS PELÍCULAS​: Se ingresan los datos de una sola película. El id deberá
generarse de manera automática a partir del número 1000. Realizar las validaciones:
a) el id es incremental.
b) código: debe ser de tres cifras sin ceros a la izquierda
c) título : no puede ser solo un número , debe tener letras.
d) el actor debe ser uno existente,
2. LISTAR​:
a) listar los datos de Películas sin actores
b) listar los datos de Películas con actores
Nota 1: Se deberá desarrollar una biblioteca para cada una de las entidades involucradas en el
dominio. Junto a las bibliotecas de funciones propias (a criterio del alumno).
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.
Nota 3: Realizar todas las validaciones necesarias tanto para los datos como para solicitar
conformidad al usuario.
Nota 4: El docente podrá solicitar, al momento de la corrección, agregar cualquier detalle que
considere necesario como por ejemplo cuestiones de estética del programa.*/
int main()
{
    int opcion;
    ePelicula lista[CANT];
    InicializarPelicula(lista, CANT);
    hardcodearActores(lista,CANT);
    do{

    printf("\n1 Alta\n2Listar\n5Salir\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:

        system("cls");
        agregarpeliculas(lista, CANT);
        break;
    case 2:

        break;
    }

}while(opcion != 5);

}

