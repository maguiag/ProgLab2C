#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED
#include "afiches.h"

typedef struct
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[51];
    char zona[51];
    int isEmpty;
    int IdAfiche;

}Afiches;
int afiches_init(Afiches* array,int limite);
int afiches_mostrarPorId(Afiches* array,int limite, int idAfiches);
int afiches_mostrarDebug(Afiches* array,int limite);
int afiches_alta(Afiches* array, Cliente* array, int limite);
int afiches_baja(Afiches* array,int limite, int idAfiches);
int afiches_modificacion(Afiches* array,int limite, int idAfiches);
int afiches_ordenar(Afiches* array,int limite, int orden);
int afiches_altaForzada(Afiches* array,int limite, char* nombre, char* apellido, char* cuit);
int afiches_buscarPorId(Afiches* array,int limite, int idAfiches);
//int menu(int* opcion);




#endif // AFICHES_H_INCLUDED
