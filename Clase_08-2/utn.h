#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/*struct S_Persona // el nombre es el tipo de dato
{
    char nombre [79];
    int edad;
    char dni [20];
    float altura;
};
typedef struct S_Persona Persona; //Persona tipo de dato propio
no permite anidar
*/

typedef struct // en el .h
{
    char nombre [79]; //campos
    int edad; //campos para escribir en eded (en este caso "p".edad, p es mi variable).edad
                // para leer printf("%d",p.edad);
    char dni [20];//campos
    float altura;
}Persona; // nombre de mi estructura

void printPersona(Persona* p);

#endif // UTN_H_INCLUDED
