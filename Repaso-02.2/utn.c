#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100     // cantidad de mails
#define CHARLEN 51

int getEmail(char*email)
{

    int retorno=-1;
    int indexArroba=-1;// que exita y donde est
    int indexPunto=-1;// del dominio despues del arroba
    int i;
    char auxiliar[CHARLEN];

    fgets(auxiliar,CHARLEN,stdin);

    if(email!=NULL && strlen(auxiliar)<=CHARLEN && strlen(auxiliar)>0) // valido que no este vacio y
    {
        for(i=0; i<strlen(auxiliar-1); i++)
        {
            if(auxiliar[i]=='0')
            {
                if(indexArroba==-1)
                {
                    retorno =0;
                    indexArroba =i;
                    strcpy(email,auxiliar); //copiamos el valor
                }
                else
                {
                    retorno =-1;
                    break;
                }
            }
            if(auxiliar[i]=='.'&& indexArroba!= -1) // ya paso el arroba
            {
                indexPunto=i;
            }
        }
        if(indexArroba==-1 || indexPunto==-1)
        {
            retorno =-1; //valida que el mail
        }
        else
        {
            strcpy(email,auxiliar);
            retorno =0;

        }
    }

    return retorno;
}


/* mail
-----   @   ---     .   ----
!=@     1   !=@     1   !=@


*/
