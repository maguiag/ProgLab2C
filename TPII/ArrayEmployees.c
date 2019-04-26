#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
//prototipos privados
static int obtenerEspacioLibre(Employee* empleado, int limite);
static int proximoId(void);

/** \brief Inicializa la estructura
 *
 * \param empledado Employee* Estructura que representa empleado
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok
 *
 */
int initEmployees(Employee* list,int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && list!=NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            list[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Busca los espacios libres en el array de la estructura
 *
 * \param empleado Employee* Estructura que representa empleado.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
static int obtenerEspacioLibre(Employee* list, int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && list!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Incrementa el Id
 *
 * \return int devuelve el valor del Id que va a ser usado en el próximo alta.
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    int i;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;

    if(len>0 && list!=NULL)
    {
        i=obtenerEspacioLibre(list,len);
        if(i>=0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es valido","\nError, mas de 51",auxName,51,2))
            {
                if(!getValidString("\nIngrese apelllido: ","\nNo es valido", "\nError, mas de 51",auxLastName,51,2))
                {
                    if(!getValidFloat("\nIngrese salario: ","\nNoes valido",auxSalary,0,1000000,2))
                    {
                        if(!getValidInt("\nIngrese sector: ","\nError",auxSector,0,10,20))
                        retorno=0;
                        strcpy(list[i].name,auxName);
                        strcpy(list[i].lastName,auxLastName);
                        list[i].salary=auxSalary;
                        list[i].sector=auxSector;
                        list[i].id=proximoId();
                        list[i].isEmpty=0;

                    }
                }
            }
        }
        else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
int removeEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int i;

    if(len>0 && list!=NULL)
    {
        retorno=-2;
        for(i=0;i<len;i++)
        {
            if(!list[i].isEmpty && list[i].id==id)
            {
                list[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }

return retorno;
}
int sortEmployees(Employee* list, int len, int order)
int printEmployees(Employee* list, int length)
