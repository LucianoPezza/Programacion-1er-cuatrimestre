#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include "Actores.h"
#define CANT 5
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

