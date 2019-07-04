#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED

typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    int peso;
}Entregas;

Entregas* entregas_new();
Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr);
void entregas_delete();

int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);

int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);

int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);

int entregas_setPeso(Entregas* this,int peso);
int entregas_getPeso(Entregas* this,int* peso);


#endif // ENTREGAS_H_INCLUDED
