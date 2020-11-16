#include "productos.h"

//////////// Funciones de carga ////////////

stProducto crearProducto(char nombreArchivo[])
{
    stProducto product;
    ventana pos = inicVentana("=====|Nuevo Producto|=====", 5);

    header();

    gotoxy(pos.posX, pos.posY);
    color(10);
    printf("=====|Nuevo Producto|=====\n");
    color(15);
    gotoxy(pos.posX, whereY());
    printf("Nombre del producto: \n");
    gotoxy(pos.posX, whereY());
    printf("Marca del producto: \n");
    gotoxy(pos.posX, whereY());
    printf("Categoria del producto: \n");
    gotoxy(pos.posX, whereY());
    printf("Precio del producto: \n");
    gotoxy(0, pos.tamY - 4);
    footer();
    color(10);
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 1);
    fflush(stdin);
    gets(product.nombre);
    while (validarString(product.nombre,30))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre de producto muy largo");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 1);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.nombre);
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 2);
    fflush(stdin);
    gets(product.marca);
    while (validarString(product.marca,20))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Marca del producto muy larga");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 2);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.marca);
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 3);
    fflush(stdin);
    gets(product.categoria);
    while (validarString(product.categoria, 15))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Categoria del producto muy larga");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 3);
        limpiarLineaDer();
        fflush(stdin);
        gets(product.categoria);
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 4);
    scanf("%f", &product.precio);
    while(product.precio < 0)
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! El precio del producto no es valido");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 4);
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
        fseek(arch, (prod.idProducto - 1) * sizeof(stProducto), SEEK_SET);
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
    printf("Id#%d\n", product.idProducto);
    gotoxy(x,whereY());
    printf("Nombre del producto:    %s\n", product.nombre);
    gotoxy(x,whereY());
    printf("Marca del producto:     %s\n", product.marca);
    gotoxy(x,whereY());
    printf("Categoria del producto: %s\n", product.categoria);
    gotoxy(x,whereY());
    printf("Precio del producto:    %.2f\n\n", product.precio);
    gotoxy(x,whereY());
}

///Funciones de modificacion
stProducto modificarProducto(stProducto producto)
{
    stProducto aux;
    int op = 0;
    char opcion = 'n';
    ventana pos = inicVentana("=====|Datos del Producto|=====", 5);

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuDatosProductosG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 7);
        op = leerInt();

        switch (op)
        {
        case 1:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Nombre actual del producto: %s\n", producto.nombre);
            gotoxy(pos.posX, whereY());
            printf("Nuevo nombre del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nuevo nombre del producto: "), pos.posY + 1);
            fflush(stdin);
            gets(producto.nombre);
            while (validarString(producto.nombre, 30))
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre de producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Nuevo nombre del producto: "), pos.posY + 1);
                limpiarLineaDer();
                fflush(stdin);
                gets(producto.nombre);
            }
            break;
        case 2:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Marca actual del producto: %s\n", producto.marca);
            gotoxy(pos.posX, whereY());
            printf("Nueva marca del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nueva marca del producto: "), pos.posY + 1);
            fflush(stdin);
            gets(producto.marca);
            while (validarString(producto.marca, 20))
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Marca del producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Marca del producto: "), pos.posY + 1);
                limpiarLineaDer();
                fflush(stdin);
                gets(producto.marca);
            }
            break;
        case 3:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Categoria actual del producto: %s\n", producto.categoria);
            gotoxy(pos.posX, whereY());
            printf("Nueva categoria del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nueva categoria del producto: "), pos.posY + 1);
            fflush(stdin);
            gets(producto.categoria);
            while (strlen(producto.categoria) > 15)
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Categoria del producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Nueva categoria del producto: "), pos.posY + 1);
                limpiarLineaDer();
                fflush(stdin);
                gets(producto.categoria);
            }
            break;
        case 4:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Precio actual del producto: %.2f\n", producto.precio);
            gotoxy(pos.posX, whereY());
            printf("Nuevo precio del producto: ");
            gotoxy(0, pos.tamY - 4);
            gotoxy(pos.posX + strlen("Nuevo precio del producto: "), pos.posY + 1);
            scanf("%f", &producto.precio);
            break;
        case 5:
            header();
            gotoxy(pos.posX, pos.posY);
            color(12);
            printf("Esta seguro de que quiere dar de baja?(s/n): ");
            color(15);
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                aux.eliminado = 0;
                gotoxy(pos.posX, pos.posY + 1);
                printf("El producto ha sido dado de baja");
            }
            break;
        default:
            break;
        }
    }
    while(op != 0);
    producto = aux;

    return producto;
}






