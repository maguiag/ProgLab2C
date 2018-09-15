#include <stdio.h>
#include <stdlib.h>
#include "stdio_ext.h"
#include <string.h>
#include "utn.h"

int main()
{
    int i;
    char miNombre[100];
    printf("carga nombre");
    if(!getNombre(miNombre)) //tiene que retornar un 0
    {
        printf("%s", miNombre);
    }

    return 0;
}
