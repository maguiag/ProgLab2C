#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#define TEXT_SIZE 20


typedef struct
{
    int idPrestamos;
    int isEmpty;
    //-----------------
    int codLibro;
    int codSocio;
    int dia;
    int mes;
    int anio;

}Prestamos;


#endif // PRESTAMOS_H_INCLUDED

int prestamos_Inicializar(Prestamos array[], int size);                                    //cambiar prestamos
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion);                    //cambiar prestamos
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarInt(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarString(Prestamos array[], int size, char* valorBuscado, int* indice);                    //cambiar prestamos
int prestamos_alta(Prestamos array[], int size, int* contadorID);                          //cambiar prestamos
int prestamos_baja(Prestamos array[], int sizeArray);                                      //cambiar prestamos
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado);
int prestamos_modificar(Prestamos array[], int sizeArray);                                //cambiar prestamos
int prestamos_ordenarPorString(Prestamos array[],int size);                              //cambiar prestamos
int prestamos_listar(Prestamos array[], int size);                      //cambiar prestamos

int librosSolicitados(Prestamos arrayPrestamo[], Socios arraySocio[], Libros arrayLibro[], int len, int idSocio);

