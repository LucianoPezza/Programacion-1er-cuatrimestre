#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"
#include "menu.h"

#define FREE 0
#define TAKEN 1

void controller_loadMovie(sMovie* movieList, int lenght, sActor* actorList, int actorLenght)
{
    int numberOfTries = 5;
    int title = 0;
    int genre = 0;
    int code = 0;
    int year = 0;
    int actor = 0;
    int auxCode = 0;
    int auxYear = 0;
    int auxActorID = 0;
    int index = -1;
    char auxTitle[51];
    char auxGenre[51];

    printf("\n\t\t\t\t:: A L T A ::\n\n");
    index = movie_getEmptySpace(movieList, lenght);

    if(index >= 0)
    {
        title = movie_getTitle(auxTitle,numberOfTries);
        genre = movie_getGenre(auxGenre);
        code = movie_getCode(movieList, lenght, &auxCode);
        year = movie_getYear (&auxYear);
        actor = movie_getActorID(actorList, actorLenght, &auxActorID);

        if(title && genre && code && year && actor)
        {
            movieList[index].id = movie_getId();
            movieList[index].movieCode = auxCode;
            movieList[index].releaseYear = auxYear;
            movieList[index].mainActorID = auxActorID;
            strcpy(movieList[index].title, auxTitle);
            strcpy(movieList[index].genre, auxGenre);
            movieList[index].state = 1;

            printf("\n>>>>> Pelicula cargada exitosamente <<<<<\n");
        }
        else
        {
            printf("\n>>>>> Error al cargar la pelicula <<<<<\n");
        }
    }
}

int controller_deleteMovie(sMovie* movieList, int movieLenght, sActor* actorList, int actorLenght)
{
    int IDforDeletion = 0;
    int i;
    int itsDone = 0;

    printf("\n\t\t\t\t:: B A J A ::\n\n");
    printMovieList(movieList,movieLenght,actorList,actorLenght);

    printf("\nIngrese el ID de la pelicula a eliminar: ");
    scanf("%d",&IDforDeletion);

    for(i=0; i<movieLenght; i++)
    {
        if(movieList[i].id == IDforDeletion)
        {
            movieList[i].state = -1;
            printf("\n>>>>> Pelicula eliminada exitosamente <<<<<\n");
            itsDone = 1;
            break;
        }
    }
    if(itsDone == 0)
    {
        printf("\n>>>>> Error al eliminar la pelicula <<<<<\n");
    }
    return itsDone;
}

