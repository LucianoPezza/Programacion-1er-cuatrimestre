#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

///FILTERS **************
int filter_actorsOfLegalAge(sActor actorList[], int len);
int filter_actorsByGenre(sMovie[], sActor[], int, char[21]);

int filter_moviesWithActors(sMovie[], sActor[], int);
int filter_moviesByOrigin(sMovie[], sActor[], int, char[21]);
int filter_moviesByInputOrigin(sMovie[], sActor[], int, char[21]);
void filter_moviesByInputGenre(sMovie[], int, char[21]);

void filter_numberOfMoviesGroupedByGenre(sMovie[], int, char[21]);
int filter_participations(sMovie[], int, int);
void filter_moreParticipatoryActors(sMovie[], sActor[], int);
int filter_numberOfMoviesByGenre(sMovie[], int, char[21]);
void filter_genreWithLessMovies(sMovie[], int);
void filter_actorsWhoDidNotWork(sMovie[], sActor[], int);

#endif // FILTROS_H_INCLUDED
