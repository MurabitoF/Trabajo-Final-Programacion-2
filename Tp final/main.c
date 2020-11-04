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
nodoListaClientes * pasarProductoaCliente(nodoListaClientes * lista, stProducto producto, stPedidos pedido);
nodoListaClientes * bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos);

int main()
{

    int i, val, j;
    int dim;

    nodoArbolProducto * arbolProductos = inicArbol();
    nodoListaClientes * clientes = inicListaClientes();

    for (i = 1; i<2; i++)
    {
        //crearProducto(A_Productos);
        //crearCliente(A_Clientes);
        cargarPedido(A_Pedidos, i, i);
    }
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

    dim = contadorDatos(A_Productos, sizeof(stProducto));
    printf("%d\n", dim);

    system("pause");

    stProducto * aProductos = (stProducto*) malloc(sizeof(stProducto) * dim);

    val = pasarArchivoArray(aProductos, A_Productos, dim);

    for (j=0; j<val; j++)
    {
        mostrarProducto(aProductos[j]);
    }

    printf("\n");
    printf("\n");

    arbolProductos = arregloOrd2arbol(arbolProductos, aProductos, 0, val-1);

    clientes = pasaArchivoALista(clientes, A_Clientes);

    mostrarInOrden(arbolProductos);

    printf("\n");

    mostrarListaCliente(clientes);
    mostrarListaProducto(clientes->listaProductos);

    clientes = bajarPedidos(A_Pedidos, clientes, arbolProductos);

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

nodoListaClientes * bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos)
{
    FILE * archi = fopen(nombreArchivo, "rb");

    stPedidos pedido;
    nodoArbolProducto * p = inicArbol();
    nodoListaClientes * aux = inicListaClientes();

    if (archi)
    {
        while (fread(&pedido, sizeof(stPedidos), 1, archi) > 0)
        {
            p = buscarNodoPorId(productos, pedido.idProducto);
            clientes = pasarProductoaCliente(clientes, p->producto, pedido);
            //aux = buscarClientePorId(clientes, pedido.idCliente);
            //aux->listaProductos = agregarFinalProducto(aux->listaProductos, crearNodoProducto(buscarNodoPorId(productos, pedido.idProducto), pedido.idPedido, pedido.fecha));
        }
        fclose(archi);
    }
    return clientes;
}

nodoListaClientes * pasarProductoaCliente(nodoListaClientes * lista, stProducto producto, stPedidos pedido)
{
    if(lista)
    {
        if(lista->cliente.idCliente == pedido.idCliente)
        {
            lista->listaProductos = agregarFinalProducto(lista->listaProductos, crearNodoProducto(producto, pedido.idPedido));
        }
        else
        {
            lista->siguiente = pasarProductoaCliente(lista->siguiente, producto, pedido);
        }
    }
    return lista;
}
