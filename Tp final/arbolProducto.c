#include "arbolProducto.h"

///Funciones Basicas
nodoArbolProducto * inicArbol()
{
    return NULL;
}

nodoArbolProducto * crearNodoArbolProducto(stProducto prod)
{
    nodoArbolProducto * aux = (nodoArbolProducto *)malloc(sizeof(nodoArbolProducto));

    aux->producto = prod;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

///Funciones de carga del arbol
nodoArbolProducto * agregarNodoEnOrden(nodoArbolProducto *arbol, nodoArbolProducto *nuevo)
{
    if(arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->producto.idProducto < arbol->producto.idProducto)
        {
            arbol->izq = agregarNodoEnOrden(arbol->izq,nuevo);
        }
        else if(nuevo->producto.idProducto > arbol->producto.idProducto)
        {
            arbol->der = agregarNodoEnOrden(arbol->der,nuevo);
        }
    }

    return arbol;
}

nodoArbolProducto * arregloOrd2arbol(stProducto arr[], int inic, int cantVal)
{
    int mid;
    nodoArbolProducto * temp = NULL;

    if (inic <= cantVal)
    {
        mid = (inic + cantVal) / 2;
        temp = crearNodoArbolProducto(arr[mid]);
        temp->izq = arregloOrd2arbol(arr, inic, mid - 1);
        temp->der = arregloOrd2arbol(arr, mid + 1, cantVal);
    }

    return temp;
}

///Funciones de muestra del arbol
void mostrarNodoArbolProd(nodoArbolProducto * nodo)
{
    mostrarProducto(nodo->producto);
}

void mostrarPreOrden(nodoArbolProducto * arbol)
{
    if(arbol)
    {
        mostrarNodoArbolProd(arbol);
        mostrarPreOrden(arbol->izq);
        mostrarPreOrden(arbol->der);
    }
}

void mostrarInOrden(nodoArbolProducto * arbol)
{
    if(arbol)
    {
        mostrarInOrden(arbol->izq);
        mostrarNodoArbolProd(arbol);
        mostrarInOrden(arbol->der);
    }
}

void mostrarPosOrden(nodoArbolProducto * arbol)
{
    if(arbol)
    {
        mostrarPosOrden(arbol->izq);
        mostrarPosOrden(arbol->der);
        mostrarNodoArbolProd(arbol);
    }
}

///Funciones de busqueda
nodoArbolProducto * buscarNodoPorId(nodoArbolProducto * arbol, int id)
{
    nodoArbolProducto *aux = NULL;
    if(arbol)
    {
        if(arbol->producto.idProducto == id)
        {
            aux = arbol;
        }
        else
        {
            if(arbol->producto.idProducto < id)
            {
                aux = buscarNodoPorId(arbol->der, id);
            }
            else
            {
                aux = buscarNodoPorId(arbol->izq, id);
            }
        }
    }
    return aux;
}

nodoArbolProducto * buscarNodoPorMarca(nodoArbolProducto * arbol, char marca[])
{
    nodoArbolProducto * aux = NULL;

    if(arbol)
    {
        if(strcmpi(marca, arbol->producto.marca) == 0)
        {
            aux = arbol;
        }
        else
        {
            aux = buscarNodoPorMarca(arbol->izq, marca);
            if(!aux)
            {
                aux = buscarNodoPorMarca(arbol->der, marca);
            }
        }
    }
    return aux;
}

nodoArbolProducto * buscarNodoPorCategoria(nodoArbolProducto * arbol, char categoria[])
{
    nodoArbolProducto * aux = NULL;

    if(arbol)
    {
        if(strcmpi(categoria, arbol->producto.categoria) == 0)
        {
            aux = arbol;
        }
        else
        {
            aux = buscarNodoPorCategoria(arbol->izq, categoria);
            if(!aux)
            {
                aux = buscarNodoPorCategoria(arbol->der, categoria);
            }
        }
    }
    return aux;
}

nodoArbolProducto * buscarNodoPorNombre(nodoArbolProducto * arbol, char nombre[])
{
    nodoArbolProducto * aux = NULL;

    if(arbol)
    {
        if(strcmpi(nombre, arbol->producto.nombre) == 0)
        {
            aux = arbol;
        }
        else
        {
            aux = buscarNodoPorNombre(arbol->izq, nombre);
            if(!aux)
            {
                aux = buscarNodoPorNombre(arbol->der, nombre);
            }
        }
    }
    return aux;
}

nodoArbolProducto * buscaNodoMasIzq(nodoArbolProducto * arbol)
{
    nodoArbolProducto * izq = NULL;

    if(arbol)
    {
        if(arbol->izq !=NULL)
        {
            izq = buscaNodoMasIzq(arbol->izq);
        }
        else
        {
            izq = arbol;
        }
    }

    return izq;
}

nodoArbolProducto * buscaNodoMasDer(nodoArbolProducto * arbol)
{
    nodoArbolProducto * der = NULL;

    if(arbol)
    {
        if(arbol->der !=NULL)
        {
            der = buscaNodoMasDer(arbol->der);
        }
        else
        {
            der = arbol;
        }
    }

    return der;
}

///Fuciones de borrado
nodoArbolProducto * borrarNodoArbolProducto(nodoArbolProducto * arbol, nodoArbolProducto * borrado)
{
    if(arbol)
    {
        if(borrado == arbol)
        {
            if(arbol->izq != NULL)
            {
                nodoArbolProducto * masDer = buscaNodoMasDer(arbol->izq);
                arbol->producto = masDer->producto;
                arbol->izq = borrarNodoArbolProducto(arbol->izq, masDer);
            }
            else if (arbol->der != NULL)
            {
                nodoArbolProducto * masIzq = buscaNodoMasIzq(arbol->der);
                arbol->producto = masIzq->producto;
                arbol->der = borrarNodoArbolProducto(arbol->der, masIzq);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else
        {
            if(borrado->producto.idProducto < arbol->producto.idProducto)
            {
                arbol->izq = borrarNodoArbolProducto(arbol->izq, borrado);
            }
            else
            {
                arbol->der = borrarNodoArbolProducto(arbol->der, borrado);
            }
        }
    }

    return arbol;
}

nodoArbolProducto * borrarArbolProductos(nodoArbolProducto * arbol)
{
    if(arbol)
    {
        arbol->izq = borrarArbolProductos(arbol->izq);
        arbol->der = borrarArbolProductos(arbol->der);
        free(arbol);
        arbol = NULL;
    }

    return arbol;
}
