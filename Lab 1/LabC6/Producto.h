#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

typedef struct
{
    int estado;
    float precio[10];
    char nombre[13];
    char proveedor[10];
    int idProveedor[10];
    int id[3];
    int productoID;
    char descripcion[3];
    char localidad[3];
    char duenio[3];
    char cuilt[3];
    char codigoDeBarra[10];
    char fechaDeVencimiento[10];

}eProducto;


eProducto pedirProducto();

void inicializarProductos(eProducto[], int);

void mostrarProducto(eProducto);

void cargarArray(eProducto[], int);

void mostrarArray(eProducto[], int);

void construirArray(eProducto[], int);

int insertarProducto(eProducto[], int);

int dameLugarLibre(eProducto[], int);

int borrarProducto(eProducto[], int);

int editarProducto(eProducto[], int);

void inicializarProveedor(eProducto[], int);

void mostrarArrayProductosConProveedor(eProducto[],int,eProducto[],int);
void mostrarArrayProveedorConProducto(eProducto[],int,eProducto[],int);
