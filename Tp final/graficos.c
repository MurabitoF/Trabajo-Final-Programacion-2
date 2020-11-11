#include "graficos.h"

///Funciones de Control de Ventanas
void getWindowSize(int * col, int * row)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    (*col) = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    (*row) = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

}

void limpiarTodaLinea()
{
    printf("%c[2K", 27); ///Borra la consola en la linea donde este el cursor
}

void limpiarLineaDer()
{
    printf("%c[K", 27); ///Borra la consola a la derecha del cursor
}

void limpiarLineaIzq()
{
    printf("%c[1K", 27); ///Borra la consola a la izquierda del cursor
}

///Header y Footer
void header()
{
    int x,y,i,posX = 0,posY = 0;
    getWindowSize(&x, &y);

    gotoxy(3,0);
    printf("%c", escSupIzq);
    for(i = 0; i <(x-8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escSupDer);
    posY = whereY() + 1;
    gotoxy(3,posY);
    printf("%c", barraVertical);
    gotoxy((x/2)-(strlen("YOU TECS - TU TIENDA DE TECNOLOGIA")/2), posY);
    color(10);
    printf("YOU TECS - TU TIENDA DE TECNOLOGIA");
    color(15);
    gotoxy(x-4,posY);
    printf("%c", barraVertical);
    posY = whereY() + 1;
    gotoxy(3,posY);
    printf("%c", escInfIzq);
    for(i = 0; i <(x-8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escInfDer);
}
void footer()
{
    int x,y,i,posX = 0,posY = 0;
    getWindowSize(&x, &y);
    posY = whereY() + 1;

    gotoxy(3,posY);
    printf("%c", escSupIzq);
    for(i = 0; i <(x-8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escSupDer);
    posY = whereY() + 1;
    gotoxy(3,posY);
    printf("%c", barraVertical);
    gotoxy(((x/2)-(strlen("YOU TECS - ASUSPENDER")/2)), posY);
    color(2);
    printf("YOU TECS - ASUSPENDER");
    color(15);
    gotoxy(x-4,posY);
    printf("%c", barraVertical);
    posY = whereY() + 1;
    gotoxy(3,posY);
    printf("%c", escInfIzq);
    for(i = 0; i <(x-8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escInfDer);
}

void loading()
{
    int i, x, y, posX = 0, posY = 0, p = 0;

    hidecursor(0);
    getWindowSize(&x, &y);
    posX = (x-8)/2 -strlen("CARGANDO");
    posY = (y-6)/2 - 1;

    while(p < 10)
    {
        system("cls");
        gotoxy(posX, posY);
        printf("CARGANDO");
        gotoxy(posX,posY+2);


        gotoxy(posX,posY+2);
        for(i = 0; i < 8; i++)
        {
            Sleep(300);
            printf("%c", 219);
        }
        p++;
    }
}

///Menús
void menuIngresoG(int x)
{
    color(10);
    gotoxy(x, whereY());
    printf("======|You TECS|======\n");
    color(15);
    gotoxy(x, whereY());
    printf("[ 1 ] Ingresar\n");
    gotoxy(x, whereY());
    printf("[ 2 ] Crear Cuenta\n");
    gotoxy(x, whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x, whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuLoginG(int x)
{
    color(10);
    gotoxy(x, whereY());
    printf("=====|Bienvenido|=====\n");
    color(15);
    gotoxy(x, whereY());
    printf("Usuario: \n");
    gotoxy(x, whereY());
    printf("Contrase%ca: \n", enie);
}

void menuPrincipalClientesG(int x)
{
    gotoxy(x,whereY());
    printf("[ 1 ] Hacer un pedido\n");
    gotoxy(x,whereY());
    printf("[ 2 ] Mostrar mis Pedidos\n");
    gotoxy(x,whereY());
    printf("[ 3 ] Modificar mis datos\n");
    gotoxy(x,whereY());
    printf("[ 4 ] Productos recomendados\n");
    gotoxy(x,whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x,whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuPrincipalAdminG(int x)
{
    color(10);
    printf("======|Menu Administrador|======\n");
    color(2);
    gotoxy(x,whereY());
    printf("|-----CLIENTES -----|\n");
    color(15);
    gotoxy(x,whereY());
    printf("[ 1 ] Dar de alta cliente\n");
    gotoxy(x,whereY());
    printf("[ 2 ] Mostrar lista clientes\n");
    gotoxy(x,whereY());
    printf("[ 3 ] Buscar un cliente\n");
    gotoxy(x,whereY());
    printf("[ 4 ] Modificar datos de un cliente\n");
    color(2);
    gotoxy(x,whereY());
    printf("|-----PRODUCTOS -----|\n");
    color(15);
    gotoxy(x,whereY());
    printf("[ 5 ] Dar de alta producto\n");
    gotoxy(x,whereY());
    printf("[ 6 ] Mostrar lista de pedidos\n");
    gotoxy(x,whereY());
    printf("[ 7 ] Buscar un producto\n");
    gotoxy(x,whereY());
    printf("[ 8 ] Modificar datos de un producto\n");
    gotoxy(x,whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x,whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuDatosClienteAdminG(int x)
{
    color(10);
    printf("============|Datos del Clientes|===========\n");
    color(15);
    gotoxy(x,whereY());
    printf("[ 1 ] Nombre\n");
    gotoxy(x,whereY());
    printf("[ 2 ] Apellido\n");
    gotoxy(x,whereY());
    printf("[ 3 ] Nombre de usuario\n");
    gotoxy(x,whereY());
    printf("[ 4 ] Contrase%ca\n", enie);
    gotoxy(x,whereY());
    printf("[ 5 ] Direccion de email\n");
    gotoxy(x,whereY());
    printf("[ 6 ] Domicilio\n");
    gotoxy(x,whereY());
    printf("[ 7 ] Genero\n");
    gotoxy(x,whereY());
    printf("[ 8 ] Dar de baja\n");
    gotoxy(x,whereY());
    printf("[ 9 ] Hacer administrador\n");
    gotoxy(x,whereY());
    printf("[ 0 ] Volver\n");
    gotoxy(x,whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuDatosClienteG(int x)
{
    color(10);
    printf("=====|Datos del Clientes|=====\n");
    color(15);
    gotoxy(x,whereY());
    printf("[ 1 ] Nombre\n");
    gotoxy(x,whereY());
    printf("[ 2 ] Apellido\n");
    gotoxy(x,whereY());
    printf("[ 3 ] Nombre de usuario\n");
    gotoxy(x,whereY());
    printf("[ 4 ] Contrase%ca\n", enie);
    gotoxy(x,whereY());
    printf("[ 5 ] Direccion de email\n");
    gotoxy(x,whereY());
    printf("[ 6 ] Domicilio\n");
    gotoxy(x,whereY());
    printf("[ 7 ] Genero\n");
    gotoxy(x,whereY());
    printf("[ 8 ] Dar de baja\n");
    gotoxy(x,whereY());
    printf("[ 0 ] Volver\n");
    gotoxy(x,whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuMostrarArbolG(int x)
{
    color(10);
    printf("=====|Mostrar Productos|=====\n");
    color(15);
    gotoxy(x, whereY());
    printf("[ 1 ] Preorden\n");
    gotoxy(x, whereY());
    printf("[ 2 ] Inorden\n");
    gotoxy(x, whereY());
    printf("[ 3 ] Posorden\n");
    gotoxy(x, whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x, whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuBusquedaClienteG(int x)
{
    color(10);
    printf("=====|Buscar Cliente|=====\n");
    color(15);
    gotoxy(x, whereY());
    printf("[ 1 ] Buscar por ID\n");
    gotoxy(x, whereY());
    printf("[ 2 ] Buscar por nombre de usuario\n");
    gotoxy(x, whereY());
    printf("[ 3 ] Buscar por email\n");
    gotoxy(x, whereY());
    printf("[ 4 ] Buscar por nombre\n");
    gotoxy(x, whereY());
    printf("[ 5 ] Buscar por apellido\n");
    gotoxy(x, whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x, whereY());
    color(2);
    printf(">>> ");
    color(15);
}
