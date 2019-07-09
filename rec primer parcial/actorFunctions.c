#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actorFunctions.h"
#include "movieFunctions.h"
#include "validations.h"

void actor_hardcode(sActor* actorList)
{
    char names[5][31] = {"Julieta roberto" ,"Richard darin" ,"Nicole Kidman" ,"Tita merello" ,"Natalia Oreiro"};
    char origins[5][21] = {"EEUU" ,"Argentina" ,"Australia" ,"Argentina" ,"Uruguay"};
    int ages[5] = {33, 77, 11, 18, 33};
    int i;
    int newID;

    for(i=0; i<5; i++)
    {
        newID = actor_getId();
        actorList[i].id = newID;
        strcpy(actorList[i].name, names[i]);
        strcpy(actorList[i].origin, origins[i]);
        actorList[i].age = ages[i];
        actorList[i].state = 1;
    }
}

int actor_getFreeSpace(sActor* actorList, int listLenght)
{
    int i;
    for(i=0; i<listLenght; i++)
    {
        if(actorList[i].state == 0)
        {
            break;
        }
    }
    return i;
}

int actor_getByID(sActor actorList[], int len, int id)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(actorList[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int actor_getId(void)
{
    static int maxId = 0 ;
    return maxId++;
}

void actor_printOne(sActor actor)
{
    printf("\n%d     %5s    %5s    %d", actor.id, actor.name, actor.origin, actor.age);
}

void actor_printList(sActor* actorList, int lenght)
{
    int i;
    printf("\nID         NOMBRE          ORIGEN      EDAD\n__________________________________________\n");

    for(i=0; i<lenght; i++)
    {
        if(actorList[i].state == 1)
        {
            actor_printOne(actorList[i]);
        }
    }
}

void actor_sortByOrigin(sActor* actorList, int lenght)
{
    int order = 1;
    int i;
    int j;
    sActor auxActor;
    int comparison;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(actorList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(actorList[j].state == 1)
                {
                    if(order == 1)
                    {
                        comparison = strcmp(actorList[i].origin,actorList[j].origin);
                        if(comparison < 0)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                    else if(order == -1)
                    {
                        comparison = strcmp(actorList[i].origin,actorList[j].origin);
                        if(comparison>0)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                }
            }
        }
    }
}
void actor_sortByAge(sActor* actorList, int lenght, int order)
{
    int i;
    int j;
    sActor auxActor;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for(i=0; i<(lenght - 1); i++)
    {
        if(actorList[i].state == 1)
        {
            for(j=i+1; j<lenght; j++)
            {
                if(actorList[j].state == 1)
                {
                    if(order == 1)
                    {
                        if(actorList[i].age < actorList[j].age)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                    else if(order == -1)
                    {
                        if(actorList[i].age > actorList[j].age)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                }
            }
        }
    }
}

int actor_getAge(int* retAge)
{
    int auxAge = 0;
    int itsDone = 0;

    auxAge = getInt("\nIngrese la edad: ");

    while(auxAge > 100 || auxAge < 1 )
    {
        printf("\n>>>>> La edad es invalida <<<<<\n");
        auxAge = getInt("\nIngrese la edad: ");
    }

    if(auxAge >= 1 && auxAge <= 100)
    {
        *retAge = auxAge;
        itsDone = 1;
    }
    return itsDone;
}

int actor_getName(char* retString/*, int tries*/)
{
    int isValid = 0;
    char auxInput[51];

    do
    {
        printf("\nIngrese el nombre: ");
        setbuf(stdin, NULL);
        fgets(auxInput,51,stdin);

        while(!(isTitle(auxInput)))
        {
            //tries--;

           /* if(tries<=0 )
            {
                break;
            }*/
            printf("\n>>>>> El nombre es invalido <<<<<\n");
            printf("\nIngrese el nombre: ");
            setbuf(stdin, NULL);
            fgets(auxInput,51,stdin);
        }
    }while(/*tries > 0 &&*/ !(isTitle(auxInput)));

    if(isTitle(auxInput))
    {
        strcpy(retString,auxInput);
        isValid = 1;
    }

    return isValid;
}

int actor_getOrigin(char* retString)
{
    int isValid = 0;
    char auxInput[51];

    do
    {
        printf("\nIngrese el origen: ");
        setbuf(stdin, NULL);
        fgets(auxInput,51,stdin);

        while(!(isTitle(auxInput)))
        {
            //tries--;

            //if(tries<=0 )
            //{
                //break;
            //}
            printf("\n>>>>> El origen es invalido <<<<<\n");
            printf("\nIngrese el origen: ");
            setbuf(stdin, NULL);
            fgets(auxInput,51,stdin);
        }
    }while(/*tries > 0 &&*/ !(isTitle(auxInput)));

    if(isTitle(auxInput))
    {
        strcpy(retString,auxInput);
        isValid = 1;
    }

    return isValid;
}
