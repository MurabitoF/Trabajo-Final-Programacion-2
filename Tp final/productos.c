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
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 1);
    strcpy(product.nombre, leerString());
    while (validarString(product.nombre,30))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre de producto muy largo");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 1);
        limpiarLineaDer();
        strcpy(product.nombre, leerString());
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 2);
    strcpy(product.marca, leerString());
    while (validarString(product.marca,20))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Marca del producto muy larga");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 2);
        limpiarLineaDer();
        strcpy(product.marca, leerString());
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 3);
    strcpy(product.categoria, leerString());
    while (validarString(product.categoria, 15))
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! Categoria del producto muy larga");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 3);
        limpiarLineaDer();
        strcpy(product.categoria, leerString());
    }
    gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 4);
    product.precio = leerfloat();
    while(product.precio < 0)
    {
        gotoxy(pos.posX, pos.posY + 6);
        limpiarTodaLinea();
        color(12);
        printf("Error! El precio del producto no es valido");
        color(10);
        gotoxy(pos.posX + strlen("Categoria del producto: "), pos.posY + 4);
        limpiarLineaDer();
        product.precio = leerfloat();
    }
    product.eliminado = 1;
    product.idProducto = contadorDatos(nombreArchivo, sizeof(stProducto)) + 1;

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

void registrarProductoModificado(char nombreArchivo[], stProducto prod)
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "rb+");
    if(arch)
    {
        fseek(arch, (prod.idProducto - 1) * sizeof(stProducto), SEEK_SET);
        fwrite(&prod, sizeof(stProducto), 1, arch);
        fclose(arch);
    }
}

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
    stProducto aux = producto;
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
            printf("Nombre actual del producto: %s\n", aux.nombre);
            gotoxy(pos.posX, whereY());
            printf("Nuevo nombre del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nuevo nombre del producto: "), pos.posY + 1);
            strcpy(aux.nombre, leerString(30));
            while (validarString(aux.nombre, 30))
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre de producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Nuevo nombre del producto: "), pos.posY + 1);
                limpiarLineaDer();
                strcpy(aux.nombre, leerString(30));
            }
            break;
        case 2:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Marca actual del producto: %s\n", aux.marca);
            gotoxy(pos.posX, whereY());
            printf("Nueva marca del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nueva marca del producto: "), pos.posY + 1);
            strcpy(aux.marca, leerString(30));
            while (validarString(aux.marca, 20))
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Marca del producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Marca del producto: "), pos.posY + 1);
                limpiarLineaDer();
                strcpy(aux.marca, leerString(20));
            }
            break;
        case 3:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Categoria actual del producto: %s\n", aux.categoria);
            gotoxy(pos.posX, whereY());
            printf("Nueva categoria del producto: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + strlen("Nueva categoria del producto: "), pos.posY + 1);
            strcpy(aux.categoria, leerString(15));
            while (strlen(aux.categoria) > 15)
            {
                gotoxy(pos.posX, pos.posY + 3);
                limpiarTodaLinea();
                color(12);
                printf("Error! Categoria del producto muy largo");
                color(15);
                gotoxy(pos.posX + strlen("Nueva categoria del producto: "), pos.posY + 1);
                limpiarLineaDer();
                strcpy(aux.categoria, leerString(30));
            }
            break;
        case 4:
            header();
            gotoxy(pos.posX, pos.posY);
            printf("Precio actual del producto: %.2f\n", aux.precio);
            gotoxy(pos.posX, whereY());
            printf("Nuevo precio del producto: ");
            gotoxy(0, pos.tamY - 4);
            gotoxy(pos.posX + strlen("Nuevo precio del producto: "), pos.posY + 1);
            aux.precio = leerfloat();
            break;
        case 5:
            header();
            gotoxy(pos.posX, pos.posY);
            color(12);
            printf("Esta seguro de que quiere dar de baja?(s/n): ");
            color(15);
            fflush(stdin);
            opcion = leerChar();
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

    return aux;
}

//////////// Funciones de Archivos ////////////
void pasarArchivoArray(stProducto arrayProducto[], char nombreArchivo[], int dim)
{
    int i = 0;
    stProducto aux;

    FILE *archi = fopen(nombreArchivo, "rb");
    if (archi != NULL)
    {
        while (fread(&aux, sizeof(stProducto), 1, archi) > 0 && i < dim)
        {
            arrayProducto[i] = aux;
            i++;
        }
        fclose(archi);
    }
}
