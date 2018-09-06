#include "utn.h"
#include <stdio.h>
#include <stdlib.h>

static int getInt(int *pResultado);
static  int getFloat(float *pResultado);

int utn_getEntero(int *pEdad,char *mensaje,char *mensajeError,int reintentos,int maximo,int minimo)
 {
    int retorno=-1;
    int auxiliarEdad;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&auxiliarEdad)==0)
        {
        if(minimo<=auxiliarEdad && auxiliarEdad<=maximo)
        {
            *pEdad=auxiliarEdad;
            retorno=0;
            break;
        }
        else
        {
            printf(mensajeError);
            reintentos--;
        }
        }
        else
        {
            printf("se debe ingresar un numero");
            fflush(stdin);
            reintentos--;
        }
    }
 return retorno;
 }

 static int getInt(int *pResultado)
 {
    int auxiliar;
    int retorno=-1;
    if(scanf("%d",&auxiliar)==1)
    {
         retorno=0;
        *pResultado=auxiliar;
    }
    return retorno;
 }

 float utn_getFloat(float *pEdad,char *mensaje,char *mensajeError,int reintentos,float maximo,float minimo)
 {
    float retorno=-1;
    float auxiliarEdad;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getFloat(&auxiliarEdad)==0)
        {
        if(minimo<=auxiliarEdad && auxiliarEdad<=maximo)
        {
            *pEdad=auxiliarEdad;
            retorno=0;
            break;
        }
        else
        {
            printf(mensajeError);
            reintentos--;
        }
        }
        else
        {
            printf("se debe ingresar un numero");
            fflush(stdin);
            reintentos--;
        }
    }
 return retorno;
 }

 static int getFloat(float *pResultado)
 {

    float auxiliar;
    int retorno=-1;
    if(scanf("%f",&auxiliar)==1)
    {
         retorno=0;
        *pResultado=auxiliar;
    }
    return retorno;

 }
