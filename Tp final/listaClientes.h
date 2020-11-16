#ifndef LISTASCLIENTES_H_INCLUDED
#define LISTASCLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "listaProducto.h"

typedef struct _nodoCliente
{
    stCliente cliente;
    nodoListaProducto * listaProductos;
    struct _nodoCliente * siguiente;
    float costoTotalDelPedido;
}nodoListaClientes;

///Funciones Basicas
nodoListaClientes * inicListaClientes();
nodoListaClientes * crearNodoCliente(stCliente cliente);

///Funciones Agregar
nodoListaClientes * agregarClientePpio(nodoListaClientes * lista, nodoListaClientes * nuevo);
nodoListaClientes * agregarClienteFinal(nodoListaClientes * lista, nodoListaClientes * nuevo);
nodoListaClientes * agregarClienteEnOrden(nodoListaClientes * lista, nodoListaClientes * nuevo);
void agregarProductoListaClientes(nodoListaClientes * lista, int id, stProducto producto);

///Funciones de Busqueda
nodoListaClientes * buscarUltimoNodoClientes(nodoListaClientes * lista);
nodoListaClientes * buscarClientePorId(nodoListaClientes * lista, int busqueda);
nodoListaClientes * buscarClientePorUsername(nodoListaClientes * lista, char busqueda[]);
nodoListaClientes * buscarClientePorEmail(nodoListaClientes * lista, char busqueda[]);
nodoListaClientes * buscarClientePorNombre(nodoListaClientes * lista, char busqueda[]);
nodoListaClientes * buscarClientePorApellido(nodoListaClientes * lista, char busqueda[]);

///Funciones de Borrado
nodoListaClientes * borrarPrimerCliente(nodoListaClientes * lista);
nodoListaClientes * borrarUltimoCliente(nodoListaClientes * lista);
nodoListaClientes * borrarNodoCliente(nodoListaClientes * lista, nodoListaClientes * borrado);
nodoListaClientes * borrarListaClientes(nodoListaClientes * lista);

///Funciones de muestra
void mostrarNodoCliente(nodoListaClientes * cliente);
void mostrarListaClientes(nodoListaClientes * lista);

///Funciones de archivos
nodoListaClientes * pasaArchivoALista(nodoListaClientes * listaCliente, char nombreArchivo[]);
void generarPedidos(nodoListaClientes * lista, char nombreArchivo[]);

///Subprogramas
void subProgramaMostrarCliente(nodoListaClientes * nodoCliente, ventana pos);


#endif // LISTASCLIENTES_H_INCLUDED
