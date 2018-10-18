#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED
#include "cliente.h"

typedef struct
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[51];
    int zona;
    int idAfiche;
    int estado;
    int isEmpty;
}Afiches;

static int proximoId();
static int buscarLugarLibre(Afiches* arrayAfiches,int limiteAfiches, int indice);
int afiches_init(Afiches* arrayAfiches,int limite);
int afiches_mostrarPorId(Afiches* arrayAfiches,int limiteAfiches,int idAfiches);
int afiches_mostrarDebug(Afiches* arrayAfiches,int limiteAfiches);

int afiches_alta(Afiches* arrayAfiches,int limiteAfiches,Cliente* pBuffer,int limiteCliente);
int afiches_baja(Afiches* arrayAfiches,int limiteAfiches,int idAfiche);
//int afiches_modificacion(Afiches* array,int limite, int idAfiche);
int afiches_ordenar(Afiches* arrayAfiches,int limiteAfiches,int orden);
int afiches_altaForzada(Afiches* arrayAfiches,int limiteAfiches,char* cantidad,char* nombreArch,char* auxZona);
int afiches_buscarPorIdAfiche(Afiches* arrayAfiches,int limiteAfiches,int idAfiche);
int afiches_cobrar(Afiches* arrayAfiches,int limiteAfiches, Cliente* pBuffer,int limiteCliente,int id,int *indice);
int afiches_aCobrarByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente);
int afiches_listado(Afiches* arrayAfiches,int limiteAfiches);
int afiches_cambiarEstado(Afiches* arrayAfiches,int limiteAfiches);
int afiches_editar(Afiches* arrayAfiches,int id,int limiteAfiches,int cantAfiches,int zona);
int informe_clientesAcobrar(Cliente* arrayClientes,int limiteClientes, Afiches* pBuffer,int limiteAfiches);

int afiches_cantidadAfiches(Afiches* arrayAfiches,int limiteAfiches);
int afiches_cantidadByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente);
int afiches_cantidadACobrarByIdCliente(Afiches* ArrayAfiches,int limiteAfiches,int idCliente);
int afiches_cantidadDeVentasByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente);
int afiches_VentasTotales(Afiches* arrayAfiches,int limiteAfiches,int idCliente);
int afiches_cantidadAfichesByZona(Afiches* arrayAfiches ,int limiteAfiches);


#endif // AFICHES_H_INCLUDED
