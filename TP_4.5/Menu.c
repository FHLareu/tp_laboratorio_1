#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Estudiante.h"
#include "Menu.h"

void menu(void)
{
    ArrayList* pList;
    ArrayList* pList2;
    Estudiante* pElement;
    char seguir='s';
    int opcion, auxiliar, auxiliar2;

    pList = al_newArrayList();

    if(pList == NULL)
    {
        printf("No hay espacio en memoria.\n");
        exit(1);
    }

    do
    {
        //printf("\t\t\t\t\t Espacio en memoria ocupado: %d / %d (%d%c)\n", pList->len(pList), pList->reservedSize, (pList->len(pList) * 100)/pList->reservedSize, 37);
        printf("1- Dar de alta un nuevo estudiante.\n");
        printf("2- Modificar un estudiante.\n");
        printf("3- Eliminacion.\n");
        printf("4- Nueva lista.\n");
        printf("5- Ordenar.\n");
        printf("6- Informar.\n");
        printf("7- Salir.\n\n");
        printf("Elija una de las opciones: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              printf("1- Carga secuencial.\n");
              printf("2- Seleccionar indice.\n");
              printf("3- Cancelar.\n\n");
              printf("Elija una de las opciones: ");

              scanf("%d", &opcion);

              switch(opcion)
              {
                  case 1:
                    pElement = est_newEstudiante();
                    pList->add(pList , pElement);
                    break;

                  case 2:
                    pElement = est_newEstudiante();
                    printf("Ingrese la posicion donde quiere guardar al estudiante: \n");
                    pElement->print(pList);

                    scanf("%d", &auxiliar);

                    pList->push(pList , pElement , auxiliar);
                    break;

                  case 3:
                    printf("Operacion abortada.\n");
                    break;

                  default:
                    printf("Error, valor ingresado no valido.\n");
              }
              break;

            case 2:
              if(pList->isEmpty(pList) == 1)
              {
                  printf("No hay estudiantes cargados en la lista actualmente.\n");
              }
              else
              {
                  pElement->print(pList , pElement);

                  printf("Ingrese la ID del estudiante que quiere modificar: ");
                  scanf("%d", &auxiliar);

                  pElement = est_newEstudiante();

                  pList->set(pList , pElement , auxiliar);
              }
              break;

            case 3:
              if(pList->isEmpty(pList) == 1)
              {
                  printf("No hay estudiantes cargados en la lista actualmente.\n");
              }
              else
              {
                  if(pList->isEmpty(pList) == 0)
                  {
                      printf("Que desea eliminar?\n");
                      printf("1- Un estudiante en particular.\n");
                      printf("2- Todos los estudiantes.\n");
                      printf("3- La lista completa\n");
                      printf("4- Cancelar.\n\n");
                      printf("Elija una de las opciones: ");

                      fflush(stdin);
                      scanf("%d", &opcion);

                      switch(opcion)
                      {
                          case 1:
                            pElement->print(pList , pElement);

                            printf("Ingrese el ID del estudiante que quiere eliminar: ");
                            scanf("%d", &auxiliar);

                            pList->remove(pList , auxiliar);
                            printf("Se ha eliminado el estudiante.\n");
                            break;

                           case 2:
                             pList->clear(pList);
                             printf("Se han eliminado todos los estudiantes.\n");
                             break;

                           case 3:
                             pList->deleteArrayList(pList);
                             printf("Se ha eliminado la lista entera.\n");
                             break;

                           case 4:
                             printf("Operacion abortada.\n");
                             break;

                           default:
                             printf("Error, valor ingresado no valido.\n");
                      }

                  }
              }
              break;

            case 4:
              printf("Como desea crear la nueva lista?\n");
              printf("1- Desde cero.\n");
              printf("2- Como una copia de la lista actual.\n");
              printf("3- Como copia parcial de la lista actual.\n");
              printf("4- Cancelar.\n");

              fflush(stdin);
              scanf("%d", &opcion);

              switch(opcion)
              {
                  case 1:
                    pList2 = al_newArrayList();

                    if(pList2 == NULL)
                    {
                        printf("No hay espacio en memoria.\n");
                    }
                    else
                    {
                        printf("Se ha creado una nueva lista.\n");
                    }
                    break;

                  case 2:
                    pList2 = pList->clone(pList);

                    if(pList2 == NULL)
                    {
                        printf("No hay espacio en memoria.\n");
                    }
                    else
                    {
                        printf("Nueva lista.\n\n");
                        pElement->print(pList2 , pElement);
                    }
                    break;

                  case 3:
                    pElement->print(pList);

                    printf("Ingrese la ID del estudiante inicial de la nueva lista: ");
                    scanf("%d", &auxiliar);

                    printf("Ingrese la ID del estudiante final de la nueva lista.(Excluyente): ");
                    scanf("%d", &auxiliar2);

                    pList2 = pList->subList(pList , auxiliar , auxiliar2);
                    if(pList2 == NULL)
                    {
                        printf("No hay espacio en memoria.\n");
                    }
                    else
                    {
                        printf("Nueva lista.\n\n");
                        pElement->print(pList2 , pElement);
                    }
                    break;

                  case 4:
                    printf("Operacion abortada.\n");
                    break;

                  default:
                    printf("Error, valor ingresado no valido.\n");
              }
              break;

            case 5:
              if(pList->isEmpty(pList) == 1)
              {
                  printf("No hay estudiantes cargados en la lista actualmente.\n");
              }
              else
              {
                  if(pList->isEmpty(pList) == 0)
                  {
                      printf("Indique el orden de acomodamiento de los estudiantes.\n");
                      printf("1- Descendente.\n");
                      printf("2- Ascendente.\n");
                      printf("3- Cancelar.\n");

                      fflush(stdin);
                      scanf("%d", &opcion);

                      switch(opcion)
                      {

                          case 1:
                            pList->sort(pList , pElement->compare , 0);
                            break;

                          case 2:
                            pList->sort(pList , pElement->compare , 1);
                            break;

                          case 3:
                            printf("Operacion abortada.\n");
                            break;

                          default:
                            printf("Error, valor ingresado no valido.\n");
                      }
                  }
              }
              break;

            case 6:
              if(pList->isEmpty(pList) == 1)
              {
                  printf("No hay estudiantes cargados en la lista actualmente.\n");
              }
              else
              {
                  if(pList->isEmpty(pList) == 0)
                  {
                      pElement->print(pList , pElement);
                      printf("Cantidad de alumnos: %d\n", pList->len(pList));
                  }
              }
              break;

            case 7:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
        }

        system("pause");
        system("cls");

    } while(seguir=='s');

}

