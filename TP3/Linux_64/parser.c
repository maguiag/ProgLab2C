#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int flag=1;
    FILE* pFile = fopen("data.csv",w);
    char* pBufferId[1024];
    char* pNombre[1024];
    char* pHorasTrabajadas[1024];
    char* pSueldo[1024];

    do
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",pBufferId,
                                                    pNombre,
                                                    pHorasTrabajadas,
                                                    pSueldo);
        // leer cada linea crear new wpleado por linea fcanf *archvo
       if(flag==1)
       {
       flag =0;
       continue;
       }

        //Employee* e

    }while(!feof(pFile));
    else
    break;
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
Employee *pEmpleado; // ver si es razonable sumar funcion de validacion
//fc de consistencia !!!
    do
    {   pEmpleado=employee_new(); //distinto parametro xq no lo tengo
        fread(pEmpleado,sizeof(Employee),1,pFile);// pide donde dejo, no origen
            ll_add(pArrayListEmployee,)
    }while(!feof(pFile));
    return 1;
}

/*
Cliente *auxiliarPunteroCliente;
    int size=0;
    FILE* pArchivoCliente;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferIsEmpty[1024];
    int flagOnce=1;

    pArchivoCliente = fopen("data.csv","r");
    while(!feof(pArchivoCliente))
    {
        if(flagOnce)
        {
            fscanf(pArchivoCliente,"%s\n",bufferId);
            flagOnce = 0;
        }
        fscanf(pArchivoCliente,"%[^,],%[^,],%[^,],%[^\n]\n",
                                        bufferId,
                                        bufferNombre,
                                        bufferApellido,
                                        bufferIsEmpty);

        auxiliarPunteroCliente = cliente_newConParametros(
                                        bufferId,
                                        bufferNombre,
                                        bufferApellido);

        if(auxiliarPunteroCliente != NULL)
        {
            arrayPunteroCliente[size] = auxiliarPunteroCliente;
            size++;
        }
    }
    fclose(pArchivoCliente);


    mostrar(arrayPunteroCliente,size);
    guardar(arrayPunteroCliente,size);
    return 0;
}

