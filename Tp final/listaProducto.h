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

nodoListaProducto * crearNodoProducto (stProducto dato);

<<<<<<< Updated upstream
=======
nodoListaProducto * pasaArchivoAListaProducto(nodoListaProducto * listaProducto, char nombreArchivo[]);

nodoListaProducto * agregarPrpioProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);

nodoListaProducto * buscarUltimoProducto (nodoListaProducto * listaProdcuto);

nodoListaProducto * agregarFinalProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);

nodoListaProducto * agregarOrdenProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);


>>>>>>> Stashed changes


#endif // LISTAPRODUCTO_H_INCLUDED
