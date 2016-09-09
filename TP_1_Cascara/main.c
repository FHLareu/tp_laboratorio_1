#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    float numero1 = 0, numero2 = 0,resultado [5];

    do
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                printf("Ingrese el primer numero: ");
                scanf("%f",&numero1);
                break;

            case 2:
                printf("Ingrese el segundo numero: ");
                scanf("%f",&numero2);
                break;

            case 3:
                resultado [0] = calcularSuma (numero1,numero2);
                printf("El resultado de la suma es: %.2f\n",resultado [0]);
                system("pause");
                break;

            case 4:
                resultado [0] = calcularResta (numero1,numero2);
                printf("El resultado de la resta es: %.2f\n",resultado [0]);
                system("pause");
                break;

            case 5:

                resultado [0] = calcularDivision (numero1,numero2);
                if (numero2!=0)
                {
                    printf("El resultado de la division es: %.2f\n",resultado [0]);
                }

                system("pause");
                break;

            case 6:
                resultado [0] = calcularMultiplicacion (numero1,numero2);
                printf("El resultado de la multiplicacion es: %.2f\n",resultado [0]);
                system("pause");
                break;

            case 7:
                resultado [0] = calcularFactorial (numero1);
                printf("El factorial del numero %.2f es: %.2f\n",numero1,resultado [0]);
                system("pause");
                break;

            case 8:
                resultado [0] = calcularSuma (numero1,numero2);
                resultado [1] = calcularResta (numero1,numero2);
                resultado [2] = calcularDivision (numero1,numero2);
                resultado [3] = calcularMultiplicacion (numero1,numero2);
                resultado [4] = calcularFactorial (numero1);
                printf("El resultado de la suma es: %.2f\nEl resultado de la resta es: %.2f\nEl resultado de la multiplicacion es: %.2f\nEl factorial del numero %.2f es: %.2f\n",resultado [0],resultado [1],resultado [3],numero1,resultado [4]);
                if(numero2==0)
                {
                    printf("El resultado de la division es: Error\n");
                }
                else
                    printf("El resultado de la division es: %.2f\n",resultado [2]);
                system("pause");
                break;

            case 9:
                seguir = 'n';
                break;

            default:
                    printf("Error\n");
                system("pause");

        }

        system("cls");

 } while(seguir == 's');

return 0;

}
