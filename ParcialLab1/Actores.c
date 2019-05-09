#include <stdio.h>
#include <stdlib.h>
#include "Actores.h"

void hardcodearActores(eActor lista[], int cant)
{


char nombre[5][50]={"Julieta Roberto","Roberto Deniro","Richar Darin","Tita Merelo","Sandro"};
char pais[5][50]={"EEUU","EEUU","Argentina","Argentina","Argentina"};
 int i;
  for(i=0;i<cant;i++)
  {
    strcpy(lista[i].nombre,nombre[i]);
    strcpy(lista[i].pais,pais[i]);
    lista[i].id=111;
 }
}
void mostrarActores(eActor lista)
{
 printf("%s\t%s",lista.nombre,lista.pais);
}
