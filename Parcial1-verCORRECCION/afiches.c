#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "afiches.h"
#include "cliente.h"


static int proximoId();
static int buscarLugarLibre(Afiches* arrayAfiches,int limiteAfiches);

/** \brief Inicializa la estructura afiches
 * \param array Afiches* puntero a array
 * \param limite int limite definido para la estructura afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_init(Afiches* arrayAfiches,int limiteAfiches)
{
    int retorno=-1;
    int i;
    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteAfiches;i++)
        {
            arrayAfiches[i].isEmpty=1;
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
int afiches_mostrarDebug(Afiches* arrayAfiches,int limiteAfiches)
{
    int retorno=-1;
    int i;
    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteAfiches;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",arrayAfiches[i].idAfiche,arrayAfiches[i].nombreArchivo,arrayAfiches[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief Muestra afiches a partir del Idafiches que recibe
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para afiches
 * \param idAfiches int ID de afiche que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_mostrarPorId(Afiches* arrayAfiches,int limiteAfiches,int idAfiche)
{
    int retorno=-1;
    int i;
    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idCliente==idAfiche)
                printf("[RELEASE] -IdCliente: %d -Cant.archivos: %d -Nombre Archivo: %s -zona: %s -idArchivo: %d\n",arrayAfiches[i].idCliente,arrayAfiches[i].cantAfiches,arrayAfiches[i].nombreArchivo,arrayAfiches[i].zona,arrayAfiches[i].idAfiche);
        }
    }
    return retorno;
}

/** \brief Da de alta afiches
 *
 * \param array Afiches* puntero al array y limite de afiches
 * \param puntero a clientes y limite clientes
 * \return int [0] OK [-1] ERROR
 *
 */
int afiches_alta(Afiches* arrayAfiches,int limiteAfiches, Cliente* pBuffer, int limiteCliente)
{
    int retorno=-1;
    int i;
    char idCliente;
    int auxCant;
    char auxArchivo[51];
    char auxZona[51];

    if((limiteCliente>0 && arrayAfiches!=NULL) && (limiteCliente>0 && pBuffer!=NULL))
    {
        i=buscarLugarLibre(arrayAfiches,limiteCliente);
        if(i>=0)
        {
            if(!getValidString("\nIngrese IdCliente","\nError","Maximo 11",pBuffer,100,2))
                do
                {
                    if(!getValidInt("\ncantidad de afiches ","\nDebe tener solo numeros","El maximo es de 999",auxCant,12,2) )
                    {
                        if(!getValidString("\nIngrese Nombre Archivo: ","\nError","El maximo es 50",auxArchivo,100,2))
                        {
                            if(!getValidString("\nIngrese la zona ","\nError","El maximo es 50",auxZona,100,2))
                            {
                                strcpy(arrayAfiches[i].cantAfiches,auxCant);
                                strcpy(arrayAfiches[i].nombreArchivo,auxArchivo);
                                strcpy(arrayAfiches[i].zona,auxZona);
                                arrayAfiches[i].idAfiche=proximoId();
                                arrayAfiches[i].isEmpty=0;
                                retorno = 0;
                            }
                        }
                    }
                }
                while( arrayAfiches[i].idCliente==pBuffer[i].idCliente && pBuffer!=NULL && limiteCliente>0);
        }
        else
        {
            retorno=-2;
        }
    }
    else
    {
        retorno = -3;
    }
return retorno;
}





/** \brief Da de baja al fiche por el ID
 *
 * \param array Afichee* puntero al array
 * \param limite int limite definido para afiche
 * \param idCliente int Id del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_baja(Afiches* arrayAfiches,int limiteAfiches,int idAfiche)
{
    int retorno=-1;
    int i;
    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idAfiche==idAfiche)
            {
                arrayAfiches[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al afiche a partir de su Id
 *
 * \param array Afiche* puntero al array
 * \param limite int limite definido para el afiche
 * \param idafiche
 * \return int [0] OK [1] ERROR
 *
 */
 /*
int cliente_modificacion(Cliente* array,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
            {
                if(!getValidString("\nIngrese nombre? ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese apellido? ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidInt("\nIngrese CUIT ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,auxNombre);
                            strcpy(array[i].apellido,auxApellido);
                            strcpy(array[i].cuit,auxCuit);
                            array[i].idCliente = proximoId();
                            array[i].estado=1;//estado  a cobrar
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
*/
/** \brief Ordena a los clientes de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */

