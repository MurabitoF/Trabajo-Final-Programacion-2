#include "productos.h"

//////////// Funciones de carga ////////////

void crearProducto(char nombreArchivo[])
{
    stProducto product;

    printf("Nombre del producto: ");
    fflush(stdin);
    gets(product.nombre);
    while (strlen(product.nombre) > 30)
    {
        printf("Error! Nombre de producto muy largo");
        printf("Nombre del producto: ");
        fflush(stdin);
        gets(product.nombre);
    }
    printf("Marca del producto: ");
    fflush(stdin);
    gets(product.marca);
    while (strlen(product.marca) > 20)
    {
        printf("Error! Marca del producto muy largo");
        printf("Marca del producto: ");
        fflush(stdin);
        gets(product.marca);
    }
    printf("Precio del producto: ");
    scanf("%f", product.precio);

    product.eliminado = 1;
    product.idProducto = contadorDatos(nombreArchivo, sizeof(stProducto) + 1);

    registrarProducto(nombreArchivo, product);
}

void registrarProducto(char nombreArchivo[], stProducto prod)  //Registra un producto en un archivo.
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"ab");

    if(arch != NULL)
    {
        fwrite(&prod,sizeof(stProducto),1,arch);
        fclose(arch);
    }
}

//////////// Funciones de descarga ////////////
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

//////////// Funciones de muestra ////////////

void mostrarProducto(stProducto product)
{
    printf("Id #%d", product.idProducto);
    printf("Nombre del producto: %s", product.nombre);
    printf("Marca del producto: %s", product.marca);
    printf("Precio del producto: %f", product.precio);
}







