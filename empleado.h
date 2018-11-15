typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Empleado;





Empleado* empleado_new();
void empleado_delete();
Empleado* empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);

int empleado_setId(Empleado* this,int id);
int empleado_getId(Empleado* this,int* id);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);

int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int empleado_setSueldo(Empleado* this,int sueldo);
int empleado_getSueldo(Empleado* this,int* sueldo);

#endif // EMPLEADO_H_INCLUDED
