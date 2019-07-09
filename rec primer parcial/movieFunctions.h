#ifndef MOVIEFUNCTIONS_H_INCLUDED
#define MOVIEFUNCTIONS_H_INCLUDED
typedef struct
{
    int id;
    int state;
    int movieCode;
    int releaseYear;
    int mainActorID;
    char title[51];
    char genre[51];
}sMovie;
#endif // MOVIEFUNCTIONS_H_INCLUDED

void movie_init(sMovie*, int);
void movie_hardcode(sMovie*);

int movie_getEmptySpace(sMovie*, int);
int movie_getId(void);
int movie_getCode(sMovie*, int, int*);
int movie_existingCode(sMovie*, int, int);
int movie_getTitle(char*, int);
int movie_getGenre(char*);
int movie_getYear(int*);
int movie_getActorID(sActor*, int, int*);
int movie_getByID(sMovie*, int, int);
int movie_getOrder(void);

/// PRINT ***************
void printMovieList(sMovie*, int, sActor*, int);
void printMovieListNoActor(sMovie*, int);
void printOneMovie(sMovie, char*);

/// SORT ***************
void movie_sortByGenre(sMovie*, int, int);
void movie_sortByTitle(sMovie*, int, int);
void movie_sortByYear(sMovie*, int, int);
void movie_sortByCode(sMovie*, int, int);

