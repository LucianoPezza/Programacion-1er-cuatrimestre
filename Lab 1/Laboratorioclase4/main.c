#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Cantidad_de_Alumnos 4

void puntero(char*nombre,char*apellido,int*nota,int*edad);
void getstring(char mensaje[],char input[]);
int esSololetras(char[]);

int main()
{
    char nombres[Cantidad_de_Alumnos][50]={"El chavo","Pedro","Lucas","Don"};
    char apellido[Cantidad_de_Alumnos][50]={"Del 8","Delaspraderas","Perez","Ramon"};
    int edad[Cantidad_de_Alumnos]={15,14,13,12};
    int nota[Cantidad_de_Alumnos]={10,9,8,7};
    float promedio;
int i;
for(i=0;i<Cantidad_de_Alumnos;i++)
    {
    if(nombres[i] !=-1)
    {
      printf("\n Nombre: %s\n Apellido: %s\n Edad: %d\n Notas: %d",nombres[i], apellido[i], edad[i], nota[i]);
    }

}
char getnombre[50];
strcpy(nombres[0],getnombre );
strcpy(apellido[0],getnombre );

for(i=0;i<Cantidad_de_Alumnos;i++)
{
getstring("\n Reemplazale el nombre: \n", nombres);
getstring("\n Reemplazale el Apellido:\n", apellido);
 if(nombres[i] !=-1)
    {
      printf("\n Nombre: %s\n Apellido: %s\n Edad: %d\n Notas: %d",nombres[i], apellido[i], edad[i], nota[i]);
    }

}
return 0;
}
void getstring(char mensaje[], char input[])
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

}
