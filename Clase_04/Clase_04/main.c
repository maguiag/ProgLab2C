#include <stdio.h> //#include <stdio_ext.h> para linux
#include <stdlib.h>
#include "utn.h" //""buesca 1ero en mi proyecto, despues n las del compilador

int main()
{
    int numero;
    if(utn_getEntero(&numero, 3, "\nIngrese un entero: ", "\nError, no valido.\n", 0, 300)==0)
    {
        printf("La edad es: %d", numero);// tengo q imprimir numero ingresado xq getEntero devuelve 0(ok) o -1
    }
    //{
      //  printf("el numero es: %d",numero);
    //}

    return 0;
}

