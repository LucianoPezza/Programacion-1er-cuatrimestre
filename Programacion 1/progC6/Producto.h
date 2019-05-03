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
    int productoID;
    char codigoDeBarra[10];
    char fechaDeVencimiento[10];

}eProducto;

typedef struct
{
int id[3];
char cuilt[3];
char descripcion[3];
char localidad[3];
char duenio[3];

}eProveedor;

eProducto pedirProducto();
eProveedor pedirProveedor();
void inicializarProductos(eProducto[], int);

void mostrarProducto(eProducto);

void mostrarProveedor(eProveedor);

void cargarArray(eProducto[], int);

void mostrarArray(eProducto[], int);

void construirArray(eProducto[], int);

int insertarProducto(eProducto[], int);

int dameLugarLibre(eProducto[], int);

int borrarProducto(eProducto[], int);

int editarProducto(eProducto[], int);

void inicializarProveedor(eProveedor[], int);

void mostrarArrayProductosConProveedor(eProducto[],int,eProveedor[],int);
void mostrarArrayProveedorConProducto(eProveedor[],int,eProducto[],int);
