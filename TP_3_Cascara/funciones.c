#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LONGITUD 5

void menu(void)
{
    char seguir='s';
    int opcion;
    int i;
    EMovie peliculas[LONGITUD];

    do
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");
        printf("Elija una de las opciones: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              agregarPelicula(peliculas , LONGITUD);
              break;

            case 2:
              borrarPelicula(peliculas , LONGITUD);
              break;

            case 3:
              modificarPelicula(peliculas , LONGITUD);
              break;

            case 4:
              mostrar(peliculas , LONGITUD);
              break;

            case 5:
              break;

            case 6:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
        }

        system("pause");
        system("cls");

    } while(seguir=='s');

}

void agregarPelicula(EMovie dato[] , int longitud)
{
   int i, contador=0;

   for (i=0 ; i<longitud ; i++)
   {
      if (dato[i].estado != 1)
      {
          printf("Ingrese el titulo de la pelicula: ");
          fflush(stdin);
          gets(dato[i].titulo);

          printf("Ingrese el genero: ");
          fflush(stdin);
          gets(dato[i].genero);

          printf("Ingrese la duracion de la pelicula [minutos]: ");
          //fflush(stdin);
          scanf("%d", &dato[i].duracion);

          printf("Ingrese una descripcion para la pelicula: ");
          fflush(stdin);
          gets(dato[i].descripcion);

          printf("Ingrese un puntaje [0 a 10]: ");
          scanf("%d", &dato[i].puntaje);
          //validarRango(&dato[i].puntaje , 0 , 10);

          printf("Ingrese el link de la imagen: ");
          fflush(stdin);
          gets(dato[i].linkImagen);

          dato[i].codigo = i+1;
          dato[i].estado = 1;
          break;
      }

      else
      {
          contador++;
      }
   }
   if(contador == longitud)
   {
      printf("No hay espacio disponible en el vector.\n");
   }
}

int buscarPorIdentificardorUnivoco (EMovie dato[], int longitud)
{
    int i, auxiliar, flag=0;

    printf("Ingrese el codigo de la pelicula: \n");

    mostrar(dato , longitud);

    scanf("%d", &auxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if(dato[i].estado==1 && auxiliar==dato[i].codigo)
        {
            return i;
        }
    }

    if(flag == 0)
    {
        printf("El codigo es inexistente\n");
        return -1;
    }
}

void borrarPelicula(EMovie dato[] , int longitud)
{
    char opcion;
    int posicion;
    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("Codigo\t\tTitulo\t\t\tGenero\n");
    printf("%d\t%s\t\t%s\n", dato[posicion].codigo, dato[posicion].titulo, dato[posicion].genero);

    printf("%cEsta seguro de que desea dar de baja esta pelicula? [s/n]: ", 168);
    fflush(stdin);
    scanf("%c", &opcion);

    switch (opcion)
    {
       case 's':
       dato[posicion].estado = 0;
       printf("Se ha dado de baja la pelicula\n");
       break;

       case 'n':
       printf("Operacion abortada\n");
       break;

       default:
       printf("Error, valor ingresado no valido\n");
    }
}

void modificarPelicula(EMovie dato[] , int longitud)
{
    int posicion, opcion;

    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("Codigo\t\tTitulo\t\t\tGenero\n");
    printf("%d\t%s\t\t%s\n", dato[posicion].codigo, dato[posicion].titulo, dato[posicion].genero);

    printf("%cQue parametro desea modificar?\n",168);
    printf("1- Titulo\n");
    printf("2- Genero\n");
    printf("3- Duracion\n");
    printf("4- Descripcion\n");
    printf("5- Puntaje\n");
    printf("6- Link de la imagen\n");
    printf("7- Cancelar\n");
    printf("Seleccione una de las opciones: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch (opcion)
    {
       case 1:
         printf("Ingrese el nuevo titulo: ");
         fflush(stdin);
         gets(dato[posicion].titulo);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 2:
         printf("Ingrese el nuevo genero: ");
         gets(dato[posicion].genero);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 3:
         printf("Ingrese la nueva duracion: ");
         scanf("%d", &dato[posicion].duracion);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 4:
         printf("Ingrese la nueva descripcion: ");
         gets(dato[posicion].descripcion);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 5:
         printf("Ingrese el nuevo puntaje: ");
         scanf("%d", &dato[posicion].puntaje);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 6:
         printf("Ingrese el nuevo link: ");
         gets(dato[posicion].linkImagen);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 7:
         printf("Operacion abortada\n");
         break;

       default:
         printf("Opcion ingresada no valida\n");
    }
}

void mostrar(EMovie dato[] , int longitud)
{
    int i,contador=0;

    printf("Codigo\t\tTitulo\t\tGenero\tpuntaje\n");

    for(i=0 ; i<longitud ; i++)
    {
      if(dato[i].estado == 1)
      {
        printf("%d\t%s\t\t%s\t\t%d/10\n", dato[i].codigo, dato[i].titulo,dato[i].genero, dato[i].puntaje);
      }
      else
      {
          contador++;
      }
    }

    if(contador == longitud)
    {
        printf("No se ha cargado ningun dato.\n");
    }
}





