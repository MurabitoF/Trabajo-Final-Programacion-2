#include "productos.h"

//////////// Funciones de carga ////////////

stProducto crearProducto(char nombreArchivo[])
{
    stProducto product;
    int x, y, posX = 0, posY = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - strlen("=====|Nuevo Producto|=====")/2 - 2;
    posY = (y/2) - 5;

    header();

    gotoxy(posX,posY);
    color(10);
    printf("=====|Nuevo Producto|=====\n");
    color(15);
    gotoxy(posX, whereY());
    printf("Nombre del producto: \n");
    gotoxy(posX, whereY());
    printf("Marca del producto: \n");
    gotoxy(posX, whereY());
    printf("Categoria del producto: \n");
    gotoxy(posX, whereY());
    printf("Precio del producto: \n");
    gotoxy(0, y - 4);
    footer();
    color(10);
    gotoxy(posX + strlen("Categoria del producto: "), posY + 1);
    fflush(stdin);
    gets(product.nombre);
    while (validarString(product.nombre,30))
    {
        gotoxy(posX, posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre de producto muy largo");
        color(10);
        gotoxy(posX + strlen("Categoria del producto: "), posY + 1);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.nombre);
    }
    gotoxy(posX + strlen("Categoria del producto: "), posY + 2);
    fflush(stdin);
    gets(product.marca);
    while (validarString(product.marca,20))
    {
        gotoxy(posX, posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Marca del producto muy larga");
        color(10);
        gotoxy(posX + strlen("Categoria del producto: "), posY + 2);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.marca);
    }
    gotoxy(posX + strlen("Categoria del producto: "), posY + 3);
    fflush(stdin);
    gets(product.categoria);
    while (validarString(product.categoria, 15))
    {
        gotoxy(posX, posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Categoria del producto muy larga");
        color(10);
        gotoxy(posX + strlen("Categoria del producto: "), posY + 3);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.categoria);
    }
    gotoxy(posX + strlen("Categoria del producto: "), posY + 4);
    scanf("%f", &product.precio);
    while(product.precio < 0)
    {
        gotoxy(posX, posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! El precio del producto no es valido");
        color(10);
        gotoxy(posX + strlen("Categoria del producto: "), posY + 4);
        limpiarLineaDer();
        scanf("%f", &product.precio);
    }

    color(15);
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
    int x = whereX();
    printf("Id #%d\n", product.idProducto);
    gotoxy(x,whereY());
    printf("Nombre del producto: %s\n", product.nombre);
    gotoxy(x,whereY());
    printf("Marca del producto:  %s\n", product.marca);
    gotoxy(x,whereY());
    printf("Precio del producto: %.2f\n\n", product.precio);
    gotoxy(x,whereY());
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
            while (validarString(producto.nombre, 30))
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
            while (validarString(producto.marca, 20))
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






