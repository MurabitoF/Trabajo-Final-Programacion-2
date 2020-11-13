
#include "productos.h"

//////////// Funciones de carga ////////////

stProducto crearProducto(char nombreArchivo[])
{
    stProducto product;

    printf("Categoria del producto: ");
    fflush(stdin);
    gets(product.categoria);
    while (strlen(product.categoria) > 15)
    {
        printf("Error! Categoria de producto muy largo");
        printf("Categoria del producto: ");
        fflush(stdin);
        gets(product.nombre);
    }
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
    scanf("%f", &product.precio);

    product.eliminado = 1;
    product.idProducto = contadorDatos(nombreArchivo, sizeof(stProducto) + 1);

    return product;
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

//////////// Funciones de Archivos ////////////
int pasarArchivoArray (stProducto arrayProducto [], char nombreArchivo[], int dim)  //// Implementar con punteros dobles
{
    int i = 0;
    stProducto aux;

    FILE * archi = fopen(nombreArchivo, "rb");
    if (archi!=NULL)
    {
        while (fread(&aux, sizeof(stProducto), 1, archi) > 0 && i<dim)
        {
            arrayProducto [i] = aux;
            i++;
        }
        fclose(archi);
    }
    return i;
}

//////////// Funciones de muestra ////////////

void mostrarProducto(stProducto product)
{
    printf("Id #%d", product.idProducto);
    printf("Categoria: %s", product.categoria);
    printf("Nombre del producto: %s", product.nombre);
    printf("Marca del producto: %s", product.marca);
    printf("Precio del producto: %f", product.precio);

}
