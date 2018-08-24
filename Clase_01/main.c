#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10

int main()
{
    int numero;
    int numeroMin;
    int numeroMax;
    int i;
    int acumulador=0;
    float promedio;

    for(i=0;i<CANTIDAD;i++) // sii=1 cantidad queda en CANTIDAD+1
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
    }
    while (numero<=0)
            {
                printf("\nError, ingrese un numero valido");
                scanf("%d",&numero);
            }

    acumulador = acumulador+numero;
    if(numero<numeroMin || i==0)
    {
      numeroMin=numero;
    }
    if(numero>numeroMax || i==0)
    {
        numeroMax=numero;
    }


    promedio = acumulador/CANTIDAD;
    printf("\nEl promedio es: %f",promedio);
    printf("\nEl numero mayor es %d y el numero menor es %d", numeroMax, numeroMin);
    return 0;
}
