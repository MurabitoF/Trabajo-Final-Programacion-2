#include <stdio.h>
#include <stdlib.h>

#define A_PRODUCTOS "numeros.dat"

int contadorDatos(char nombreArchivo[], int byte);

int main()
{
    printf("Hello world!\n");

    int val = contadorDatos(A_PRODUCTOS, sizeof(int));
    int i;

    int * numeros = pasarArchivoArray(A_PRODUCTOS);

    for (i=0; i<val; i++)
    {
        printf("%d", numeros[i]);
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
        fclose(arch);
    }

    return cant;
}
