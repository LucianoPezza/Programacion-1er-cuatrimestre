#ifndef ACTORFUNCTIONS_H_INCLUDED
#define ACTORFUNCTIONS_H_INCLUDED
// 1 TAKEN / 0 EMPTY / -1 DELATED
typedef struct
{
    int id;
    int state;
    char name[51];
    char origin[51];
    int age;
} sActor ;
#endif // ACTORFUNCTIONS_H_INCLUDED

void actor_hardcode(sActor*);
int actor_getFreeSpace(sActor*, int);
int actor_getByID(sActor[], int, int);
int actor_getId(void);
void actor_printOne(sActor);
void actor_printList(sActor*,int);
void actor_sortByOrigin(sActor*, int);
void actor_sortByAge(sActor*, int, int order);

int actor_getAge(int* retAge);
int actor_getName(char* retString); //int tries);
int actor_getOrigin(char* retString); //int tries);
