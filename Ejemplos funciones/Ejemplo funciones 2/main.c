#include <stdio.h>
#include <stdlib.h>

int sumar (int numero1, int numero2);

int main()
{
    int numeroA, numeroB, resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &numeroA);
    printf("Ingrese otro numero: ");
    scanf("%d", &numeroB);
    resultado = sumar(numeroA, numeroB);
    printf("La suma es: %d", resultado);

    return 0;
}

int sumar(int numero1, int numero2)
{
    int retorno;
    retorno = numero1 + numero2;

    return retorno;
}
