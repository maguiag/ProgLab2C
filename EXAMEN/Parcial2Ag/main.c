#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "entregas.h"
#include "generadoInforme.h"

int main()
{
    // Definir lista de empleados
    LinkedList* listaEntregas;
    listaEntregas=ll_newLinkedList();
    // Crear lista empledos
    //...

    // Leer empleados de archivo data.csv
    if(parser_EntregasFromText("data.csv",listaEntregas)==1)
     {
        if(generarInformes("informes.txt",listaEntregas)==0)
        {
            printf("Informes.txt generado con exito\n");
        }
     }



    return 0;
}
