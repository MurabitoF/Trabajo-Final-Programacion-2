#include "clientes.h"


//////////// Funciones de carga ////////////

stCliente crearCliente(char nombreArchivo[])
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
    gotoxy(0, y-4);
    footer();
    color(10);
    gotoxy((posX+strlen("Nombre usuario: ")), posY);
    fflush(stdin);
    gets(client.nombre);
    while (validarString(client.nombre,30))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre muy largo");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.nombre);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+1);
    fflush(stdin);
    gets(client.apellido);
    while (validarString(client.apellido,30))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Apellido muy largo.");
        color(10);
        gotoxy((posX+strlen("Apellido: ")), posY+1);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.apellido);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+2);
    fflush(stdin);
    gets(client.userName);
    while (validarString(client.userName,20))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre de usuario muy largo");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY+2);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.userName);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+3);
    fflush(stdin);
    gets(client.password);
    //encriptar
    while(validarString(client.password,20))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Password muy larga.");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY+3);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.password);
        //encriptar
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+4);
    fflush(stdin);
    gets(client.mail);
    while(validarString(client.mail,20))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Email no apto.");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY+4);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.mail);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+5);
    fflush(stdin);
    gets(client.domicilio);
    while(validarString(client.domicilio,30))
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Domicilio muy largo");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY+5);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.domicilio);
    }
    gotoxy((posX+strlen("Nombre usuario: ")), posY+6);
    fflush(stdin);
    scanf("%c", &client.genero);
    while(client.genero != 'f' && client.genero != 'm' && client.genero != 'o')
    {
        gotoxy(posX, posY + 8);
        limpiarTodaLinea();
        color(12);
        printf("Error! Genero no valido");
        color(10);
        gotoxy((posX+strlen("Nombre usuario: ")), posY+6);
        limpiarLineaDer();
        fflush(stdin);
        scanf("%c", &client.genero);
    }
    client.rol = 0;
    client.activo = 1;
    client.idCliente = contadorDatos(nombreArchivo, sizeof(stCliente)) + 1;
    color(15);

    return client;
}

///Funciones de muestra

void mostrarCliente(stCliente client, int x)
{
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
    gotoxy(x, whereY());
}

///Funciones de Archivos
void registrarCliente(char nombreArchivo[], stCliente cliente)
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"ab");
    fwrite(&cliente,sizeof(stCliente),1,arch);
    fclose(arch);
}

void registrarClienteModificado(char nombreArchivo[], stCliente cliente)
{
    int flag = 0;
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"r+b");

    if(arch)
    {
        while(fread(&aux,sizeof(stCliente),1,arch) > 0 && !flag)
        {
            if(aux.idCliente == cliente.idCliente)
                flag = 1;
        }
        fseek(arch,-2*sizeof(stCliente),SEEK_CUR);
        fwrite(&cliente,sizeof(stCliente),1,arch);
        fclose(arch);
    }

}

