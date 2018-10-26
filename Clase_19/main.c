#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    char texto[]="hola";
    int id=100;
    char nombre[]="juan";
    char apellido[]="Lopez";
    guardo las cosas como un char gigante porque puede haber un error de carga o de transferencia
       */

    char bufferId[1024]; // no auxiliar
    char bufferNombre[1024];
    char bufferApellido[1024];


    FILE *pArchivo;

    /*pArchivo = fopen("archivo.ext","w");
    if(pArchivo!=NULL)
    {
        //printf("Abrio"); // sale por consola

        printf(pArchivo,"%d, %s, %s\n",id,nombre,apellido);// sale por el achivo
        fclose(pArchivo);
    }
    else
    {
        printf("eL ARCHIVO NO EXISTE");
    }

    */
    pArchivo =fopen("archivo.ext","r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo)) // end of file
        {
            strcpy(bufferApellido, "-------*......");
            fscanf(pArchivo,"%[^,], %[^,], %[^\n]\n",bufferId,bufferNombre,bufferApellido);
            //%s mascara que cubre[0-9A-Za-z]
            //(^excluye la , o lo que sea que quiero excluir)
            printf("%s - %s - %s\n",bufferId,bufferNombre,bufferApellido);
        }
        //printf("Abrio"); // sale por consola
        fclose(pArchivo);
    }
    else
    {
        printf("eL ARCHIVO NO EXISTE");
    }

    return 0;
}
