#include "listaProducto.h"
#include "clientes.h"

//////////// Funciones Basicas ////////////

nodoListaProducto * pasaArbol2Lista(nodoArbolProducto * arbolProducto ,nodoListaProducto * listaProducto, stPedidos * pedido)
{

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
    }
    else
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

nodoListaProducto * agregarFinalProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    }
    else
    {
        nodoListaProducto * ult = buscarUltimoProducto(listaProducto);
        ult->sig = nuevoProducto;
    }
    return listaProducto;
}

nodoListaProducto * agregarOrdenProducto(nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    }
    else
    {
        if (strcmp(listaProducto->p.nombre, nuevoProducto->p.nombre) > 0)
        {
            listaProducto = agregarPrpioProducto(listaProducto, nuevoProducto);
        }
        else
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

//////////// Funciones de Muestra ////////////

void mostrarNodoProducto (nodoListaProducto * aux)
{
    mostrarProducto(aux->p);
}

void mostrarListaProducto(nodoListaProducto * aux)
{
    int x = whereX();
    nodoListaProducto * seg = aux;
    if(aux)
    {
        while (seg->sig != NULL)
        {
            mostrarNodoProducto(seg);
            seg = seg->sig;
        }
    }
    else
    {
        gotoxy(x,whereY());
        printf("No hay pedidos...\n");
    }
}

//////////// Funciones de Borrado de Datos ////////////

nodoListaProducto * borrarProductoId (nodoListaProducto * listaProducto, int id)
{
    if (listaProducto)
    {
        if (listaProducto->p.idProducto == id)
        {
            nodoListaProducto * aux = listaProducto;
            listaProducto = listaProducto->sig;
            free(aux);
        }
        else
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
        }
        else
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

///Funciones contar productos comprados

int * contarCategorias (nodoListaProducto * listaProductos)
{
    int comprasProducto[7] = {0};

    char categorias[15];

    nodoListaProducto * seg = listaProductos;

    while (seg)
    {
        categorias = listaProductos->p.categoria
        switch (categorias)
        {
            case 'Televisores'
            comprasProducto [0] = comprasProducto [0] + 1;
            break;

            case 'Computadoras'
            comprasProducto [1] = comprasProducto [1] + 1;
            break;

            case 'Celulares'
            comprasProducto [2] = comprasProducto [2] + 1;
            break;

            case 'Accesorios'
            comprasProducto [3] = comprasProducto [3] + 1;
            break;

            case 'Heladeras'
            comprasProducto [4] = comprasProducto [4] + 1;
            break;

            case 'Aires'
            comprasProducto [5] = comprasProducto [5] + 1;
            break;

            case 'Cocina'
            comprasProducto [6] = comprasProducto [6] + 1;
            break;
        }
        seg = seg->sig;
    }
    return comprasProducto;
}

int buscaMayor(int comprasProducto[])
{
    int may = 0;
    int i;
    for (i=0; i<7; i++)
    {
        if (comprasProducto[i] > comprasProducto[i+1])
            may = i;
    }
    return may;
}
