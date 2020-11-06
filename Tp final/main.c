#include <stdio.h>
#include <stdlib.h>
#include "listaClientes.h"
#include "arbolProducto.h"

const char A_Clientes[] = "Datos\\clientes.dat";
const char A_Productos[] = "numeros.dat";

///Menus
void menuLogin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuPrincipalClientes(nodoListaClientes * nodoCliente, nodoArbolProducto * arbolProductos);
void menuPrincipalAdmin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos);
void menuMostrarArbol(nodoArbolProducto * arbolProducto);
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
    nodoArbolProducto * productos = inicArbol();

    //cargar Lista y arbol

    do
    {
        system("cls");
        hidecursor(0);
        header();
        gotoxy(posX,posY);
        menuIngresoG(posX);
        gotoxy(posX, whereY());
        footer();
        gotoxy(posX + 4, posY + 4);
        hidecursor(1);
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            //menuLogin(clientes, productos);
            //menuPrincipalAdmin(clientes, productos);
            menuPrincipalClientes(clientes, productos);
            break;
        case 2:
            system("cls");
            nuevo = crearCliente(A_Clientes);
            registrarCliente(A_Clientes, nuevo);
            clientes = agregarClienteFinal(clientes, crearNodoCliente(nuevo));
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
    nodoListaClientes * cliente;
    int x,y,posX = 0,posY = 0,op = 0;
    char usuario[20], pass[20];
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("=====|Bienvenido|=====")/2)-2;
    posY = (y/3) - 1;
    do
    {
        system("cls");
        hidecursor(0);
        header();
        gotoxy(posX,posY);
        menuLoginG(posX);
        footer();
        gotoxy((posX+strlen("Usuario: ")), posY + 1);
        hidecursor(1);
        fflush(stdin);
        gets(usuario);
        gotoxy((posX+strlen("Contrasena: ")), posY + 2);
        fflush(stdin);
        gets(pass);

        cliente = buscarClientePorUsername(listaClientes, usuario);
        if(!cliente)
        {
            gotoxy(posX, posY + 3);
            color(12);
            printf("El usuario no existe!");
            color(15);
            system("pause");
        }
        else if(strcmpi(cliente->cliente.password, pass) != 0)
        {
            gotoxy(posX, posY + 4);
            color(12);
            printf("La contrase%ca es incorrecta!", enie);
            color(15);
            system("pause");
        }
        else
        {
            if(cliente->cliente.rol == 1)
            {
                menuPrincipalAdmin(listaClientes, arbolProductos);
            }
            else
            {
                menuPrincipalClientes(cliente, arbolProductos);
            }
        }
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
        hidecursor(0);
        header();
        gotoxy(posX, posY);
        color(10);
        printf("======|Hola! |======\n");
        color(15);
        menuPrincipalClientesG(posX);
        footer();
        gotoxy(posX+4, posY + 6);
        hidecursor(1);
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            //subprogramaHacerPedido
            break;
        case 2:
            mostrarListaProducto(nodoCliente->listaProductos);
            gotoxy(posX, whereY() + 1);
            system("pause");
            break;
        case 3:
            //subProgramaModificarCliente(nodoCliente, A_Clientes);
            break;
        case 4:
            //mostrarProductosRecomendado
            break;
        default:
            break;
        }
    }while(op != 0);
}
void menuPrincipalAdmin(nodoListaClientes * listaClientes, nodoArbolProducto * arbolProductos)
{
    stCliente nuevoCliente;
    stProducto nuevoProducto;
    int op = 0, x, y, posX = 0, posY = 0, mostrar = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("======|Menu Administrador|======")/2);
    posY = (y/2) - 8;

    do
    {
        system("cls");
        hidecursor(0);
        header();
        gotoxy(posX, posY);
        menuPrincipalAdminG(posX);
        footer();
        gotoxy(posX+4,posY + 12);
        hidecursor(1);
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            system("cls");
            nuevoCliente = crearCliente(A_Clientes);
            registrarCliente(A_Clientes, nuevoCliente);
            listaClientes = agregarClienteFinal(listaClientes, crearNodoCliente(nuevoCliente));
            break;
        case 2:
            mostrarListaCliente(listaClientes);
            break;
        case 3:
            //subprogramaBuscarCliente();
            break;
        case 4:
            //subProgramaModificarCliente();
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
    int op = 0, x, y, posX = 0, posY = 0;
    getWindowSize(&x, &y);
    posX = (x/2)-(strlen("=====|Mostrar Productos|=====")/2);
    posY =(y/2)-5;

    do
    {
        system("cls");
        hidecursor(0);
        header();
        gotoxy(posX, posY);
        menuMostrarArbolG(posX);
        footer();
        gotoxy(posX+4, posY+5);
        hidecursor(1);
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            mostrarPreOrden(arbolProductos);
            gotoxy(posX, whereY()+1);
            system("pause");
            break;
        case 2:
            mostrarInOrden(arbolProductos);
            gotoxy(posX, whereY()+1);
            system("pause");
            break;
        case 3:
            mostrarPosOrden(arbolProductos);
            gotoxy(posX, whereY()+1);
            system("pause");
            break;
        default:
            break;
        }
    }while(op != 0);
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
