#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LONGITUD 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona datos[LONGITUD];

    do
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              alta(datos , LONGITUD);
              break;

            case 2:
              baja(datos , LONGITUD);
              system("pause");
              break;

            case 3:
              ordenamiento(datos , LONGITUD);
              mostrar(datos , LONGITUD);
              system("pause");
              break;

            case 4:
              imprimirGrafico(datos , LONGITUD);
              system("pause");
              break;

            case 5:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
                system("pause");
        }

        system("cls");

    } while(seguir=='s');

    return 0;
}




