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
//nodoListaClientes * bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos);
nodoListaProducto * bajarPedidos(char nombreArchivo[], int idCliente, nodoArbolProducto * productos, nodoListaProducto * listaPedidos);
nodoListaClientes * subProgramaBajaPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos);

int main()
{

    int i, val, j;
    int dim;

    nodoArbolProducto * arbolProductos = inicArbol();
    nodoListaClientes * clientes = inicListaClientes();
    stCliente client;
    stProducto product;
    dim = contadorDatos(A_Productos, sizeof(stProducto));
    stProducto arrayP [1];

    /*for (i = 0; i<2; i++)
    {
        product = crearProducto(A_Productos);
        registrarProducto(A_Productos, product);
        printf("\n");
        client = crearCliente(A_Clientes);
        registrarCliente(A_Clientes, client);
        printf("\n");
        if (i == 0)
        cargarPedido(A_Pedidos, client.idCliente, product.idProducto);
        if (i == 1)
        cargarPedido(A_Pedidos, client.idCliente, product.idProducto);
    }*/
    printf("%d \n", dim);
    //system("pause");

    val = pasarArchivoArray(arrayP, A_Productos, dim);
    printf("%d \n", val);
    //system("pause");

    mostrarProducto(arrayP[0]);
    //system("pause");

    arbolProductos = arregloOrd2arbol(arbolProductos, arrayP, 0, val);

    clientes = pasaArchivoALista(clientes, A_Clientes);

    clientes = subProgramaBajaPedidos(A_Pedidos, clientes, arbolProductos);

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

/*nodoListaClientes * bajarPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    stPedidos pedido;
    nodoArbolProducto * p = (nodoArbolProducto*) malloc(sizeof(nodoArbolProducto));

    if (archi)
    {
        while (fread(&pedido, sizeof(stPedidos), 1, archi) > 0)
        {
            p = buscarNodoPorId(productos, pedido.idProducto);
            agregarProductoListaClientes(clientes, pedido.idCliente, p->producto);
            clientes->listaProductos->idPedido = pedido.idPedido;
            strcpy(clientes->listaProductos->fecha, pedido.fecha);
        }
        fclose(archi);
    }
    return clientes;
}*/

nodoListaProducto * bajarPedidos(char nombreArchivo[], int idCliente, nodoArbolProducto * productos, nodoListaProducto * listaPedidos)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    stPedidos pedido;
    nodoArbolProducto * p = inicArbol();
    nodoListaProducto * aux = listaPedidos;

    if(archi)
    {
        while (fread(&pedido, sizeof(stPedidos), 1, archi) > 0)
        {
            if (pedido.idCliente == idCliente)
            {
                p = buscarNodoPorId(productos, pedido.idProducto);
                aux = agregarFinalProducto(aux, crearNodoProducto(p->producto, pedido.idPedido));
                strcpy(aux->fecha, pedido.fecha);
                aux->idPedido = pedido.idPedido;
                aux = aux->sig;
            }
        }
    }
    fclose(archi);
    return productos;
}

nodoListaClientes * subProgramaBajaPedidos (char nombreArchivo[], nodoListaClientes * clientes, nodoArbolProducto * productos)
{
    nodoListaClientes * seg = clientes;

    if(seg)
    {
        while (seg)
        {
            seg->listaProductos = bajarPedidos(nombreArchivo, seg->cliente.idCliente, productos, seg->listaProductos);
            seg = seg->siguiente;
        }
    }
    return clientes;
}

