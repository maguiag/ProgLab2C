#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

// CARGA SECUENCIAL

int maximoArray(int array[],int cantidad);
int minimoArray(int array[],int cantidad);
float promedioArray(int array[],int cantidad);
float retornarTotal(int array[], int cantidad);
void cargarListado(int array[], int cantidad);
void mostrarListado(int array[], int cantidad);
void mostrarInfoArrays(int array[], int cantidad);
int instanciasNotas(int array[], int cantidad, int limInferior, int limSuperior);

int main()
{
    int listadoDeNotas[CANTIDAD];
    cargarListado(listadoDeNotas,CANTIDAD);
    mostrarListado(listadoDeNotas,CANTIDAD);
    mostrarInfoArrays(listadoDeNotas,CANTIDAD);
    return 0;
}


int maximoArray(int array[],int cantidad)
{
    int mayor;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(i==0)
        {
            mayor = array[0];
        }
        else if(array[i] > mayor)
        {
            mayor = array[i];
        }
    }

    return mayor;
}

int minimoArray(int array[],int cantidad)
{

    int minimo;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(i==0)
        {
            minimo = array[0];
        }
        else if(array[i] < minimo)
        {
            minimo = array[i];
        }
    }

    return minimo;
}

float promedioArray(int array[],int cantidad)
{
    float suma;
    float promedio;

    suma = retornarTotal(array,cantidad);

    promedio = suma / cantidad;

    return promedio;
}

float retornarTotal(int array[], int cantidad)
{
    int i;
    float suma=0;

    for(i=0;i<cantidad;i++)
    {
          suma = suma + array[i];
    }

    return suma;
}

void cargarListado(int array[], int cantidad)
{
     int i, numeroIngresado;


     for(i=0;i<cantidad;i++)
    {
        printf("Ingrese Nota: ");
        scanf("%d",&numeroIngresado);

        while(numeroIngresado <= 1 && numeroIngresado >= 10)
        {
            printf("Ingrese Nota: ");
            scanf("%d",&numeroIngresado);
        }


        array[i] = numeroIngresado; //CARGA SECUENCIAL
    }

}

void mostrarListado(int array[], int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        printf("\nNota %i: %i",i+1,array[i]);

        if(i == cantidad-1)
        {
            printf("\n");
        }
    }

}

void mostrarInfoArrays(int array[], int cantidad)
{

    printf("\nMayor: %i",maximoArray(array,cantidad));
    printf("\nMinimo: %i",minimoArray(array,cantidad));
    //printf("\nSuma Total: %i",(int)promedioArray(array,cantidad)*cantidad);
    printf("\nSuma Total: %i",(int)retornarTotal(array,cantidad));
    printf("\nPromedio: %.2f\n",promedioArray(array,cantidad));
    printf("\nDesaprobados: %i",instanciasNotas(array,cantidad,1,3));
    printf("\nA Final: %i",instanciasNotas(array,cantidad,4,5));
    printf("\nAprobados: %i\n",instanciasNotas(array,cantidad,6,10));

}

int instanciasNotas(int array[], int cantidad, int limInferior, int limSuperior)
{
    int cuantosAlumnos = 0;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(array[i] >= limInferior && array[i] <= limSuperior)
        {
            cuantosAlumnos++;
        }
    }

    return cuantosAlumnos;
}
