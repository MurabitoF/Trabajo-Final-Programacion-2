#include <stdio.h>
#include <stdlib.h>
#include "productos.h"
#include "clientes.h"
#include "pedidos.h"
#include "listaClientes.h"
#include "listaProducto.h"
#include "arbolProducto.h"
#include "gotoxy.h"

const char A_Clientes[] = "Datos\\clientes.dat";
const char A_Productos[] = "Datos\\productos.dat";
const char A_Pedidos[] = "Datos\\pedidos.dat";

///Menus
void menuLogin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuPrincipalClientes(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos);
void menuPrincipalAdmin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuMostrarArbol(nodoArbolProducto * arbolProductos);
void menuBusquedaCliente(nodoListaClientes * listaClientes);
void menuModificarCliente(nodoListaClientes * listaClientes);
void menuBusquedaProducto(nodoArbolProducto * arbolProductos);
void menuModificarProducto(nodoArbolProducto * arbolProductos);

///Subprogramas
void subprogramaHacerPedido(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos);
void subProgramaModificarCliente(nodoListaClientes * nodoCliente, char nombreArchivo[], int admin);
void subProgramaModificarProducto(nodoArbolProducto * arbol, char nombreArchivo[]);
nodoArbolProducto * subProgramaArchivo2Arbol (char nombreArchivo[]);
nodoListaClientes *subProgramaBajaPedidos(char nombreArchivo[], nodoListaClientes *clientes, nodoArbolProducto *productos);

///Funciones Extra
int contadorDatos(char nombreArchivo[], int byte);
void fechaHora(char * fecha[]);
int validarString(char palabra[], int dim);
void muestraRecomendados(nodoListaClientes *clientes, nodoArbolProducto *arbolProductos);
nodoListaProducto *bajarPedidos(char nombreArchivo[], int idCliente, nodoArbolProducto *productos, nodoListaProducto *listaPedidos);

const char categorias[7][15] = {"Televisores", "Computadoras", "Celulares", "Accesorios", "Heladeras", "Aires", "Cocina"};

int main()
{
    ventana pos = inicVentana("======|You TECS|======", 3);
    int op = 0;
    pos.posX = pos.posX -2;
    stCliente nuevo;
    nodoListaClientes * clientes = inicListaClientes();
    nodoListaClientes * clienteEncotrado = inicListaClientes();
    nodoArbolProducto * productos = inicArbol();

    clientes = pasaArchivoALista(clientes, A_Clientes);
    productos = subProgramaArchivo2Arbol(A_Productos);

    //cargar Lista y arbol

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuIngresoG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 4);
        op = leerInt();

        switch(op)
        {
        case 1:
            menuLogin(clientes, productos);
            //menuPrincipalAdmin(clientes, productos);
            //menuPrincipalClientes(clientes, productos);
            break;
        case 2:
            nuevo = crearCliente(A_Clientes);
            clienteEncotrado = buscarClientePorUsername(clientes, nuevo.userName);
            if(!clienteEncotrado)
            {
                registrarCliente(A_Clientes, nuevo);
                clientes = agregarClienteFinal(clientes, crearNodoCliente(nuevo));
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 5);
                color(12);
                printf("El usuario ya existe, intente nuevamente!\n");
                color(15);
                gotoxy(pos.posX, whereY());
                pausa();
            }
            break;
        default:
            break;
        }
    }
    while(op != 0);

    gotoxy(0, pos.tamY + 1);
    return 0;
}

