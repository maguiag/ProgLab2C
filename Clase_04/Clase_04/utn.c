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

static int getInt(int* presultado);


/** \brief Pide entero
 *
 * \param puntero a numero, intentos, puntero a mensaje
 * \param puntero a mensaje de error, minimo, maximo
 * \return 0 ok, -1 error
 *
 */

int utn_getEntero (int* pNumero, int intentos, char* mensaje, char* error, int min,int max)
{
    int auxNumero;
    int retorno =-1;

    for(intentos; intentos>0; intentos--)
    {
        printf(mensaje);
        if(getInt("%d",&auxNumero)==1)// scanf ver funcion wiki
        {
            if(auxNumero>=min && auxNumero<=max)
            {
                pNumero=auxNumero;
                retorno=0;
                //return 0; // 0 esta ok
                break;
            }
            else
            {
                printf(error);// no cumple parametros de max o min
            }
        }
        else
        {
         printf(error);   // no es un numero
        }
    }
    return retorno;
}


static int getInt(int* presultado)// solo resulta dentro de este archivo
{
    int auxResultado;
    int r
}
