#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "informes.h"


/** \brief cliente con mas ventas a cobrar
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteMasACobrar(Cliente* arrayC,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{
    int i;
    int j;
    int retorno=-1;
    int contadorVentas=0;
    int masAcobrar=0;
    int idCliente;
    int indiceCliente;

    if(arrayC!=NULL && pBuffer!=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno=0;
        for(i=0;i<limiteClientes;i++)
        {
            if(!arrayC[i].isEmpty)
            {
                contadorVentas=0;

                for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBuffer[j].isEmpty && pBuffer[j].idCliente == idCliente && pBuffer[j].estado==0)
                    {
                        contadorVentas++;
                    }
                }
                if(contadorVentas>masAcobrar)
                {
                    masAcobrar=contadorVentas;
                    indiceCliente=i;
                }
            }
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente con mas avisos a cobrar es: %d",indiceCliente);
    }
    return retorno;
}


/** \brief cliente con mas ventas cobradas
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteMasCobradas(Cliente* arrayC,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{
    int i;
    int auxId;
    int auxVentas;
    int auxFlag=0;
    if(arrayC!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++){
            if (!arrayC[i].isEmpty)
            {
                if(!auxFlag || auxVentas<afiches_cantidadDeVentasByIdCliente(pBuffer,limiteAfiches,arrayC[i].idCliente))
                {
                    auxFlag=1;
                    auxVentas=afiches_cantidadDeVentasByIdCliente(pBuffer,limiteAfiches,arrayC[i].idCliente);
                    auxId=arrayC[i].idCliente;
                }

            }
        }
        if(!auxVentas)
            {
            printf("\nsin ventas cobradas");
            }
        else
            {
            printf("\nmaximo de ventas cobradas: %d",auxVentas);
            cliente_buscarPorId(arrayC, limiteClientes,auxId);
        }
    }
return 0;
}


/** \brief cliente con la mayor cantidad de ventas
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_ventasTotales(Cliente* arrayC,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{   int i;
    int flag=0;
    int auxId;
    int auxVentas;

    if(arrayC!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++)
        {
            if (!arrayC[i].isEmpty)
            {
                if(!flag || auxVentas<afiches_cantidadDeVentasByIdCliente(pBuffer,limiteAfiches,pBuffer[i].idCliente))
                {
                    flag=1; //cambia
                    auxVentas=afiches_VentasTotales(pBuffer,limiteAfiches,pBuffer[i].idCliente);
                    auxId=pBuffer[i].idCliente;
                }

            }
        }
        if(!auxVentas)
            {
            printf("\nsin ventas");
        }
        else
            {
            printf("\nmaxima de ventas: %d",auxVentas);
            cliente_mostrarPorId(arrayC,limiteClientes,auxId);
        }
    }
return 0;
}

/** \brief cliente con mas afiches a cobrar
 *
 * \param punteros a arrays cliente y afiches
 * \param limites clientes y afiches
 * \return [-1]si mal, [0] si ok
 *
 */

int informe_clienteMasAfichesCobrar(Cliente* arrayC,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{// tine que considedar la cant de afiches

    int i;
    int auxId;
    int mas;
    int auxMas;
    int retorno=-1;

    if(arrayC!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++)
        {
            auxMas=afiches_cantidadACobrarByIdCliente(pBuffer,limiteAfiches,arrayC[i].idCliente);
            if(!i)
            {
                mas=auxMas;
                auxId=i;
            }
    else if(mas<auxMas)
            {
                mas=auxMas;
                auxId=i;
            }
        }
        printf("\nla cantidad maxima de afiches por cobrar es de: %d",mas);
        cliente_mostrarPorId(arrayC,limiteClientes,auxId);

    }
return retorno;

}

/** \brief cliente que compro mas afiches
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteComproMasAfiches(Cliente* arrayC,int limiteClientes,Afiches* pBuffer,int limiteAfiches)
{// tine que considedar la cant de afiches

    int i;
    int auxId;
    int mas;
    int auxMas;
    int retorno=-1;

    if(arrayC!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++)
        {
            auxMas=afiches_cantidadDeVentasByIdCliente(pBuffer,limiteAfiches,arrayC[i].idCliente);
            if(!i)
            {
                mas=auxMas;
                auxId=i;
            }
    else if(mas<auxMas)
            {
                mas=auxMas;
                auxId=i;
            }
        }
        printf("\nla cantidad maxima de afiches comprados es de: %d",mas);
        cliente_mostrarPorId(arrayC,limiteClientes,auxId);

    }
return retorno;

}



