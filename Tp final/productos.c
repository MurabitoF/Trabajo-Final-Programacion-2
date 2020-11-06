#include "productos.h"

//////////// Funciones de carga ////////////

stProducto crearProducto(char nombreArchivo[])
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
    printf("Categoria del producto: ");
    fflush(stdin);
    gets(product.categoria);
    while (strlen(product.categoria) > 15)
    {
        printf("Error! Categoria del producto muy largo");
        printf("Marca del producto: ");
        fflush(stdin);
        gets(product.categoria);
    }
    printf("Precio del producto: ");
    scanf("%f", product.precio);

    product.eliminado = 1;
    product.idProducto = contadorDatos(nombreArchivo, sizeof(stProducto) + 1);
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
//stProducto * pasarArchivoArray (char nombreArchivo)  //// Implementar con punteros dobles

void registrarProductoModificado(char nombreArchivo[], stProducto prod)
{
    FILE * arch = NULL;

    fopen(nombreArchivo, "r+b");
    if(arch)
    {
        fseek(arch, prod.idProducto, SEEK_SET);
        fwrite(&prod, sizeof(stProducto), 1, arch);
        fclose(arch);
    }
}

///Funciones de descarga
/*stProducto * pasarArchivoArray (stProducto arrayProducto [], char nombreArchivo[], int dim)  //// Implementar con punteros dobles
{
    stProducto aux;
    int totalProductos;
    int i = 0;

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

    totalProductos = contadorDatos(nombreArchivo, sizeof(stProducto));
    arrayProducto = (stProducto*) malloc (sizeof(stProducto) * totalProductos);

    fread(&arrayProducto[i], sizeof(stProducto), totalProductos, archi);

    return arrayProducto;
}*/

///Funciones de muestra
void mostrarProducto(stProducto product)
{
    printf("Id #%d", product.idProducto);
    printf("Nombre del producto: %s", product.nombre);
    printf("Marca del producto: %s", product.marca);
    printf("Precio del producto: %f", product.precio);
}

///Funciones de modificacion
stProducto modificarProducto(stProducto producto)
{
    stProducto aux;
    int op = 0;
    char opcion = 'n';
    do
    {
        system("cls");
        header();
        //menuDatosProducto();
        footer();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Nombre del producto: ");
            fflush(stdin);
            gets(producto.nombre);
            while (strlen(producto.nombre) > 30)
            {
                printf("Error! Nombre de producto muy largo");
                printf("Nombre del producto: ");
                fflush(stdin);
                gets(producto.nombre);
            }
            break;
        case 2:
            printf("Marca del producto: ");
            fflush(stdin);
            gets(producto.marca);
            while (strlen(producto.marca) > 20)
            {
                printf("Error! Marca del producto muy largo");
                printf("Marca del producto: ");
                fflush(stdin);
                gets(producto.marca);
            }
            break;
        case 3:
            printf("Precio del producto: ");
            scanf("%f", producto.precio);
            break;
        case 4:
            printf("Categoria del producto: ");
            fflush(stdin);
            gets(producto.categoria);
            while (strlen(producto.categoria) > 15)
            {
                printf("Error! Categoria del producto muy largo");
                printf("Marca del producto: ");
                fflush(stdin);
                gets(producto.categoria);
            }
            break;

        case 5:
            printf("Esta seguro de que quiere dar de baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                aux.eliminado = 0;
            }
            break;
        default:
            break;
        }
    }while(op != 0);
    producto = aux;

    return producto;
}






