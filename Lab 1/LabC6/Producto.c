#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Producto.h"


void mostrarArrayProductosConProveedor(eProducto listadeproductos[],int tamprod,eProducto listadeproveedor[],int tamprov)
{
    int i;
    int j;
    for(i=0; i<tamprod; i++)
    {
        mostrarProducto(listadeproductos[i]);

        for(j=0; j<tamprov ;j++)
        {
            if(listadeproductos[i].idProveedor==listadeproveedor[j].id)
            {
                mostrarProveedor(listadeproveedor[j]);
            }
        }
    }
}
void mostrarArrayProveedorConProducto(eProducto listadeproductos[],int tamprod,eProducto listadeproveedor[],int tamprov)
{
    int i;
    int j;
    for(i=0; i<tamprod; i++)
    {
         mostrarProveedor(listadeproveedor[i]);

        for(j=0; j<tamprov ;j++)
        {
            if(listadeproductos[i].idProveedor==listadeproveedor[j].id)
            {
                 mostrarProducto(listadeproductos[j]);

            }
        }
    }

}

void inicializarProveedor(eProducto listaProductos[], int cant)
{
    int i;
    int id[3]= {1,2,3};
    char descripcion[3][50]= {"Petrolera", "Petrolera", "Petrolera"};
    char localidad[3][50]= {"Avellaneda", "Bahía Blanca", "Rio Negro"};
    char cuilt[3][13]= {"444", "555", "666"};
    char duenio[3][50]= {"YPF", "ACTION", "SHELL"};

    for(i=0; i<3; i++)
    {
        strcpy(listaProductos[i].descripcion,descripcion[i]);
        strcpy(listaProductos[i].localidad,localidad[i]);
        strcpy(listaProductos[i].cuilt, cuilt[i]);
        strcpy(listaProductos[i].duenio, duenio[i]);
        listaProductos[i].id[i]=id[i];

    }
}
    void inicializarProductos(eProducto listaProductos[], int cant)
    {
        int i;
        float precio[10]= {42,43,44,40,41,42,35,36,37,38};
        int idProveedor[10]= {1,2,3,1,2,3,1,2,3,1};
        char nombre[13][50]= {"infinia","Axion Power","V-Power","InfiniaDisel","AxionDiesel","V-Power Diesel","Super","AxionSuper","Queroseno"};
        char codigoDeBarra[10][13]= {"000","111","222","333","444","555","666","777","888","999"};
        char fechaDeVencimiento[10][50]= {"01/02/2020","02/02/2020","03/02/2020","04/02/2020","05/02/2020","06/02/2020","07/02/2020","08/02/2020","09/02/2020","010/02/2020"};

        for(i=0; i<3; i++)
        {
            strcpy(listaProductos[i].nombre,nombre[i]);
            strcpy(listaProductos[i].codigoDeBarra,codigoDeBarra[i]);
            strcpy(listaProductos[i].fechaDeVencimiento, fechaDeVencimiento[i]);
            listaProductos[i].precio[i]=precio[i];
            listaProductos[i].idProveedor[i]=idProveedor[i];
        }
    }


    eProducto pedirProducto()
    {
        eProducto productoParaRetornar;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(productoParaRetornar.nombre);

        printf("Ingrese proveedor: ");
        fflush(stdin);
        gets(productoParaRetornar.proveedor);

        printf("Ingrese codigo de barra: ");
        fflush(stdin);
        gets(productoParaRetornar.codigoDeBarra);

        printf("Ingrese fecha de vencimiento: ");
        fflush(stdin);
        gets(productoParaRetornar.fechaDeVencimiento);

        printf("Ingrese precio: ");
        scanf("%f", &productoParaRetornar.precio);

        productoParaRetornar.estado= OCUPADO;

        return productoParaRetornar;
    }


    void mostrarProducto(eProducto unProducto)
    {
        printf("%s %10s %15s %15s %15f %10d\n", unProducto.nombre, unProducto.proveedor, unProducto.codigoDeBarra, unProducto.fechaDeVencimiento, unProducto.precio, unProducto.estado);
    }
void mostrarProveedor(eProducto unProveedor)
    {
        printf("%s %10s %15s %15s %15f %10d\n", unProveedor.id, unProveedor.descripcion, unProveedor.localidad, unProveedor.cuilt, unProveedor.duenio);
    }


    void cargarArray(eProducto listado[], int cant)
    {
        int i;
        for(i=0; i<cant; i++)
        {
            listado[i]= pedirProducto();
        }
    }


    void mostrarArray(eProducto listado[], int cant)
    {
        int i;
        for(i=0; i<cant; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                mostrarProducto(listado[i]);
            }
        }
    }


    void construirArray(eProducto listado[], int cant)
    {
        int i;
        for(i=0; i<cant; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].precio;
            strcpy(listado[i].nombre, "");
            strcpy(listado[i].proveedor, "");
            strcpy(listado[i].codigoDeBarra, "");
            strcpy(listado[i].fechaDeVencimiento, "");
        }
    }


    int insertarProducto(eProducto listado[], int cant)
    {
        int indice;
        indice= dameLugarLibre(listado, cant);
        if(indice != -1)
        {
            listado[indice]= pedirProducto();
        }
        return indice;
    }


    int dameLugarLibre(eProducto listado[], int cant)
    {
        int i;
        int index= -1;

        for(i=0; i<cant; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                index= i;
                break;
            }
        }
        return index;
    }


    int borrarProducto(eProducto lista[], int tam)
    {
        int i;
        int loEncontro= 0;

        char codigo[50];

        printf("Ingrese el codigo de barra: ");
        fflush(stdin);
        gets(codigo);

        for(i=0; i<tam; i++)
        {
            if(strcmp(lista[i].codigoDeBarra, codigo) == 0)
            {
                lista[i].estado= LIBRE;
                loEncontro= 1;
                break;
            }
        }

        if(loEncontro == 0)
        {
            printf("Codigo inexistente");
        }

        return 0;
    }


    int editarProducto(eProducto lista[], int tam)
    {
        int i;
        int loEncontro= 0;

        char codigo[50];

        printf("Ingrese el codigo de barra: ");
        fflush(stdin);
        gets(codigo);

        for(i=0; i<tam; i++)
        {
            if(strcmp(lista[i].codigoDeBarra, codigo) == 0)
            {
                printf("Ingrese el nuevo precio: ");
                scanf("%f", &lista[i].precio);
                loEncontro= 1;
                break;
            }
        }

        if(loEncontro == 0)
        {
            printf("Codigo inexistente");
        }

        return 0;
    }
