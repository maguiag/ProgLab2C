#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libros.h" //cambiar por nombre entidad

// magic numbers
// 11 function names (fantasma)
// 48 struct array names (Fantasma)
// 12 idLibro
// 24 varInts
// 26 varString



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libros Array of libros
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libros_Inicializar(Libros array[], int size)                                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libros_buscarEmpty(Libros array[], int size, int* posicion)                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarID(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idLibro==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarInt(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].codAutor==valorBuscado)                                                   //cambiar campo codAutor
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarString(Libros array[], int size, char* valorBuscado, int* indice)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)                                        //cambiar campo titulo
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libros_alta(Libros array[], int size, int* contadorID)                          //cambiar libros
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libros_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idLibro=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese codigo de autor para este libro: ","\nError",1,10,1,5,1,&array[posicion].codAutor);           //mensaje + cambiar campo codAutor
            utn_getName("Ingrese titulo del libro: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                      //mensaje + cambiar campo titulo
            printf("\n Posicion: %d\n ID: %d\n codAutor: %d\ntitulo: %s\n",
                   posicion, array[posicion].idLibro,array[posicion].codAutor,array[posicion].titulo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_baja(Libros array[], int sizeArray)                                      //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de libro a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idLibro=0;                                                                   //cambiar campo id
            array[posicion].codAutor=0;                                                               //cambiar campo codAutor
            strcpy(array[posicion].titulo,"");                                                   //cambiar campo titulo
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libros Array de libros
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_bajaValorRepetidoInt(Libros array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idLibro==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idLibro=0;                                                                   //cambiar campo id
                array[i].codAutor=0;                                                               //cambiar campo codAutor
//                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].titulo,"");                                                   //cambiar campo titulo
//                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libros_modificar(Libros array[], int sizeArray)                                //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n codAutor: %d\n titulo: %s\n",
                       posicion, array[posicion].idLibro,array[posicion].codAutor,array[posicion].titulo);
                utn_getChar("\nModificar: A : Codigo - B: Titulo - S : salir\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nIngrese el nuevo codigo de autor: ","\nError",1,sizeof(int),1,50,1,&array[posicion].codAutor);           //mensaje + cambiar campo codAutor
                        break;

                    case 'B':
                        utn_getName("\nIngrese nuevo titulo de libro: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                      //mensaje + cambiar campo titulo
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libros_ordenarPorString(Libros array[],int size)                              //cambiar libros
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo titulo
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
//    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].titulo);                      //cambiar campo titulo
            bufferId=array[i].idLibro;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].codAutor;                                //cambiar campo codAutor
//            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
//            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].titulo)<0)         //cambiar campo titulo                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].codAutor
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].titulo,array[j].titulo);          //cambiar campo titulo
                array[j + 1].idLibro=array[j].idLibro;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].codAutor=array[j].codAutor;                        //cambiar campo codAutor
//                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
//                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].titulo,bufferString);                     //cambiar campo titulo
            array[j + 1].idLibro=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].codAutor=bufferInt;                                                        //cambiar campo codAutor
//            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
//            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libros_listar(Libros array[], int size)                      //cambiar libros
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
                printf("\n\tlibros");
                printf("\n**************\n ID: %d\n codAutor: %d\n titulo: %s\n",
                       array[i].idLibro,array[i].codAutor,array[i].titulo);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}


