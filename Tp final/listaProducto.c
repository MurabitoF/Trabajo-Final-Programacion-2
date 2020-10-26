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
        if (strcmp(listaProducto->p.nombre, nuevoProducto->p.nombre) > 0)
        {
            listaProducto = agregarPrpioProducto(listaProducto, nuevoProducto);
        } else
        {
            nodoListaProducto * seg = listaProducto->sig;
            nodoListaProducto * ante = listaProducto;
            while (seg != NULL && strcmp(listaProducto->p.nombre, nuevoProducto->p.nombre) < 0)
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

void mostrarNodoProducto (nodoListaProducto * aux)
{
    mostrarProducto(aux->p);
}

void mostrarListaProducto(nodoListaProducto * aux)
{
    nodoListaProducto * seg = aux;
    while (seg->sig != NULL)
    {
        mostrarNodoProducto(seg);
        seg = seg->sig;
    }
}

nodoListaProducto * borrarProductoId (nodoListaProducto * listaProducto, int id)
{
    if (listaProducto)
    {
        if (listaProducto->p.idProducto == id)
        {
            nodoListaProducto * aux = listaProducto;
            listaProducto = listaProducto->sig
            free(aux);
        } else
        {
            listaProducto->sig = borrarProductoId(listaProducto->sig, id);
        }
    }
    return listaProducto;
}

nodoListaProducto * borrarProductoNombre (nodoListaProducto * listaProducto, char nombre[])
{
    if (listaProducto)
    {
        if (strcmp(listaProducto->p.nombre, nombre) == 0)
        {
            nodoListaProducto * aux = listaProducto;
            listaProducto = listaProducto->sig;
            free(aux);
        } else
        {
            listaProducto->sig = borrarProductoNombre(listaProducto->sig, nombre);
        }
    }
    return listaProducto;
}

nodoListaProducto * borrarListaProducto (nodoListaProducto * listaProducto)
{
    nodoListaProducto * seg = listaProducto;
    nodoListaProducto * prox;
    while (seg != NULL)
    {
        prox = seg->sig;
        free(seg);
        seg = prox;
    }
    return seg;
}

