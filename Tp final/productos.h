#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gotoxy.h"

typedef struct _stProductos
{
    int idProducto;
    char nombre[30];
    char marca[20];
    char categoria[15];
    float precio;
    int eliminado;
} stProducto;

///Funciones de carga
stProducto crearProducto(char nombreArchivo[]);
void registrarProducto(char nombreArchivo[], stProducto prod);  //Registra un producto en un archivo.
void registrarProductoModificado(char nombreArchivo[], stProducto prod);

//////////// Funciones de descarga ////////////
stProducto * pasarArchivoArray (char nombreArchivo); // Descarga los datos de un archivo a un arreglo.

///Funciones de descarga
//stProducto * pasarArchivoArray (stProducto arrayProducto [], char nombreArchivo[], int dim); // Descarga los datos de un archivo a un arreglo.

///Funciones de muestra
void mostrarProducto(stProducto product, int x);

///Funciones de modificacion
stProducto modificarProducto(stProducto);
#endif // PRODUCTOS_H_INCLUDED
