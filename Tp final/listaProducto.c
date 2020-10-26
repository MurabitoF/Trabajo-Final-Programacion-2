<<<<<<< Updated upstream
=======
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
            //listaProducto = agregarAlFinalProducto(listaProducto, crearNodoProducto(&aux));
        }
        fclose(arch);
    }

    return listaProducto;
}

nodoListaProducto * inicListaProducto()
{
    return NULL;
}

nodoListaProducto * crearNodoProducto (stProducto dato)
{
    nodoListaProducto * aux = (nodoListaProducto*) malloc(sizeof(nodoListaProducto));

    aux->p = dato;
    aux->sig = NULL;

    return aux;
}

nodoListaProducto * agregarPrpioProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if (!listaProducto)
    {
        listaProducto = nuevoProducto;
    } else
    {
        nuevoProducto->sig = listaProducto;
        listaProducto = nuevoProducto;
    }
    return listaProducto;
}

nodoListaProducto * buscarUltimoProducto (nodoListaProducto * listaProdcuto)
{
    nodoListaProducto * seg = listaProdcuto;
    if (seg->sig != NULL)
        while (seg->sig!=NULL)
        {
            seg = seg->sig;
        }
    return seg;
}

nodoListaProducto * agregarFinalProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto);
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    } else
    {
        nodoListaProducto * ult = buscarUltimoProducto(listaProducto);
        ult->sig = nuevoProducto;
    }
    return lista;
}

nodoListaProducto * agregarOrdenProducto(nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    } else
    {
        if (listaProducto->p.idProducto > nuevoProducto->p.idProducto)
        {
            listaProducto = agregarPrpioProducto(listaProducto, nuevoProducto);
        } else
        {
            nodoListaProducto * seg = listaProducto->sig;
            nodoListaProducto * ante = listaProducto;
            while (seg != NULL && listaProducto->p.idProducto < nuevoProducto->p.idProducto)
            {
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevoProducto;
            nuevoProducto->sig = seg;
        }
    }
    return listaProducto;
}


>>>>>>> Stashed changes