///Funciones de modificación
stCliente modificarCliente(stCliente cliente, int admin)
{
    int op = 0, x, y, posX = 0, posY = 0;
    char opcion = 'n';
    stCliente aux = cliente;
    getWindowSize(&x, &y);
    posX = (x/2) - (strlen("=====|Datos del Clientes|=====")/2) - 2;
    posY = y/2 - 8;

    do
    {
        system("cls");
        header();
        gotoxy(posX, posY);
        admin == 1 ? menuDatosClienteAdminG(posX) : menuDatosClienteG(posX);
        gotoxy(0, y - 4);
        footer();
        admin ? gotoxy(posX+4, posY + 11) : gotoxy(posX+4, posY + 10);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Nombre actual: %s\n",aux.nombre);
            gotoxy(posX+5, whereY());
            printf("Nuevo nombre: ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nuevo nombre: "), posY + 5);
            fflush(stdin);
            gets(aux.nombre);
            while (validarString(aux.nombre,30))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre muy largo");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo nombre: ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.nombre);
            }
            break;
        case 2:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Apellido actual: %s\n",aux.apellido);
            gotoxy(posX + 5, whereY());
            printf("Nuevo apellido: ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nuevo apellido: "), posY + 5);
            fflush(stdin);
            gets(aux.apellido);
            while (validarString(aux.apellido,30))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Apellido muy largo");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo apellido: ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.apellido);
            }
            break;
        case 3:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Nombre de usuario actual: %s\n",aux.userName);
            gotoxy(posX + 5, whereY());
            printf("Nuevo nombre de usuario: ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 +strlen("Nuevo nombre de usuario: "), posY + 5);
            fflush(stdin);
            gets(aux.userName);
            while (validarString(aux.userName,20))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre de usuario muy largo");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo nombre de usuario: ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.userName);
            }
            break;
        case 4:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Contrase%ca actual: %s\n", enie,aux.password);
            gotoxy(posX + 5, whereY());
            printf("Nueva contrase%ca: ",enie);
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nueva contrasena: "), posY +5);
            fflush(stdin);
            gets(aux.password);
            while (validarString(aux.password,20))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Contrase%ca muy larga", enie);
                color(10);
                gotoxy((posX + 5 + strlen("Nueva contrasena: ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.password);
            }
            break;
        case 5:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Mail actual: %s\n", aux.mail);
            gotoxy(posX + 5, whereY());
            printf("Nuevo mail: ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nuevo mail: "), posY + 5);
            fflush(stdin);
            gets(aux.mail);
            while (validarString(aux.mail,30))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! El mail es muy largo");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo mail: ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.mail);
            }
            break;
        case 6:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Domicilio actual: %s\n", aux.domicilio);
            gotoxy(posX + 5, whereY());
            printf("Nuevo domicilio: ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nuevo domicilio: "), posY + 5);
            fflush(stdin);
            gets(aux.domicilio);
            while (validarString(aux.domicilio,30))
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! El domicilio no valido");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo domicilio: ")), posY + 1);
                limpiarLineaDer();
                fflush(stdin);
                gets(aux.domicilio);
            }
            break;
        case 7:
            system("cls");
            header();
            gotoxy(posX + 5, posY + 4);
            printf("Genero actual: %c\n", aux.genero);
            gotoxy(posX + 5, whereY());
            printf("Nuevo Genero(f/m/o): ");
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + 5 + strlen("Nuevo Genero(f/m/o): "), posY + 5);
            fflush(stdin);
            scanf("%c", &aux.genero);
            while(aux.genero != 'f' && aux.genero != 'm' && aux.genero != 'o')
            {
                gotoxy(posX + 5, posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Genero no valido");
                color(10);
                gotoxy((posX + 5 + strlen("Nuevo Genero(f/m/o): ")), posY + 5);
                limpiarLineaDer();
                fflush(stdin);
                scanf("%c", &aux.genero);
            }
            break;
        case 8:
            system("cls");
            header();
            gotoxy(posX - strlen("Esta seguro que quiere darse de baja?(s/n): ")/2, posY + 4);
            color(12);
            printf("Esta seguro que quiere darse de baja?(s/n): ");
            color(15);
            gotoxy(0,y - 4);
            footer();
            gotoxy(posX + strlen("Esta seguro que quiere darse de baja?(s/n): ")/2 + 1, posY + 4);
            color(10);
            fflush(stdin);
            scanf("%c", &opcion);
            color(15);
            if(opcion == 's')
            {
                aux.activo = 0;
                gotoxy(posX + 5,posY + 4);
                limpiarTodaLinea();
                printf("El usuario %s sera dado de baja al cerrar la cesion", aux.userName);
                gotoxy(posX - strlen("Esta seguro que quiere darse de baja?(s/n): ")/2 ,posY + 5);
                color(10);
                system("pause");
                color(15);
            }
            break;

        case 9:
            if(admin)
            {
                system("cls");
                header();
                gotoxy(posX-(strlen("Esta seguro que quiere hacer admin a este usuario?(s/n): ")/2), posY + 4);
                color(12);
                printf("Esta seguro que quiere hacer admin a este usuario?(s/n): ");
                color(15);
                gotoxy(0,y - 4);
                footer();
                gotoxy(posX + strlen("Esta seguro que quiere hacer admin a este usuario?(s/n): ")/2 + 1,posY + 4);
                fflush(stdin);
                color(10);
                scanf("%c", &opcion);
                color(15);
                if(opcion == 's')
                {
                    aux.rol = 1;
                    gotoxy(posX + 5,posY + 4);
                    limpiarTodaLinea();
                    printf("El usuario %s ahora es administrador", aux.userName);
                    gotoxy(posX - strlen("Esta seguro que quiere hacer admin a este usuario?(s/n): ")/2,posY + 5);
                    color(10);
                    system("pause");
                    color(15);
                }
            }
            break;

        default:

            break;

        }
    }
    while(op != 0);

    cliente = aux;

    return cliente;
}
