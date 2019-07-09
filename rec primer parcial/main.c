#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"
#include "controller.h"
#define LEN 100
int main()
{
    sMovie movieList[LEN];
    sActor actorList[LEN];
    actor_hardcode(actorList);
    movie_init(movieList,LEN);
    movie_hardcode(movieList);
    int option;

    do
    {
        switch(menu_main())
        {
            case 1:
                controller_loadMovie(movieList,LEN,actorList,LEN);
                break;
            case 2:
                controller_deleteMovie(movieList,LEN,actorList,LEN);
                break;
            case 3:
                controller_modifyMovie(movieList,LEN,actorList,LEN);
                break;
            case 4:
                printMovieList(movieList,LEN,actorList,LEN);
                break;
            case 5:
                controller_loadActor(actorList,LEN);
                break;
            case 6:
                controller_deleteActor(actorList,LEN);
                break;
            case 7:
                controller_modifyActor(actorList,LEN);
                break;
            case 8:
                actor_printList(actorList,LEN);
                break;
            case 9:
                menu_printFilterList(movieList,LEN,actorList,LEN);
                break;
            case 10:
                option = 10;
                printf("\nPresione 'Enter' para terminar el programa\n");
                break;
        }
    }while(option != 10);

    return 0;
}
