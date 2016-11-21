#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    char nombre[15];
    int edad;
    void (*print)();
    int (*compare)();
}Estudiante;

void estilizarArrayDeChars(char* array , int);

void validarEdad(int* edad);

/** \brief Crea y carga un nuevo elemento del tipo Estudiante.
 * \param Vacio (void).
 * \return Retorna un puntero al nuevo elemento (Estudiante*) u nulo (NULL) en caso de error (no se pudo reservar espacio en memoria).
 */
Estudiante* est_newEstudiante(void);

/** \brief Despliega una lista de los elementos del tipo Estudiante.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al elemento (void*).
 * \return Vacio (void).
 */
void est_printEstudiantes(ArrayList* , Estudiante*);

/** \brief Compuebra si el primer el nombre del primer parametro es mayor o menor al del segundo.
 * \param Un puntero al elemento (void*).
 * \param Un puntero al elemento (void*).
 * \return Retorna un entero (1) en caso de que el primer elemento sea menor al segundo o (0) en caso contrario.
 */
int est_compareEstudiantes(void* , void*);

#endif
