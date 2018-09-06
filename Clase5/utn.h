#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/**
    utn_getEntero: pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 ok ,-1 error
*/

int utn_getEntero(int *pEdad,char *mensaje,char *mensajeError,int reintentos,int maximo,int minimo);
float utn_getFloat(float *pEdad,char *mensaje,char *mensajeError,int reintentos,float maximo,float minimo);


#endif // UTN_H_INCLUDED
