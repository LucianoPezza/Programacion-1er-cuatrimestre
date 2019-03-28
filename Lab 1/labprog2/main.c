#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int EsUnNumero(char *cadena)
{
//printf("\nPalabra:%s",palabra);
int indice = 0;
int retorno = 0;
int indice= 0;

while(cadena[indice]!='\0')
{
    if(cadena[indice]<'\0' || cadena[indice]>'9')
    {
        break;
    }else
    {
      indice++;
    }
}

}
if(cadena[indice]!='\0')
{
return retorno;
}

int main()
{
char letra;
char palabra[10];
int numero;
int indice = 0;
esUnNumero(palabra)

/*printf("Ingrese una letra we\n");
scanf("%d",&letra);
fflush(stdin);
printf("\nletra: %d",letra);

printf("\nAhora ingresame una palabra we\n");
scanf("\n%s",&palabra);
fflush(stdin);
printf("\palabra: %s",palabra);
while(indice<10){

    if(palabra[indice]=='\0'])
        {
        printf("el barra cero esta en: %c",palabra);
    }

    printf("\n letra %c",palabra[indice]);
    indice ++;
}

//saludar();

 //int miDato = 333;
 //cambiarValor(miDato);
 //printf("mi dato es:%d",miDato);

 int dato;
dato = dividir(3);
    printf("el dato es: %d",dato);
    dato = dividir(0);
    printf("\nel dato es: %d",dato);

    int unfactorear;
    unfactorear = factorear(5);
    printf("el factoreo es: %d", unfactorear);

    int edad;
    int retorno;
    do{
    printf("Ingrese una edad:");
    retorno=scanf("%d",&edad);
    fflush(stdin);

    }while(retorno ==0);




printf("La respuesta es: %d ", retorno);
printf("\nLa edad es es: %d", edad);
return 0;
*/
}






