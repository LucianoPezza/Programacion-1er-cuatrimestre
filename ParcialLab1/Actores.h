#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED
typedef struct
{
int id;
char nombre[5][50];
char pais[5][50];
}eActor;


#endif // ACTORES_H_INCLUDED
void hardcodearActores(eActor[], int);
void mostrarActores(eActor);
