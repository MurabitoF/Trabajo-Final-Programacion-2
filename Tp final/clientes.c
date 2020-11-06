#include "clientes.h"


//////////// Funciones de carga ////////////

stCliente crearCliente(char nombreArchivo)
{
    int x, y, posX = 0, posY = 0;
    getWindowSize(&x, &y);
    posX = (x/2) - strlen("Nombre Usuario: " + 3);
    posY = (y/2) - 5;
    stCliente client;

    header();

    gotoxy(posX,posY);
    printf("Nombre: \n");
    gotoxy(posX, whereY());
    printf("Apellido: \n");
    gotoxy(posX, whereY());
    printf("Nombre usuario: \n");
    gotoxy(posX, whereY());
    printf("Contrase%ca: \n", enie);
    gotoxy(posX, whereY());
    printf("Email: \n");
    gotoxy(posX, whereY());
    printf("Domicilio: \n");
    gotoxy(posX, whereY());
    printf("Genero (f/m/o): \n");
    footer();
    gotoxy((posX+strlen("Nombre: ")), posY);
    fflush(stdin);
    gets(client.nombre);
    while (validarString(client.nombre,30))
    {
        gotoxy(posX, posY + 8);
        color(12);
        printf("Error! Nombre muy largo.");
        color(15);
        gotoxy((posX+strlen("Nombre: ")), posY);
        fflush(stdin);
        gets(client.nombre);
    }
    gotoxy((posX+strlen("Apellido: ")), posY+1);
    fflush(stdin);
    gets(client.apellido);
    while (validarString(client.apellido,30))
    {
        printf("Error! Apellido muy largo.");
        printf("Apellido: ");
        fflush(stdin);
        gets(client.apellido);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+2);
    fflush(stdin);
    gets(client.userName);
    while (validarString(client.userName,20))
    {
        printf("Error! Nombre de usuario muy largo.");
        printf("Nombre usuario: ");
        fflush(stdin);
        gets(client.userName);
    }
    gotoxy((posX+strlen("Contrasena: ")), posY+3);
    fflush(stdin);
    gets(client.password);
    while(validarString(client.password,20))
    {
        printf("Error! Password muy larga.");
        printf("Password: ");
        fflush(stdin);
        gets(client.password);
    }
    gotoxy((posX+strlen("Email: ")), posY+4);
    fflush(stdin);
    gets(client.mail);
    while(validarString(client.mail,20))
    {
        printf("Error! Email no apto.");
        printf("Email: ");
        fflush(stdin);
        gets(client.mail);
    }
    gotoxy((posX+strlen("Domicilio: ")), posY+5);
    fflush(stdin);
    gets(client.domicilio);
    while(validarString(client.domicilio,30))
    {
        printf("Error! Domicilio muy largo");
        printf("Domicilio: ");
        fflush(stdin);
        gets(client.domicilio);
    }
    gotoxy((posX+strlen("Genero (f/m/o): ")), posY+6);
    fflush(stdin);
    scanf("%c", &client.genero);
    while(client.genero != 'f' && client.genero != 'm' && client.genero != 'o')
    {
        printf("Error! Genero no valido");
        printf("Genero: ");
        fflush(stdin);
        scanf("%c", &client.genero);
    }
    client.rol = 0;
    client.activo = 1;
    client.idCliente = 1;//ontadorDatos(nombreArchivo, sizeof(stCliente)) + 1;

    return client;
}

///Funciones de muestra

void mostrarCliente(stCliente client)
{/*
    int x;

    printf("Id #%d\n", client.idCliente);
    gotoxy(x, whereY());
    printf("Nombre y Apellido: %s %s\n", client.nombre, client.apellido);
    gotoxy(x, whereY());
    printf("Nombre de usuario: %s\n", client.userName);
    gotoxy(x, whereY());
    printf("Email: %s\n", client.mail);
    gotoxy(x, whereY());
    printf("Domicilio: %s\n", client.domicilio);
    gotoxy(x, whereY());
    printf("Genero: %c\n\n", client.genero);
    gotoxy(x, whereY());*/
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
        //menuDatosClienteG();
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
            gets(aux.nombre);
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
            gets(aux.apellido);
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
            gets(aux.userName);
            while(strlen(aux.userName)>20)
            {
                system("cls");
                header();
                printf("El username es demaciado largo\n");
                printf("Ingrese el username: ");
                footer();
                fflush(stdin);
                gets(aux.userName);
            }
            break;
        case 4:
            system("cls");
            header();
            printf("Ingrese el password: ");
            footer();
            fflush(stdin);
            gets(aux.password);
            while(strlen(aux.password)>20)
            {
                system("cls");
                header();
                printf("El password es demaciado largo\n");
                printf("Ingrese el password: ");
                footer();
                fflush(stdin);
                gets(aux.password);
            }
            break;
        case 5:
            system("cls");
            header();
            printf("Ingrese el mail: ");
            footer();
            fflush(stdin);
            gets(aux.mail);
            while(strlen(aux.mail)>30)
            {
                system("cls");
                header();
                printf("El mail es demaciado largo\n");
                printf("Ingrese el mail: ");
                footer();
                fflush(stdin);
                gets(aux.mail);
            }
            break;
        case 6:
            system("cls");
            header();
            printf("Ingrese el domicilio: ");
            footer();
            fflush(stdin);
            gets(aux.domicilio);
            while(strlen(aux.domicilio)>30)
            {
                system("cls");
                header();
                printf("El domicilio es demaciado largo\n");
                printf("Ingrese el domicilio: ");
                footer();
                fflush(stdin);
                gets(aux.domicilio);
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
