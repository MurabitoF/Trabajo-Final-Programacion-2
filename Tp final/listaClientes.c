#include "listaClientes.h"
#include "listaProducto.h"

///Funciones Basicas
nodoListaClientes * inicListaClientes()
{
    return NULL;
}

nodoListaClientes * crearNodoCliente(stCliente cliente)
{
    nodoListaClientes * aux = (nodoListaClientes *) malloc(sizeof(nodoListaClientes));
    aux->cliente = cliente;
    aux->listaProductos = inicListaProducto();
    aux->siguiente = NULL;

    return aux;
}

///Funciones Agregar
nodoListaClientes * agregarClientePpio(nodoListaClientes * lista, nodoListaClientes * nuevo)
{
    nuevo->siguiente = lista;

    return nuevo;
}

nodoListaClientes * agregarClienteFinal(nodoListaClientes * lista, nodoListaClientes * nuevo)
{
    nodoListaClientes * ultimo;

    if(lista)
    {
        ultimo = buscarUltimoNodoClientes(lista);
        ultimo->siguiente = nuevo;
    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

nodoListaClientes * agregarClienteEnOrden(nodoListaClientes * lista, nodoListaClientes * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if (nuevo->cliente.idCliente < lista->cliente.idCliente)
        {
            lista = agregarClientePpio(lista, nuevo);
        }
        else
        {
            nodoListaClientes *ante = lista;
            nodoListaClientes *seg = lista->siguiente;

            while (seg != NULL && nuevo->cliente.idCliente < lista->cliente.idCliente)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

void agregarProductoListaClientes(nodoListaClientes * lista, int id, stProducto producto)
{
    if(lista)
    {
        if(lista->cliente.idCliente == id)
        {
            lista->listaProductos = agregarFinalProducto(lista->listaProductos, crearNodoProducto(producto));
        }
        else
        {
            agregarProductoListaClientes(lista->siguiente, id, producto);
        }
    }
}

///Funciones de Busqueda
nodoListaClientes * buscarUltimoNodoClientes(nodoListaClientes * lista)
{
    nodoListaClientes * ultimo;

    if(lista)
    {
        if(lista->siguiente == NULL)
        {
            ultimo = lista;
        }
        else
        {
            ultimo = buscarUltimoNodoClientes(lista->siguiente);
        }
    }

    return ultimo;
}

nodoListaClientes * buscarClientePorId(nodoListaClientes * lista, int id)
{
    nodoListaClientes * busca = NULL;

    if(lista)
    {
        if(lista->cliente.idCliente == id)
        {
            busca = lista;
        }
        else
        {
            busca = buscarClientePorId(lista->siguiente, id);
        }
    }

    return busca;
}

nodoListaClientes * buscarClientePorUsername(nodoListaClientes * lista, char busqueda[])
{
    nodoListaClientes * busca = NULL;

    if(lista)
    {
        if(strcmpi(lista->cliente.userName, busqueda) == 0)
        {
            busca = lista;
        }
        else
        {
            busca = buscarClientePorId(lista->siguiente, busqueda);
        }
    }

    return busca;
}

nodoListaClientes * buscarClientePorEmail(nodoListaClientes * lista, char busqueda[])
{
    nodoListaClientes * busca = NULL;

    if(lista)
    {
        if(strcmpi(lista->cliente.mail, busqueda) == 0)
        {
            busca = lista;
        }
        else
        {
            busca = buscarClientePorId(lista->siguiente, busqueda);
        }
    }

    return busca;
}

nodoListaClientes * buscarClientePorNombre(nodoListaClientes * lista, char busqueda[])
{
    nodoListaClientes * busca = NULL;

    if(lista)
    {
        if(strcmpi(lista->cliente.nombre, busqueda) == 0)
        {
            busca = lista;
        }
        else
        {
            busca = buscarClientePorId(lista->siguiente, busqueda);
        }
    }

    return busca;
}

nodoListaClientes * buscarClientePorApellido(nodoListaClientes * lista, char busqueda[])
{
    nodoListaClientes * busca = NULL;

    if(lista)
    {
        if(strcmpi(lista->cliente.apellido, busqueda) == 0)
        {
            busca = lista;
        }
        else
        {
            busca = buscarClientePorId(lista->siguiente, busqueda);
        }
    }

    return busca;
}

///Funciones de Borrado
nodoListaClientes * borrarPrimerCliente(nodoListaClientes * lista)
{
    nodoListaClientes * borrado = lista;

    if(lista)
    {
        lista = lista->siguiente;
        borrado->listaProductos = borrarListaProducto(lista->listaProductos);
        free(borrado);
    }

    return lista;
}

nodoListaClientes * borrarUltimoCliente(nodoListaClientes * lista)
{
    if(lista)
    {
        if(lista->siguiente == NULL)
        {
            lista->listaProductos = borrarListaProducto(lista->listaProductos);
            free(lista);
            lista = NULL;
        }
        else
        {
            lista->siguiente = borrarUltimoCliente(lista->siguiente);
        }
    }

    return lista;
}

nodoListaClientes * borrarNodoCliente(nodoListaClientes * lista, nodoListaClientes * borrado)
{
    if(lista)
    {
        if(lista == borrado)
        {
            lista = lista->siguiente;
            borrado->listaProductos = borrarListaProducto(lista->listaProductos);
            free(borrado);
        }
        else
        {
            lista->siguiente = borrarNodoCliente(lista->siguiente, borrado);
        }
    }

    return lista;
}

nodoListaClientes * borrarListaClientes(nodoListaClientes * lista)
{
    if(lista)
    {
        lista->siguiente = borrarListaClientes(lista->siguiente);

        lista->listaProductos = borrarListaProducto(lista->listaProductos);
        free(lista);
        lista = NULL;
    }

    return lista;
}

///Funciones de muestra
void mostrarNodoCliente(nodoListaClientes * cliente)
{
    if(cliente->cliente.activo == 1)
        mostrarCliente(cliente->cliente);
}

void mostrarListaClientes(nodoListaClientes * lista)
{
    nodoListaClientes * seg = lista;

    while(seg != NULL)
    {
        mostrarNodoCliente(seg);
        seg = seg->siguiente;
    }
}

///Funcines de archivo
nodoListaClientes * pasaArchivoALista(nodoListaClientes * listaCliente, char nombreArchivo[])
{
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "rb");

    if(arch != NULL)
    {
        while(fread(&aux,sizeof(stCliente),1,arch)>0)
        {
            if(aux.activo == 1)
            {
                listaCliente = agregarClienteFinal(listaCliente, crearNodoCliente(aux));
            }
        }
        fclose(arch);
    }

    return listaCliente;
}

void generarPedidos(nodoListaClientes * lista, char nombreArchivo[])
{
    nodoListaProducto * productos = lista->listaProductos;
    stPedidos aux;
    int ultimoID = contadorDatos(nombreArchivo, sizeof(stPedidos)) + 1;

    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "wb");

    if(arch)
    {
        while(productos)
        {
            aux.idCliente = lista->cliente.idCliente;
            aux.idProducto = productos->p.idProducto;
            strcpy(aux.fecha, productos->fecha);
            if(productos->idPedido != 0)
            {
                aux.idPedido = productos->idPedido;
            }
            else
            {
                aux.idPedido = ultimoID;
                ultimoID++;
            }
            productos = productos->sig;
            fwrite(&aux,sizeof(stPedidos), 1, arch);
        }
        lista = lista->siguiente;
        productos = lista->listaProductos;
    }
    fclose(arch);
}

///Subprogramas
void subProgramaModificarCliente(nodoListaClientes * nodoCliente, char nombreArchivo[], int admin)
{
    stCliente aux;
    aux =  modificarCliente(nodoCliente->cliente, admin);
    nodoCliente->cliente = aux;
    registrarClienteModificado(nombreArchivo, aux);

}

void subProgramaMostrarCliente(nodoListaClientes * nodoCliente, int posX, int posY)
{
    int x,y;
    getWindowSize(&x, &y);

    system("cls");
    header();
    gotoxy(posX, posY);
    mostrarNodoCliente(nodoCliente);
    gotoxy(posX, whereY());
    printf("Pedidos: \n");
    if(nodoCliente->listaProductos)
    {
        gotoxy(posX, 3);
        mostrarListaProducto(nodoCliente->listaProductos);
    }
    else
    {
        gotoxy(posX + 3, whereY());
        printf("No hay pedidos\n");
    }
    if(whereY() <= y - 4)
        gotoxy(0, y-4);
    footer();
    gotoxy(posX, whereY()- 3);
    color(10);
    system("pause");
    color(15);
}
