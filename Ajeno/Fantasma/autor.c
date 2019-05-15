#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

// magic numbers
// 11 function names (fantasma)
// 48 struct array names (Fantasma)
// 12 idUnico
// 24 varInts
// 26 varString

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autor Array of autor
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autor_Inicializar(Autor array[], int size)                                    //cambiar autor
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autor_buscarEmpty(Autor array[], int size, int* posicion)                    //cambiar autor
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarID(Autor array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAutor==valorBuscado)                                                   //cambiar campo ID
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarString(Autor array[], int size, char* valorBuscado, int* indice)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
//            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
//            {
//                *indice=i;
//                retorno=0;
//                break;
//            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autor_alta(Autor array[], int size, int* contadorID)                          //cambiar autor
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(autor_buscarEmpty(array,size,&posicion)==-1)                          //cambiar autor
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idAutor=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("Ingrese nombre del autor: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("Ingrese apellido del autor: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo apellido
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s",
                   posicion, array[posicion].idAutor,array[posicion].nombre,array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_baja(Autor array[], int sizeArray)                                      //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de autor a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idAutor=0;                                                                   //cambiar campo id                                                            //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array autor Array de autor
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_bajaValorRepetidoInt(Autor array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idAutor == valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idAutor=0;                                                                                                                              //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autor_modificar(Autor array[], int sizeArray)                                //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de autor a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s",
                       posicion, array[posicion].idAutor,array[posicion].nombre,array[posicion].apellido);
                utn_getChar("\nModificar: A : Nombre - B: Apellido - S : salir\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de autor: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getTexto("\nIngrese nuevo apellido de autor: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
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
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int autor_ordenarPorString(Autor array[],int size)                              //cambiar autor
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;
    char bufferApellido[TEXT_SIZE];                           //cambiar campo apellido

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idAutor;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferApellido,array[i].apellido);          //cambiar campo apellido

            j = i - 1;
            while ((j >= 0) && strcmp(bufferNombre,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idAutor=array[j].idAutor;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].apellido,array[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);                     //cambiar campo nombre
            array[j + 1].idAutor=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
            strcpy(array[j + 1].apellido,bufferApellido);                                  //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autor_listar(Autor array[], int size)                      //cambiar autor
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
           {
                printf("\n\tAutores");
                printf("\n********************\n ID: %d\n Nombre: %s\n Apellido: %s",
                       array[i].idAutor,array[i].nombre,array[i].apellido);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}

