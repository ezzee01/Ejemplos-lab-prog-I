#include <stdio.h>
#include <stdlib.h>

void sumar ();

int main()
{
    sumar();
    return 0;
}

void sumar()
{
    int retorno, numero1, numero2;
    printf("Ingrese un numero: ");
    scanf("%d", &numero1);
    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);
    retorno = numero1 + numero2;
    printf("La suma es: %d", retorno);
}
