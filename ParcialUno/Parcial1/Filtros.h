#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED


void listarActoresPorGenero(ePelicula[], eActor[], int len, char generoAlistar[21]);

int mostrarPeliculasConActores(ePelicula[], eActor[], int len);

int listarPeliculasPorNacionalidad(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);

int listarPeliculasPorNacionalidadIngresada(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);

void peliculasAgrupadasPorGenero(ePelicula[], int len, char generoAlistar[21]);

void cantidadpeliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21]);

int participaciones(ePelicula listadoPel[], int len, int idAcontar);

void actoresMasParticipativos(ePelicula listadoPel[], eActor listadoAct[], int len);

void actoresQueNoTrabajaron(ePelicula listadoPel[], eActor listadoAct[], int len);

int cantidadPeliculasPorGenero(ePelicula listadoPel[], int len, char generoAcontar[21]);

void generoConMenosPeliculas(ePelicula listadoPel[], int len);

void actoresAntesDeFecha(ePelicula listadoPel[], eActor listadoAct[], int len, int fecha);

void peliculasAgrupadasPorActor(ePelicula listadoPel[], eActor listadoAct[], int len, int idDeActor);

int actoresConEdadesOrdenadas(eActor [], int len);

void actoresViejoAjoven(eActor [], int len);

void actoresMayoresDeEdad(eActor [], int len);

int listarActoresPorNacionalidadIngresada(eActor [], int len, char nacionalidad[21]);

#endif // FILTROS_H_INCLUDED
