#include <stdio.h>
#include <string.h>
#include "peliculas.h"


void InicializarPelicula(ePelicula lista[], int cant)
{
  int i;
  for(i=0;i<cant;i++)
  {
    strcpy(lista[i].Titulo," ");
    strcpy(lista[i].fechaDeEstreno," ");
    strcpy(lista[i].genero," ");
    strcpy(lista[i].actorP," ");
    lista[i].codigoDePelicula=0;
  }

int buscarLibre(ePelicula lista[], int cant)
{
int i;
int aux = -1;
for(i=0;i<cant;i++)
{
    if(lista[i].estado==LIBRE)
    {
        aux = i;
        break;
    }
}
  return aux;
}


ePelicula pedirpelicula()
{
ePelicula peliculaParaRecibir;

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(peliculaParaRecibir.Titulo);

    printf("Ingrese la fecha de estreno de la pelicula: ");
    fflush(stdin);
    gets(peliculaParaRecibir.fechaDeEstreno);

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(peliculaParaRecibir.genero);

    printf("Ingrese el actor principal de la pelicula: ");
    fflush(stdin);
    gets(peliculaParaRecibir.actorP);

    printf("Ingrese el codigo de la pelicula");
    scanf("%d",&peliculaParaRecibir.codigoDePelicula);

    return peliculaParaRecibir;
}

}
int agregarpeliculas(ePelicula lista[], int cant)
    {
        int indice;
        indice = buscarLibre(lista, cant);
        if(indice != -1)
        {
            lista[indice]= pedirpelicula();
        }
         else
    {
        printf("No hay mas lugar.");
    }
        return indice;
    }

void mostrarpelicuas(ePelicula lista)
{
    printf("%s\t%s\t%s\t%s\t%d", lista.Titulo,lista.genero,lista.fechaDeEstreno,lista.actorP,lista.codigoDePelicula);
}
