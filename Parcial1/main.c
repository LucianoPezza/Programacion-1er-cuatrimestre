#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "Actores.h"
#include "Peliculas.h"
#include "Menu.h"
#include "Validaciones.h"
#include "Filtros.h"
#define CANT 50

int main()
{
    eActor listadoActores[CANT];
    ePelicula listadoPeliculas[CANT];

    inicializarActores(listadoActores, CANT);
    harcodeActores(listadoActores, CANT);

    inicializarPeliculas(listadoPeliculas, CANT);
    harcodePeliculas(listadoPeliculas, CANT);

    int opcion;
    int opcionMod;
    int opcionListar;
    char seguir = 's';
    int opcionNacionalidad;
    char nacionalidad[21];
    int idExiste;
    int id;


    do
    {
        opcion = pedirMenu();

        switch(opcion)
        {
        case 1:

            altaPeliculas(listadoPeliculas, listadoActores, CANT);

            break;
        case 2:

          do{
                 opcionListar = mostrar();

            switch(opcionListar)
            {

            case 1:

                peliculasAgrupadasPorActor(listadoPeliculas, listadoActores, CANT, 2);
                mostrarListadoPeliculas(listadoPeliculas, CANT);
                break;
            case 2:
                mostrarPeliculasConActores(listadoPeliculas, listadoActores, CANT);
                break;
            case 3:
                listarPeliculasPorFecha(listadoPeliculas, CANT);
                break;
            case 4:
                listarActoresPorNacionalidad(listadoActores, CANT);
                break;
            case 5:
                printf("  Peliculas con actores y genero \n");
                mostrarPeliculasConActores(listadoPeliculas, listadoActores, CANT);
                printf("\n");
                break;

            case 6:
                listarPeliculasPorNacionalidad(listadoPeliculas, listadoActores, CANT, "EEUU");
                printf("\n");
                break;
            case 7:
                do
                {
                    opcionNacionalidad = pedirNacionalidad();

                    switch(opcionNacionalidad)
                    {
                    case 1:
                        strcpy(nacionalidad, "EEUU");
                        break;
                    case 2:
                        strcpy(nacionalidad, "Argentina");
                        break;
                    case 3:
                        strcpy(nacionalidad, "Australia");
                        break;
                    case 4:
                        strcpy(nacionalidad, "Uruguay");
                        break;
                    default:
                        printf("opcion invalida \n");
                        break;
                    }
                }
                while(opcionNacionalidad > 4 || opcionNacionalidad < 1);
                listarPeliculasPorNacionalidadIngresada(listadoPeliculas, listadoActores, CANT, nacionalidad);
                break;
            case 8:
                peliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Accion");
                peliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Terror");
                peliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Comedia");
                peliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Romantica");
                peliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Otro");
                break;
            case 9:
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Accion");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Terror");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Comedia");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Romantica");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, CANT, "Otro");
                printf("\n");
                break;
            case 10:
                actoresMasParticipativos(listadoPeliculas, listadoActores, CANT);
                break;
            case 11:
                generoConMenosPeliculas(listadoPeliculas, CANT);
                break;
            case 12:
                actoresQueNoTrabajaron(listadoPeliculas, listadoActores, CANT);
                break;
            default:
                printf("%s", "Opcion Invalida\n");
                break;
            }
          }
          while(opcionListar < 1 || opcionListar > 12);
          break;
        case 3:
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, CANT);
            id = getInt("Ingrese ID de Pelicula a modificar \n");
            idExiste = buscarPeliPorID(listadoPeliculas, CANT, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, CANT, id);

            }
            opcionMod = pedirPelicula();
            modificacionPelicula(listadoPeliculas, listadoActores, CANT, id, opcionMod);
            break;
        case 4:
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, CANT);
            id = getInt("Ingrese ID de pelicula a remover\n");
            idExiste = buscarPeliPorID(listadoPeliculas, CANT, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, CANT, id);

            }

            bajaPelicula(listadoPeliculas, CANT, id);
            break;
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion invalida \n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}
