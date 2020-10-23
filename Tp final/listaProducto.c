#include "listaProducto.h"
#include "clientes.h"

nodoListaProducto * pasaArchivoAListaProducto(nodoListaProducto * listaProducto, char nombreArchivo[])
{
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "rb");

    if(arch != NULL)
    {
        while(fread(&aux,sizeof(stProducto),1,arch)>0)
        {
            listaProducto = agregarAlFinalProducto(listaProducto, crearNodoProducto(&aux));
        }
        fclose(arch);
    }

    return listaProducto;
}
