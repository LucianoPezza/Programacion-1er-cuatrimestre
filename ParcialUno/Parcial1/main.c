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
    char nacionalidad[21];
    int idExiste;
    int id;
    int idActorModify;



    do
    {
        opcion = pedirMenu();

        switch(opcion)
        {
        case 1:
            altosActores(listadoActores, CANT);
            break;
        case 2:
            mostrarListadoActores(listadoActores,CANT);
            id = getInt("Ingrese ID de actor a eliminar \n");
            bajaPropietario(listadoActores,CANT,id);
            break;
        case 3:
           mostrarListadoActores(listadoActores, CANT);
            printf("\n");
            idActorModify = getInt("ID a editar\n");
            modificarActorcitoRezarpado(listadoActores, CANT, idActorModify);
            break;
            break;
        case 4:
            do
            {
                opcionListar = getInt("1 Peliculas con actores\n2 Actores con edad ordenada de mayor a menor\n3 Solor actores\n4 Actores mayores de edad\n5 Actores segun nacionalidad\n introduzca una opcion: ");
                switch(opcionListar)
                {

                case 1:
                    mostrarPeliculasConActores(listadoPeliculas,listadoActores,CANT);
                    break;
                case 2:
                    actoresViejoAjoven(listadoActores, CANT);
                    break;
                case 3:
                    mostrarListadoActores(listadoActores,CANT);
                    break;
                case 4:
                     actoresMayoresDeEdad(listadoActores,CANT);
                     break;
                case 5:
                    getString("Ingrese pais\n", nacionalidad);
                     listarActoresPorNacionalidadIngresada(listadoActores, CANT, nacionalidad);
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
