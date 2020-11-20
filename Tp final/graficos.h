#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "gotoxy.h"

///Caracteres especiales
#define enie 164
#define barraHorizontal 205
#define barraVertical 186
#define escSupIzq 201
#define escSupDer 187
#define escInfIzq 200
#define escInfDer 188

///Estructura de posicion en ventana
/*
La estructura que utilizaremos para posicionar el cursor y mostrar por pantalla
*/
typedef struct
{
    int tamX; //Tamaño maximo en x de la ventana
    int tamY; //Tamaño maximo en y de la ventana
    int posX; //Posición central en x de la ventana
    int posY; //Posición central en y de la ventana
}ventana;

///Funciones Control de ventana
void getWindowSize(int * col, int * row);
void limpiarTodaLinea();
void limpiarLineaDer();
void limpiarLineaIzq();
ventana inicVentana(char texto[], int items);


///Funciones de lectura
int leerInt();
float leerfloat();
char leerChar();
char * leerString(int dim);
void pausa();

///Header y Footer
void header();
void footer();
void loading();

///Menús
void menuIngresoG();
void menuLoginG();
void menuPrincipalAdminG();
void menuPrincipalClientesG();
void menuDatosClienteAdminG();
void menuDatosClienteG();
void menuMostrarArbolG();
void menuBusquedaClienteG();
void menuBusquedaProductoG();
void menuDatosProductosG();
#endif // GRAFICOS_H_INCLUDED
