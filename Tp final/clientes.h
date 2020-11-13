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
    int activo; // indica 0 si el cliente fue eliminado si no 1
} stCliente;

///Funciones de Carga
stCliente crearCliente(char nombreArchivo[]);  //Ingresa los datos por teclado los datos para crear un cliente.
///Funcioes de Muestra
void mostrarCliente(stCliente client); //Muestra un cliente
///Funcines de archivos
void registrarCliente(char nombreArchivo[], stCliente client); //Registra un cliente en un archivo.
void registrarClienteModificado(char nombreArchivo[], stCliente cliente); //Registra un cliente modificado
///Funciones de modificación
stCliente modificarCliente(stCliente cliente, int admin); //Modifica los datos de un cliente

#endif // CLIENTES_H_INCLUDED
