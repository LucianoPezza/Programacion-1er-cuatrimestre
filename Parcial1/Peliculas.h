#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    int codigoPelicula;
    char titulo[51];
    int fechaDeEstreno;
    char genero[21];
    int estado;
    int idActor;
} ePelicula;

int inicializarPeliculas(ePelicula[], int len);

int altaPeliculas(ePelicula[], eActor[], int len);

int mostrarListadoPeliculas(ePelicula[], int len);

int buscarPeliPorID(ePelicula[], int len,int id);

int bajaPelicula(ePelicula[], int len, int id);

int harcodePeliculas(ePelicula[], int len);

int buscarLibrePelicula(ePelicula[], int len);

int modificacionPelicula(ePelicula[], eActor[], int len, int id, int option);

int listarPeliculasPorFecha(ePelicula[], int len);

int verificarCodigo(ePelicula listadoPeliculas[], int len, int codigoPelicula);


#endif // PELICULAS_H_INCLUDED
