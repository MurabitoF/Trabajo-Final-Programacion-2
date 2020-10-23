#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "listaProducto.h"

typedef struct _nodoListaCliente
{
    stCliente client;
    struct nodoListaProducto * listaDeProductos;
    struct _nodoListaCliente * sig;
    float costoTotalDelPedido;
} nodoListaCliente;

nodoListaCliente * pasaArchivoALista(nodoListaCliente * listaCliente, char nombreArchivo[]);




#endif // LISTACLIENTE_H_INCLUDED
