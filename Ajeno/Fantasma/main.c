#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio_ext.h>
#include "utn.h"
#include "fantasma.h"
#include "autor.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdfantasma = 0;
    int contadorIdautor = 0;                   //cambiar
    int contadorIdlibro = 0;                   //cambiar
    int contadorIdsocios = 0;                   //cambiar
    int contadorIdprestamos = 0;                   //cambiar

    Fantasma arrayFantasma[QTY_TIPO]; //cambiar
    Autor arrayAutor[QTY_TIPO];
    Libros arrayLibros[QTY_TIPO];
    Socios arraySocios[QTY_TIPO];
    Prestamos arrayPrestamos[QTY_TIPO];

    fantasma_Inicializar(arrayFantasma, QTY_TIPO);          //cambiar
    autor_Inicializar(arrayAutor, QTY_TIPO);
    libros_Inicializar(arrayLibros, QTY_TIPO);
    socios_Inicializar(arraySocios, QTY_TIPO);
    prestamos_Inicializar(arrayPrestamos, QTY_TIPO);


    arrayAutor[0].isEmpty = 0;
    strncpy(arrayAutor[0].nombre, "AA", sizeof(arrayAutor[0].nombre));
    strncpy(arrayAutor[0].apellido, "BB", sizeof(arrayAutor[0].apellido));


    arrayLibros[0].isEmpty = 0;
    strncpy(arrayLibros[0].titulo, "TT", sizeof(arrayLibros[0].titulo));
    arrayLibros[0].codAutor = 1;

    arraySocios[0].isEmpty = 0;
    strncpy(arraySocios[0].apellido, "XX", sizeof(arraySocios[0].apellido));
    strncpy(arraySocios[0].nombre, "ZZ", sizeof(arraySocios[0].nombre));
    arraySocios[0].sexo ='M';
    strncpy(arraySocios[0].telefono, "49819140", sizeof(arraySocios[0].telefono));
    strncpy(arraySocios[0].eMail, "cris@hotmail.com", sizeof(arraySocios[0].eMail));
    arraySocios[0].dia = 12;
    arraySocios[0].mes = 6;
    arraySocios[0].anio = 1994;

    arrayPrestamos[0].codLibro = 0;
    arrayPrestamos[0].codSocio = 0;
    arrayPrestamos[0].dia = 15;
    arrayPrestamos[0].mes = 4;
    arrayPrestamos[0].anio = 1995;

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Fantasma\n2) Modificar Fantasma\n3) Baja Fantasma\n4) Listar Fantasma\n5) Ordenar Fantasma\n****************************\n6) Alta Autores\n7) Modificar Autor\n8) Baja Autor\n9) Listar Autor\n****************************\n10) Alta Libro\n11) Modificar Libro\n12) Baja Libro\n13) Listar Libro\n****************************\n14) Alta Socio\n15) Modificar Socio\n16) Baja Socio\n17) Listar Socio\n18) Listar Libros-Socio\n19) Listar Autores-Socios\n20)Prestamos\n****************************\n21) Salir\n",  //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma, QTY_TIPO, &contadorIdfantasma);  //cambiar
                break;

            case 2: //Modificar
                fantasma_modificar(arrayFantasma, QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma, QTY_TIPO);        //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma, QTY_TIPO);  //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorString(arrayFantasma, QTY_TIPO);                  //cambiar
                break;

            case 6:
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);
                break;
            case 7:
                autor_modificar(arrayAutor,QTY_TIPO);
                break;
            case 8:
                autor_baja(arrayAutor,QTY_TIPO);
                break;
            case 9:
                autor_listar(arrayAutor,QTY_TIPO);
                break;
            case 10:
                libros_alta(arrayLibros, QTY_TIPO, &contadorIdlibro);
                break;
            case 11:
                libros_modificar(arrayLibros, QTY_TIPO);
                break;
            case 12:
                libros_baja(arrayLibros, QTY_TIPO);
                break;
            case 13:
                libros_listar(arrayLibros, QTY_TIPO);
                break;
            case 14:
                socios_alta(arraySocios, QTY_TIPO, &contadorIdsocios);
                break;
            case 15:
                socios_modificar(arraySocios, QTY_TIPO);
                break;
            case 16:
                socios_baja(arraySocios, QTY_TIPO);
                break;
            case 17:
                socios_listar(arraySocios, QTY_TIPO);
                break;
            case 18:
                socios_listar(arraySocios, QTY_TIPO); // socios - libros
                break;
            case 19:
                socios_listar(arraySocios, QTY_TIPO); // socios - autores
                break;
            case 20:
                prestamos_alta(arrayPrestamos, QTY_TIPO, &contadorIdprestamos);
                break;
            case 21://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=21);
    return 0;
}
