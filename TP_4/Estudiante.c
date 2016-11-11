#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Estudiante.h"

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

    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &pEst->edad);

    pEst->print = est_printEstudiantes;

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
