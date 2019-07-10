#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED

typedef struct
{
    int id;
    int edad;
    char nombreActor[51];
    char nacionalidad[51];
    int estado;
} eActor;

int inicializarActores(eActor[], int len);

int mostrarListadoActores(eActor[], int len);

int buscarActorPorID(eActor[], int len,int idPropietario);

int modificarActorcitoRezarpado(eActor[], int len, int id);

int bajaActor(eActor[], int len, int id);

int harcodeActores(eActor[], int len);

int buscarLibreActores(eActor[], int len);

int listarActoresPorNacionalidad(eActor[], int len);

int altosActores(eActor[],int len);

int idAutoIncremetalActores(eActor [], int len);



#endif // ACTORES_H_INCLUDED
