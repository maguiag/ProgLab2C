#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "producto.h"
#define CANTIDAD 200

int main()
{
    Producto productos[CANTIDAD];//P es la estruct; p es el array
    inicializarArray(productos, CANTIDAD); //ARRAY, LIMITE
    imprimirArray(productos,CANTIDAD);
    cargarProducto(productos,5);

    return 0;
}