///Menus
void menuLogin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos)
{
    nodoListaClientes * cliente = inicListaClientes();
    ventana pos = inicVentana("=====|Bienvenido|=====", 1);
    int op = 0;
    char usuario[20], pass[20];
    pos.posX = pos.posX - 2;

    header();
    gotoxy(pos.posX, pos.posY);
    menuLoginG();
    gotoxy(0, pos.tamY - 4);
    footer();
    gotoxy(pos.posX + strlen("Contrasena: "), pos.posY + 1);
    strcpy(usuario, leerString(20));
    cliente = buscarClientePorUsername(listaClientes, usuario);
    while(!cliente)
    {
        gotoxy(pos.posX, pos.posY + 3);
        color(12);
        printf("El usuario no existe!");
        color(15);
        gotoxy(pos.posX + strlen("Contrasena: "), pos.posY + 1);
        limpiarLineaDer();
        strcpy(usuario, leerString(20));
        cliente = buscarClientePorUsername(listaClientes, usuario);
    }
    gotoxy(pos.posX, pos.posY + 3);
    limpiarTodaLinea();
    gotoxy(pos.posX + strlen("Contrasena: "), pos.posY + 2);
    strcpy(pass, leerString(20));
    while(strcmpi(pass, cliente->cliente.password))
    {
        gotoxy(pos.posX, pos.posY + 3);
        color(12);
        printf("La contrase%ca es incorrecta!", enie);
        color(15);
        gotoxy(pos.posX + strlen("Contrasena: "), pos.posY + 2);
        limpiarLineaDer();
        strcpy(pass, leerString(20));
    }

    cliente->cliente.rol == 1 ? menuPrincipalAdmin(listaClientes, arbolProductos) : menuPrincipalClientes(cliente, arbolProductos);
}

void menuPrincipalClientes(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos)
{
    int op = 0, mostrar = 0;
    ventana pos = inicVentana("======|Hola!          |======", 5);

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        color(10);
        printf("======|Hola! %s|======\n", nodoCliente->cliente.userName);
        color(15);
        gotoxy(pos.posX,whereY());
        menuPrincipalClientesG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 6);
        op = leerInt();

        switch(op)
        {
        case 1:
            subprogramaHacerPedido(nodoCliente, arbolProductos);
            break;
        case 2:
            header();
            gotoxy(pos.posX, 3);
            mostrarListaProducto(nodoCliente->listaProductos);
            if(whereY() <= pos.tamY - 4)
                gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX, whereY() + 1);
            pausa();
            break;
        case 3:
            subProgramaModificarCliente(nodoCliente, A_Clientes, 0);
            break;
        case 4:
            //mostrarProductosRecomendado
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuPrincipalAdmin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos)
{
    stCliente nuevoCliente;
    nodoListaClientes * clienteEncotrado = inicListaClientes();
    stProducto nuevoProducto;
    int op = 0, mostrar = 0, aux = 0;
    ventana pos = inicVentana("======|Menu Administrador|======", 8);

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuPrincipalAdminG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 12);
        op = leerInt();

        switch(op)
        {
        case 1:
            nuevoCliente = crearCliente(A_Clientes);
            clienteEncotrado = buscarClientePorUsername(listaClientes, nuevoCliente.userName);
            if(!clienteEncotrado)
            {
                registrarCliente(A_Clientes, nuevoCliente);
                listaClientes = agregarClienteFinal(listaClientes, crearNodoCliente(nuevoCliente));
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 10);
                color(12);
                printf("El usuario ya existe, intente nuevamente!\n");
                gotoxy(pos.posX, whereY());
                pausa();
            }
            break;
        case 2:
            header();
            gotoxy(pos.posX, 3);
            mostrarListaClientes(listaClientes);
            aux = whereY();
            if(whereY() <= pos.tamY - 4)
                gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX, aux);
            pausa();
            break;
        case 3:
            menuBusquedaCliente(listaClientes);
            break;
        case 4:
            menuModificarCliente(listaClientes);
            break;
        case 5:
            nuevoProducto = crearProducto(A_Productos);
            registrarProducto(A_Productos, nuevoProducto);
            arbolProductos = agregarNodoEnOrden(arbolProductos, crearNodoArbolProducto(nuevoProducto));
            break;
        case 6:
            menuMostrarArbol(arbolProductos);
            break;
        case 7:
            menuBusquedaProducto(arbolProductos);
            break;
        case 8:
            menuModificarProducto(arbolProductos);
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuMostrarArbol(nodoArbolProducto * arbolProductos)
{
    int op = 0, aux = 0;
    ventana pos = inicVentana("=====|Mostrar Productos|=====", 5);

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuMostrarArbolG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 5);
        op = leerInt();
        switch(op)
        {
        case 1:
            header();
            gotoxy(pos.posX, 3);
            mostrarPreOrden(arbolProductos);
            aux = whereY();
            if(whereY() <= pos.tamY - 4)
                gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX, aux);
            pausa();
            break;
        case 2:
            header();
            gotoxy(pos.posX, 3);
            mostrarInOrden(arbolProductos);
            aux = whereY();
            if(whereY() <= pos.tamY - 4)
                gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX, aux);
            pausa();
            break;
        case 3:
            header();
            gotoxy(pos.posX, 3);
            mostrarPosOrden(arbolProductos);
            aux = whereY();
            if(whereY() <= pos.tamY - 4)
                gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX, aux);
            pausa();
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuBusquedaCliente(nodoListaClientes * listaClientes)
{
    int op = 0, idCli = 0;
    char busca[30] = "\0";
    ventana pos = inicVentana("=====|Buscar Cliente|=====", 5);
    pos.posX = pos.posX - 3;
    nodoListaClientes * clienteEncontrado = inicListaClientes();

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuBusquedaClienteG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 7);
        op = leerInt();

        switch (op)
        {
        case 1:
            gotoxy(pos.posX, pos.posY + 8);
            printf("Ingrese el ID: ");
            idCli = leerInt();
            clienteEncontrado = buscarClientePorId(listaClientes, idCli);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, pos);
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun usuario");
                gotoxy(pos.posX, pos.posY + 9);
                pausa();
            }
            break;
        case 2:
            gotoxy(pos.posX, pos.posY + 8);
            printf("Ingrese el nombre de usuario: ");
            strcpy(busca, leerString(20));
            clienteEncontrado = buscarClientePorUsername(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, pos);
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun usuario");
                gotoxy(pos.posX, pos.posY + 9);
                pausa();
            }
            break;
        case 3:
            gotoxy(pos.posX, pos.posY + 8);
            printf("Ingrese el email: ");
            strcpy(busca, leerString(30));
            clienteEncontrado = buscarClientePorEmail(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, pos);
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun usuario");
                gotoxy(pos.posX, pos.posY + 9);
                pausa();
            }
            break;
        case 4:
            gotoxy(pos.posX, pos.posY + 8);
            printf("Ingrese el nombre: ");
            strcpy(busca, leerString(30));
            clienteEncontrado = buscarClientePorNombre(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, pos);
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun usuario");
                gotoxy(pos.posX, pos.posY + 9);
                pausa();
            }
            break;
        case 5:
            gotoxy(pos.posX, pos.posY + 8);
            printf("Ingrese el apellido: ");
            strcpy(busca, leerString(30));
            clienteEncontrado = buscarClientePorApellido(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, pos);
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun usuario");
                gotoxy(pos.posX, pos.posY + 9);
                pausa();
            }
            break;
        default:
            break;
        }

    }
    while(op != 0);
}

