#include <stdio.h>
#include <stdlib.h>

#include "productos.h"
#include "clientes.h"
#include "pedidos.h"
#include "listaClientes.h"
#include "listaProducto.h"
#include "arbolProducto.h"
#include "gotoxy.h"

const char categorias[7][15] = {"Televisores", "Computadoras", "Celulares", "Accesorios", "Heladeras", "Aires", "Cocina"};

const char A_Productos[] = "productos.dat";
const char A_Clientes[] = "clientes.dat";
const char A_Pedidos[] = "pedidos.dat";

int contadorDatos(char nombreArchivo[], int byte);
void pasarProductoaCliente(nodoListaClientes * lista, stProducto producto, stPedidos pedido);
void bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos);

int main()
{

    int i, val;
    int dim;

    nodoArbolProducto * arbolProductos = inicArbol();
    nodoListaClientes * clientes = inicListaClientes();

    /*for (i = 1; i<2; i++)
    {
        crearProducto(A_Productos);
        crearCliente(A_Clientes);
        cargarPedido(A_Pedidos, &i, &i);
    }*/
    FILE * productos = fopen(A_Productos, "rb");
    stProducto p;

    if (productos)
    {
        while (fread(&p, sizeof(stProducto), 1, productos) > 0)
        {
            mostrarProducto(p);
            printf("\n");
        }
    }
    fclose(productos);

    system("pause");

    dim = contadorDatos(A_Productos, sizeof(stProducto));
    printf("%d", dim);

    system("pause");

    stProducto aProductos [dim];

    val = pasarArchivoArray(&aProductos, A_Productos, dim);

    arbolProductos = arregloOrd2arbol(arbolProductos, aProductos, 0, val);

    pasaArchivoALista(clientes, A_Clientes);

    bajarPedidos(A_Pedidos, clientes, arbolProductos);

    mostrarListaCliente(clientes);
    return 0;
}

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

void muestraRecomendados(nodoListaClientes * clientes, nodoArbolProducto * arbolProductos)
{
    int masVendido;
    masVendido = buscaMayor(contarCategorias(clientes->listaProductos));
    mostrarPorCategoria(arbolProductos, categorias);
}

void bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos)
{
    FILE * archi = fopen(nombreArchivo, "rb");

    stPedidos pedido;
    nodoArbolProducto * p;
    nodoListaClientes * aux = inicListaClientes();

    if (archi)
    {
        while (fread(&pedido, sizeof(stPedidos), 1, archi) > 0)
        {
            p = buscarNodoPorId(productos, pedido.idProducto);
            pasarProductoaCliente(clientes, p->producto, pedido);
            //aux = buscarClientePorId(clientes, pedido.idCliente);
            //aux->listaProductos = agregarFinalProducto(aux->listaProductos, crearNodoProducto(buscarNodoPorId(productos, pedido.idProducto), pedido.idPedido, pedido.fecha));
        }
        fclose(archi);
    }
}

void pasarProductoaCliente(nodoListaClientes * lista, stProducto producto, stPedidos pedido)
{
    if(lista)
    {
        if(lista->cliente.idCliente == pedido.idCliente)
        {
            lista->listaProductos = agregarFinalProducto(lista->listaProductos, crearNodoProducto(producto, pedido.idPedido));
        }
        else
        {
            pasarProductoaCliente(lista->siguiente, producto, pedido);
        }
    }
}
