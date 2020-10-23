#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _stProductos
{
    int idProducto;
    char nombre[30];
    char marca[20];
    float precio;
    int eliminado;
} stProducto;




#endif // PRODUCTOS_H_INCLUDED
