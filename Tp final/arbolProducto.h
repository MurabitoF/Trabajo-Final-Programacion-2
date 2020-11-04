#ifndef ARBOLPRODUCTO_H_INCLUDED
#define ARBOLPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "productos.h"

typedef struct _nodoArbolstProducto
{
    stProducto p;
    struct _nodoArbolstProducto * izq;
    struct _nodoArbolstProducto * der;
} nodoArbolstProducto;

stProducto * pasarArchivoArray (char nombreArchivo[]);

///Funciones Basicas
nodoArbolProducto * inicArbol();
nodoArbolProducto * crearNodoArbolProducto(stProducto prod);
///Funciones de carga del arbol
nodoArbolProducto * agregarNodoEnOrden(nodoArbolProducto *arbol, nodoArbolProducto *nuevo);
nodoArbolProducto * arregloOrd2arbol(nodoArbolProducto *arbol, stProducto arr[], int inic, int cantVal);
///Funciones de muestra del arbol
void mostrarNodoArbolProd(nodoArbolProducto * nodo);
void mostrarPreOrden(nodoArbolProducto * arbol);
void mostrarInOrden(nodoArbolProducto * arbol);
void mostrarPosOrden(nodoArbolProducto * arbol);
///Funciones de busqueda
nodoArbolProducto * buscarNodoPorId(nodoArbolProducto * arbol, int id);
nodoArbolProducto * buscarNodoPorMarca(nodoArbolProducto * arbol, char marca[]);
nodoArbolProducto * buscarNodoPorCategoria(nodoArbolProducto * arbol, char categoria[]);
nodoArbolProducto * buscarNodoPorNombre(nodoArbolProducto * arbol, char nombre[]);
nodoArbolProducto * buscaNodoMasIzq(nodoArbolProducto * arbol);
nodoArbolProducto * buscaNodoMasDer(nodoArbolProducto * arbol);
///Fuciones de borrado
nodoArbolProducto * borrarnodoArbolProducto(nodoArbolProducto * arbol, nodoArbolProducto * borrado);
nodoArbolProducto * borrarArbolProductos(nodoArbolProducto * arbol);
///Subprogramas
void subProgramaModificarProducto(nodoArbolProducto * nodoProducto, char nombreArchivo[]);

#endif // ARBOLPRODUCTO_H_INCLUDED
