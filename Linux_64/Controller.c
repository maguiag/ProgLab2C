#include <stdio_ext.h>

#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)

{
    int retorno=0;
    FILE* pFile;
    pFile = fopen("data.csv","r");

    if(parser_EmployeeFromText(pFile,pArrayListEmployee)
    {
        retorno=1;
    }
    else
    {

        printf("\nError de archivo\n");
    }

    fclose(pFile);
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen("data.csv","r");
    retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    return retorno;
    /*
    if(fp

    */
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    if(pArrayListEmployee!=NULL)
    {
        retorno=0;
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            ll_get(pArrayListEmployee,i);
            employee_getNombre(pArrayListEmployee,nombre);
            printf("\nNombre: %s",nombre);
        }
    }



    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile=fopen("data.csv","wb");
    Employee* pEmpleado;
    int i;
    int lenArray=ll_len(pArrayListEmployee);

    if(pFile!=NULL)
    {
        for(i=0;i<lenArray;i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pFile);
        }
    }


    return 1;
}

