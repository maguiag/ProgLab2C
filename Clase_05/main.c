#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5

int mostrarArray(int* pArray,int limite)

int main()
{
    int edades;
    //=[CANTIDAD_EMPLEADOS];
    int i;

    for(i=0; i<CANTIDAD_EMPLEADOS; i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?", "\nFuera de rango", 0, 200)==-1);//posicion de memoria del elemento i
        //utn_get devolvia 0 si todo ok
        //o &edades[i]=>(edades +1) (es algebra de punteros)
        // if(!utn_()) niega todo lo que pasa en utn_get pero lo reemplazo x ==0 al final. -1 porque es si sale mal
        {
            edades[i]=-1; //pongo -1 en la posicion i; -1 es que la fc no levanto edad
        }
    }

    mostrarArray(edades, CANTIDAD_EMPLEADOS);
    //mostrarArray(edades+2,CANTIDAD_EMPLEADOS-2); //slicing

    return 0;
}




int mostrarArray(int* pArray,int limite) //o int pArray[]
{
    int i;
    //en este caso CANTIDAD_EMPLEADOS

    for(i=0; i<limite;i++)
    {
        printf("\n[%d] %d", i, pArray[i]);// "Index:%d - Value: %d - add: %p" , i , pArray[i],&pArray[i]
        //\n
    }
    return 0;
}

int calcularMaximo(int* pArray, int limite, )
{
    int i;
    int maximo;
    int auxM;

    for(i=0; i<limite; i++)
    {

    }


    return 0;
}


int initArray(int* pArray,int limite)
{
    int i;
    int retorno=-1
    if (pArray != NULL && limite>0)
      {
        retorno = 0;
      }

    return retorno;
}
