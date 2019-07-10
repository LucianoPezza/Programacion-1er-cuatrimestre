#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleado.h"


int parser_PeliculasFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    ePelicula* auxPelicula = pelicula_new();
    int r;
    int i = 0;
    char idAux[50],nombreAux[50],anioAux[50],generoAux[50];

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,generoAux, anioAux);
        if(r==4)
        {
            auxPelicula = pelicula_nuevosParametros(idAux,nombreAux,generoAux, anioAux);
            ll_add(pArrayListEmployee, auxPelicula );
            i++;
        }
    }
    printf("Se cargaron %d empleados a la lista (modo texto)\n", i);

    return i;

}
