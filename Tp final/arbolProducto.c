#include "arbolProducto.h"

stProducto * pasarArchivoArray (char nombreArchivo)  //// Implementar con punteros dobles
{
    stProducto * arrayProducto;
    int totalProductos;
    int i = 0;

    FILE * archi = fopen(nombreArchivo, "rb");

    totalProductos = contadorDatos(nombreArchivo, sizeof(stProducto));
    arrayProducto = (stProducto*) malloc (sizeof(stProducto) * totalProductos);

    fread(&arrayProducto[i], sizeof(stProducto), totalProductos, archi);

    return arrayProducto;
}
