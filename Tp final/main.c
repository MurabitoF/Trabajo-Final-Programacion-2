#include <stdio.h>
#include <stdlib.h>

#define A_PRODUCTOS "numeros.dat"

int contadorDatos(char nombreArchivo[], int byte);

int main()
{
    printf("Hello world!\n");

    int val, dim, i;
    dim = contadorDatos(A_PRODUCTOS, sizeof(int));

    int arrayInt [dim];
    val = pasarArchivoArrayInt(A_PRODUCTOS, dim, arrayInt);

    for (i=0; i<val; i++)
    {
        printf("%d ", arrayInt[i]);
    }

    return 0;
}

int contadorDatos(char nombreArchivo[], int byte) //Cuenta cuantos bloques de datos hay en un archivo y devuelve el valor.
{
    FILE * arch = NULL;
    int cant = 0;

    arch = fopen(nombreArchivo, "rb");

    if(arch != NULL)
    {
        fseek(arch, 0, SEEK_END);
        cant = ftell(arch)/ byte;
    }
    fclose(arch);

    return cant;
}
