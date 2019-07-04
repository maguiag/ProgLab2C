#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromText(FILE* pFile , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPeso[4096];
    int flag=1;
    Entregas *pEntregas;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

            if(flag)// leo  y descarto la cabecera del archivo
            {
                flag=0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);
            }


            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);

            pEntregas = entregas_newParametros(bufferId,
                                               bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);

            pEntregas=entregas_newParametros(bufferId,
                                            bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);



            if(pEntregas != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEntregas,pEntregas);
            }

        }

    }


    fclose(pFile);


    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromBinary(FILE* pFile , LinkedList* pArrayListEntregas)
{
    Entregas* pEntregas;

    do
    {
        pEntregas=entregas_new();//crea esp de memoria
        if(fread(pEntregas,sizeof(Entregas),1,pFile)==1)// llenarlo con datos del archivo-devuelve1 si lo leyo 0 si no
        // si leyo es porq el arch no esta vacio
        {

         ll_add(pArrayListEntregas,pEntregas);//agregarlo a ala lista
         }
         else
         {
            entregas_delete(pEntregas);// borro porq sino queda un leak, espacio de memoria vacia
         }
    }
    while(!feof(pFile));
    return 1;
}
