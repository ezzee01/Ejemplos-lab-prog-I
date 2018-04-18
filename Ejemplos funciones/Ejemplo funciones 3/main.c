#include <stdio.h>
#include <stdlib.h>

void sumar (int numero1, int numero2);

int main()
{
    int numeroA, numeroB, resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &numeroA);
    printf("Ingrese otro numero: ");
    scanf("%d", &numeroB);
    sumar(numeroA, numeroB);
    return 0;
}

void sumar(int numero1, int numero2)
{
    int retorno;
    retorno = numero1 + numero2;
    printf("La suma es: %d", retorno);
}
