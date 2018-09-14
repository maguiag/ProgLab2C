#include <stdio.h>
#include <stdlib.h>
#include "stdio_ext.h"
#include <string.h>
#include "utn.h"


void insertion(int data[],int len)
{
 int i,j;
 int temp;
 for(i=1;i<len;i++)
     {
        temp = data[i];
        j=i-1;//0
        while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
    {
     data[j+1] = data[j]; // desplaza
     j--;
    }
    data[j+1]=temp; // inserción
 }
}
