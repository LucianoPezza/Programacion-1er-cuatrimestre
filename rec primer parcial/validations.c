#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validations.h"

/**
 * \brief Solicita un numero de opcion y lo valida
 * \param int maxOption La opcion maxima que se puede introducir
 * \return La opcion
 */
int getOption(int maxOption)
{
    int option;

    option = getInt("\nIntroduzca una opcion: ");

    while(option < 1 || option > maxOption)
    {
        printf("\n>>>>> Opcion inexistente <<<<<\n\nIntroduzca una opcion: ");
        setbuf(stdin, NULL);
        scanf("%d",&option);
    }

    return option;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param text Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getUnvalidatedString(char text[], char input[])
{
    printf("%s", text);
    setbuf(stdin, NULL);
    scanf("%s", input);
}

/**
 * \brief Solicita un string
 * \param text Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si son todas letras, 0 si no lo son
 *
 */
int getString(char mensaje[], char input[])
{
   printf(mensaje);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param text Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
     char auxiliarChar[10];
    int enteroADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    enteroADevolver = atoi(auxiliarChar);

    while(enteroADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        enteroADevolver = atoi(auxiliarChar);
    }

    return enteroADevolver;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int itsNumeric(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumbers(char message[],char input[])
{
    char aux[256];
    int correct = 0;

    getUnvalidatedString(message,aux);
    if(itsNumeric(aux))
    {
        strcpy(input,aux);
        correct = 1;
    }

        while(correct == 0)
        {
            printf("\n>>>>> Solo se permite ingresar numeros enteros <<<<<\n");
            getUnvalidatedString(message,aux);
            if(itsNumeric(aux))
            {
                strcpy(input,aux);
                correct = 1;
            }
        }

    return correct;
}

int itsTitle(char title[])
{
    int ret = -1;

    if(title != NULL)
    {
        int i = 0;
        while((title[i] != '\0') && (title[i] != '\n'))
        {
            if(i==0)
            {
                if(isalpha(title[i]) == 0)
                {
                    ret = 0;
                    break;
                }
            }
            else
            {
                if(isalnum(title[i]) != 0)
                {
                    ret = i;
                }
                else
                {
                     ret = 0;
                     break;
                }
            }

           i++;
        }
    }

    return ret;
}
int getTitleValidated(char text[], char input[])
{
   int ret = -1;
   int len;

   if(input != NULL)
   {
        int tries = 0;
        do
        {
            getUnvalidatedString(text, input);

            len = itsTitle(input);

            if(len < 1)
            {
                printf("\n>>>>> El titulo debe ser alfanumerico <<<<<\n");
            }
            else
            {
                //ret = len;
                 ret = 0;
                 break;
            }
            tries ++;

        }while(tries < 5);
    }

    return ret;
}

/**
 * \brief Solicita el numero de opcion de un menu para confirmar los cambios de acuerdo a ese menu
 * \param int menuOption El numero de la opcion del menu principal
 * \return 1 si se confirmaron los cambios, 0 si no se confirmaron
 */
int confirmChanges(int menuOption)//le paso el numero de la opcion del menu principal y muestra el mensaje de confirmacion adecuado para la accion que vaya a realizar
{
    char option;
    int confirmed = 0;

    if(menuOption == 4)
    {
        printf("\n¿Esta seguro que desea modificar? s/n: ");
        setbuf(stdin, NULL);
        option = getchar();

        if(option == 's')
        {
            confirmed = 1;
            printf("\n>>>>> Registro modificado exitosamente <<<<<");
        }
        else
        {
            confirmed = 0;
            printf("\n>>>>> El registro no fue modificado <<<<<");
        }
    }
    else
    {
        if(menuOption == 5)
        {
            printf("\n¿Esta seguro que desea dar de baja? s/n: ");
            setbuf(stdin, NULL);
            option = getchar();

            if(option == 's')
            {
                confirmed = 1;
                printf("\n>>>>> Registro dado de baja exitosamente <<<<<");
            }
            else
            {
                confirmed = 0;
                printf("\n>>>>> El registro no fue dado de baja <<<<<");
            }
        }
    }
    return confirmed;
}

int isLetter(char inputData)
{
    int isValid;

    if(inputData > 'z' || inputData < 'a')
    {
        if(inputData > 'Z' || inputData < 'A')
        {
            isValid = 0;
        }
        else
        {
            isValid = 1;
        }
    }
    else
    {
        isValid = 1;
    }
    return isValid;
}

int isTitle(char* inputData)
{
    int itIs = 0;

    if(isLetter(inputData[0]))
    {
        itIs = 1;
    }
    return itIs;
}
