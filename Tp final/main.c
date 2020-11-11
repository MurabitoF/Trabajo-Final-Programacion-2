#include <stdio.h>
#include <stdlib.h>
#include "listaClientes.h"
#include "arbolProducto.h"

const char A_Clientes[] = "Datos\\clientes.dat";
const char A_Productos[] = "Datos\\productos.dat";
const char A_Pedidos[] = "Datos\\pedidos.dat";

///Menus
void menuLogin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuPrincipalClientes(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos);
void menuPrincipalAdmin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuMostrarArbol(nodoArbolProducto * arbolProducto);
void menuBusquedaCliente(nodoListaClientes * listaClientes);

///Subprogramas
void subprogramaHacerPedido(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos);

///Funciones Extra
int contadorDatos(char nombreArchivo[], int byte);
void fechaHora(char * fecha[]);
int validarString(char palabra[], int dim);

int main()
{
    int x, y, posX = 0, posY = 0, op = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("======|You TECS|======")/2)-2;
    posY = (y/2) - 3;
    stCliente nuevo;
    nodoListaClientes * clientes = inicListaClientes();
    nodoListaClientes * clienteEncotrado = inicListaClientes();
    nodoArbolProducto * productos = inicArbol();

    clientes = pasaArchivoALista(clientes, A_Clientes);

    //cargar Lista y arbol

    do
    {
        system("cls");
        header();
        gotoxy(posX,posY);
        menuIngresoG(posX);
        gotoxy(0, y-4);
        footer();
        gotoxy(posX + 4, posY + 4);
        color(10);
        scanf("%d", &op);
        color(15);

        switch(op)
        {
        case 1:
            //menuLogin(clientes, productos);
            menuPrincipalAdmin(clientes, productos);
            //menuPrincipalClientes(clientes, productos);
            break;
        case 2:
            system("cls");
            nuevo = crearCliente(A_Clientes);
            clienteEncotrado = buscarClientePorUsername(clientes, nuevo.userName);
            if(!clienteEncotrado)
            {
                registrarCliente(A_Clientes, nuevo);
                clientes = agregarClienteFinal(clientes, crearNodoCliente(nuevo));
            }
            else
            {
                gotoxy(posX, posY + 5);
                color(12);
                printf("El usuario ya existe, intente nuevamente!\n");
                color(15);
                gotoxy(posX, whereY());
                color(10);
                system("pause");
                color(15);
            }
            break;
        default:
            break;
        }
    }
    while(op != 0);

    gotoxy(0, y+1);
    return 0;
}

///Menus
void menuLogin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos)
{
    nodoListaClientes * cliente = inicListaClientes();
    int x,y,posX = 0,posY = 0,op = 0;
    char usuario[20], pass[20];
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("=====|Bienvenido|=====")/2)-2;
    posY = (y/3) - 1;
    do
    {
        system("cls");
        header();
        gotoxy(posX,posY);
        menuLoginG(posX);
        gotoxy(0, y-4);
        footer();
        gotoxy((posX+strlen("Contrasena: ")), posY + 1);
        color(10);
        fflush(stdin);
        gets(usuario);
        color(15);
        cliente = buscarClientePorUsername(listaClientes, usuario);
        while(!cliente)
        {
            gotoxy(posX, posY + 3);
            color(12);
            printf("El usuario no existe!");
            color(15);
            gotoxy((posX+strlen("Contrasena: ")), posY + 1);
            limpiarLineaDer();
            color(10);
            fflush(stdin);
            gets(usuario);
            color(15);
            cliente = buscarClientePorUsername(listaClientes, usuario);
        }
        gotoxy(posX, posY + 3);
        limpiarTodaLinea();
        gotoxy((posX+strlen("Contrasena: ")), posY + 2);
        color(10);
        fflush(stdin);
        gets(pass);
        color(15);
        while(strcmpi(pass, cliente->cliente.password))
        {
            gotoxy(posX, posY + 3);
            color(12);
            printf("La contrase%ca es incorrecta!", enie);
            color(15);
            gotoxy((posX+strlen("Contrasena: ")), posY + 2);
            limpiarLineaDer();
            color(10);
            fflush(stdin);
            gets(pass);
            color(15);
        }

        cliente->cliente.rol == 1 ? menuPrincipalAdmin(listaClientes, arbolProductos) : menuPrincipalClientes(cliente, arbolProductos);
    }
    while(op != 0);
}

