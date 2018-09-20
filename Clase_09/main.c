#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "producto.h"
#define CANTIDAD 200

int main()
{
    int indice;
    Producto productos[CANTIDAD];//P es la estruct; p es el array

    inicializarArray(productos, CANTIDAD); //ARRAY, LIMITE
    //imprimirArray(productos,CANTIDAD);
    printProducto(productos,1);// en el indice 1
    cargarProducto(productos,5);
    buscarIsEmpty(productos,&indice,CANTIDAD);//& xq voy a modificar
    return 0;
}
