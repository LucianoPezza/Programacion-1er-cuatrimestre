#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"
#include "controller.h"
#include "menu.h"
#include "filters.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t _______________________________________\n\t\t*                                       *\n\t\t*                 MENU                  *\n\t\t*                                       *");
    printf("\n\t\t*    1. ALTA DE PELICULA                *");
    printf("\n\t\t*    2. BAJA DE PELICULA                *");
    printf("\n\t\t*    3. MODIFICACION DE PELICULA        *");
    printf("\n\t\t*    4. MOSTRAR PELICULAS               *");
    printf("\n\t\t*    5. ALTA DE ACTOR                   *");
    printf("\n\t\t*    6. BAJA DE ACTOR                   *");
    printf("\n\t\t*    7. MODIFICACION DE ACTOR           *");
    printf("\n\t\t*    8. MOSTRAR ACTORES                 *");
    printf("\n\t\t*    9. FILTROS                         *");
    printf("\n\t\t*    10. SALIR                          *");
    printf("\n\t\t*                                       *\n\t\t*_______________________________________*\n\n");
    option = getOption(10);

	return option;
}

int menu_movieGenre()
{
    int option;

    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*           GENEROS           *\n\t\t\t*                             *\n\t\t\t*    1. ACCION                *\n\t\t\t*    2. COMEDIA               *\n\t\t\t*    3. TERROR                *\n\t\t\t*    4. OTRO                  *\n\t\t\t*    5. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(5);

    return option;
}

int menu_movieModify()
{
    int option;

    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*          MODIFICAR          *\n\t\t\t*                             *\n\t\t\t*    1. TITULO                *\n\t\t\t*    2. GENERO                *\n\t\t\t*    3. CODIGO                *\n\t\t\t*    4. AÑO                   *\n\t\t\t*    5. ACTOR                 *\n\t\t\t*    6. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(6);

    return option;
}

int menu_movieList()
{
    int option;

    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*           LISTAR            *\n\t\t\t*                             *\n\t\t\t*    1. PELICULAS             *\n\t\t\t*    2. ACTORES              *\n\t\t\t*    3. ORDENAR                *\n\t\t\t*    4. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(4);

    return option;
}

int menu_movieSort()
{
    int option;
    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*           SUBMENU           *\n\t\t\t*                             *\n\t\t\t*    1. TITULO                *\n\t\t\t*    2. AÑO                   *\n\t\t\t*    3. GENERO                *\n\t\t\t*    4. CODIGO                *\n\t\t\t*    5. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(5);

    return option;
}

int menu_order()
{
    int option;

    printf("\n\t\t\t _______________________________\n\t\t\t*                               *\n\t\t\t*            SUBMENU            *\n\t\t\t*                               *\n\t\t\t*     1. DESCENDENTE            *\n\t\t\t*     2. ASCENDENTE             *\n\t\t\t*                               *\n\t\t\t*_______________________________*\n\n");
    option = getOption(2);

    return option;
}

int menu_filter()
{
    int option;

    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*           SUBMENU           *\n\t\t\t*                             *");
    printf("\n\t\t\t*    1. ACTORES MAYORES       *");
    printf("\n\t\t\t*    2. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(2);

    return option;
}

int menu_actorModify()
{
    int option;

    printf("\n\t\t\t _____________________________\n\t\t\t*                             *\n\t\t\t*           SUBMENU           *\n\t\t\t*                             *");
    printf("\n\t\t\t*    1. NOMBRE                *");
    printf("\n\t\t\t*    2. ORIGEN                *");
    printf("\n\t\t\t*    3. EDAD                  *");
    printf("\n\t\t\t*    4. VOLVER                *\n\t\t\t*                             *\n\t\t\t*_____________________________*\n\n");
    option = getOption(4);

    return option;
}



void menu_printFilterList(sMovie* movieList, int lenght, sActor* actorList, int actorsLenght)
{
    int option;

    printf("\n\t\t\t\t:: F I L T R O S ::\n\n");
    do
    {
        switch(menu_filter())
        {
            case 1:
                actor_sortByAge(actorList, actorsLenght, 1);
                actor_printList(actorList, actorsLenght);
                break;
            case 2:
                filter_actorsOfLegalAge(actorList, actorsLenght);
                break;
            case 6:
                option = 6;
                break;
        }
    }while(option != 6);
}
