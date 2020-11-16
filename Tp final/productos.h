#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graficos.h"
#include "gotoxy.h"

typedef struct _stProductos
{
    int idProducto;
    char categoria[15];
    char nombre[30];
    char marca[20];
    float precio;
    int eliminado;
} stProducto;

///Funciones de carga
stProducto crearProducto(char nombreArchivo[]);
void registrarProducto(char nombreArchivo[], stProducto prod);  //Registra un producto en un archivo.
void registrarProductoModificado(char nombreArchivo[], stProducto prod);

//////////// Funciones de descarga ////////////
void pasarArchivoArray(stProducto arrayProducto[], char nombreArchivo[], int dim); // Descarga los datos de un archivo a un arreglo.

///Funciones de muestra
void mostrarProducto(stProducto product);

///Funciones de modificacion
stProducto modificarProducto(stProducto);
#endif // PRODUCTOS_H_INCLUDED
