#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define CANT 4

int main()
{
    int opcion;
    Employee list[CANT];
    initEmployees(list, CANT);
    do{

    printf("\n1 Alta\n2Modificacion\n3Baja\n4Mostrar la lista\n5Salir\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        system("cls");
        addemployees(list, CANT);
        break;
    case 2:
        system("cls");
        isEmptyEmployeed(list, CANT);
        modifyEmployee(list,CANT);
        break;
    case 3:
        system("cls");
        isEmptyEmployeed(list, CANT);
        removeEmployee(list, CANT);
        break;
    case 4:
        system("cls");
        sortemployeeBylastN(list,CANT);
        isEmptyEmployeed(list,CANT);

        break;

system("pause");
system("cls");
    }
}while(opcion != 5);

}
