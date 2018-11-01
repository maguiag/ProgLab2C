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

    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int retorno = -1;
    int flagOnce=1;
    Employee * pEmpleado;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce = 0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                        bufferInt,
                                        bufferNombre,
                                        bufferHorasTrabajadas,
                                        bufferSueldo);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                        bufferInt,
                                        bufferNombre,
                                        bufferHorasTrabajadas,
                                        bufferSueldo);
            //printf("\n%s",bufferNombre);

            pEmpleado = employee_newConParametros(
                                        bufferInt,
                                        bufferNombre,
                                        bufferHorasTrabajadas,
                                        bufferSueldo);

            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEmployee,pEmpleado);
            }

        }
    }
    return retorno;
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
    {
        pEmpleado=employee_new(); //distinto parametro xq no lo tengo
        fread(pEmpleado,sizeof(Employee),1,pFile);// pide donde dejo, no origen
        ll_add(pArrayListEmployee,pEmpleado)
    }
    while(!feof(pFile));
    return 1;
}

/*
Employee * pEmpleado;
    int size=0;
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce=1;
    int rerono =-1


  if(pFile!=NULL)
    {
        while(!feof(pFile))
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

