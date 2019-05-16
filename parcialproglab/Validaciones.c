#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "validaciones.h"

int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;

}

float getFloat (char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}

char getChar(char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}

void getStr(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(input);
}


int soloNumeros(char str[])
{
      int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;

}

int SoloLetras (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int numeroAlfa (char str[])
{
     int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}


int getStrLetras(char mensaje[], char input[])
{
    char aux[256];
    getStr(mensaje, aux);
    if(SoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }

    return 0;
}

int getStrNumeros(char mensaje[], char input[])
{
    char aux[256];
    getStr(mensaje, aux);
    if(soloNumeros(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

 int getNumeroAlfa(char mensaje[], char input[])
 {
    char aux[256];
    getStr(mensaje, aux);
    if(numeroAlfa(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }
