#include <stdio.h>
#include <stdlib.h>

void mostrarArray(int*, int);
//1-Cargar enteros, 2-Mostrar,3-Ordenar,4-CacularMax,5-DevolverPromedio
int main()
{
  int variable[5]={1,2,3,4,5};
  mostrarArray(variable,5);

  /*    int* puntero;
    int i;

    puntero=variable;

    printf("%d\n",puntero);
    printf("%d\n",puntero+0);
    printf("%d\n",puntero+1);
    printf("%d\n",puntero+2);

    printf("%d\n", *(puntero+0));
    printf("%d\n", *(puntero+1));
    printf("%d\n", *(puntero+2));


for(i=0;i<5;i++)
{
    printf("%d\n", *(puntero+i));
}
*/
return 0;
}
void mostrarArray(int*pArray, int cant)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d\n", *(pArray+i));
    }
}



/** \brief Permite cargar un caracter
 *
 * \param char* El char a cargar
 * \return int [0] -> Si no se pudo cargar el caracter
            O
           [1] -> Si se pudo cargar el caracter
 *
 */
/*
int getCaracter(char*, char*mensaje,char msjError, char, char);
void mostrarletra(char*);




int main()
{
    int estado;

    estado = getCaracter(&pLetra);

    if(estado ==1)
    {
        printf("Dato cargado con exito!!!");
    }
    else
    {
        printf("El dato no ah sido cargado!!!");
    }
    /*char variableChar;
    char* punteroAChar=NULL;

    punteroAChar = &variableChar;

    printf("Dame tu char: ");
    fflush(stdin);
    scanf("%c",punteroAChar);



    printf("Tu char es : %c", *punteroAChar);

    return 0;
}
void mostrarletra(char*mostrarLetra)
{
    if(mostrarLetra!=NULL)
    {
        printf("Ingrese una letra");
        fflush(stdin);
        scanf("%c",mostrarLetra);
    }
}
int getCaracter(char*pLetra)
{
    int cargo=0;
    if(pLetra!=NULL)
    {
        printf("Ingrese una letra");
        fflush(stdin);
        scanf("%c",pLetra);
        cargo =1;
    }
    return cargo;
}
*/
