#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Estudiante.h"

void estilizarArrayDeChars(char* array , int longitud)
{
    int i;

    strlwr(array);
    *(array+0) = toupper(*(array+0));

    for(i=0 ; i<longitud ; i++)
    {
        if(*(array+i) == ' ')
        {
            *(array+(i+1)) = toupper(*(array+(i+1)));
        }
    }
}

void validarEdad(int* edad)
{
    while(*edad<0 || *edad>120)
    {
        printf("Edad no valida, reingrese: ");
        fflush(stdin);
        scanf("%d", &*edad);
    }
}

Estudiante* est_newEstudiante(void)
{
    Estudiante* pEst = (Estudiante*) malloc(sizeof(Estudiante));

    if (pEst == NULL)
    {
        return NULL;
    }

    printf("Ingrese el nombre del estudiante: ");
    fflush(stdin);
    gets(pEst->nombre);
    estilizarArrayDeChars(pEst->nombre , strlen(pEst->nombre));

    printf("Ingrese la edad del estudiante: ");
    fflush(stdin);
    scanf("%d", &pEst->edad);
    validarEdad(&pEst->edad);

    pEst->print = est_printEstudiantes;
    pEst->compare = est_compareEstudiantes;

    return pEst;
}

void est_printEstudiantes(ArrayList* pList , Estudiante* pElement)
{
    int i;

    printf("ID\t\tNombre\t\tEdad\n\n");

    for(i=0 ; i<pList->len(pList) ; i++)
    {
        pElement = (Estudiante*) pList->get(pList , i);
        printf("%d\t\t%s\t\t%d\n", i, pElement->nombre, pElement->edad);
    }
}

int est_compareEstudiantes(void* pElement , void* pElement2)
{
    int retorno=0;

    if(strcmp(((Estudiante*)pElement)->nombre , ((Estudiante*)pElement2)->nombre)>0)
    {
        retorno = 1;
    }

    return retorno;
}
