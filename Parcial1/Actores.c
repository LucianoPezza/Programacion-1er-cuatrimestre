#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Actores.h"
#include "Peliculas.h"


int inicializarActores(eActor listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}
int modificarActor(eActor listadoActores[], int len, int id, int option)
{
    char nombreActor[51];
    int edadActor;
    int idActor;
    int idExiste;
    int posAeditar= buscarActorPorID(listadoActores,len,idActor);
    if(posAeditar == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        getString(" Ingrese nuevo nombre \n", nombreActor);

        while(esNumerico(nombreActor)==1)
        {
            getString(" Ingrese un nombre valido: \n", nombreActor);
        }
        strcpy(listadoActores[posAeditar].nombreActor, nombreActor);
        break;
    case 2:
        edadActor = getInt("Ingrese Nueva edad: \n");
        while(edadActor< 10|| edadActor > 90)
        {
            edadActor = getInt("Reingrese una edad valida (entra 10 y 90) \n");
        }

        listadoActores[posAeditar].edad = edadActor;
        break;
    case 3:
        mostrarListadoActores(listadoActores, len);
        idActor = getInt("ID del actor\n");
        idExiste = buscarActorPorID(listadoActores, len, idActor);
        while(idExiste == -1)
        {
            idActor = getInt("Reingrese una ID de Actor valida\n");
            idExiste = buscarActorPorID(listadoActores, len, idActor);;
        }
        listadoActores[posAeditar].id = idActor;
        break;
    }
    return 0;
}


int mostrarListadoActores(eActor listado[], int len)
{
    int i;
    printf("%s  %10s  %20s %5s", "ID", "Nombre", "Nacionalidad", "Edad");

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("\n%d   %10s   %15s  %5d  \n", listado[i].id, listado[i].nombreActor, listado[i].nacionalidad, listado[i].edad);
        }

    }
    return 0;
}

int buscarActorPorID(eActor listado[], int len,int id)
{
    int i;

    for(i = 0; i<len; i++)
    {
        if(listado[i].id == id)
        {
            return i;
        }
    }

    return -1;

}

int bajaPropietario(eActor listado[], int len, int id)
{

    int idAborrar = buscarActorPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}


int harcodeActores(eActor listado[], int len)
{
    int i;

    int id[5]= {1, 2, 3, 4, 5};
    char nombreActor[5][50]= {"Julieta robert", "Richar darin", "Nicole Kidman", "Tita merello", "Natalia Oreiro"};
    char nacionalidad[5][13]= {"EEUU", "Argentina", "Australiana ", "Argentina", "Uruguay"};
    int edad[5]={33 , 77, 11 , 18, 33};
    int estado[5]= { 0, 0, 0, 0};

    for(i=0; i<5; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombreActor,nombreActor[i]);
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].estado = estado[i];
        listado[i].edad=edad[i];

    }
    return -1;
}


int buscarLibreActores(eActor listado[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(listado[i].estado ==1)
        {
            id = i+1000;
            break;
        }
    }
    return id;
}

int listarActoresPorNacionalidad(eActor listado[], int len)
{
    int i;
    int j;
    eActor aux;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listado[i].estado==0 && listado[j].estado==0)
            {
                if(stricmp(listado[i].nacionalidad, listado[j].nacionalidad)>0)
                {
                    aux =listado[i];
                    listado[i] = listado[j];
                    listado[j] = aux;
                }


            }
        }

    }
    mostrarListadoActores(listado, len);
    printf("\n");
    return 0;
}
