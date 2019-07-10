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

int modificarActorcitoRezarpado(eActor listadoAct[], int len, int id)
{
    char nombre[51];
    char nacionalidad[51];
    int edadActor;

    int posAeditar = buscarActorPorID(listadoAct, len, id);
    int opcion;
    if(posAeditar == -1)
    {
        return -1;
    }
    opcion = pedirOpcionModificacionActor();
    switch(opcion)
    {
    case 1:
        getString(" Ingrese nuevo nombre del actor \n", nombre);
        strcpy(listadoAct[posAeditar].nombreActor, nombre);
        break;
    case 2:
        getString(" Ingrese nueva nacionalidad del actor \n", nacionalidad);
        strcpy(listadoAct[posAeditar].nacionalidad, nacionalidad);
        break;
    case 3:
        edadActor = getInt("Ingrese nueva edad\n");

        while(edadActor < 0 || edadActor > 100)
        {
            edadActor = getInt("Reingrese una edad valida 0/100 \n");
        }

    listadoAct[posAeditar].edad = edadActor;

        break;
    }
    return 0;
}

int altosActores(eActor listadoActores[],int len)
{
    int idActor;
    char nombreDeActor[50];
    char nacionalidad[50];
    int idExiste;
    int edadActor;
    int estadoActores;

    idActor = idAutoIncremetalActores(listadoActores,len);

    getString(" Ingrese nombre:  ", nombreDeActor);

    while(esNumerico(nombreDeActor)==1)
    {
        getString("\nError. Tiene que ser solo letras, ingrese un nuevo titulo: \n", nombreDeActor);
    }

    getString("\n Ingrese nacionalidad: ", nacionalidad);

    while(esNumerico(nombreDeActor)==1)
    {
        getString("\nError. Tiene que ser solo letras, ingrese un nuevo titulo: ",nombreDeActor);
    }

    edadActor = getInt("\nIngrese la edad del actor: ");
    while(edadActor<10 || edadActor>90)
    {
        edadActor= getInt("\nIngrese una edad valida (Entre 10 y 90 anios)");
    }


    int i;
    for(i = 0; i<len; i++)
    {
        if(listadoActores[i].estado == 1)
        {
            listadoActores[i].edad=edadActor;
            strcpy(listadoActores[i].nacionalidad, nacionalidad);
            strcpy(listadoActores[i].nombreActor, nombreDeActor);
            listadoActores[i].id=idActor;
            listadoActores[i].estado= 0;
            return 0;
        }
    }
    return -1;
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
int idAutoIncremetalActores(eActor listado[], int len)
{
    int i;
    int id=1;

    for(i=0; i<len; i++)
    {
        if(listado[i].estado ==1)
        {
            id+=i;
            break;
        }
    }
    return id;
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