void menuPrincipalClientes(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos)
{
    int op = 0, x, y, posX = 0, posY = 0, mostrar = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("======|Hola!          |======")/2);
    posY = (y/2) - 5;

    do
    {
        system("cls");
        header();
        gotoxy(posX, posY);
        color(10);
        printf("======|Hola! |======\n");
        color(15);
        menuPrincipalClientesG(posX);
        gotoxy(0, y-4);
        footer();
        gotoxy(posX+4, posY + 6);
        color(10);
        scanf("%d", &op);
        color(15);

        switch(op)
        {
        case 1:
            system("cls");
            subprogramaHacerPedido(nodoCliente, arbolProductos);
            break;
        case 2:
            mostrarNodoCliente(nodoCliente->listaProductos, posX);
            gotoxy(posX, whereY() + 1);
            system("pause");
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
    int op = 0, x, y, posX = 0, posY = 0, mostrar = 0, aux = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("======|Menu Administrador|======")/2);
    posY = (y/2) - 8;

    do
    {
        system("cls");
        header();
        gotoxy(posX, posY);
        menuPrincipalAdminG(posX);
        gotoxy(0, y-4);
        footer();
        gotoxy(posX+4,posY + 12);
        color(10);
        scanf("%d", &op);
        color(15);

        switch(op)
        {
        case 1:
            system("cls");
            nuevoCliente = crearCliente(A_Clientes);
            clienteEncotrado = buscarClientePorUsername(listaClientes, nuevoCliente.userName);
            if(!clienteEncotrado)
            {
                registrarCliente(A_Clientes, nuevoCliente);
                listaClientes = agregarClienteFinal(listaClientes, crearNodoCliente(nuevoCliente));
            }
            else
            {
                gotoxy(posX, posY + 10);
                color(12);
                printf("El usuario ya existe, intente nuevamente!\n");
                color(15);
                gotoxy(posX, whereY());
                color(10);
                system("pause");
                color(15);
            }
            break;
        case 2:
            system("cls");
            header();
            gotoxy(posX, 3);
            mostrarListaClientes(listaClientes, posX);
            aux = whereY();
            if(whereY() <= y-4)
                gotoxy(0, y-4);
            footer();
            gotoxy(posX, aux);
            color(10);
            system("pause");
            color(15);
            break;
        case 3:
            menuBusquedaCliente(listaClientes);
            break;
        case 4:
            menuModificarCliente(listaClientes);
            break;
        case 5:
            system("cls");
            nuevoProducto = crearProducto(A_Productos);
            registrarProducto(A_Productos, nuevoProducto);
            arbolProductos = agregarNodoEnOrden(arbolProductos, crearNodoArbolProducto(nuevoProducto));
            break;
        case 6:
            menuMostrarArbol(arbolProductos);
            break;
        case 7:
            //subprogramaBuscarProducto();
            break;
        case 8:
            //subProgramaModificarProducto();
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuMostrarArbol(nodoArbolProducto * arbolProductos)
{
    int op = 0, x, y, posX = 0, posY = 0, aux = 0;
    getWindowSize(&x, &y);
    posX = (x/2)-(strlen("=====|Mostrar Productos|=====")/2);
    posY =(y/2)-5;

    do
    {
        system("cls");
        header();
        gotoxy(posX, posY);
        menuMostrarArbolG(posX);
        gotoxy(0, y-4);
        footer();
        gotoxy(posX+4, posY+5);
        color(10);
        scanf("%d", &op);
        color(15);
        switch(op)
        {
        case 1:
            system("cls");
            header();
            gotoxy(posX, 3);
            mostrarPreOrden(arbolProductos, posX);
            aux = whereY();
            if(whereY() <= y-4)
                gotoxy(0, y-4);
            footer();
            gotoxy(posX, aux);
            color(10);
            system("pause");
            color(15);
            break;
        case 2:
            system("cls");
            header();
            gotoxy(posX, 3);
            mostrarInOrden(arbolProductos, posX);
            aux = whereY();
            if(whereY() <= y-4)
                gotoxy(0, y-4);
            footer();
            gotoxy(posX, aux);
            color(10);
            system("pause");
            color(15);
            break;
        case 3:
            system("cls");
            header();
            gotoxy(posX, 3);
            mostrarPosOrden(arbolProductos, posX);
            aux = whereY();
            if(whereY() <= y-4)
                gotoxy(0, y-4);
            footer();
            gotoxy(posX, aux);
            color(10);
            system("pause");
            color(15);
            break;
        default:
            break;
        }
    }
    while(op != 0);
}

void menuBusquedaCliente(nodoListaClientes * listaClientes)
{
    int op = 0, x, y, posX = 0, posY = 0, idCli = 0;
    char busca[30] = "\0";
    getWindowSize(&x, &y);
    posX = (x/2)-(strlen("=====|Buscar Cliente|=====")/2) - 3;
    posY =(y/2)-5;
    nodoListaClientes * clienteEncontrado = inicListaClientes();

    do
    {
        system("cls");
        header();
        gotoxy(posX,posY);
        menuBusquedaClienteG(posX);
        gotoxy(0,y - 4);
        footer();
        gotoxy(posX + 4, posY + 7);
        color(10);
        scanf("%d", &op);
        color(15);

        switch (op)
        {
        case 1:
            gotoxy(posX, posY + 8);
            printf("Ingrese el ID: ");
            color(10);
            scanf("%d", &idCli);
            color(15);
            clienteEncontrado = buscarClientePorId(listaClientes, idCli);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, posX, posY);
            }
            else
            {
                gotoxy(posX, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No hay ningun usuario con ese ID!");
                color(10);
                gotoxy(posX, posY + 9);
                system("pause");
                color(15);
            }
            break;
        case 2:
            gotoxy(posX, posY + 8);
            printf("Ingrese el nombre de usuario: ");
            color(10);
            fflush(stdin);
            gets(busca);
            color(15);
            clienteEncontrado = buscarClientePorUsername(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, posX, posY);
            }
            else
            {
                gotoxy(posX, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No hay ningun usuario con ese nombre de usuario!");
                color(10);
                gotoxy(posX, posY + 9);
                system("pause");
                color(15);
            }
            break;
        case 3:
            gotoxy(posX, posY + 8);
            printf("Ingrese el email: ");
            color(10);
            fflush(stdin);
            gets(busca);
            color(15);
            clienteEncontrado = buscarClientePorEmail(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, posX, posY);
            }
            else
            {
                gotoxy(posX, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No hay ningun usuario con ese email!");
                color(10);
                gotoxy(posX, posY + 9);
                system("pause");
                color(15);
            }
            break;
        case 4:
            gotoxy(posX, posY + 8);
            printf("Ingrese el nombre: ");
            color(10);
            fflush(stdin);
            gets(busca);
            color(15);
            clienteEncontrado = buscarClientePorNombre(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, posX, posY);
            }
            else
            {
                gotoxy(posX, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No hay ningun usuario con ese Nombre!");
                color(10);
                gotoxy(posX, posY + 9);
                system("pause");
                color(15);
            }
            break;
        case 5:
            gotoxy(posX, posY + 8);
            printf("Ingrese el apellido: ");
            color(10);
            fflush(stdin);
            gets(busca);
            color(15);
            clienteEncontrado = buscarClientePorApellido(listaClientes, busca);
            if(clienteEncontrado)
            {
                subProgramaMostrarCliente(clienteEncontrado, posX, posY);
            }
            else
            {
                gotoxy(posX, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("No hay ningun usuario con ese apellido!");
                color(10);
                gotoxy(posX, posY + 9);
                system("pause");
                color(15);
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
    int op = 0, x, y, posX = 0, posY = 0, idCli = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - strlen("=====|Modificar Cliente|=====")/2 - 2;
    posY = y/2 - 2;

    system("cls");
    header();
    gotoxy(posX,posY);
    color(10);
    printf("=====|Modificar Cliente|=====\n\n");
    color(15);
    gotoxy(posX, whereY());
    printf("Ingrese ID del usuario a modificar: ");
    gotoxy(0, y - 4);
    footer();
    gotoxy(posX + strlen("Ingrese ID del usuario a modificar: "), posY + 2);
    color(10);
    scanf("%d", &idCli);
    color(15);

    clienteEncontrado = buscarClientePorId(listaClientes, idCli);

    if(clienteEncontrado)
    {
        subProgramaModificarCliente(clienteEncontrado, A_Clientes, 1);
    }
    else
    {
        gotoxy(posX, whereY());
        color(12);
        printf("No hay un usuario con ese ID!\n");
        color(10);
        gotoxy(posX, whereY());
        system("pause");
        color(15);
    }
}

///Subprogramas
void subprogramaHacerPedido(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos)
{
    nodoArbolProducto * nodoProducto = inicArbol();
    int x,y, posX = 0, posY = 0, idProd = 0, aux = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - strlen("=====|Productos|=====");
    posY = 3;

    header();
    gotoxy(posX, posY);
    color(10);
    printf("=====|Productos|=====\n");
    color(15);
    mostrarInOrden(arbolProductos, posX);
    printf("Ingrese ID de producto: ");
    aux = whereY();
    if(whereY() <= y - 4)
        gotoxy(0,y - 4);
    footer();
    gotoxy(posX + strlen("Ingrese ID de producto: "), aux);
    color(10);
    scanf("%d", &idProd);
    color(15);

    nodoProducto = buscarNodoPorId(arbolProductos, idProd);
    agregarProductoListaClientes(nodoCliente, nodoCliente->cliente.idCliente, nodoProducto->producto);
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

int validarString(char palabra[], int dim)
{
    int flag = 0;

    if(strlen(palabra) > dim)
    {
        flag = 1;
    }

    return flag;
}
