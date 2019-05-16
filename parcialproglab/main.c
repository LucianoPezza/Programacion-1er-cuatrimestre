#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#define CANT 5

int main()
{
    int opcion;
    ePelicula lista[CANT];
    do
    {
        printf("\n1 Alta\n2Baja\n3Modificacion\n4Mostrar\n5Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
         case 1:
            agregarPelicula(lista,CANT);
            system("cls");
            break;

         case 2:

             break;

         case 3:
             break;

         case 4:
             mostrarPeliculas(lista, CANT);
             break;
        }

    }while(opcion != 5);

return 0;
}
