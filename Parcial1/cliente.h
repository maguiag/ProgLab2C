#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[51];
    char apellido[51];
    char cuit[12];
    int idCliente;
    int isEmpty;
}Cliente;
static int proximoId();
static int buscarLugarLibre(Cliente* arrayCliente,int limiteCliente);
int cliente_init(Cliente* arrayCliente,int limiteCliente);
int cliente_mostrarPorId(Cliente* arrayCliente,int limiteCliente,int idCliente);
int cliente_mostrarDebug(Cliente* arrayCliente,int limiteCliente);
int cliente_alta(Cliente* arrayCLiente,int limiteCliente);
int cliente_baja(Cliente* arrayCliente,int limiteClienete,int idCliente);
int cliente_modificacion(Cliente* arrayCliente,int limiteCliente,int idCliente);
int cliente_ordenar(Cliente* arrayCliente,int limiteCliente,int orden);
int cliente_altaForzada(Cliente* arrayCliente,int limiteCliente,char* nombre,char* apellido,char* cuit);
int cliente_buscarPorId(Cliente* arrayCliente,int limiteCliente,int idCliente);

#endif // CLIENTE_H_INCLUDED
