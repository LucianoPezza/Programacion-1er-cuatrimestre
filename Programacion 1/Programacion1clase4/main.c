#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CantidaddeAlumnos 4

//void puntero(char*nombre,char*apellido,int*nota,int*edad);
//void getstring(char mensaje[],char input[]);
//int esSololetras(char[]);
void mostrarAlumnos(char[][50], char[][50],int [], int[], int);
void ordenarAlumnos(char[][50], char[][50],int [], int[], int);


int main()
{
    char nombres[CantidaddeAlumnos][50]={"Martin","Agustin","Lucas","Don"};
    char apellido[CantidaddeAlumnos][50]={"Coronel","Ramirez","Perez","Ramon"};
    int edad[CantidaddeAlumnos]={15,14,13,12};
    int nota[CantidaddeAlumnos]={10,9,8,7};



mostrarAlumnos(nombres,apellido,edad,nota,CantidaddeAlumnos);
ordenarAlumnos(nombres,apellido,edad,nota,CantidaddeAlumnos);

}
void mostrarAlumnos(char nombres[][50], char apellido[][50],int edad[], int nota[], int  CantidaddeAlumnos)
{
    for(i=0;i<CantidaddeAlumnos;i++)
    {
    if(nombres[i] !=-1)
    {

    }
      printf("Nombre: %s\t Apellido:%s\t Edad: %d\t Notas: %d\n",nombres[i],apellido[i],edad[i],nota[i]);
    }


}
void ordenarAlumnos(char nombres[][50], char apellido[][50],int edad[], int nota[], int CantidaddeAlumnos)
{
    int auxentero;
    char auxCadena[50];
    int i, j;
    for(i=0; 1<CantidaddeAlumnos-1;i++)
    {
        for(j=i+1; j<TAM4; j++)
        {

            if(strcmp(nombre[i],nombre[j])>0)
            {
                strcpy(auxCadena,nombre[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j], auxCadena);

                strcpy(auxCadena,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j], auxCadena);

                auxentero = edad[i];
                edad[i] = edad[j];
                edad[j] = auxentero;

                auxentero = nota[i];
                nota[i] = nota[j];
                nota[j] = auxentero;
            }
        }
    }


}









/*void getstring(char mensaje[], char input[])
{
printf(mensaje);
scanf("%s",input);
}
int esSololetras(char palabra[])
{
 int i;
 for(i=0; i;;)
    {
    if(palabra[i]<'a'&& palabra[i]>'a')
}
}
int esSololetras(char[])
{
int i;
while(palabra[i]!= -º)

}*/
