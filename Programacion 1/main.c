#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char nombre[6];
char otroNombre[50]="Jose Perez";
//int largo;
int compara;
//strcpy(nombre, otroNombre);
strncpy(nombre, otroNombre,5;
printf("Su nombre es: %s", nombre);

compara = strcmp(nombre, "pepe");
//printf("Ingrese su nombre: ");
//fgets(nombre, 50, stdin);
//scanf("%[^\a]", nombre);
//gets(nombre);

//largo = strlen(nombre);
//printf("\n%d",largo);

//printf("%d",compara);
/*if(nombre == "pepe")
{

printf("Usted se llama pepe");

}
*/
return 0;
}
