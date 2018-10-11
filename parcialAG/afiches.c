#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "afiches.h"
#include "cliente.h"
#include "utn.h"


static int proximoId();
static int buscarLugarLibre(Afiches* array,int limite);


/** \brief Inicializa la estructura afichess
 * \param array Afiches* puntero a array
 * \param limite int limite definido para la estructura afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_init(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra el debug de la estructura Afiches
 *
 * \param array Afiches* puntero a array
 * \param limite int limite definido para afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_mostrarDebug(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idAfiches, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief Muestra afiches a partir del IdAfiches que recibe
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para afiches
 * \param idAfiches int ID del afiches que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_mostrarPorId(Afiches* array,int limite, int idAfiches)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
                printf("[RELEASE] -IDCliente: %d -NOMBRE: %s -Cantidad de afiches: %d -NOmbre del Archivo: %s -Zona: %s\n",array[i].idCliente, array[i].cantAfiches, array[i].nombreArchivo, array[i].zona);
        }
    }
    return retorno;
}

/** \brief Da de alta al afiches
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para Afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_alta(Afiches* array, Cliente* array, int limite)
{
    int retorno = -1;
    int i;
    int auxIdCliente[51];
    int auxCant;
    char auxArchivo[51];
    char auxZona[51];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidStringNumerico("\nIngrese el IdCliente:","\nIngrese unicamente numeros","El maximo es de 11",auxIdCliente,100,2)

        {
            if(if(!array[i].isEmpty && array[i].idCliente==idCliente))// veo si el cliente existe
                    {
                        if(!getValidStringNumerico("\nIngrese la cantidad de afiches: ","\nIngrese unicamente numeros","El maximo es de 11",auxCant,200,2))

                        {
                            if(!getValidString("\nIngrese el nombre el archivo: ","\nNo es un nombre valido","El maximo es de 50",auxArchivo,50,2))

                            {
                                if(!getValidString("\nIngrese la zona; ","\nNo es un nombre valido","El maximo es de 50",auxZona,50,2))

                                {
                                    retorno = 0;
                                    array[i].idCliente=auxIdCliente;
                                    strcpy(array[i].cantAfiches,auxCant);
                                    strcpy(array[i].nombreArchivo,auxArchivo);
                                    strcpy(array[i].zona,auxZona);

                                    array[i].idAfiches = proximoId();
                                    array[i].isEmpty = 0;
                                    printf("Id afiches: %d\n",array[i].idAfiches);
                                }
                            }

                        }
                    }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/** \brief Da de baja al afiches por el ID
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para afiches
 * \param idAfiches int Id del afiches que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_baja(Afiches* array,int limite, int idAfiches)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAfiches==idAfiches)
            {

                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al afiches a partir de su Id
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para el afiches
 * \param idAfiches int Id del afiches buscado
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_modificacion(Afiches* array,int limite, int idAfiches)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    char auxApellido[50];
    char auxCuit[12];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAfiches==idAfiches)
            {
                if(!getValidString("\nINgrese el nombre ","\nNo es un nombre valido","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese el apellido ","\nNo es un apellido valido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidStringNumerico("\nIngrese el CUIT ","\nIngrese unicamente numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,auxNombre);
                            strcpy(array[i].apellido,auxApellido);
                            strcpy(array[i].cuit,auxCuit);
                            array[i].idAfiches = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Ordena a los afichess de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para el afiches
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_ordenar(Afiches* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Afiches auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Busca el lugar libre en el array de afichess
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para el afiches
 * \return int [0] OK [1] ERROR
 *
 */
static int buscarLugarLibre(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Incremente el Id al ser llamada
 *
 * \return int retorna el valor correspondiente al proximoId
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief Fuerza el alta de afiches
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_altaForzada(Afiches* array,int limite, char* nombre, char* apellido, char* cuit)
{

    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            strcpy(array[i].cuit,cuit);
            array[i].idAfiches = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para afiches
 * \param idAfiches int id del afiches buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int afiches_buscarPorId(Afiches* array,int limite, int idAfiches)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAfiches==idAfiches)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Menu
 *
 * \param int* opcion
 * \return [0] Ok.
 *
 */

/*int menu(int* opcion)
{
    int aux;

    do
    {   system("clear");//limpia pantalla
        printf("1- ALTA de un Afiches\n");
        printf("2- MODIFICACION de un Afiches\n");
        printf("3- BAJA de un Afiches\n");
        printf("4- VENDER afiches\n");
        printf("5- EDITAR venta\n");
        printf("6- COBRAR venta\n");
        printf("7- IMPRIMIR Afichess\n");
        printf("8- SALIR\n");



        while(scanf("%d",&aux)==0||aux<0||aux>8)
        {
            printf("\nError, ingrese opcion valida\n");
        }

    *opcion=aux;
    }while(aux!=8);
    return 0;
}
