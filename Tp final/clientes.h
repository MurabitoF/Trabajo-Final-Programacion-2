#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char domicilio[30];
    char genero;
    int rol; // 1: es admin - 0: cliente
    int activo; // indica 1 o 0 si el cliente fue eliminado
} stCliente;

///Funcion de muestra
void mostrarCliente(stCliente dato);

///Funciones de carga
stCliente crearCliente(char nombreArchivo[]);

void registrarCliente(char nombreArchivo[], stCliente client);

#endif // CLIENTES_H_INCLUDED
