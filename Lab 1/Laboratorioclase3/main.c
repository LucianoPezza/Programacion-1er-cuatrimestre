#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Clase de arrays
void mostrarVector(int datos[], int tamanio);
void mostarPalabra(char palabra[][10], int tamanio);
void cargarVector(int datos[], int tamanio);
int main()
{
 char usuario[/*10 filas*/][10/*10 columnas*/]={"Jose","Marisa","Jesus","Mendez","Lautaro"};
 int nota [10]={10,9,8,7,6};
 int i;
 int j;
//mostrarVector(nota,5);
mostarPalabra(usuario,5);
//cargarVector(nota, 5);
/* for(i=0;i<5;i++)
{
printf("Alumno: %s Nota:%d \n",usuario[i],nota[i]);
}
/*for(i=0;i<5;i++)
{
for(j=0;j<4;j++){
    printf("%d => %d\n",nota[i],nota[j]);
/*int resultado;
resultado = strcmp("hola","hola");
printf("iguales:%d\n", resultado);
resultado= strcmp("Hola","hola");
printf("\nprimera: %d",resultado);
resultado= strcmp("hola", "Hola");
printf("\nsegunda:%d",resultado);
resultado = strcmp("A","a");
printf("\n la A:%d",resultado);
resultado=strcmp("a","b");
printf("\n la a-b:%d,",resultado);
resultado =strcmp("b","a");
printf("\n la b-a :%d",resultado);
*/
/*if(strcmp(usuario[i],usuario[j])==-1){
 int aux = nota[i];
 nota[i]=nota[j];
 nota[j]=aux;

char auxString[10];
 strcpy(auxString,usuario[i]);
 strcpy(usuario[i], usuario[j]);
 strcpy(usuario[j],auxString);

    }

}
}
//Ordenamiento por nota

for(i=0;i<5;i++)
{
printf("Alumno: %s Nota:%d \n",usuario[i],nota[i]);
}







 /*for(i=0;i<5;i++)Inicializacion de arrays en paralelo
{
  // usuario[i][10]="";
strcpy(usuario[i],"");
//nota[i]=0;

}
for(i=0;i<5;i++){//Muestra de arrays en paralelo
printf("Ingrese usuario # %d:", i+1);
//scanf("%s",&usuario[i]);
gets(usuario[i]);
printf("Ingrese nota # %d:", i+1);
scanf("%d",&nota[i]);
}



//strcpy(usuario[0],"hola");
//printf("test %s \n",usuario[0]);
  //  printf("test %s \n",usuario[1]);



 /*printf("Ingrese usuario :");
 scanf("%s",usuario[0]);
 printf("Ingrese usuario :");
 scanf("%s",usuario[1]);
int tamanio = strlen(usuario[1]);
printf("Tamaño :%d\n",tamanio);

 return 0;



*/
}
/*void mostrarVector(int datos[10], int tamanio){
int i;

for(i=0;i<tamanio;i++){
    printf("Nota: %d\n",datos[i]);
}*/

void mostarPalabra(char palabra[][10], int tamanio){
int i;
for(i=0;i<tamanio;i++)
{
    printf("Palabra: %s\n",palabra[i]);
}

}
void cargarVector(int datos[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++){
        datos[i]=-1;

    }
}
