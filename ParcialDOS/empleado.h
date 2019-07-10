#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[50];
    char genero[50];
    int anio;
} ePelicula;


ePelicula* pelicula_new();

int ePelicula_get_id(ePelicula* ,int* );


ePelicula* pelicula_nuevosParametros(char idAux[50],char nombreAux[50],char empleoAux[50],char edadAux[50]);


int ePelicula_get_id(ePelicula* ,int* this);
int eEmpleado_get_nombre (ePelicula*,char* this);
int eEmpleado_get_genero(ePelicula*,char* this);
int eEmpleado_get_anitos(ePelicula* ,int* this);
int eEmpleado_set_idd(ePelicula*,int* this);
int eEmpleado_set_nombre(ePelicula* ,char* this);
int eEmpleado_set_genero(ePelicula* ptrEmp,char* this);
int eEmpleado_set_anio (ePelicula*,int* this);



#endif // EMPLEADO_H_INCLUDED
