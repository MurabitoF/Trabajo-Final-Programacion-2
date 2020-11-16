#include "clientes.h"


//////////// Funciones de carga ////////////

stCliente crearCliente(char nombreArchivo[])
{
    ventana pos = inicVentana("=====|Nuevo Usuario|=====", 5);
    pos.posX = pos.posX - 2;
    stCliente client;

    header();

    gotoxy(pos.posX, pos.posY);
    color(10);
    printf("=====|Nuevo Usuario|=====\n");
    color(15);
    gotoxy(pos.posX,whereY());
    printf("Nombre: \n");
    gotoxy(pos.posX, whereY());
    printf("Apellido: \n");
    gotoxy(pos.posX, whereY());
    printf("Nombre usuario: \n");
    gotoxy(pos.posX, whereY());
    printf("Contrase%ca: \n", enie);
    gotoxy(pos.posX, whereY());
    printf("Email: \n");
    gotoxy(pos.posX, whereY());
    printf("Domicilio: \n");
    gotoxy(pos.posX, whereY());
    printf("Genero (f/m/o): \n");
    gotoxy(0, pos.tamY - 4);
    footer();
    color(10);
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 1);
    fflush(stdin);
    gets(client.nombre);
    while (validarString(client.nombre,30))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre muy largo");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY+1);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.nombre);
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 2);
    fflush(stdin);
    gets(client.apellido);
    while (validarString(client.apellido,30))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Apellido muy largo.");
        color(10);
        gotoxy(pos.posX + strlen("Apellido: "), pos.posY + 2);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.apellido);
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 3);
    fflush(stdin);
    gets(client.userName);
    while (validarString(client.userName,20))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Nombre de usuario muy largo");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 3);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.userName);
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 4);
    fflush(stdin);
    gets(client.password);
    //encriptar
    while(validarString(client.password,20))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Password muy larga.");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 4);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.password);
        //encriptar
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 5);
    fflush(stdin);
    gets(client.mail);
    while(validarString(client.mail,20))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Email no apto.");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 5);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.mail);
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 6);
    fflush(stdin);
    gets(client.domicilio);
    while(validarString(client.domicilio, 30))
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Domicilio muy largo");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 6);
        limpiarLineaDer();
        fflush(stdin);
        gets(client.domicilio);
    }
    gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 7);
    fflush(stdin);
    scanf("%c", &client.genero);
    while(client.genero != 'f' && client.genero != 'm' && client.genero != 'o')
    {
        gotoxy(pos.posX, pos.posY + 9);
        limpiarTodaLinea();
        color(12);
        printf("Error! Genero no valido");
        color(10);
        gotoxy(pos.posX + strlen("Nombre usuario: "), pos.posY + 7);
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


void mostrarCliente(stCliente client)
{
    int x = whereX();
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
    FILE *arch = NULL;

    arch = fopen(nombreArchivo, "ab");

    if (arch != NULL)
    {
        fwrite(&client, sizeof(stCliente), 1, arch);
        fclose(arch);
    }
}

void registrarClienteModificado(char nombreArchivo[], stCliente cliente)
{
    int flag = 0;
    stCliente aux;
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"r+b");

    if(arch)
    {
        fseek(arch,(cliente.idCliente-1)*sizeof(stCliente),SEEK_SET);
        fwrite(&cliente,sizeof(stCliente),1,arch);
        fclose(arch);
    }

}

