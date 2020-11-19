#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gotoxy.h"
#include "clientes.h"
#include "productos.h"

typedef struct _stPedidos
{
    int idPedido;
    int idCliente;
    int idProducto;
    char fecha[15];
} stPedidos;

stPedidos cargarPedido (char nombreArchivo[], stCliente cliente, stProducto prod, char fecha[]);

#endif // PEDIDOS_H_INCLUDED
