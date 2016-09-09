#include "funciones.h"

/**brief Suma dos numeros flotantes
*
*\param Un numero flotante
*\param Un numero flotante
*\return Retorna el resultado de la suma de los dos numeros flotantes
*
*/
float calcularSuma (float n1,float n2)
{
    float suma;
    suma = n1+n2;
    return suma;
}

/**brief Resta dos numeros flotantes
*
*\param Un numero flotante
*\param Un numero flotante
*\return Retorna el resultado de la resta de los dos numeros flotantes
*
*/
float calcularResta (float n1,float n2)
{
    float resta;
    resta = n1-n2;
    return resta;
}

/**brief Divide dos numeros flotantes
*
*\param Un numero flotante
*\param Un numero flotante
*\return Retorna el resultado de la division de los dos numeros flotantes
*
*/
float calcularDivision (float n1,float n2)
{

    float division;
        if(n2==0)
     {
        division = printf("Error\n");
        return division;
     }
     division = n1/n2;
     return division;


}

/**brief Multiplica dos numeros flotantes
*
*\param Un numero flotante
*\param Un numero flotante
*\return Retorna el resultado de la multiplicacion de los dos numeros flotantes
*
*/
float calcularMultiplicacion (float n1,float n2)
{
    float multiplicacion;
    multiplicacion = n1*n2;
    return multiplicacion;
}

/**brief Efectua el factorial de un numero entero
*
*\param Un numero entero
*\return Retorna el factorial del numero entero
*
*/
int calcularFactorial (int n)
{
    int i,factorial=n,resultado=n;

    if (n==0)
    {
        return 1;
    }

    for(i=0 ; i<n-1 ; i++)
    {
        resultado = resultado*(factorial-1);
        factorial--;
    }

    return resultado;

}