///Funciones de modificación
stCliente modificarCliente(stCliente cliente, int admin)
{
    int op = 0;
    char opcion = 'n';
    stCliente aux = cliente;
    ventana pos = inicVentana("=====|Datos del Clientes|=====", 8);
    pos.posX = pos.posX - 2;

    do
    {
        header();
        gotoxy(pos.posX, pos.posY);
        admin == 1 ? menuDatosClienteAdminG() : menuDatosClienteG();
        gotoxy(0, pos.tamY - 4);
        footer();
        admin ? gotoxy(pos.posX + 4, pos.posY + 11) : gotoxy(pos.posX + 4, pos.posY + 10);
        op = leerInt();

        switch (op)
        {
        case 1:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Nombre actual: %s\n",aux.nombre);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo nombre: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo nombre: "), pos.posY + 5);
            strcpy(aux.nombre, leerString(30));
            while (validarString(aux.nombre,30))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre muy largo");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo nombre: "), pos.posY + 5);
                limpiarLineaDer();
                strcpy(aux.nombre, leerString(30));
            }
            break;
        case 2:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Apellido actual: %s\n",aux.apellido);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo apellido: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo apellido: "), pos.posY + 5);
            strcpy(aux.apellido, leerString(30));
            while (validarString(aux.apellido,30))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Apellido muy largo");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo apellido: "), pos.posY + 5);
                limpiarLineaDer();
                strcpy(aux.apellido, leerString(30));
            }
            break;
        case 3:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Nombre de usuario actual: %s\n",aux.userName);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo nombre de usuario: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo nombre de usuario: "), pos.posY + 5);
            strcpy(aux.userName, leerString(20));
            while (validarString(aux.userName,20))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Nombre de usuario muy largo");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo nombre de usuario: "), pos.posY + 5);
                limpiarLineaDer();
                strcpy(aux.userName, leerString(20));
            }
            break;
        case 4:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Contrase%ca actual: %s\n", enie,aux.password);
            gotoxy(pos.posX + 5, whereY());
            printf("Nueva contrase%ca: ",enie);
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nueva contrasena: "), pos.posY +5);
            strcpy(aux.password, leerString(20));
            while (validarString(aux.password,20))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Contrase%ca muy larga", enie);
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nueva contrasena: "), pos.posY + 5);
                limpiarLineaDer();
                strcpy(aux.password, leerString(20));
            }
            break;
        case 5:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Mail actual: %s\n", aux.mail);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo mail: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo mail: "), pos.posY + 5);
            strcpy(aux.mail, leerString(30));
            while (validarString(aux.mail,30))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! El mail es muy largo");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo mail: "), pos.posY + 5);
                limpiarLineaDer();
                strcpy(aux.mail, leerString(30));
            }
            break;
        case 6:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Domicilio actual: %s\n", aux.domicilio);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo domicilio: ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo domicilio: "), pos.posY + 5);
            strcpy(aux.domicilio, leerString(30));
            while (validarString(aux.domicilio,30))
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! El domicilio no valido");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo domicilio: "), pos.posY + 1);
                limpiarLineaDer();
                strcpy(aux.domicilio, leerString(30));
            }
            break;
        case 7:
            header();
            gotoxy(pos.posX + 5, pos.posY + 4);
            printf("Genero actual: %c\n", aux.genero);
            gotoxy(pos.posX + 5, whereY());
            printf("Nuevo Genero(f/m/o): ");
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + 5 + strlen("Nuevo Genero(f/m/o): "), pos.posY + 5);
            aux.genero = leerChar();
            while(aux.genero != 'f' && aux.genero != 'm' && aux.genero != 'o')
            {
                gotoxy(pos.posX + 5, pos.posY + 8);
                limpiarTodaLinea();
                color(12);
                printf("Error! Genero no valido");
                color(10);
                gotoxy(pos.posX + 5 + strlen("Nuevo Genero(f/m/o): "), pos.posY + 5);
                limpiarLineaDer();
                aux.genero = leerChar();
            }
            break;
        case 8:
            header();
            gotoxy(pos.posX - strlen("Esta seguro que quiere darse de baja?(s/n): ")/2 + 5, pos.posY + 4);
            color(12);
            printf("Esta seguro que quiere darse de baja?(s/n): ");
            color(15);
            gotoxy(0, pos.tamY - 4);
            footer();
            gotoxy(pos.posX + (strlen("Esta seguro que quiere darse de baja?(s/n): ")/2) + 1, pos.posY + 4);
            opcion = leerChar();
            if(opcion == 's')
            {
                aux.activo = 0;
                gotoxy(pos.posX, pos.posY + 4);
                limpiarTodaLinea();
                printf("El usuario %s sera dado de baja al cerrar la cesion", aux.userName);
                gotoxy(pos.posX, pos.posY + 5);
                pausa();
            }
            break;

        case 9:
            if(admin)
            {
                header();
                gotoxy(pos.posX - (strlen("Esta seguro que quiere hacer admin a este usuario?(s/n): ")/2) + 5, pos.posY + 4);
                color(12);
                printf("Esta seguro que quiere hacer admin a este usuario?(s/n): ");
                color(15);
                gotoxy(0, pos.tamY - 4);
                footer();
                gotoxy(pos.posX + strlen("Esta seguro que quiere hacer admin a este usuario?(s/n): ")/2 + 1, pos.posY + 4);
                opcion = leerChar();
                if(opcion == 's')
                {
                    aux.rol = 1;
                    gotoxy(pos.posX, pos.posY + 4);
                    limpiarTodaLinea();
                    printf("El usuario %s ahora es administrador", aux.userName);
                    gotoxy(pos.posX, pos.posY + 5);
                    pausa();
                }
            }
            break;

        default:

            break;

        }
    }
    while(op != 0);

    return aux;
}
