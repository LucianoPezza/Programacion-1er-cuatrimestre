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
   // int opcionNacionalidad;
    //char nacionalidad[21];
    int idExiste;
    int id;
    int idMod;


    do
    {
        opcion = pedirMenu();

        switch(opcion)
        {
        case 1:

            altaPeliculas(listadoPeliculas, listadoActores, CANT);
            break;
        case 2:
            mostrarListadoActores(listadoActores,CANT);
            id = getInt("Ingrese ID de actor a eliminar \n");
            bajaPropietario(listadoActores,CANT,id);
            break;
        case 3:
            mostrarListadoActores(listadoActores,CANT);
            id = getInt("Ingrese ID del actor a modificar \n");
            idExiste = buscarActorPorID(listadoActores, CANT, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, CANT, id);
            }
            modificarActor(listadoActores,CANT, id, opcionMod);
            break;
        case 4:
            do
            {
                opcionListar = getInt("1 Peliculas con actores\n2 Actores con edad ordenada de mayor a menor\n3 Solor actores\n introduzca una opcion: ");
                switch(opcionListar)
                {

                case 1:
                    mostrarPeliculasConActores(listadoPeliculas,listadoActores,CANT);
                    break;
                case 2:
                    break;
                case 3:
                    mostrarListadoActores(listadoActores,CANT);
                    break;
                default:
                    printf("%s", "Opcion Invalida\n");
                    break;
                }
            }
            while(opcionListar < 1 || opcionListar > 12);

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
