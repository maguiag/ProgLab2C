#include <stdio.h>
#include <stdlib.h>
#include "stdio_ext.h"
#include <string.h>
#include "utn.h"


int utn_getFloat (float* pNumero, int intentos, char* mensaje, char* error, float min, float max)
{
    float auxNumero;
    int retorno =-1;

    for(intentos; intentos>0; intentos--)
    {
        printf(mensaje);
        if(getFloat(&auxNumero)==0)// getFloat retorna 0 si ok
        {
            if(min<=auxNumero && auxNumero<=max)
            {
                *pNumero=auxNumero;
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
         __fpurge(stdin);
        }
    }
    return retorno;
}



int utn_getChar(char* pLetra, char* mensaje)
{
    char auxChar;
    int retorno=-1;
    printf(mensaje);

    if(scanf("%c",&auxChar)==1)
    {
        *pLetra=auxChar;
        retorno=0;
    }

    return retorno;
}

int esNumerica()

//
static int getInt(int* pResultado)// solo resulta dentro de este archivo 0ok, -1 error
{
    int auxResultado;
    int retorno =-1;

    if(scanf("%d",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;

    }

    return retorno;
}


static int getFloat(float* pResultado)// solo resulta dentro de este archivo 0 ok, -1 error
{
    float auxResultado;
    int retorno =-1;

    if(scanf("%f",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;

    }

    return retorno;
}

static int getString ()
{
    char bufferString[4096];
    __fpurge(stdin);
    fgets(bufferString,sizeof(bufferString), stdin);
    if(bufferString[strlen(bufferString)-1]=='\n')
    {
        buffer[strlen(buffer)-1]='\0';
    }

}


int isFloat(char* pBuffer)
{
    return 1;
}

static int getFloat(float* pBuffer)
{
    char bufferString[5];
    int retorno=-1;
    char* retornoFgets;


    __fpurge(stdin);
    fgets(bufferString,sizeof(bufferString), stdin );//destino, espacio puse sizeof, qda mjor, solo arreglo[espacio]
    //sizeof largo de la cantidad reservada
    //strlen se fija \0 y te devuelve -1
    if(bufferString[strlen(bufferString)-1]='\n')
    {
        buffer[sterlen(buffer)-1]='0';
    }
    if(strlen(bufferString)!=4)
    {
        printf("\n\ntodo ok");
    }
    else
    {
        printf("\n\ntodo mal");
    }
    printf("\n\nSALIDA------>%s", bufferString);

/*
    if(sgetStrin(bufferString)==0 && isFloat(bufferString))
    {
        *pBuffer=atof(bufferString);//atof pasa el alfanumerico a float
        retorno =0;
    }
  */
    return retorno;
}

int utn_getFloat (float* pNumero, int reintentos, char* mensaje, char* error, float min, float max)
{//mensaje tb puede ser    char msgErr[]  pero es mejo char* // intenteos !=  reintentos
    int retorno=-1;
    float buffer;
    if(pNumero!=NULL && mensaje!=NULL && error!=NULL && min<=max && reintentos>=0) //VALIDO PUNTEROS!!! puntero!=NULL
    {
       do
       {
            reintentos--;
            printf("%s",mensaje);
            if(getFloat(&buffer)==0 && buffer>=min && buffer<=max)//(mauricio pBuffer) si 1 solo = le asigna 0 a get float
            {
                    retorno 0;
                    *pNumero = buffer;//aca * es OPERADOR DE inDIRECCION
                    break;
            }
            else
            {
                printf("%s", error);
            }
            //cotinue salta aca
       }
       while(reintentos >=0);
       // break salta aca. me deja hacer algo mas antes del retorno
    }

    return retorno;
}




