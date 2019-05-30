#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO".\\Alumnos.csv"

typedef struct
{
 char nombre[50];
 int nota;
 int legajo;

}eAlumno;


int main()
{
    eAlumno Alumno;
    FILE* pArchivo = NULL;
    char texto[]="kakaka,222,7";
    if((pArchivo=fopen(ARCHIVO,"w"))==NULL)
    {
        printf("No se pudo leer");
        exit(1);
    }else
    {
        int largo=strlen(texto);
        printf("El archivo esta abierto\n");
        //fwrite(&eAlumno0,sizeof(eAlumno),1,pArchivo);
        fwrite(texto,sizeof(char),largo,pArchivo);
        printf("%s",texto);
    }
    //pArchivo=fclose(ARCHIVO);
     if((pArchivo=fopen(ARCHIVO,"r"))==NULL)
     {
        printf("No se pudo leer");
        exit(1);
     }else
     {
         char renglon[50];
         while(!feof(pArchivo))
         {
           int cantidad = fread(renglon,sizeof(char),70,pArchivo);
           printf("Cantidad %d y Texto %s",cantidad,texto);
         }
     }

    return 0;
}
