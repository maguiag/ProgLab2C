#include <stdio_ext.h>
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
    int retorno=-1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int flag=1;
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

            if(flag)// leo  y descarto la cabecera del archivo
            {
                flag=0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);
            }


            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,
                                               bufferNombre,
                                               bufferHorasTrabajadas,
                                               bufferSueldo);

            pEmpleado=employee_newParametros(bufferId,
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


    fclose(pFile);


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
    Employee* pEmpleado;

    do
    {
        pEmpleado=employee_new();//crea esp de memoria
        if(fread(pEmpleado,sizeof(Employee),1,pFile)==1)// llenarlo con datos del archivo-devuelve1 si lo leyo 0 si no
        // si leyo es porq el arch no esta vacio
        {

         ll_add(pArrayListEmployee,pEmpleado);//agregarlo a ala lista
         }
         else
         {
            employee_delete(pEmpleado);// borro porq sino queda un leak, espacio de memoria vacia
         }
    }
    while(!feof(pFile));
    return 1;
}
