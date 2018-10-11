#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "afiches.h"
#define QTY 100
#define VENTAS 1000

int main()
{

    Cliente clientes[QTY];
    Afiches afiches[VENTAS];

    int auxCuit;
    int opcion;
    char auxApellido[51];
    char auxNombre[51];
    int auxId;
    char seguir='s';


    cliente_init(clientes,QTY);
    afiches_init(afiches,VENTAS);
     do
     {
        getValidInt("1.Alta\n2.Modificar Cliente\n3.Baja Cliente\n4.Vender\n5.Editar\n6.Cobrar\n7.Imprimir Clientes\n8.Salir\n","\nNo valida\n\n",&menu,1,8,1);


         switch(menu)
         {
             case 1:
                cliente_alta(clientes,QTY);
             break;
             case 2:
                getValidInt("\nIngrese el Id del Cliente\n","\nError, no valido",&auxId,0,999,2);
                cliente_modificacion(clientes,QTY, auxId);
             break;
             case 3:
                getValidInt("\nIngrese el Id del Cliente\n","\nError, no valido",&auxId,0,999,2);
                cliente_baja(clientes,QTY,auxId);
             break;
             case 4:

             break;
             case 5:

             break;
             case 6:

             break;
             case 7:
             // editar le falta ventas

             break;
         }
     }while(opcion!=8);
    return 0;
}
