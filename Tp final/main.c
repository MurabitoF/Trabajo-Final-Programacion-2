#include <stdio.h>
#include <stdlib.h>

const char A_Productos[] = "numeros.dat";

int contadorDatos(char nombreArchivo[], int byte);
void fechaHora(char * fecha[]);

int main()
{
    printf("Hello world!\n");

    int val, dim, i;
    dim = contadorDatos(A_Productos, sizeof(int));

    int arrayInt [dim];
//    val = pasarArchivoArrayInt(A_Productos, dim, arrayInt);

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

void fechaHora(char * fecha[]) //Devuelve la fecha y la hora del sistema.
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char formato[] = {"%d/%m/%y %H:%M"};

    strftime(fecha,20,formato,tlocal);
}
