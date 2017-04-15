#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char apellido[26] , nombre[26];
    int edad;
    int estado;
    int dni;
}EPersona;

/**Pasa a minuscula todas las letras de un array de chars. La primer letra del array y cada letra despues de un espacio las pasa a mayuscula
\* Param Un array de chars
\* Param Un entero
\* Return Un array de chars*/
void estilizarArrayDeChars(char[] , int);

/** Carga los campos de la estructura EPersona con valores que se le piden al usuario
\* Param Un array del tipo EPersona
\* Param Un entero
\* Return No retorna nada (void)*/
void alta(EPersona[] , int);

int buscarPorIdentificardorUnivoco (EPersona [], int);

/** Verifica una igualdad entre un valor que ingrese el usuario y el identificador univoco de la estructura EPersona (DNI)
\* Param Param Un array del tipo EPersona
\* Param Param Un entero
\* Return No retorna nada (void)*/
void baja(EPersona[] , int);

/** Muestra los elementos del array del tipo EPersona
\* Param Param Un array del tipo EPersona
\* Param Param Un entero
\* Return No retorna nada (void)*/
void mostrar(EPersona[] , int);

/** Ordena los elementos del array del tipo EPersona por orden alfabetico ascendente con los valores almacenados en el campo apellido empleando el metodo de burbujeo
\* Param Param Un array del tipo EPersona
\* Param Param Un entero
\* Return No retorna nada (void)*/
void ordenamiento(EPersona [], int);

/** Muesra en pantalla un grafico tomando como referencia el campo edad del array de tipo EPersona
\* Param Param Un array del tipo EPersona
\* Param Param Param Un entero
\* Return No retorna nada (void)*/
void imprimirGrafico(EPersona [], int);

#endif
