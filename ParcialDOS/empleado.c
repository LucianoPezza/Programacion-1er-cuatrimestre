#include "empleado.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>


ePelicula* pelicula_new()
{
    ePelicula* pPelicula;
    pPelicula = (ePelicula*)calloc(sizeof(ePelicula), 1);
    return pPelicula;
}

ePelicula* pelicula_nuevosParametros(char idAux[50],char nombreAux[50],char generoAux[50],char anioAux[50])
{

    ePelicula* auxPelicula = pelicula_new();

    if( auxPelicula != NULL )
    {

        int idAux = atoi(idAux);
        eEmpleado_set_idd(auxPelicula, idAux);
        eEmpleado_set_nombre(auxPelicula, nombreAux);
        eEmpleado_set_genero(auxPelicula, generoAux);

        int anio = atoi(anioAux);
        eEmpleado_set_anio(auxPelicula,anioAux);
    }
    return auxPelicula;
}

int ePelicula_get_id(ePelicula* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->id;
            ret = 0;
        }
    }
    return ret;
}
eEmpleado_get_anitos(ePelicula* ptrEmp,int* this)
{

    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->anio;
            ret = 0;
        }
    }
    return ret;


}


int eEmpleado_get_nombre (ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->nombre);
            ret = 0;
        }
    }
    return ret;
}
int eEmpleado_get_genero(ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->genero);
            ret = 0;
        }
    }
    return ret;
}
int eEmpleado_set_anio (ePelicula* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
           ptrEmp->anio=this;
            ret = 0;
        }
    }
    return ret;
}

int eEmpleado_set_nombre(ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->nombre,this);
            ret = 0;
        }
    }
    return ret;
}
int eEmpleado_set_genero(ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->genero,this);
            ret = 0;
        }
    }
    return ret;
}

int eEmpleado_set_idd(ePelicula* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
           ptrEmp->id=this;
            ret = 0;
        }
    }
    return ret;
}


int employee_sortPorNombre(void* PeliculaA,void* PeliculaB)
{
    char auxNameA [50], auxNameB [50];
    int ret;

    if((PeliculaA != NULL)&&(PeliculaB !=NULL))
    {
        eEmpleado_get_nombre(PeliculaA, auxNameA);
        eEmpleado_get_nombre(PeliculaB, auxNameB);

        ret = stricmp(auxNameA, auxNameB);

    }

    return ret;

}
