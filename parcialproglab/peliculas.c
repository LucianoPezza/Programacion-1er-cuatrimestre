#include <stdio.h>
#include <string.h>
#include "peliculas.h"
#include "validaciones.h"


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


int buscarPeliculaPorId(ePelicula lista[], int cant, int id)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==OCUPADO && lista[i].id==id)
        {
            return i;
        }
    }

    return -1;
}

int idAutoincremental(ePelicula lista[], int cant)
{
    int retorno = 1000;
    int i;
    if(cant > 0 && lista != NULL)
    {
        for(i=0; i<cant; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                if(lista[i].id > retorno)
                {
                    retorno = lista[i].id;
                }
            }
        }
    }
    return retorno+1;
}

int agregarPelicula(ePelicula lista[], int cant)
{
 int retorno = -1;
    int i;
    int k;

    char auxTitulo[50];
    char auxFechaDeEstreno[50];
    char auxGenero[50];
    int id;

    i = buscarLibre(lista, cant);
    id = idAutoincremental(lista, cant);

   if(i>=0)
    {
        printf("Ingrese el titulo de la pelicula:");
        fflush(stdin);
        gets(auxTitulo);
        while(SoloLetras(auxTitulo)==LIBRE)
        {
            printf("Usted ha ingresado un titulo incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxTitulo);
        }

        for (k=0; k<cant; k++)
        {
            if (lista[k].estado == OCUPADO)
            {
                while (stricmp(lista[k].Titulo, auxTitulo) == 0)
                {
                    printf("El titulo de esta pelicula esta repetido. Ingrese otro titulo: ");
                    fflush(stdin);
                    gets(auxTitulo);
                }
            }
        }
        strcpy(lista[i].Titulo, auxTitulo);



        printf("Ingrese el genero de la pelicula :");
        fflush(stdin);
        gets(lista[i].genero);

        while(SoloLetras(lista[i].genero)==0)
        {
            printf("Genero incorrecto. Ingrese un genero valido: ");
            fflush(stdin);
            gets(lista[i].genero);
        }
        strcpy(lista[i].genero, auxGenero);



        printf("Ingrese la fecha de estreno:");
        fflush(stdin);
        gets(lista[i].fechaDeEstreno);

        while(SoloLetras(auxFechaDeEstreno)==LIBRE)
        {
            printf("Fecha de estreno incorrecta. Ingrese una fecha correcta: ");
            fflush(stdin);
            gets(lista[i].fechaDeEstreno);
        }
        strcpy(lista[i].fechaDeEstreno, auxFechaDeEstreno);



        lista[i].estado=OCUPADO;
        lista[i].id=id;
        retorno=0;
    }
    return retorno;
}

void printearPeliculas (ePelicula lista)
{
    printf("%d %10s %10s %10s\n", lista.id, lista.Titulo, lista.genero, lista.fechaDeEstreno);
}

int mostrarPeliculas(ePelicula lista[], int cant)
{
    int i;
    printf("\n\nID -- \t TITULO \t GENERO \t FECHA DE ESTRENO\n\n");
    for(i=0; i<cant; i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            printearPeliculas(lista[i]);
        }

    }
return 0;
}
