#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
int id;
int codigoDePelicula;
char Titulo[50];
char fechaDeEstreno[50];
char genero[50];
char actorP[50];
int estado;
}ePelicula;

#endif // PELICULA_H_INCLUDED

int agregarPelicula(ePelicula[], int);
void InicializarPelicula(ePelicula [], int);
int buscarLibre(ePelicula [],int);
int modificarpelicula(ePelicula [],int);
void mostrarpelicuas(ePelicula);
int buscarPeliculaPorId(ePelicula[], int , int );
int idAutoincremental(ePelicula[], int);
