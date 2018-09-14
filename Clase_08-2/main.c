#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//typedef int Persona;





int main()
{
    Persona p;
    p.edad=33;
    p.altura=1.90;
    fgets(p.nombre,70,stdin);//stdin sale de la consola
// para escribirlo yo directamente: strncpy(p.nombre, "juan",70);
    printPersona(p);
     return 0;
}