void controller_modifyMovie(sMovie* movieList, int moviesLenght, sActor* actorList, int actorLenght)
{
    int option;
    int i;
    int numberOfTries = 5;
    int title = 1;
    int genre = 1;
    int code = 1;
    int year = 1;
    int actor = 1;
    int auxCode = 0;
    int auxYear = 0;
    int auxActorID = 0;
    char auxTitle[51];
    char auxGenre[51];
    sActor actorPrint;

    int movieID;
    int index;

    printf("\n\t\t\t:: M O D I F I C A C I O N ::\n\n");
    printMovieList(movieList,moviesLenght,actorList,actorLenght);

    printf("\nIngrese el ID de la pelicula a modificar: ");
    scanf("%d",&movieID);
    index = movie_getByID(movieList, moviesLenght, movieID);

    if(index >= 0)
    {
        do
        {
            for(i=0; i<actorLenght; i++)
            {
                if(movieList[index].mainActorID == actorList[i].id)
                {
                    actorPrint = actorList[i];
                    break;
                }
            }
            printOneMovie(movieList[index],actorPrint.name);

            switch(menu_movieModify())
            {
            case 1:
                title = movie_getTitle(auxTitle,numberOfTries);
                if(title)
                {
                    strcpy(movieList[index].title,auxTitle);
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 2:
                genre = movie_getGenre(auxGenre);
                if(genre)
                {
                    strcpy(movieList[index].genre,auxGenre);
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 3:
                code = movie_getCode( movieList, moviesLenght, &auxCode );
                if(code)
                {
                    movieList[index].movieCode = auxCode;
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 4:
                year = movie_getYear ( &auxYear );
                if(year)
                {
                    movieList[index].releaseYear = auxYear;
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 5:
                actor = movie_getActorID (actorList, actorLenght, &auxActorID );
                if(actor)
                {
                    movieList[index].mainActorID = auxActorID;
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 6:
                option = 6;
                break;
            }
        }
        while(option!=6);
    }
}

void controller_sortMovies(sMovie* movieList, int lenght)
{
    int option;
    int order;

    option = menu_movieSort();
    order = menu_order();

    switch(option)
    {
    case 1:
        movie_sortByTitle(movieList,lenght,order);
        printf("\n>>>>> Pelicula ordenada exitosamente <<<<<\n");
        break;
    case 2:
        movie_sortByYear(movieList,lenght,order);
        printf("\n>>>>> Pelicula ordenada exitosamente <<<<<\n");
        break;
    case 3:
        movie_sortByGenre(movieList,lenght,order);
        printf("\n>>>>> Pelicula ordenada exitosamente <<<<<\n");
        break;
    case 4:
        movie_sortByCode(movieList,lenght,order);
        printf("\n>>>>> Pelicula ordenada exitosamente <<<<<\n");
        break;
    }
}

int controller_loadActor(sActor* listadoActores, int len)
{
    int idActor;
    char nombreDeActor[50];
    char nacionalidad[50];
    int idExiste;
    int edadActor;


    idActor = actor_getId();

    getString(" Ingrese nombre: \n", nombreDeActor);
    while(itsNumeric(nombreDeActor)==1)
    {
        getString("Error. Tiene que ser solo letras, ingrese un nuevo titulo: \n", nombreDeActor);
    }
    getString(" Ingrese nacionalidad: \n", nacionalidad);
    while(itsNumeric(nombreDeActor)==1)
    {
        getString("Error. Tiene que ser solo letras, ingrese un nuevo titulo: ",nombreDeActor);
    }

    edadActor = getInt("Ingrese la edad del actor: ");
    while(edadActor<10 || edadActor>90)
    {
        edadActor= getInt("Ingrese una edad valida (Entre 10 y 90 anios)");
    }
    while(idExiste == -1)
    {
        idActor = getInt("Reingrese una ID de Actor valida\n");
        idExiste = actor_getByID(listadoActores, len, idActor);
    }

    int i;
    for(i = 0; i<len; i++)
    {
        if(listadoActores[i].state ==FREE)
        {
            listadoActores[i].id=idActor;
            listadoActores[i].age=edadActor;
            strcpy(listadoActores[i].origin, nacionalidad);
            strcpy(listadoActores[i].name, nombreDeActor);
            listadoActores[i].state=TAKEN;
            return 0;
        }
    }
    return -1;
}

int controller_deleteActor(sActor* actorList, int actorLenght)
{
    char originToDelate[51];
    int i;
    int exist = 0;

    printf("\n\t\t\t\t:: B A J A ::\n\n");
    actor_printList(actorList, actorLenght);

    getString("\n\nIngrese el pais del actor a eliminar: ", originToDelate);

    for(i=0; i<actorLenght; i++)
    {
        if(strcmp(actorList[i].origin, originToDelate) == 0)//stricmp
        {
            actorList[i].state = -1;
            printf("\n>>>>> Actor eliminado exitosamente <<<<<\n");
            exist = 1;
            //break; saco el break para que me elimine todos lo de un pais
        }
    }
    if(exist == 0)
    {
        printf("\n>>>>> No hay actores de %s <<<<<\n", originToDelate);
    }
    return exist;
}


void controller_modifyActor(sActor* actorList, int actorLenght)
{
    int option;
    int i;
    int numberOfTries = 5;
    int name = 1;
    int origin = 1;
    int age = 1;

    int auxAge = 0;
    //int auxActorID = 0;
    char auxName[51];
    char auxOrigin[51];
    sActor actorPrint;

    int actorID;
    int index;

    printf("\n\t\t\t:: M O D I F I C A C I O N ::\n\n");
    actor_printList(actorList, actorLenght);

    printf("\n\nIngrese el ID del actor a modificar: ");
    scanf("%d",&actorID);
    index = actor_getByID(actorList, actorLenght, actorID);

    if(index >= 0)
    {
        do
        {
            for(i=0; i<actorLenght; i++)
            {
                if(actorList[index].id == actorID)
                {
                    actorPrint = actorList[i];
                    break;
                }
            }

            actor_printOne((actorList[index]));

            switch(menu_actorModify())
            {
            case 1:
                name = actor_getName(auxName);
                if(name)
                {
                    strcpy(actorList[index].name,auxName);
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 2:
                origin = actor_getOrigin(auxOrigin);
                if(origin)
                {
                    strcpy(actorList[index].origin, auxOrigin);
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 3:
                age = actor_getAge(&auxAge);
                if(age)
                {
                    actorList[index].age = auxAge;
                    printf("\n>>>>> Dato modificado exitosamente <<<<<\n");
                }
                else
                {
                    printf("\n>>>>> Error al modificar el dato <<<<<\n");
                }
                break;
            case 4:
                option = 4;
                break;
            }
        }
        while(option!=4);
    }
}
