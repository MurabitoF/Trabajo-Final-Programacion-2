#include "clientes.h"
<<<<<<< Updated upstream
=======


//////////// Funciones de carga ////////////

stCliente crearCliente(char nombreArchivo[])
{
    stCliente client;

    printf("Nombre: ");
    fflush(stdin);
    gets(client.nombre);
    while (strlen(client.nombre)>30)
    {
        printf("Error! Nombre muy largo. ");
        printf("Nombre: ");
        fflush(stdin);
        gets(client.nombre);
    }
    printf("Apellido: ");
    fflush(stdin);
    gets(client.apellido);
    while (strlen(client.apellido)>30)
    {
        printf("Error! Apellido muy largo. ");
        printf("Apellido: ");
        fflush(stdin);
        gets(client.apellido);
    }
    printf("Nombre usuario: ");
    fflush(stdin);
    gets(client.userName);
    while (strlen(client.userName)>20)
    {
        printf("Error! Nombre de usuario muy largo. ");
        printf("Nombre usuario: ");
        fflush(stdin);
        gets(client.userName);
    }
printf("Password: ");
    fflush(stdin);
    gets(client.password);
    while(strlen(client.password)>20)
    {
        printf("Error! Password muy larga. ");
        printf("Password: ");
        fflush(stdin);
        gets(client.password);
    }
    printf("Email: ");
    fflush(stdin);
    gets(client.mail);
    while(strlen(client.mail)>20)
    {
        printf("Error! Email no apto. ");
        printf("Email: ");
        fflush(stdin);
        gets(client.mail);
    }
    printf("Domicilio: ");
    fflush(stdin);
    gets(client.domicilio);
    while(strlen(client.domicilio)>30)
    {
        printf("Error! Domicilio muy largo. ");
        printf("Domicilio: ");
        fflush(stdin);
        gets(client.domicilio);
    }
    printf("Genero (f/m/o): ");
    fflush(stdin);
    scanf("%c", &client.genero);
    while(client.genero != 102 && client.genero != 109 && client.genero != 111)
    {
        printf("Error! Genero no valido. ");
        printf("Genero: ");
        fflush(stdin);
        scanf("%c", &client.genero);
    }
    client.rol = 0;
    client.activo = 1;
    client.idCliente = contadorDatos(nombreArchivo, sizeof(stCliente)) + 1;

    return client;
}

void registrarCliente(char nombreArchivo[], stCliente client)
{
    FILE * arch = NULL;

    arch = fopen(nombreArchivo,"ab");

    if(arch != NULL)
    {
        fwrite(&client,sizeof(stCliente),1,arch);
        fclose(arch);
    }
}

//////////// Funciones de muestra ////////////

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

//////////// Funciones de modificaci�n ////////////

void modificarCliente(stCliente cliente, FILE * nombreArchivo)
{

}
>>>>>>> Stashed changes
