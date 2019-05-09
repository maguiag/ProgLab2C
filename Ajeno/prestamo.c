#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamo.h" //cambiar por nombre entidad


/** \brief To indicate that all positions in the array are empty,
*          this function puts the flag (isEmpty) in TRUE in all
*          positions of the array
* \param array prestamo Array of prestamo
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamo_Inicializar(Prestamo array[], int size)                                    //cambiar prestamo
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamo_buscarEmpty(Prestamo array[], int size, int* posicion)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamo_buscarID(Prestamo array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPrestamo==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamo_buscarString(Prestamo array[], int size, char* valorBuscado, int* indice)                    //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].fecha,valorBuscado)==0)                                        //cambiar campo fecha
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int prestamo_alta(Prestamo array[], int size, int* contadorID)                          //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(prestamo_buscarEmpty(array,size,&posicion)==-1)                          //cambiar prestamo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPrestamo=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,array[posicion].fecha);                      //mensaje + cambiar campo fecha
            printf("\n Posicion: %d\n ID: %d\n fecha: %s",
                   posicion, array[posicion].idPrestamo,array[posicion].fecha);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamo_baja(Prestamo array[], int sizeArray)                                      //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPrestamo=0;                                                                   //cambiar campo id                                                         //cambiar campo varFloat
            strcpy(array[posicion].fecha,"");                                                   //cambiar campo fecha                                           //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamo_bajaValorRepetidoInt(Prestamo array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPrestamo==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idPrestamo=0;                                                                   //cambiar campo id                                                           //cambiar campo varFloat
                strcpy(array[i].fecha,"");
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int prestamo_modificar(Prestamo array[], int sizeArray)                                //cambiar prestamo
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(prestamo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n fecha: %s\n",
                       posicion, array[posicion].idPrestamo,array[posicion].fecha);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        //utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        //utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].fecha);                      //mensaje + cambiar campo fecha
                        break;
                    case 'D':
                        //utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int prestamo_ordenarPorString(Prestamo array[],int size)                              //cambiar prestamo
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo fecha
    int bufferId;
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].fecha);                      //cambiar campo fecha
            bufferId=array[i].idPrestamo;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].fecha)<0)         //cambiar campo fecha                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].fecha,array[j].fecha);          //cambiar campo fecha
                array[j + 1].idPrestamo=array[j].idPrestamo;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                j--;
            }
            strcpy(array[j + 1].fecha,bufferString);                     //cambiar campo fecha
            array[j + 1].idPrestamo=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array prestamo Array de prestamo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int prestamo_listar(Prestamo array[], int size)                      //cambiar prestamo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\nfecha: %s\n",
                       array[i].idPrestamo,array[i].fecha);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
