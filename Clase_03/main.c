#include <stdio_ext.h>
#include <stdlib.h>

int getEdad(int *pEdad);


int main()
{
 int edad;

 if(getEdad(&edad)==0)
 {
  printf("La edad es: %d",edad);
 }

    return 0;
}

int getEdad(int*pEdad)
{
    int retorno = -1;
    int auxEdad;
    int i;
    int reintentos =3;

    for(i=0; i<reintentos; i++) // reintentos=3; reintentos>0; reintentos--
    {
    printf("Ingrese la edad: ");
    if(scanf("%d", &auxEdad)==1);
    {
        if(auxEdad>=0 && auxEdad<199)
            { //
             *pEdad =auxEdad;
             retorno = 0;
             break;
            }
    }
        else
         {
          printf("La edad esta fuera de rango");
          __fpurge(stdin); // vaciamos standar imput
         }
    }
 return retorno;
}
