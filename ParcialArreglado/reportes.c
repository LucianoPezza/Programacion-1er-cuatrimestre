#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int listarActoresPorGenero(ePelicula listadoPel[], eActor listadoAct[], int len,  char generoAlistar[21])
{





    return 0;
}

int mostrarPeliculasConActores(ePelicula listado[], eActor listadoActores[], int len)
{
    int i;
    int idAux;
    printf("%s\t %s\t %s\t %s\t %s\t %s\t \n", "ID", "codigoPelicula", "titulo", "fechaDeEstreno", "genero", "Uptor");

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado==0)
        {
            idAux = buscarActorPorID(listadoActores,len,listado[i].idActor);
            printf("%d\t  %d\t  %s\t %d\t %s\t %s\t \n", listado[i].id, listado[i].codigoPelicula, listado[i].titulo, listado[i].fechaDeEstreno, listado[i].genero, listadoActores[idAux].nombreActor);
        }


    }



    return 0;
}


int listarPeliculasPorNacionalidad(ePelicula listadoPel[], eActor listadoAct[], int len,  char nacionalidadAlistar[21])
{
    int i;
    int j;
    for(i=0; i<len;i++)
    {
        if(listadoPel[i].estado==0 && stricmp(nacionalidadAlistar, listadoAct[i].nacionalidad)==0)
        {
            for(j=0; j<len; j++)
            {
                if(listadoPel[j].idActor==listadoAct[i].id)
                {
                    printf("\n%s",listadoPel[j].titulo);
                }
            }

        }

    }
    return 0;
}

int listarPeliculasPorNacionalidadIngresada(ePelicula listadoPel[], eActor listadoAct[], int len,  char nacionalidadAlistar[21])
{



    return 0;
}

void peliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21])
{


}

void cantidadpeliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21])
{

}
