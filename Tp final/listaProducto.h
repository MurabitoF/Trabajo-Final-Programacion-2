#ifndef LISTAPRODUCTO_H_INCLUDED
#define LISTAPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "productos.h"
#include "pedidos.h"
#include "arbolProducto.h"

typedef struct _nodoListaProducto
{
    stProducto p;
<<<<<<< Updated upstream
=======
    int idPedido;
    char fecha[20];
>>>>>>> Stashed changes
    struct _nodoListaProducto * sig;
} nodoListaProducto;

//////////// Funciones Basicas ////////////

nodoListaProducto * inicListaProducto();

nodoListaProducto * crearNodoProducto (stProducto dato);

nodoListaProducto * pasaArchivoAListaProducto(nodoListaProducto * listaProducto, char nombreArchivo[]);

nodoListaProducto * agregarPrpioProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);

nodoListaProducto * buscarUltimoProducto (nodoListaProducto * listaProdcuto);

nodoListaProducto * agregarFinalProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);

nodoListaProducto * agregarOrdenProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);


//////////// Funciones de Muestra ////////////

void mostrarNodoProducto(nodoListaProducto * aux);

void mostrarListaProducto(nodoListaProducto * aux);

//////////// Funciones de Borrado de Datos ////////////


nodoListaProducto * borrarProductoNombre (nodoListaProducto * listaProducto, char nombre[]);

nodoListaProducto * borrarListaProducto (nodoListaProducto * listaProducto);

#endif // LISTAPRODUCTO_H_INCLUDED