void menuModificarCliente(nodoListaClientes * listaClientes)
{
    nodoListaClientes * clienteEncontrado = inicListaClientes();
    int op = 0, idCli = 0;
    ventana pos = inicVentana("=====|Modificar Cliente|=====", 2);
    pos.posX = pos.posX - 2;

    header();
    gotoxy(pos.posX, pos.posY);
    color(10);
    printf("=====|Modificar Cliente|=====\n\n");
    color(15);
    gotoxy(pos.posX, whereY());
    printf("Ingrese ID del usuario a modificar: ");
    gotoxy(0, pos.tamY - 4);
    footer();
    gotoxy(pos.posX + strlen("Ingrese ID del usuario a modificar: "), pos.posY + 2);
    idCli = leerInt();

    clienteEncontrado = buscarClientePorId(listaClientes, idCli);

    if(clienteEncontrado)
    {
        subProgramaModificarCliente(clienteEncontrado, A_Clientes, 1);
    }
    else
    {
        gotoxy(pos.posX, whereY());
        color(12);
        printf("No hay un usuario con ese ID!\n");
        gotoxy(pos.posX, whereY());
        pausa();
    }
}

void menuBusquedaProducto(nodoArbolProducto * arbolProductos)
{
    int op = 0, idProd = 0;
    char busca[30] = "\0";
    ventana pos = inicVentana("=====|Buscar Producto|=====", 5);
    pos.posX = pos.posX - 3;
    nodoArbolProducto * prodEncontrado = inicArbol();

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        menuBusquedaProductoG();
        gotoxy(0, pos.tamY - 4);
        footer();
        gotoxy(pos.posX + 4, pos.posY + 6);
        op = leerInt();

        switch (op)
        {
        case 1:
            gotoxy(pos.posX, pos.posY + 7);
            printf("Ingrese el ID: ");
            idProd = leerInt();
            prodEncontrado = buscarNodoPorId(arbolProductos, idProd);
            if(prodEncontrado)
            {
                header();
                gotoxy(pos.posX, pos.posY);
                mostrarNodoArbolProd(prodEncontrado);
                gotoxy(0, pos.posY - 4);
                footer();
                gotoxy(pos.posX, pos.posY + 5);
                pausa();
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 7);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun producto");
                gotoxy(pos.posX, pos.posY + 8);
                pausa();
            }
            break;
        case 2:
            gotoxy(pos.posX, pos.posY + 7);
            printf("Ingrese el nombre producto: ");
            strcpy(busca, leerString(30));
            prodEncontrado = buscarNodoPorNombre(arbolProductos, busca);
            if(prodEncontrado)
            {
                header();
                gotoxy(pos.posX, pos.posY);
                mostrarNodoArbolProd(prodEncontrado);
                gotoxy(0, pos.tamY - 4);
                footer();
                gotoxy(pos.posX, pos.posY + 5);
                pausa();
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 7);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun producto");
                gotoxy(pos.posX, pos.posY + 8);
                pausa();
            }
            break;
        case 3:
            gotoxy(pos.posX, pos.posY + 7);
            printf("Ingrese el marca: ");
            strcpy(busca, leerString(20));
            prodEncontrado = buscarNodoPorMarca(arbolProductos, busca);
            if(prodEncontrado)
            {
                header();
                gotoxy(pos.posX, pos.posY);
                mostrarNodoArbolProd(prodEncontrado);
                gotoxy(0, pos.tamY - 4);
                footer();
                gotoxy(pos.posX, pos.posY + 5);
                pausa();
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 7);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun producto");
                gotoxy(pos.posX, pos.posY + 8);
                pausa();
            }
            break;
        case 4:
            gotoxy(pos.posX, pos.posY + 7);
            printf("Ingrese el categoria: ");
            strcpy(busca, leerString(15));
            prodEncontrado = buscarNodoPorCategoria(arbolProductos, busca);
            if(prodEncontrado)
            {
                header();
                gotoxy(pos.posX, pos.posY);
                mostrarNodoArbolProd(prodEncontrado);
                gotoxy(0, pos.tamY - 4);
                footer();
                gotoxy(pos.posX, pos.posY + 5);
                pausa();
            }
            else
            {
                gotoxy(pos.posX, pos.posY + 7);
                limpiarTodaLinea();
                color(12);
                printf("No se ha econtrdo ningun producto");
                gotoxy(pos.posX, pos.posY + 8);
                pausa();
            }
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuModificarProducto(nodoArbolProducto * arbolProductos)
{
    nodoArbolProducto * productoEncontrado = inicArbol();
    int op = 0, idProd = 0;
    ventana pos = inicVentana("=====|Modificar Producto|=====", 2);
    pos.posX = pos.posX - 2;

    header();
    gotoxy(pos.posX, pos.posY);
    color(10);
    printf("=====|Modificar Producto|=====\n\n");
    color(15);
    gotoxy(pos.posX, whereY());
    printf("Ingrese ID del producto a modificar: ");
    gotoxy(0, pos.tamY - 4);
    footer();
    gotoxy(pos.posX + strlen("Ingrese ID del producto a modificar: "), pos.posY + 2);
    idProd = leerInt();

    productoEncontrado = buscarNodoPorId(arbolProductos, idProd);

    if(productoEncontrado)
    {
        subProgramaModificarProducto(productoEncontrado, A_Productos);
    }
    else
    {
        gotoxy(pos.posX, whereY());
        color(12);
        printf("No hay un producto con ese ID!\n");
        gotoxy(pos.posX, whereY());
        pausa();
    }
}

