#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu_main();
int menu_movieGenre();
int menu_movieModify();
int menu_movieList();
int menu_movieSort();
int menu_order();
int menu_filter();
void menu_printFilterList(sMovie* movieList, int lenght, sActor* actorList, int actorsLenght);
int menu_actorModify();

#endif // MENU_H_INCLUDED
