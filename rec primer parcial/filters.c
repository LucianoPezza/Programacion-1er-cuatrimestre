#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"
#include "controller.h"
#include "menu.h"
#include "filters.h"

int filter_actorsOfLegalAge(sActor actorList[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(actorList[i].state == 1 && actorList[i].age >= 18)
        {
            actor_printOne(actorList[i]);
        }
    }
    return 0;
}

int filter_actorsByGenre(sMovie movieList[], sActor actorList[], int len, char genreToPrint[21])
{
    int i;
    int posActorDeGenero;

    printf("Actores que trabajaron en peliculas de %s \n", genreToPrint);

    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1 && strcmp(genreToPrint, movieList[i].genre)==0)
        {
            posActorDeGenero = actor_getByID(actorList, len, movieList[i].mainActorID);
            printf("%10s \n", actorList[posActorDeGenero].name);
        }
    }
    return 0;
}

int filter_moviesWithActors(sMovie movieList[], sActor actorList[], int len)
{
    int i;
    int posActor;
    printf("%s\t %s\t %15s  %s\t\t %s\t\t %15s \n", "ID", "Codigo", "titulo", "Fecha", "Genero", "Actor");

    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1)
        {

            posActor = actor_getByID(actorList, len, movieList[i].mainActorID);

            printf("%d\t %d\t %15s %d\t\t %s %30s\t \n", movieList[i].id, movieList[i].movieCode, movieList[i].title, movieList[i].releaseYear, movieList[i].genre, actorList[posActor].name);
        }
    }

    return 0;
}


int filter_moviesByOrigin(sMovie movieList[], sActor actorList[], int len, char originToPrint[21])
{
    int i;
    int j;

    printf("Peliculas que trabajaron actores de %s \n", originToPrint);

    for(i=0; i<len; i++)
    {
        if(actorList[i].state == 1 && strcmp(originToPrint, actorList[i].origin)==0)
        {
            for(j=0; j<len; j++)
            {
                if(movieList[j].mainActorID == actorList[i].id)
                printf("%10s \n", movieList[j].title);
            }
        }
    }

    return 0;
}

int filter_moviesByInputOrigin(sMovie movieList[], sActor actorList[], int len, char originToPrint[21])
{
    int i;
    int j;
    int exist = 0;

    printf("Peliculas que trabajaron actores de %s :\n", originToPrint);

    for(i=0; i<len; i++)
    {
        if(actorList[i].state == 1 && strcmp(originToPrint, actorList[i].origin)==0)
        {
            for(j=0; j<len; j++)
            {
                if(movieList[j].mainActorID == actorList[i].id)
                {
                     printf("%s \n",movieList[j].title);
                }
            }
            exist = 1;
        }
    }

    if(exist == 0)
    {
        printf("\n>>>>> No hay peliculas con actores de esa nacionalidad <<<<<\n\n");
    }

    return 0;
}

void filter_moviesByInputGenre(sMovie movieList[], int len, char genreToPrint[21])
{
    printf(" %s %s  \n", "Peliculas del genero: ", genreToPrint);

    int i;
    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1 && strcmp(genreToPrint, movieList[i].genre)==0)
        {
            printf("%s  \n", movieList[i].title);
        }
    }
    printf("\n");

}

void filter_numberOfMoviesGroupedByGenre(sMovie movieList[], int len, char genreToPrint[21])
{
    int i;
    int nomberOfMovies = 0;
    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1 && strcmp(genreToPrint, movieList[i].genre)==0)
        {
            nomberOfMovies++;
        }
    }
    printf("%s  %d %s %s \n", "Hay", nomberOfMovies, " peliculas de ", genreToPrint);
    printf("\n");
}



int filter_participations(sMovie movieList[], int len, int idToCount)
{
    int i;
    int participations = 0;

    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1 && movieList[i].id == idToCount)
        {
            participations++;
        }
    }

    return participations;
}

void filter_moreParticipatoryActors(sMovie movieList[], sActor actorList[], int len)
{
    int i;
    int j;
    int participations;
    int auxParticipations;


    for(i=0; i<len; i++)
    {
        auxParticipations = filter_participations(movieList, len, actorList[i].id);

        if(i == 0 || auxParticipations > participations)
        {
            participations = auxParticipations;
        }
    }

    printf("%s \n","Actores con mas participaciones:");

    for(j=0; j<len; j++)
    {
        auxParticipations = filter_participations(movieList, len, actorList[j].id);

        if(actorList[j].state == 1 && auxParticipations == participations)
        {
            printf("%s \n",actorList[j].name);
        }
    }
}

int filter_numberOfMoviesByGenre(sMovie movieList[], int len, char genreToCount[21])
{
    int i;
    int cant = 0;

    for(i=0; i<len; i++)
    {
        if(movieList[i].state == 1 && strcmp(genreToCount, movieList[i].genre)==0)
        {
            cant++;
        }
    }

    return cant;
}

void filter_genreWithLessMovies(sMovie movieList[], int len)
{
    int a[5];
    char b[5][21] = { "Accion", "Terror", "Romantica", "Comedia", "Otro" };
    int i,j;
    int cantidad;

    for(i=0; i<5; i++)
    {
        a[i] = filter_numberOfMoviesByGenre(movieList, len, b[i]);
    }

    for(i=0; i<5; i++)
    {
        if(i==0|| cantidad > a[i])
        {
            cantidad = a[i];
        }
    }

    printf("%s \n", "Generos con menos peliculas: ");

    for(j=0; j<5; j++)

    {
        if(a[j] == cantidad)
        {
            printf("%s \n", b[j]);
        }
    }
}

void filter_actorsWhoDidNotWork(sMovie movieList[], sActor actorList[], int len)
{
    int i;
    int auxCantidad = 0;

    printf("%s \n","Actores sin participacion: ");

    for(i=0; i<len; i++)
    {
        auxCantidad = filter_participations(movieList, len, actorList[i].id);

        if(actorList[i].state == 1 && auxCantidad == 0)
        {
            printf("%s \n", actorList[i].name);
        }
    }
}
