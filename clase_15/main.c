#include <stdio.h>
#include <stdlib.h>
int* newArray(int size);
int initArray(int* arrayInt, int limite, int valor);
int showArray(int* arrayInt, int limite);
int deleteArray(int* arrayInt, int limite);
int main()
{
    int* arrayEnteros;//puntero a int
    newArray(100);
    initArray(arrayEnteros,100,1024);
    showArray(arrayEnteros,100);
    deleteArray(arrayEnteros);
        return 0;
}

int* newArray(int limite) // contruye espacio en memoria par lo que yo quiero alocar
{
    int* retorno=NULL;
    int* auxiliarInt;
    if(size>0)
    {
        auxiliarInt=(int*)malloc(sizeof(int)*size);
        if(auxiliarInt!=NULL)
        {
            retorno=auxiliarInt;

        }
    }
    return retorno;
}

int initArray(int* arrayInt, int limite,int valor)
{
    int retorno=-1;
    if(arrayInt!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            //arrayInt[i]=1; funciona pero tiene error de estilo, xq lo pase como* pero  uso [i]
            *(arrayInt+i)=valor;
        }
        retorno=0;
    }
    return retorno;
}


int showArray(int* arrayInt, int limite)
{
   int retorno=-1;
   int i;
   printf("\n---> i %p",&i);// direccion de memoria de i
    if(arrayInt!=NULL && limite>0)
    {
        for(i=;i<limite;i++)
        {
            printf("%p -[%d] - %d", (arrayInt+i),i,*(arrayInt+i));
        }
        retorno=0;
    }
    return retorno;
}
int deleteArray(int* arrayInt)
{
   int retorno=-1;
   if(arrayInt!=NULL )
    {
    free(arrayInt);
    retorno=0;
    }
    return retorno;
}
