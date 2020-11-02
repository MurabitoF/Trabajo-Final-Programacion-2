#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graficos.h"

typedef struct _stCliente
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

///Funciones de Carga
stCliente crearCliente(char nombreArchivo);  //Ingresa los datos por teclado los datos para crear un cliente.
///Funcioes de Muestra
void mostrarCliente(stCliente client);
///Funcines de archivos
void registrarCliente(char nombreArchivo[], stCliente client); //Registra un cliente en un archivo.
void escribirCliente(FILE * arch, stCliente cliente);
void registrarClienteModificado(char nombreArchivo, stCliente cliente);
///Funciones de modificación
stCliente modificarCliente(stCliente cliente);

#endif // CLIENTES_H_INCLUDED
