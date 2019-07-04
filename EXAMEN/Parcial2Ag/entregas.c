#include "entregas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidName(char* name);
Entregas* entregas_new()
{
     Entregas* this;
    this=malloc(sizeof(Entregas));
return this;
}

Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr)
{
    Entregas* this;
    this=entregas_new();

    if(!entregas_setId(this,atoi(idStr)) &&
       !entregas_setTipo(this,tipoStr) &&
       !entregas_setCantidad(this,atoi(cantidadStr)) &&
       !entregas_setPeso(this,atoi(pesoStr)))
    {
        return this;

    }
   entregas_delete(this);
    return NULL;
}

void entregas_delete(Entregas* this)
{
    free(this);
}

int entregas_setId(Entregas* this,int id)
{
     int retorno=-1;
     static int proximoId=-1;

     if(this!=NULL && id==-1)
     {
         proximoId++;
         this->id=proximoId;
         retorno=0;
     }
     else if(id>proximoId)
     {
         proximoId=id;
         this->id=proximoId;
         retorno=0;
     }
     return retorno;
}

int entregas_getId(Entregas* this,int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int entregas_setTipo(Entregas* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && !isValidName(tipo))
    {
        strcpy(this->tipo,tipo);
        retorno=0;
    }
    return retorno;
}

int entregas_getNombre(Entregas* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && tipo!=NULL)
    {
          strcpy(tipo,this->tipo);
        retorno=0;
    }
    return retorno;
}

int entregas_setCantidad(Entregas* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {

        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_getCantidad(Entregas* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_setPeso(Entregas* this,int peso)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int entregas_getPeso(Entregas* this,int* peso)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *peso=this->peso;
        retorno=0;
    }
return retorno;
}

//int informes_entregasCantidad(void* pElement);
/*
int informe_cantidadByTipo(void* element)
{
    Entregas* pEntregas;
    int retorno=0;
    aux=(Venta*)element;
    char auxCodigo[20];
    if(auxVenta!=NULL)
    {
        Venta_getCodigo_producto(auxVenta,auxCodigo);
        if(strcmp(auxCodigo,"LCD_TV")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}




*/

/*int Entregas_criterioName(void* thisA, void* thisB)
{
    int retorno=-1;
    char nameA[200];
    char nameB[200];

    entregas_getNombre((Entregas*)thisA,nameA);
    entregas_getNombre((Entregas*)thisB,nameB);

    if(strcmp(nameA,nameB)>0)
    {
        retorno=1;
    }
    if(strcmp(nameA,nameB)<0)
       {
           retorno=-1;
       }
       return retorno;
}

static int isValidName(char* name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        retorno=0;
    }
    return retorno;
}
*/
