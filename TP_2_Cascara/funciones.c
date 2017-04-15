#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void estilizarArrayDeChars(char array[] , int longitud)
{
    int i;

    strlwr(array);
    array[0] = toupper(array[0]);
    for(i=0 ; i<longitud ; i++)
    {
        if(array[i] == ' ')
        {
            array[i+1] = toupper(array[i+1]);
        }
    }
}

void alta(EPersona dato[] , int longitud)
{
   int i, contador=0;
   for (i=0 ; i<longitud ; i++)
   {
      if (dato[i].estado != 1)
      {
          printf("Ingrese el nombre de la persona: ");
          fflush(stdin);
          gets(dato[i].nombre);
          estilizarArrayDeChars(dato[i].nombre , longitud);

          printf("Ingrese el apellido de la persona: ");
          fflush(stdin);
          gets(dato[i].apellido);
          estilizarArrayDeChars(dato[i].apellido , longitud);

          printf("Ingrese su edad: ");
          scanf("%d", &dato[i].edad);

          printf("Ingrese su numero de documento: ");
          scanf("%d", &dato[i].dni);
          dato[i].estado = 1;
          break;
      }

      else
      {
          contador++;
      }

      if(contador == longitud)
      {
          printf("No hay espacio disponible en el vector.\n");
          system("pause");
      }

   }

}

int buscarPorIdentificardorUnivoco (EPersona dato[], int longitud)
{
    int i, auxiliar;

    printf("Ingrese el identificardor univoco de lo que quiere buscar: ");
    scanf("%d", &auxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if(dato[i].estado==1 && auxiliar==dato[i].dni)
        {
            return i;
        }
    }
}

void baja(EPersona dato[] , int longitud)
{
    int i, auxiliar, flag=0;
    char opcion;

    printf("Ingrese el DNI de la persona que quiere buscar: ");
    scanf("%d", &auxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if (auxiliar == dato[i].dni)
        {
            flag = 1;
            printf("DNI\t\tNombre\t\t\tEdad\n");
            printf("%d\t%s, %s\t\t%d\n", dato[i].dni, dato[i].apellido, dato[i].nombre, dato[i].edad);

            printf("¿Desea dar de baja a esta persona? [s/n]: ");
            fflush(stdin);
            scanf("%c", &opcion);

            switch (opcion)
             {
               case 's':
                 dato[i].estado = 0;
                 printf("Se ha dado de baja la persona\n");
                 break;

               case 'n':
                 printf("Operacion abortada\n");
                 break;

               default:
                 printf("Error, valor ingresado no valido\n");
            }

            break;
        }
    }

    if (flag == 0)
    {
        printf("El DNI ingresado es inexistente\n");
    }
}

void ordenamiento(EPersona dato[] , int longitud)
{
    int i, j;
    EPersona auxiliar;

    for(i=0 ; i<longitud-1 ; i++)
    {
        for(j=i+1 ; j<longitud ; j++)
        {
            if(strcmp(dato[i].apellido , dato[j].apellido)>0)
            {
                auxiliar = dato[i];
                dato[i] = dato[j];
                dato[j] = auxiliar;
            }
        }
    }
}

void mostrar(EPersona dato[] , int longitud)
{
    int i;

    printf("DNI\t\tNombre\t\t\tEdad\n");

    for(i=0 ; i<longitud ; i++)
    {
      if(dato[i].estado == 1)
      {
        printf("%d\t%s, %s\t\t%d\n", dato[i].dni, dato[i].apellido, dato[i].nombre, dato[i].edad);
      }
    }
}

void imprimirGrafico(EPersona dato [], int longitud)
{
    int i, j, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

    for(i=0 ; i<longitud ; i++)
    {
      if(dato[i].estado == 1)
      {


        if(dato[i].edad <= 18)
        {
            hasta18++;
        }
        else
        {
            if(dato[i].edad>=19 && dato[i].edad<=35)
            {
                de19a35++;
            }
            else
            {
                mayorDe35++;
            }
        }
      }
    }

    if(hasta18>=de19a35 && hasta18>=mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35>=hasta18 && de19a35>=mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
          mayor = mayorDe35;
        }
    }

    for(j=mayor ; j>0 ; j--)
    {
        if(j <= hasta18)
        {
            printf("*");
        }

        if(j <= de19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(j <= mayorDe35)
        {
            if(flag == 0)
            {
                printf("\t\t*");
            }

            if(flag == 1)
            {
                printf("\t*");
            }

        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n");
    printf("%d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
}







