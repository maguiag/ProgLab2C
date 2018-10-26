#include <stdio.h>
#include <stdlib.h>

int main()
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    FILE *pArchivo;
/*
    pArchivo = fopen("archivo.ext","w");
    if(pArchivo != NULL)
    {
        fprintf(pArchivo,"%d,%s,%s\n",id,nombre,apellido);
        fprintf(pArchivo,"%d,%s,%s\n",id+1,nombre,apellido);
        fprintf(pArchivo,"%d,%s,%s\n",id+2,nombre,apellido);
        fclose(pArchivo);
    }
    else
    {
        printf("El archivo no existe");
    }
*/
    pArchivo = fopen("archivo.ext","r");
    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            strcpy(bufferApellido,"-----*-----");
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido);
            printf("%s - %s\n",bufferId,bufferApellido);
        }
        fclose(pArchivo);
    }
    else
    {
        printf("El archivo no existe");
    }

    return 0;
}
