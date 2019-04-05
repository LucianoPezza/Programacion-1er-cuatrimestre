#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char nombre[50];
char otroNombre[50]="Jose";
int largo;
int compara;
strcpy(nombre, otroNombre);
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
