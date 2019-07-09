#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"

void controller_loadMovie(sMovie*, int, sActor*, int);
int controller_deleteMovie(sMovie*, int, sActor*, int);
void controller_modifyMovie(sMovie*, int, sActor*, int);
void controller_sortMovies(sMovie*, int);

int controller_loadActor(sActor* actorList, int actorLenght);
int controller_deleteActor(sActor* actorList, int actorLenght);
void controller_modifyActor(sActor* actorList, int actorLenght);

#endif // CONTROLLER_H_INCLUDED
