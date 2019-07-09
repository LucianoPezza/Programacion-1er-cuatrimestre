#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"
#include "controller.h"
#include "menu.h"

void movie_init(sMovie *movieList, int len)
{
    int i;
    if(movieList != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            movieList[i].id = 0;
            movieList[i].state = 0;
            movieList[i].movieCode = 0;
            movieList[i].releaseYear = 0;
            strcpy(movieList[i].title, " ");
            strcpy(movieList[i].genre, " ");
        }
    }
}

void movie_hardcode(sMovie* movieList)
{
    int index;
    char titles[10][51] = {"terminator", "thor", "it", "gladiador", "scary movie 4", "yo soy asi", "scary movie 2", "sexto sentido", "Maze Runner", "Bright"};
    char genres[10][51] = {"Accion", "Accion", "Terror", "Romantica", "Comedia", "Otros", "Comedia", "Otros", "Accion", "Comedia"};
    int release[10] = {2020, 2019, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010};
    int codes[10] = {999, 666, 555, 777, 111, 222, 101, 202, 109, 110};
    int IDs [10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    for(index = 0; index < 10; index++)
    {
        movieList[index].id = movie_getId();
        movieList[index].movieCode = codes[index];
        movieList[index].releaseYear = release[index];
        movieList[index].mainActorID = IDs[index];
        strcpy(movieList[index].title, titles[index]);
        strcpy(movieList[index].genre, genres[index]);
        movieList[index].state = 1;
    }
}

int movie_getEmptySpace(sMovie* movieList, int lenght)
{
    int i;

    for(i=0; i<lenght; i++)
    {
        if(movieList[i].state == 0)
        {
            break;
        }
    }
    return i;
}

int movie_getId(void)
{
    static int maxId = 1000;
    return maxId++;
}

int movie_getTitle(char* retString, int tries)
{
    int isValid = 0;
    char auxInput[51];

    do
    {
        printf("\nIngrese el titulo: ");
        setbuf(stdin, NULL);
        fgets(auxInput,51,stdin);

        while(!(isTitle(auxInput)))
        {
            tries--;

            if(tries<=0 )
            {
                break;
            }
            printf("\n>>>>> El titulo es invalido <<<<<\n");
            printf("\nIngrese el titulo: ");
            setbuf(stdin, NULL);
            fgets(auxInput,51,stdin);
        }
    }while(tries > 0 && !(isTitle(auxInput)));

    if(isTitle(auxInput))
    {
        strcpy(retString,auxInput);
        isValid = 1;
    }

    return isValid;
}

int movie_getCode(sMovie* movieList, int lenght, int* retCode)
{
    int auxCode;
    int itsDone = 0;
    int codeExist;

    auxCode = getInt("\nIngrese el codigo: ");

    codeExist = movie_existingCode(movieList,lenght,auxCode);

    while(auxCode > 999 || auxCode < 100 || codeExist)
    {
        printf("\n>>>>> El codigo es invalido (debe ser entre 100 y 999) o esta repetido <<<<<\n");
        auxCode = getInt("\nIngrese el codigo: ");
        codeExist = movie_existingCode(movieList,lenght,auxCode);
    }

    if(auxCode<=999 && auxCode>=100 && codeExist == 0)
    {
        *retCode = auxCode;
        itsDone = 1;
    }
    return itsDone;
}

int movie_existingCode(sMovie* movieList, int lenght, int code)
{
    int i;
    int exist = 0;

    for(i=0; i<lenght; i++)
    {
        if(movieList[i].movieCode == code)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

int movie_getGenre(char* retGenre)
{
    int itsDone = 0;
    char genre[51];

    switch(menu_movieGenre())
    {
        case 1:
            strcpy(retGenre, "Accion");
            break;
        case 2:
            strcpy(retGenre, "Comedia");
            break;
        case 3:
            strcpy(retGenre, "Terror");
            break;
        case 4:
            getString("\nIngrese el genero de la pelicula: ", genre);
            strcpy(retGenre, genre);
            break;
        case 5:
            break;
    }

    if(retGenre[0] != '\0')
    {
        itsDone = 1;
    }

    return itsDone;
}


int movie_getYear(int* retYear)
{
    int auxYear = 0;
    int itsDone = 0;

    auxYear = getInt("\nIngrese el año: ");

    while(auxYear > 2025 || auxYear < 1894 )
    {
        printf("\n>>>>> El año es invalido (debe ser entre 1894 y 2025) <<<<<\n");
        auxYear = getInt("\nIngrese el año: ");
    }

    if(auxYear >= 1894 && auxYear <= 2025)
    {
        *retYear = auxYear;
        itsDone = 1;
    }

    return itsDone;
}
int movie_getActorID(sActor* actorList, int lenght, int* actorId)
{
    int option = 0;
    int itsDone = 0;
    int actorsIDs [lenght];
    int i;
    int j=0;

    printf("\n\t\t\t __________________________________\n\t\t\t*                                  *\n\t\t\t*             ACTORES              *\n\t\t\t*                                  *");
    for(i=0;i<lenght;i++)
    {
        if(actorList[i].state)
        {
            j++;
            printf("\n\t\t\t    %d. %s, %s",j,actorList[i].name,actorList[i].origin);
            actorsIDs[j] = actorList[i].id;
        }
    }
    printf("\n\t\t\t*                                  *\n\t\t\t*__________________________________*\n\n");

    printf("\nSeleccione un actor: ");
    setbuf(stdin, NULL);
    scanf("%d",&option);

    while(option < 1 || option > j)
    {
        printf("\n>>>>> Opcion invalida <<<<<");
        printf("\nSeleccione un actor: ");
        setbuf(stdin, NULL);
        scanf("%d",&option);
    }
    *actorId = actorsIDs[option];

    for(i=0; i<lenght; i++)
    {
        if(*actorId == actorList[i].id)
        {
            itsDone = 1;
        }
    }

    return itsDone;
}

int movie_getByID(sMovie* movieList , int lenght , int movieID)
{
    int index = -1;
    int i;
    for(i=0; i<lenght; i++)
    {
        if(movieList[i].id == movieID)
        {
            index = i;
            break;
        }
    }
    return index;
}

/// PRINT FUNCTIONS *******************************************************************************************
void printMovieList(sMovie* movieList, int lenght, sActor* actorList, int actorLenght)
{
    int i;
    int j;
    char actor[51] = {" "};

    printf("\n ID      CODIGO        TITULO        ESTRENO      GENERO        ACTOR\n");
    printf(" ___________________________________________________________________________\n");

    for(i=0; i<lenght; i++)
    {
        for(j=0; j<actorLenght; j++)
        {
            if(movieList[i].mainActorID == actorList[j].id)
            {
                strcpy(actor,actorList[j].name);
                break;
            }
        }
        printOneMovie(movieList[i],actor);
    }
}
void printMovieListNoActor(sMovie* movieList, int lenght)
{
    int i;

    for(i=0; i<lenght; i++)
    {
        if(movieList[i].state == 1)
        {
            printf("\n%5d%7d     %10s   %8d     %5s",movieList[i].id, movieList[i].movieCode, movieList[i].title, movieList[i].releaseYear, movieList[i].genre);
        }
    }
}
void printOneMovie(sMovie movie ,char* actor)
{
    if(movie.state == 1)
    {
        printf("\n%5d%7d     %10s   %8d     %5s",movie.id, movie.movieCode, movie.title, movie.releaseYear, movie.genre);

        if(actor[0] == '\n' || actor[0] == '\0')
        {
            printf("  No Definido\n");
        }
        else
        {
            printf("  %5s\n",actor);
        }
    }
}


/// SORT FUNCTIONS *******************************************************************************************
void movie_sortByGenre(sMovie* movieList, int lenght, int order)
{
    int i ;
    int j ;
    sMovie auxMovie ;
    int comparison ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(movieList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(movieList[j].state == 1)
                {
                    if(order == 1)
                    {
                        comparison = strcmp(movieList[i].genre,movieList[j].genre);
                        if(comparison < 0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if(order == -1)
                    {
                        comparison = strcmp(movieList[i].genre,movieList[j].genre);
                        if(comparison > 0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void movie_sortByTitle(sMovie* movieList, int lenght, int order)
{
    int i;
    int j;
    sMovie auxMovie;
    int comparison;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(movieList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(movieList[j].state == 1)
                {
                    if(order == 1)
                    {
                        comparison = strcmp(movieList[i].title,movieList[j].title);
                        if(comparison < 0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if(order == -1)
                    {
                        comparison = strcmp(movieList[i].title,movieList[j].title);
                        if(comparison > 0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void movie_sortByYear(sMovie* movieList, int lenght, int order)
{
    int i;
    int j;
    sMovie auxMovie;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(movieList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(movieList[j].state == 1)
                {
                    if(order == 1)
                    {
                        if(movieList[i].releaseYear < movieList[j].releaseYear)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if(order == -1)
                    {
                        if(movieList[i].releaseYear > movieList[j].releaseYear)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void movie_sortByCode(sMovie* movieList, int lenght, int order)
{
    int i;
    int j;
    sMovie auxMovie;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(movieList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(movieList[j].state == 1)
                {
                    if(order == 1)
                    {
                        if(movieList[i].movieCode < movieList[j].movieCode)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if(order == -1)
                    {
                        if(movieList[i].movieCode > movieList[j].movieCode)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
