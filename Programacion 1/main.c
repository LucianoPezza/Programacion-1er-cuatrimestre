#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numero1;
    char letra;
    char palabra[10];

    printf("Ingrese un numero\n");
    scanf("%d",&numero);

    printf("Ingrese numero1\n");
    scanf("%d",&numero1);

    printf("Ingrese una letra\n");
    fflush(stdin);//* una de las soluciones era tambien agregarle un espacio al "%c" provocando asi que al presionar Enter no terminara el proceso(la funcion en linux se llama setbuf(stdin,null))"
    scanf("%c",&letra);

    printf("Ingrese una palabra\n");
    scanf("\n %s",palabra);//no se utiliza el ampersan (&) por que es una cadena de caracteres

    int suma = numero + numero1;

    printf("\nEl numero es: %d\nEl numero1 es: %d\nLa letra es: %c\nY la suma de los numeros es: %d\nLa palabra es:%s\n", numero,numero1,letra,suma,palabra);


    system("pause");//*sirve para que el ejecutable que se encuentra en bin se pause*//






    return 0;
    }
