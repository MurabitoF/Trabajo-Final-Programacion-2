#include "arbolProducto.h"

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

void mostrarPorCategoria (nodoArbolProducto * arbol, char categoria[])
{
    if (arbol)
    {
        mostrarPorCategoria(arbol->izq, categoria);

        if (strcmp(arbol->producto.categoria, categoria) == 0)
            mostrarNodoArbolProd(arbol);

        mostrarPorCategoria(arbol->der, categoria);
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

int pasarArchivoArray (char nombreArchivo[], int dim, int arrayProductos[])  //// Implementar con punteros dobles
{
    int i = 0;
    stProducto aux;
    FILE * archi = fopen(nombreArchivo, "rb");

    if (archi != NULL)
    {
        while (fread(&aux, sizeof(int), 1, archi) > 0 && i<dim)
        {
            arrayProductos [i] = aux;
            i++;
        }
    }
    fclose(archi);

    return i;
}
