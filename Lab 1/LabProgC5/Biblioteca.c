#include "Biblioteca.h"
#include "Biblioteca.h"
#include <string.h>

int damelugarlibre(aProducto listado[])
{

}

int existeproducto()
{

}

int inserteproducto(aProducto elproducto,aProducto listado[])
{
    int indice;
    indice = damelugarlibre(listado);
    if(indice!=-1)
    {
        listado[indice]=elproducto;
    }
return indice;
}
int borrarproducto(aProducto elproducto,aProducto listado[])
{
    int indice;
    indice = existeproducto(elproducto,listado);
    if(indice!=-1)
    {
        listado[indice].estado=-1;
    }
return indice;
}


void cargarArray(int TAM, aProducto listado[])
{
int i;
for(i=0 ;i<TAM; i++)
{
    listado[i]=pedirP();
}


}
void mostrarArray(int TAM, aProducto listado[])
{
    int i;
for(i=0 ;i<TAM; i++)
    {
        mostrarproducto(listado[i]);
    }
}


aProducto pedirP()
{
aProducto productoretornado;


        printf("Ingrese nombre de producto: ");
        gets(productoretornado.nombre);

        printf("Ingrese el codigo de barra");
        gets(productoretornado.codigoDeBarra);


        printf("Ingrese Fecha de vencimiento: ");
        gets(productoretornado.fechaDeVencimiento);


        printf("Ingrese precio:");
        scanf("%f",productoretornado.precio);


    return productoretornado;

}
/*void construirArray(aProducto listado[],int tam)
{
listado[i].estado=0;


}
/*void mostrarproducto(aProducto Elproductomostrado)
{
printf("\n El nombre:",Elproductomostrado.nombre);
printf("\n El codigo de barra:", Elproductomostrado.codigoDeBarra);
printf("\n fecha de vencimiento:", Elproductomostrado.fechaDeVencimiento);
printf("\n Proveedor es:", Elproductomostrado.proveedor);
}*/
