#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

static int proximoId();
static int buscarLugarLibre(Cliente* arrayCliente,int limiteCliente);


/** \brief Inicializa la estructura clientes
 * \param array Cliente* puntero a array
 * \param limite int limite definido para la estructura cliente
 * \return int [0] OK [1] ERROR
 *
 */

int cliente_init(Cliente* arrayCliente,int limiteCliente)
{
    int retorno=-1;
    int i;
    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteCliente;i++)
        {
            arrayCliente[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra el debug de la estructura Cliente
 *
 * \param array Cliente* puntero a array
 * \param limite int limite definido para cliente
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_mostrarDebug(Cliente* arrayCliente,int limiteCliente)
{
    int retorno=-1;
    int i;
    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteCliente;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",arrayCliente[i].idCliente,arrayCliente[i].nombre,arrayCliente[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief Muestra cliente a partir del IdCliente que recibe
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int ID del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_mostrarPorId(Cliente* arrayCliente,int limiteCliente,int idCliente)
{
    int retorno=-1;
    int i;
    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==idCliente)
            printf("[RELEASE] -ID: %d -NOMBRE: %s -APELLIDO: %s -CUIT: %s\n",arrayCliente[i].idCliente,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].cuit);
        }
    }
    return retorno;
}

/** \brief Da de alta al cliente
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para Cliente
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_alta(Cliente* arrayCliente,int limiteCliente)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];

    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        i=buscarLugarLibre(arrayCliente,limiteCliente);
        if(i>=0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidString("\nIngrese el apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                {
                    if(!getValidInt("\nIngrese CUIT: ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                    {
                        retorno=0;
                        strcpy(arrayCliente[i].nombre,auxNombre);
                        strcpy(arrayCliente[i].apellido,auxApellido);
                        strcpy(arrayCliente[i].cuit,auxCuit);
                        arrayCliente[i].idCliente=proximoId();
                        arrayCliente[i].isEmpty=0;
                        printf("El IdCliente es: %d\n",arrayCliente[i].idCliente);
                    }
                }
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}


/** \brief Da de baja al cliente por el ID
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int Id del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_baja(Cliente* arrayCliente,int limiteCliente,int idCliente)
{
    int retorno=-1;
    int i;
    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno = -2;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==idCliente)
            {
                arrayCliente[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al cliente a partir de su Id
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param idCliente int Id del cliente buscado
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_modificacion(Cliente* arrayCliente,int limiteCliente,int idCliente)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];

    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==idCliente)
            {
                if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidInt("\nIngrese CUIT: ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno=0;
                            strcpy(arrayCliente[i].nombre,auxNombre);
                            strcpy(arrayCliente[i].apellido,auxApellido);
                            strcpy(arrayCliente[i].cuit,auxCuit);
                            arrayCliente[i].idCliente=proximoId();
                            arrayCliente[i].isEmpty=0;
                        }
                    }
                }
                else
                {
                    retorno=-3;
                }
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Ordena a los clientes de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_ordenar(Cliente* arrayCliente,int limiteCliente,int orden)
{
    int retorno=-1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        do
        {
            flagSwap=0;
            for(i=0;i<limiteCliente-1;i++)
            {
                if(!arrayCliente[i].isEmpty && !arrayCliente[i+1].isEmpty)
                {
                    if((strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre)>0 && orden) || (strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre)<0 && !orden)) //******
                    {
                        auxiliarEstructura=arrayCliente[i];
                        arrayCliente[i]=arrayCliente[i+1];
                        arrayCliente[i+1]=auxiliarEstructura;
                        flagSwap=1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Busca el lugar libre en el array de clientes
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \return int [0] OK [1] ERROR
 *
 */
static int buscarLugarLibre(Cliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente> 0 && arrayCliente!=NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            if(arrayCliente[i].isEmpty==1)
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
    static int proximoId=-1;
    proximoId++;
    return proximoId;
}

/** \brief Fuerza el alta de cliente
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_altaForzada(Cliente* arrayCliente,int limiteCliente,char* nombre,char* apellido,char* cuit)
{
    int retorno=-1;
    int i;

    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        i=buscarLugarLibre(arrayCliente,limiteCliente);
        if(i>=0)
        {
            retorno=0;
            strcpy(arrayCliente[i].nombre,nombre);
            strcpy(arrayCliente[i].apellido,apellido);
            strcpy(arrayCliente[i].cuit,cuit);
            arrayCliente[i].idCliente=proximoId();
            arrayCliente[i].isEmpty=0;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int id del cliente buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int cliente_buscarPorId(Cliente* arrayCliente,int limiteCliente,int idCliente)
{
    int retorno=-1;
    int i;
    if(limiteCliente>0 && arrayCliente!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==idCliente)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


