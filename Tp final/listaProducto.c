#include "listaProducto.h"
#include "clientes.h"


nodoListaProducto * pasaArchivoAListaProducto(nodoListaProducto * listaProducto, char nombreArchivo[])
{
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo, "rb");

    if(arch != NULL)
    {
        while(fread(&aux,sizeof(stProducto),1,arch)>0)
        {
            //listaProducto = agregarAlFinalProducto(listaProducto, crearNodoProducto(&aux));
        }
        fclose(arch);
    }

    return listaProducto;
}

//////////// Funciones Basicas ////////////

nodoListaProducto * inicListaProducto()
{
    return NULL;
}

nodoListaProducto * crearNodoProducto (stProducto producto, int idPedido)
{
    nodoListaProducto * aux = (nodoListaProducto*) malloc(sizeof(nodoListaProducto));

    aux->p = producto;
    aux->idPedido = idPedido;
    aux->sig = NULL;

    return aux;
}

nodoListaProducto * agregarPrpioProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    nuevoProducto->sig = listaProducto;
    return nuevoProducto;
}

nodoListaProducto * agregarFinalProducto (nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    }
    else
    {
        listaProducto->sig = agregarFinalProducto(listaProducto->sig, nuevoProducto);
    }
    return listaProducto;
}

nodoListaProducto * agregarOrdenProducto(nodoListaProducto * listaProducto, nodoListaProducto * nuevoProducto)
{
    if(!listaProducto)
    {
        listaProducto = nuevoProducto;
    }
    else
    {
        if (strcmp(listaProducto->p.nombre, nuevoProducto->p.nombre) > 0)
        {
            listaProducto = agregarPrpioProducto(listaProducto, nuevoProducto);
        }
        else
        {
            nodoListaProducto * seg = listaProducto->sig;
            nodoListaProducto * ante = listaProducto;
            while (seg != NULL && strcmp(listaProducto->p.nombre, nuevoProducto->p.nombre) < 0)
            {
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevoProducto;
            nuevoProducto->sig = seg;
        }
    }
    return listaProducto;
}

//////////// Funciones de Muestra ////////////

void mostrarNodoProducto (nodoListaProducto * aux)
{
    if(aux->p.eliminado == 1)
        mostrarProducto(aux->p);
}

void mostrarListaProducto(nodoListaProducto * aux)
{
    int x = whereX();
    nodoListaProducto * seg = aux;
    if(aux)
    {
        while (seg->sig != NULL)
        {
            mostrarNodoProducto(seg);
            seg = seg->sig;
        }
    }
    else
    {
        gotoxy(x,whereY());
        printf("No hay pedidos...\n");
    }
}

//////////// Funciones de Borrado de Datos ////////////

nodoListaProducto * borrarProductoId (nodoListaProducto * listaProducto, int id)
{
    if (listaProducto)
    {
        if (listaProducto->p.idProducto == id)
        {
            nodoListaProducto * aux = listaProducto;
            listaProducto = listaProducto->sig;
            free(aux);
        }
        else
        {
            listaProducto->sig = borrarProductoId(listaProducto->sig, id);
        }
    }
    return listaProducto;
}

nodoListaProducto * borrarProductoNombre (nodoListaProducto * listaProducto, char nombre[])
{
    if (listaProducto)
    {
        if (strcmp(listaProducto->p.nombre, nombre) == 0)
        {
            nodoListaProducto * aux = listaProducto;
            listaProducto = listaProducto->sig;
            free(aux);
        }
        else
        {
            listaProducto->sig = borrarProductoNombre(listaProducto->sig, nombre);
        }
    }
    return listaProducto;
}

nodoListaProducto * borrarListaProducto (nodoListaProducto * listaProducto)
{
    nodoListaProducto * seg = listaProducto;
    nodoListaProducto * prox;
    while (seg != NULL)
    {
        prox = seg->sig;
        free(seg);
        seg = prox;
    }
    return seg;
}

///Funciones contar productos comprados

int * contarCategorias (nodoListaProducto * listaProductos)
{
    int comprasProducto[7] = {0};

    char categorias[15];

    nodoListaProducto * seg = listaProductos;

    while (seg)
    {
        strcpy(categorias, seg->p.categoria);
        if (strcmp(categorias ,"Televisores") == 0)
            {
                comprasProducto [0] = comprasProducto [0] + 1;
            } else
            {
                if (strcmp(categorias ,"Computadoras") == 0)
                    {
                        comprasProducto [1] = comprasProducto [1] + 1;
                    } else
                    {
                        if (strcmp(categorias ,"Celulares") == 0)
                            {
                                comprasProducto [2] = comprasProducto [2] + 1;
                            } else
                            {
                                if (strcmp(categorias ,"Accesorios") == 0)
                                    {
                                        comprasProducto [3] = comprasProducto [3] + 1;
                                    } else
                                    {
                                        if (strcmp(categorias ,"Heladeras") == 0)
                                            {
                                                comprasProducto [4] = comprasProducto [4] + 1;
                                            } else
                                            {
                                                if (strcmp(categorias ,"Aires") == 0)
                                                    {
                                                        comprasProducto [5] = comprasProducto [5] + 1;
                                                    } else
                                                    {
                                                        if (strcmp(categorias ,"Cocina") == 0)
                                                            {
                                                                comprasProducto [6] = comprasProducto [6] + 1;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            seg = seg->sig;
        }
    return comprasProducto;
}

int buscaMayor(int comprasProducto[])
{
    int may = 0;
    int i;
    for (i=0; i<7; i++)
    {
        if (comprasProducto[i] > comprasProducto[i+1])
            may = i;
    }
    return may;
}

float cuentaPrecios (nodoListaProducto * listaProducto)
{
    nodoListaProducto * seg = listaProducto;
    float precio;

    while (seg != NULL)
    {
        precio = precio + seg->p.precio;
        seg = seg->sig;
    }
    return precio;
}
