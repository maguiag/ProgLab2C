#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "LinkedList.h"
int generarInformes (char* fileName,LinkedList* listaVentas)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(fileName,"w");
    int unidadesVendidas;
    int ventasMayoresA;
    int ventasMayoresB;
    int tvVendidas;
    if(pFile !=NULL)
    {
        retorno=0;
        //
        fprintf(pFile,"********************\n");
        fprintf(pFile,"Informe de Ventas\n");
        fprintf(pFile,"********************\n");
        fprintf(pFile,"- Cantidad de Unidades Vendidas totales: %d\n",unidadesVendidas);
        fprintf(pFile,"- Cantidad de ventas por un monton mayor a $10000 : %d\n",ventasMayoresA);
        fprintf(pFile,"- Cantidad de ventas por un monton mayor a $20000 : %d\n",ventasMayoresB);
        fprintf(pFile,"- Cantidad de TVs LCD Vendidas: %d\n",tvVendidas);

    }
    fclose(pFile);
    return retorno;
}
