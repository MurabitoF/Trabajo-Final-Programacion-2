#include "pedidos.h"


void cargarPedido (char nombreArchivo[], int idCliente, int idProducto)
{
    stPedidos aux;

    aux.idCliente = idCliente;
    aux.idProducto = idProducto;
    aux.idPedido = contadorDatos(nombreArchivo, sizeof(stPedidos) + 1);

    registrarPedido(nombreArchivo, aux);
}

void registrarPedido(char nombreArchivo[], stPedidos pedi)  //Registra un producto en un archivo.
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"ab");

    if(arch != NULL)
    {
        fwrite(&pedi,sizeof(stPedidos),1,arch);
        fclose(arch);
    }
}
