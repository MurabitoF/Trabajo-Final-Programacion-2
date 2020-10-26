<<<<<<< Updated upstream
=======
#include "arbolProducto.h"

stProducto * pasarArchivoArray (char nombreArchivo[], int dim, stProducto arrayProducto[])  //// Implementar con punteros dobles
{
    stProducto aux;
    int i = 0;

    FILE * archi = fopen(nombreArchivo, "rb");
    if (archi != NULL)
    {
        while (fread(&aux, sizeof(stProducto), 1, archi) > 0 && i<dim)
        {
            arrayProducto[i] = aux;
            i++;
        }
    }

    fclose(archi);
    return i;
}

int pasarArchivoArrayInt (char nombreArchivo[], int val, int arrayInt[])  //// Implementar con punteros dobles
{
    int i = 0;
    int aux;
    FILE * archi = fopen(nombreArchivo, "rb");

    if (archi != NULL)
    {
        while (fread(&aux, sizeof(int), 1, archi) > 0 && i<val)
        {
            arrayInt [i] = aux;
            i++;
        }
    }
    fclose(archi);

    return i;
}
>>>>>>> Stashed changes
