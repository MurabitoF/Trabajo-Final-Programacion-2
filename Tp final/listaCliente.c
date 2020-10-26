#include "listaCliente.h"

nodoListaCliente * pasaArchivoALista(nodoListaCliente * listaCliente, char nombreArchivo[])
{
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "rb");

    if(arch != NULL)
    {
        while(fread(&aux,sizeof(stCliente),1,arch)>0)
        {
            //listaCliente = agregarAlFinalCliente(listaCliente, crearNodoCliente(aux));
        }
        fclose(arch);
    }

    return listaCliente;
}

nodoListaCliente * crearNodoCliente (char nombreArchivo[], stCliente aux)
{
    FILE * archi = fopen(nombreArchivo, "rb");

    nodoListaCliente * clienteAux = (nodoListaCliente*) malloc(sizeof(nodoListaCliente));
    clienteAux->client = aux;
    clienteAux->sig = NULL;
}




