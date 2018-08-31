#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

static int getInt(int* pResultado);
static int getFloat(float* pResultado); //es int xq devueve 0 ó -1

/** \brief Pide entero
 * \param puntero a numero, intentos, puntero a mensaje
 * \param puntero a mensaje de error, minimo, maximo
 * \return 0 ok, -1 error
  */

int utn_getEntero (int* pNumero, int intentos, char* mensaje, char* error, int min,int max)
{
    int auxNumero;
    int retorno =-1;

    for(intentos; intentos>0; intentos--)
    {
        printf(mensaje);
        if(getInt("%d",&auxNumero)==1)// scanf devuelve 1 si logra escanear variable
        {
            if(auxNumero>=min && auxNumero<=max)
            {
                pNumero=auxNumero;
                retorno=0;
                //return 0; // 0 esta ok no cumple parametros de max o min
                break;
            }
            else
            {
                printf(error);//
            }
        }
        else
        {
         printf(error);   // no es un numero
        }
    }
    return retorno;
}

/** \brief pide flotante
  * \param puntero a numero, intentos, puntero a mensaje
 * \param puntero a mensaje de error, minimos, maximos
 * \return 0 para ok, -1 para error.
 *
 */


int utn_getFloat (float* pNumero, int intentos, char* mensaje, char* error, int min,int max)
{
    float auxNumero;
    int retorno =-1;

    for(intentos; intentos>0; intentos--)
    {
        printf(mensaje);
        if(getFloat("%f",&auxNumero)==1)// scanf devuelve 1 si logra escanear variable
        {
            if(auxNumero>=min && auxNumero<=max)
            {
                pNumero=auxNumero;
                retorno=0;
                //return 0; // 0 esta ok no cumple parametros de max o min
                break;
            }
            else
            {
                printf(error);//
            }
        }
        else
        {
         printf(error);   // no es un numero
        }
    }
    return retorno;
}

static int getInt(int* pResultado)// solo resulta dentro de este archivo 0ok, -1 error
{
    int auxResultado;
    int retorno =-1;

    if(scanf("%d",&auxResultado)==1)
    {
        pResultado=auxResultado;
        retorno=0;
        break;
    }
    else
        {
            retorno=-1;
        }
    return retorno;
}

static int getFloat(float* pResultado)// solo resulta dentro de este archivo 0 ok, -1 error
{
    float auxResultado;
    int retorno =-1;

    if(scanf("%f",&auxResultado)==1)
    {
        pResultado=auxResultado;
        retorno=0;
        break;
    }
    else
        {
            retorno=-1;
        }
    return retorno;
}
