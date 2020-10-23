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

stProducto * pasarArchivoArray (char nombreArchivo);


#endif // ARBOLPRODUCTO_H_INCLUDED
