#include "pedidos.h"


stPedidos cargarPedido (char nombreArchivo[], stCliente cliente, stProducto prod, char fecha[])
{
    stPedidos aux;

    aux.idCliente = cliente.idCliente;
    aux.idProducto = prod.idProducto;
    strcpy(aux.fecha, fecha);

    return aux;
}
