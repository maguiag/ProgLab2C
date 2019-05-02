#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funciones2.0.h"

int utn_getNumber(int* pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret = -1;
    char bufferStr[4096];
    int bufferInt;

    if (pResultado!=NULL && reintentos>=0 && minimo<maximo)
    {
    while(reintentos>0)
    {
        if(!getString(bufferStr,mensaje,mensajeError,1,6,1) && isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if (bufferInt>=minimo && bufferInt<=maximo)
            {
                ret = 0;
                *pResultado = bufferInt;
                break;
            }
        }
    reintentos--;
    }
    }
    return ret;
}

int getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    char bufferStr[4096];
    int ret = -1;
    if  (resultado!=NULL &&
        mensaje!=NULL &&
        mensajeError!=NULL &&
        minimo<maximo &&
        reintentos>=0)
    {
    printf("ok1\n");
        while (reintentos>0)
        {
            printf("%s",mensaje);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if (strlen(bufferStr)>=minimo && strlen(bufferStr)<=maximo)
            {
                ret = 0;
                strncpy(resultado,bufferStr,maximo);
                break;
            }
            reintentos--;
            printf("%s\n",mensajeError);
            //__fpurge(stdin);
        }
    printf("ok2\n");
    }
    return ret;
}
int isValidIntNumber(char *cadena)
{
    int ret = 0;
    int i=0;
    if (cadena[i]=='-')
    {
        i++;
    }
    if (cadena!=NULL)
    {
        while (cadena[i]!='\0')
        {
            if (cadena[i]<'0' || cadena[i]>'9')
            {
                break;
            }

            i++;
        }
        if (strlen(cadena)==i)
        {
            ret = 1;
        }
    }

    return ret;
}
