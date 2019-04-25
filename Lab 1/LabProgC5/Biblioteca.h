#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED


//ABM (Alta, baja, modificacion) en ingles CRU
typedef struct
{

char nombre[50];
char codigoDeBarra[13];
char fechaDeVencimiento[50];
char proveedor[50];
char estado;
float precio;


}aProducto;



#endif // BIBLIOTECA_H_INCLUDED
aProducto pedirP();
void construirArray(aProducto[],int);
//void mostrarproducto(aProducto);
void cargarArray(int, aProducto[]);
void mostrarArray(int, aProducto[]);
int existeproducto(aProducto,aProducto[]);
int damelugarlibre(aProducto[]);
int inserteproducto(aProducto,aProducto[]);
int editarproducto(aProducto,aProducto[]);
int borrarproducto(aProducto,aProducto[]);
