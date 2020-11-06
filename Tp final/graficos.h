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

///Funciones Control de ventana
void getWindowSize(int * col, int * row);

///Header y Footer
void header();
void footer();
void loading();

///Menús
void menuIngresoG(int x);
void menuLoginG(int x);
void menuPrincipalAdminG(int x);
void menuPrincipalClientesG(int x);
void menuDatosClienteG(int x);
void menuMostrarArbolG(int x);

#endif // GRAFICOS_H_INCLUDED
