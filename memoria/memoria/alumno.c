#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


Alumno* alumno_new()
{
    return (Alumno*) malloc(sizeof(Alumno));
}

Alumno* alumno_newParametros(int id,int legajo,int status,char* nombre)
{
    return NULL;
}

int alumno_delete(Alumno* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int alumno_setId(Alumno* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}


int alumno_getId(Alumno* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}