/*int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

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

/** \brief Busca el lugar libre en el array de clientes
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \return int [0] OK [1] ERROR
 *
 */

static int buscarLugarLibre(Afiches* arrayAfiches,int limiteAfiches)
{
    int retorno = -1;
    int i;
    if(limiteAfiches> 0 && arrayAfiches!=NULL)
    {
        for(i=0;i<limiteAfiches;i++)
        {
            if(arrayAfiches[i].isEmpty==1)
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
int afiches_altaForzada(Afiches* arrayAfiches,int limiteAfiches,char* cantidad,char* nombreArch,char* auxZona)
{
    int retorno=-1;
    int i;

    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        i=buscarLugarLibre(arrayAfiches,limiteAfiches);
        if(i>=0)
        {
            retorno=0;
            strcpy(arrayAfiches[i].cantAfiches,cantidad);
            strcpy(arrayAfiches[i].nombreArchivo,nombreArch);
            strcpy(arrayAfiches[i].zona,auxZona);
            arrayAfiches[i].idCliente=proximoId();
            arrayAfiches[i].isEmpty=0;
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
int afiches_buscarPorIdAfiche(Afiches* arrayAfiches,int limiteAfiches,int idAfiche)
{
    int retorno=-1;
    int i;
    if(limiteAfiches>0 && arrayAfiches!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idAfiche==idAfiche)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief listado de afiches a cobrar
 *
 * \param afiches y su limite, cliente y su limite
 * \param id e indice
 * \return [-1] si mal, [0] si ok
 *
 */

int afiches_cobrar(Afiches* arrayAfiches,int limiteAfiches,Cliente* pBuffer,int limiteCliente,int id,int *indice)
{
    int i;
    int j;
    int retorno=-1;

    if(arrayAfiches!=NULL && limiteAfiches>0 && pBuffer!=NULL && limiteCliente>0)
        {
        for(i=0;i<limiteAfiches;i++)
        {
            if(arrayAfiches[i].idAfiche==id)
            {
                for(j=0;j<limiteCliente;j++)
                {
                    if(arrayAfiches[i].idCliente==pBuffer[i].idCliente && !arrayAfiches[i].isEmpty)
                    {
                        printf("\nIdCliente: %d",pBuffer[i].idCliente);
                        printf("\nNombre: %s",pBuffer[i].nombre);
                        printf("\nApellido: %s",pBuffer[i].apellido);
                        printf("\nCuit: %s",pBuffer[i].cuit);
                        retorno=0;
                        *indice=i;
                        break;
                    }
                }
            }
        }
    }
return retorno;
}

/** \brief contador fiches cobrar segun IDCLIENTE
 *
 * \param afiches y su limite
 * \param id cliente
 * \return retorno
 *
 */

int afiches_aCobrarByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente)
{
    int i;
    int retorno=-1;
    int aCobrar=0;
    for(i=0; i<limiteAfiches; i++)
    {
        if(arrayAfiches[i].idCliente==idCliente && arrayAfiches[i].estado==1 && !arrayAfiches[i].isEmpty)
        {
            aCobrar++;
            retorno=0;
        }
    }
  return retorno;
}

/** \brief lista afiches
 *
 * \param afiches
 * \param limite afiches
 * \return [-1] si mal, [0]si ok
 *
 */

int afiches_listado(Afiches* arrayAfiches,int limiteAfiches)
{
    int i;
    int retorno=-1;
    if(arrayAfiches!=NULL && limiteAfiches>0)
    {
        for(i=0;i<limiteAfiches;i++)
        {
            if(arrayAfiches[i].isEmpty==0)
            {
                retorno=0;
                printf("\nIdCliente: %d",arrayAfiches[i].idCliente);
                printf("\nIdAfiche: %d",arrayAfiches[i].idAfiche);
                printf("\nCantidad Afiches: %d",arrayAfiches[i].cantAfiches);
                printf("\nNombreArchivo: %s",arrayAfiches[i].nombreArchivo);
                printf("\nEStado (0 cobrada, 1 por cobrar): %s",arrayAfiches[i].estado);
            }
        }
    }
    return retorno;
}

int afiches_cambiarEstado(Afiches* arrayAfiches,int limiteAfiches)
{
    int i;
    int retorno=-1;
    if(arrayAfiches!=NULL && limiteAfiches>0)
    {
        if(arrayAfiches[i].estado==1)
        {
           arrayAfiches[i].estado=0;
           printf("EStado de la venta: Cobrada");
        }
    }
}


/** \brief editar afiches
 *
 * \param afiche y su limite
 * \param id, cantidad de afiches y las zona
 * \return [-1] si mal, [0] is ok
 *
 */

int afiches_editar(Afiches* arrayAfiches,int id,int limiteAfiches,int cantAfiches,int zona)
{
    int i;
    int retorno=-1;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for (i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idAfiche==id)
            {
                arrayAfiches[i].cantAfiches=cantAfiches;
                arrayAfiches[i].zona=zona;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief imprime listado a cobrar
 *
 * \param cliente y su limite
 * \param afiches y su limite
 * \return [-1] si mal, [0] si ok
 *
 */

int informe_clientesAcobrar(Cliente* arrayClientes,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{
    int i;
    int retorno=-1;

    int afichesAcobrar=0;;
    if(arrayClientes!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++)
            {
            if(!pBuffer[i].isEmpty)
            {
                printf("\nIdCLIENTE: %d",arrayClientes[i].idCliente);
                printf("\nNombre: %s",arrayClientes[i].nombre);
                printf("\nApellido: %s",arrayClientes[i].apellido);
                printf("\nCuit: %s",arrayClientes[i].cuit);
                afichesAcobrar=afiches_cantidadACobrarByIdCliente(pBuffer,limiteAfiches,pBuffer[i].idCliente);
                printf("\nVentas a cobrar: %d",afichesAcobrar);
                retorno=0;
            }
        }
    }
return retorno;
}
/** \brief cant gral de afiches
 *
 * \param puntero array afiches
 * \param limite afiches
 * \return cantidad afiches
 *
 */

int afiches_cantidadAfiches(Afiches* arrayAfiches,int limiteAfiches)
{
     int i;
    int cantidad=0;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty)
            {
                cantidad=cantidad+arrayAfiches[i].cantAfiches;
            }
        }
    }
return cantidad;
}

/** \brief afiches por cliente
 *
 * \param puntero a array CLIENTE, su limite
 * \param id cliente
 * \return cantidad de afiches
 *
 */

int afiches_cantidadByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente)
{
    int i;
    int cantidad=0;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++)
            {
            if((!arrayAfiches[i].isEmpty && arrayAfiches[i].idCliente==idCliente && arrayAfiches[i].estado==1)||
            (arrayAfiches[i].idCliente==idCliente && arrayAfiches[i].estado==0))
            {
                cantidad++;
            }
        }
    }
return cantidad;

}
/** \brief a cobrar segun cliente
 *
 * \param puntero a afiches y su limite
 * \param id cliente
 * \return cantidad a cobrar
 *
 */

int afiches_cantidadACobrarByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente)
{
    int i;
    int cantidad=0;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++){
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idCliente==idCliente){
                cantidad = cantidad + arrayAfiches[i].cantAfiches;
            }
        }
    }
