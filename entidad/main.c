#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

void ordenar(void* lista[],int limite, int (*comparar)(void*,void*));
int main()
{
    Empleado* listaEmpleados[1000];
    int qtyEmpleados = 0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"Juan_%d",i);
        listaEmpleados[i] = empleado_newParametros(auxiliar,"Perez",1.45);
        qtyEmpleados++;
    }
    listaEmpleados[i] = empleado_newParametros("AAAAAA","Perez",1.45);
    qtyEmpleados++;


    ordenar((void*)listaEmpleados,qtyEmpleados,empleado_compareNombre);


    for(i=0;i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }

    return 0;
}

void ordenar(void* lista[],int limite, int(*comparar)(void*,void*))
{
    int flagSwap;
    int i;
    void* auxiliarPuntero;

    do
    {
        flagSwap = 0;
        for(i=0;i<limite-1;i++)
        {
            if(comparar(lista[i],lista[i+1]) > 0)
            {
                auxiliarPuntero = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = auxiliarPuntero;
                flagSwap = 1;
            }
        }
    }while(flagSwap);
}


