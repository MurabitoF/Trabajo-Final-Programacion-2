#include "graficos.h"

///Funciones de Control de Ventanas
void getWindowSize(int * col, int * row)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    (*col) = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    (*row) = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

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
    gotoxy(x/2.8, posY);
    color(12);
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
    int x,y,i,posX = 0,posY = whereY();
    getWindowSize(&x, &y);

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
    gotoxy(x/2.6, posY);
    color(7);
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

void menuEditarDatosClientes()
{

}
