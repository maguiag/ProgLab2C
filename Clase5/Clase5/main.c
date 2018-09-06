#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 10

int main()
{
    int listadoDeNotas[CANTIDAD];
    int numeroIngresado;
    int i;

    printf("Tamaño: %ld\n",sizeof(numeroIngresado));
    printf("Tamaño: %ld\n",sizeof(listadoDeNotas));
    printf("Direccion: %ld\n",&numeroIngresado);
    printf("Direccion: %ld\n",listadoDeNotas);
    printf("Valor de Int: %d",numeroIngresado);
    printf("\nValor de 1º Array: %d\n\n",listadoDeNotas[0]);

    for(i=0;i<CANTIDAD;i++)
    {
        printf("Direccion %iº Posicion: %ld\n",i,&listadoDeNotas[i]); //VALOR Y DIRECCION DEL ARRAY
        printf("Valor %iº Posicion: %d\n\n",i,listadoDeNotas[i]);
    }

    return 0;
}
