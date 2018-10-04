#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"

/*
int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

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
int pantallaOrdenar(Pantalla* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((array[i].precio>array[i+1].precio) && orden) || (array[i].precio<array[i+1].precio)  && !orden))
                        // strcmp es para string
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                    else if(array[i].precio==array[i+1].precio)
                    {
                        if(strcmp(array[i].nombre>array[i+1].nombre) >0)

                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 2;
                        }
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

int informar_listadoPantallas(Pantalla* arrayPantallas, int limiteArrayPantalla)   //asi devuelve 0 si todo ok
{
    int retorno =-1;
    if(arrayPantallas !=NULL && limiteArrayPantalla>0)
    {
        pantalla_mostrarDebug(arrayPantallas,limiteArrayPantalla);
        pantalla_ordenarPrecioNombre(arrayPantallas,limiteArrayPantalla);
    }
    return retorno;
}
int pantalla_ordenarPrecioNombre(Pantalla* arrayPantallas, int limiteArrayPantalla)   //asi devuelve 0 si todo ok
{
    int retorno =-1;
    int flagSwap;
    int i;
    Pantalla auxiliarPantalla; // pantalla es un tipo de dato
    if(arrayPantallas !=NULL && limiteArrayPantalla>0)
    {
        do
        {
            flagSwap=0; // si hago swap levanto flag
            for(i=0;i<limiteArrayPantalla-1;i++ ) // recorro 1- que el limite
            { //ahora comparo en este caso precio . elijo<
                if(arrayPantallas[i].precio>arrayPantallas[i+1].precio||
                   (arrayPantallas[i].precio==arrayPantallas[i+1].precio&&
                    strcmp(arrayPantallas[i].nombre,arrayPantallas[i+1].nombre)>0))
                        //despues de 0)*) en * agrego + ||
                        //no pasarme de la columna 80
                {
                    flagSwap=1; //hice swap
                    auxiliarPantalla=arrayPantallas[i];
                    arrayPantallas[i]=arrayPantallas[i+1];
                    arrayPantallas[i+1]=auxiliarPantalla;
                }
            }
        }while(flagSwap);
    }// paro cuando puedo hacer pasda sin levantar flag
    return retorno;
}

//g
int informar_contrataciones(Contratacion* arrayContrat,int limiteContrat,Pantalla* arrayPant, int limitePant)
{
    int retorno;
    int i;
    int flagSwap;
    Contratacion auxContrat;
    Pantalla auxPant;

    if(limiteContrat >0 && arrayContrat!=NULL)
    {

        for()
    }


}



