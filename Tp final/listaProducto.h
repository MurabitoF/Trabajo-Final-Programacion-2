#ifndef LISTAPRODUCTO_H_INCLUDED
#define LISTAPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "productos.h"

typedef struct _nodoListaProducto
{
    stProducto p;
    struct _nodoListaProducto * sig;
} nodoListaProducto;

//////////// Funciones Basicas ////////////

nodoListaProducto * inicListaProducto ();

nodoListaProducto * crearNodoProducto (nodoListaProducto * lista);

nodoListaProducto * pasaArchivoAListaProducto(nodoListaProducto * listaProducto, char nombreArchivo[]);




#endif // LISTAPRODUCTO_H_INCLUDED
