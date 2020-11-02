#include "clientes.h"


//////////// Funciones de carga ////////////

stCliente crearCliente(char nombreArchivo)
{
    stCliente client;

    printf("Nombre: ");
    fflush(stdin);
    gets(client.nombre);
    while (strlen(client.nombre)>30)
    {
        printf("Error! Nombre muy largo.");
        printf("Nombre: ");
        fflush(stdin);
        gets(client.nombre);
    }
    printf("Apellido: ");
    fflush(stdin);
    gets(client.apellido);
    while (strlen(client.apellido)>30)
    {
        printf("Error! Apellido muy largo.");
        printf("Apellido: ");
        fflush(stdin);
        gets(client.apellido);
    }
    printf("Nombre usuario: ");
    fflush(stdin);
    gets(client.userName);
    while (strlen(client.userName)>20)
    {
        printf("Error! Nombre de usuario muy largo.");
        printf("Nombre usuario: ");
        fflush(stdin);
        gets(client.userName);
    }
    printf("Password: ");
    fflush(stdin);
    gets(client.password);
    while(strlen(client.password)>20)
    {
        printf("Error! Password muy larga.");
        printf("Password: ");
        fflush(stdin);
        gets(client.password);
    }
    printf("Email: ");
    fflush(stdin);
    gets(client.mail);
    while(strlen(client.mail)>20)
    {
        printf("Error! Email no apto.");
        printf("Email: ");
        fflush(stdin);
        gets(client.mail);
    }
    printf("Domicilio: ");
    fflush(stdin);
    gets(client.domicilio);
    while(strlen(client.domicilio)>30)
    {
        printf("Error! Domicilio muy largo");
        printf("Domicilio: ");
        fflush(stdin);
        gets(client.domicilio);
    }
    printf("Genero (f/m/o): ");
    fflush(stdin);
    gets(client.genero);
    while(client.genero != 'f' || client.genero != 'm' || client.genero != 'o')
    {
        printf("Error! Genero no valido");
        printf("Genero: ");
        fflush(stdin);
        gets(client.genero);
    }
    client.rol = 0;
    client.activo = 1;
    client.idCliente = contadorDatos(nombreArchivo, sizeof(stCliente)) + 1;

    return client;
}

///Funciones de muestra

void mostrarCliente(stCliente client)
{
    int posX = whereX(), posY = whereY() + 1;

    gotoxy(posX, posY);
    printf("Id #%d", client.idCliente);
    posY++;
    gotoxy(posX, posY);
    printf("Nombre y Apellido: %s %s", client.nombre, client.apellido);
    posY++;
    gotoxy(posX, posY);
    printf("Nombre de usuario: %s", client.userName);
    posY++;
    gotoxy(posX, posY);
    printf("Email: %s", client.mail);
    posY++;
    gotoxy(posX, posY);
    printf("Domicilio: %s", client.domicilio);
    posY++;
    gotoxy(posX, posY);
    printf("Genero: %c", client.genero);
    posY++;
    gotoxy(posX, posY);
}

///Funciones de Archivos
void registrarCliente(char nombreArchivo[], stCliente cliente)
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"ab");
    escribirCliente(arch, cliente);
    fclose(arch);
}

void escribirCliente(FILE * arch, stCliente cliente)
{
    if(arch != NULL)
    {
        fwrite(&cliente,sizeof(stCliente),1,arch);
    }
}

void registrarClienteModificado(char nombreArchivo, stCliente cliente)
{
    FILE * arch = NULL;

    fopen(nombreArchivo,"r+b");

    if(arch)
    {
        fseek(arch,cliente.idCliente,SEEK_SET);
        escribirCliente(arch, cliente);
        fclose(arch);
    }

}

///Funciones de modificación
stCliente modificarCliente(stCliente cliente)
{
    int op = 0;
    char opcion = 'n';
    stCliente aux;

    do
    {
        system("cls");
        header();
        menuEditarDatosClientes();
        footer();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            header();
            printf("Ingrese el nombre: ");
            footer();
            fflush(stdin);
            gets(&aux.nombre);
            while(strlen(aux.nombre)>30)
            {
                system("cls");
                header();
                printf("El nombre es demaciado largo\n");
                printf("Ingrese el nombre: ");
                footer();
                fflush(stdin);
                gets(&aux.nombre);
            }
            break;
        case 2:
            system("cls");
            header();
            printf("Ingrese el apellido: ");
            footer();
            fflush(stdin);
            gets(&aux.apellido);
            while(strlen(aux.apellido)>30)
            {
                system("cls");
                header();
                printf("El apellido es demaciado largo\n");
                printf("Ingrese el apellido: ");
                footer();
                fflush(stdin);
                gets(&aux.apellido);
            }
            break;
        case 3:
            system("cls");
            header();
            printf("Ingrese el username: ");
            footer();
            fflush(stdin);
            gets(&aux.userName);
            while(strlen(aux.userName)>20)
            {
                system("cls");
                header();
                printf("El username es demaciado largo\n");
                printf("Ingrese el username: ");
                footer();
                fflush(stdin);
                gets(&aux.userName);
            }
            break;
        case 4:
            system("cls");
            header();
            printf("Ingrese el password: ");
            footer();
            fflush(stdin);
            gets(&aux.password);
            while(strlen(aux.password)>20)
            {
                system("cls");
                header();
                printf("El password es demaciado largo\n");
                printf("Ingrese el password: ");
                footer();
                fflush(stdin);
                gets(&aux.password);
            }
            break;
        case 5:
            system("cls");
            header();
            printf("Ingrese el mail: ");
            footer();
            fflush(stdin);
            gets(&aux.mail);
            while(strlen(aux.mail)>30)
            {
                system("cls");
                header();
                printf("El mail es demaciado largo\n");
                printf("Ingrese el mail: ");
                footer();
                fflush(stdin);
                gets(&aux.mail);
            }
            break;
        case 6:
            system("cls");
            header();
            printf("Ingrese el domicilio: ");
            footer();
            fflush(stdin);
            gets(&aux.domicilio);
            while(strlen(aux.domicilio)>30)
            {
                system("cls");
                header();
                printf("El domicilio es demaciado largo\n");
                printf("Ingrese el domicilio: ");
                footer();
                fflush(stdin);
                gets(&aux.domicilio);
            }
            break;
        case 7:
            system("cls");
            header();
            printf("Ingrese el genero(f/m/o): ");
            footer();
            fflush(stdin);
            scanf("%c", &opcion);
            while(aux.genero != 'f' && aux.genero != 'm' && aux.genero != 'o')
            {
                printf("Error! Genero no valido");
                printf("Genero: ");
                fflush(stdin);
                scanf("%c", &opcion);
            }
            break;
        case 8:
            system("cls");
            header();
            printf("Esta seguro que quiere darse de baja?(s/n): ");
            footer();
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                aux.activo = 0;
            }
            break;
            if(cliente.rol == 1)
            {
            case 9:
                system("cls");
                header();
                printf("Esta seguro que quiere hacer admin a este usuario?(s/n): ");
                footer();
                fflush(stdin);
                scanf("%c", &opcion);
                if(opcion == 's')
                {
                    aux.rol = 1;
                }
                break;
            }
        default:

            break;

        }
    }
    while(op != 0);

    cliente = aux;

    return cliente;
}
