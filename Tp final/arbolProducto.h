#ifndef ARBOLPRODUCTO_H_INCLUDED
#define ARBOLPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "productos.h"

typedef struct _nodoArbolProducto
{
    stProducto producto;
    struct _nodoArbolProducto * izq;
    struct _nodoArbolProducto * der;
} nodoArbolProducto;

///Funciones Basicas
nodoArbolProducto * inicArbol();
nodoArbolProducto * crearNodoArbolProducto(stProducto prod);
///Funciones de carga del arbol
nodoArbolProducto * agregarNodoEnOrden(nodoArbolProducto *arbol, nodoArbolProducto *nuevo);
nodoArbolProducto * arregloOrd2arbol(nodoArbolProducto *arbol, stProducto arr[], int inic, int cantVal);
///Funciones de muestra del arbol
void mostrarNodoArbolProd(nodoArbolProducto * nodo, int x);
void mostrarPreOrden(nodoArbolProducto * arbol, int x);
void mostrarInOrden(nodoArbolProducto * arbol, int x);
void mostrarPosOrden(nodoArbolProducto * arbol, int x);
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
