#include "graficos.h"

///Funciones de Control de Ventanas
void getWindowSize(int * col, int * row) //Obtiene el tamaño de la ventana
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    (*col) = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    (*row) = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

}

void limpiarTodaLinea()
{
    printf("%c[2K", 27); //Borra la consola en la linea donde este el cursor
}

void limpiarLineaDer()
{
    printf("%c[K", 27); //Borra la consola a la derecha del cursor
}

void limpiarLineaIzq()
{
    printf("%c[1K", 27); //Borra la consola a la izquierda del cursor
}

ventana inicVentana(char texto[], int items) //Inicializa mi estructura de ventana, tratando de centrar el texto en pantalla
{
    ventana aux;
    int x = 0, y = 0, posX = 0, posY = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen(texto)/2);
    posY = (y/2) - items;

    aux.tamX = x;
    aux.tamY = y;
    aux.posX = posX;
    aux.posY = posY;

    return aux;
}

///Header y Footer
void header() //Banner superior del sistema
{
    int i;
    ventana pos = inicVentana("\0", 0);

    system("cls");
    gotoxy(3,0);
    printf("%c", escSupIzq);
    for(i = 0; i <(pos.tamX - 8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escSupDer);
    pos.posY = whereY() + 1;
    gotoxy(3, pos.posY);
    printf("%c", barraVertical);
    gotoxy((pos.tamX/2) - (strlen("YOU TECS - TU TIENDA DE TECNOLOGIA")/2), pos.posY);
    color(10);
    printf("YOU TECS - TU TIENDA DE TECNOLOGIA");
    color(15);
    gotoxy(pos.tamX - 4, pos.posY);
    printf("%c", barraVertical);
    pos.posY = whereY() + 1;
    gotoxy(3, pos.posY);
    printf("%c", escInfIzq);
    for(i = 0; i <(pos.tamX - 8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escInfDer);
}

void footer() //Banner inferior del sistema
{
    int i;
    ventana pos = inicVentana("\0", 0);
    pos.posY = whereY() + 1;

    gotoxy(3, pos.posY);
    printf("%c", escSupIzq);
    for(i = 0; i < (pos.tamX - 8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escSupDer);
    pos.posY = whereY() + 1;
    gotoxy(3, pos.posY);
    printf("%c", barraVertical);
    gotoxy(((pos.tamX/2)-(strlen("YOU TECS - ASUSPENDER")/2)), pos.posY);
    color(2);
    printf("YOU TECS - ASUSPENDER");
    color(15);
    gotoxy(pos.tamX - 4, pos.posY);
    printf("%c", barraVertical);
    pos.posY = whereY() + 1;
    gotoxy(3, pos.posY);
    printf("%c", escInfIzq);
    for(i = 0; i <(pos.tamX - 8); i++)
    {
        printf("%c", barraHorizontal);
    }
    printf("%c", escInfDer);
}

///Funciones de lectura
int leerInt() //Lee un entrero y lo devuelve
{
    int aux = 0;

    color(10);
    scanf("%d", &aux);
    color(15);

    return aux;
}
float leerfloat() //Lee un numero real y lo devuelve
{
    float aux = 0;

    color(10);
    scanf("%f", &aux);
    color(15);

    return aux;
}

char leerChar() //Lee un caracter y lo devuelve
{
    char aux = 'n';

    fflush(stdin);
    color(10);
    scanf("%c", &aux);
    color(15);

    return aux;
}

char * leerString(int dim) //Lee una cadena de caracteres y lo devuelve
{
    char * aux = (char *)malloc(sizeof(char) * dim);

    fflush(stdin);
    color(10);
    gets(aux);
    color(15);

    return aux;
}

void pausa() //Pausa el programa hasta que se precione una tecla
{
    color(10);
    system("pause");
    color(15);
}

///Menús
void menuIngresoG()
{
    int x = whereX();

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

void menuLoginG()
{
    int x = whereX();

    color(10);
    gotoxy(x, whereY());
    printf("=====|Bienvenido|=====\n");
    color(15);
    gotoxy(x, whereY());
    printf("Usuario: \n");
    gotoxy(x, whereY());
    printf("Contrase%ca: \n", enie);
}

void menuPrincipalClientesG()
{
    int x = whereX();

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

void menuPrincipalAdminG()
{
    int x = whereX();

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

void menuDatosClienteAdminG()
{
    int x = whereX();

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

void menuDatosClienteG()
{
    int x = whereX();

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

void menuDatosProductosG()
{
    int x = whereX();

    color(10);
    printf("=====|Datos del Producto|=====\n");
    color(15);
    gotoxy(x,whereY());
    printf("[ 1 ] Nombre del producto\n");
    gotoxy(x,whereY());
    printf("[ 2 ] Marca del producto\n");
    gotoxy(x,whereY());
    printf("[ 3 ] Categoria del producto\n");
    gotoxy(x,whereY());
    printf("[ 4 ] Precio del producto\n");
    gotoxy(x,whereY());
    printf("[ 5 ] Eliminar producto\n");
    gotoxy(x,whereY());
    printf("[ 0 ] Volver\n");
    gotoxy(x,whereY());
    color(2);
    printf(">>> ");
    color(15);
}

void menuMostrarArbolG()
{
    int x = whereX();

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

void menuBusquedaClienteG()
{
    int x = whereX();

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

void menuBusquedaProductoG()
{
    int x = whereX();

    color(10);
    printf("=====|Buscar Producto|=====\n");
    color(15);
    gotoxy(x, whereY());
    printf("[ 1 ] Buscar por ID\n");
    gotoxy(x, whereY());
    printf("[ 2 ] Buscar por nombre producto\n");
    gotoxy(x, whereY());
    printf("[ 3 ] Buscar por marca\n");
    gotoxy(x, whereY());
    printf("[ 4 ] Buscar por categorias\n");
    gotoxy(x, whereY());
    printf("[ 0 ] Salir\n");
    gotoxy(x, whereY());
    color(2);
    printf(">>> ");
    color(15);
}