///Subprogramas
void subprogramaHacerPedido(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos)
{
    nodoArbolProducto * nodoProducto = inicArbol();
    int idProd = 0, aux = 0;
    ventana pos = inicVentana("=====|Productos|=====", 0);
    pos.posY = 3;

    header();
    gotoxy(pos.posX, pos.posY);
    color(10);
    printf("=====|Productos|=====\n");
    color(15);
    gotoxy(pos.posX,whereY());
    mostrarInOrden(arbolProductos);
    printf("Ingrese ID de producto: ");
    aux = whereY();
    if(whereY() <= pos.tamY - 4)
        gotoxy(0, pos.tamY - 4);
    footer();
    gotoxy(pos.posX + strlen("Ingrese ID de producto: "), aux);
    idProd = leerInt();

    nodoProducto = buscarNodoPorId(arbolProductos, idProd);
    agregarProductoListaClientes(nodoCliente, nodoCliente->cliente.idCliente, nodoProducto->producto);
}

void subProgramaModificarCliente(nodoListaClientes * nodoCliente, char nombreArchivo[], int admin)
{
    stCliente aux;
    aux =  modificarCliente(nodoCliente->cliente, admin);
    nodoCliente->cliente = aux;
    registrarClienteModificado(nombreArchivo, aux);

}

