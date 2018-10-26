#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pArchivo;
    pArchivo = fopen("archivo.ext","w");
    if(pArchivo!=NULL)
    {
        printf("Abrio");
        fclose(pArchivo);
    }
    else
    {
        printf("eL ARCHIVO NO EXISTE");
    }
    return 0;
}