return cantidad;
}

/** \brief ventas por Clientes
 *
 * \param puntero a afiches y su limite
 * \param id cliente
 * \return cantidad de ventas por clientes
 *
 */

int afiches_cantidadDeVentasByIdCliente(Afiches* arrayAfiches,int limiteAfiches,int idCliente)
{
    int i;
    int cantidad=0;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idCliente==idCliente && arrayAfiches[i].estado==1)
            {
                cantidad=cantidad+arrayAfiches[i].cantAfiches;
            }
        }
    }
return cantidad;
}

/** \brief ventas totales
 *
 * \param puntero a afiches y su limite
 * \param id cliente
 * \return cant de ventas
 *
 */

int afiches_VentasTotales(Afiches* arrayAfiches,int limiteAfiches,int idCliente)
{
    int i;
    int cantidad=0;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].idCliente==idCliente )
            {
                cantidad++;
            }
        }
    }
return cantidad;
}
/** \brief cantidad de afciches por zona
 *
 * \param puntero array afiches y su limite
 * \param zona
 * \return cantidad por zona
 *
 */

int afiches_cantidadAfichesByZona(Afiches* arrayAfiches,int limiteAfiches)
{
    int i;
    int cantidad=0;
    int zona;
    if(arrayAfiches!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteAfiches;i++)
        {
            if(!arrayAfiches[i].isEmpty && arrayAfiches[i].zona==zona)
            {
                cantidad=cantidad+arrayAfiches[i].cantAfiches;
            }
        }
    }
return cantidad;
}