void subProgramaModificarProducto(nodoArbolProducto * arbol, char nombreArchivo[])
{
    stProducto aux;
    aux =  modificarProducto(arbol->producto);
    arbol->producto = aux;
    registrarProductoModificado(nombreArchivo, aux);
}

nodoListaClientes *subProgramaBajaPedidos(char nombreArchivo[], nodoListaClientes *clientes, nodoArbolProducto *productos)
{
    nodoListaClientes *seg = clientes;

    if (seg)
    {
        while (seg)
        {
            seg->listaProductos = bajarPedidos(nombreArchivo, seg->cliente.idCliente, productos, seg->listaProductos);
            seg = seg->siguiente;
        }
    }
    return clientes;
}

nodoArbolProducto * subProgramaArchivo2Arbol (char nombreArchivo[])
{
    FILE * archi = fopen(nombreArchivo, "rb");
    int dim = contadorDatos(nombreArchivo, sizeof(stProducto));
    int val;
    stProducto * arrayP = (stProducto*) malloc(sizeof(stProducto)*dim);
    nodoArbolProducto * p;

    pasarArchivoArray(arrayP, nombreArchivo, dim);
    arregloOrd2arbol(&p, arrayP, 0, dim);

    return p;

}


///Funciones Extra
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

void fechaHora(char * fecha[]) //Devuelve la fecha y la hora del sistema.
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char formato[] = {"%d/%m/%y %H:%M"};

    strftime(fecha,20,formato,tlocal);
}

int validarString(char palabra[], int dim)
{
    int flag = 0;

    if(strlen(palabra) > dim)
    {
        flag = 1;
    }

    return flag;
}

void muestraRecomendados(nodoListaClientes *clientes, nodoArbolProducto *arbolProductos)
{
    int masVendido;
    masVendido = buscaMayor(contarCategorias(clientes->listaProductos));
    mostrarPorCategoria(arbolProductos, categorias[masVendido]);
}

nodoListaProducto *bajarPedidos(char nombreArchivo[], int idCliente, nodoArbolProducto *productos, nodoListaProducto *listaPedidos)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stPedidos pedido;
    nodoArbolProducto *p = inicArbol();
    nodoListaProducto *aux = listaPedidos;

    if (archi)
    {
        while (fread(&pedido, sizeof(stPedidos), 1, archi) > 0)
        {
            if (pedido.idCliente == idCliente)
            {
                p = buscarNodoPorId(productos, pedido.idProducto);
                aux = agregarFinalProducto(aux, crearNodoProducto(p->producto, pedido.idPedido));
                strcpy(aux->fecha, pedido.fecha);
                aux->idPedido = pedido.idPedido;
                aux = aux->sig;
            }
        }
    }
    fclose(archi);
    return productos;
}

