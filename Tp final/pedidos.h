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
} stPedidos;

void cargarPedido (char nombreArchivo[], int idCliente, int idProducto);

void registrarPedido(char nombreArchivo[], stPedidos pedi);

#endif // PEDIDOS_H_INCLUDED
