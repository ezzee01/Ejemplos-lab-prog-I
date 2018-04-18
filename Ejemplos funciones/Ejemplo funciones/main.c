#include <stdio.h>
#include <stdlib.h>

int sumarValor(int num);

int main()
{
    int numero;
    int numeroFinal;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    sumarValor(numero);
    numeroFinal = sumarValor(numero);
    printf("Numero incrementado: %d", numeroFinal);
    return 0;
}

int sumarValor(int num)
{
    int retorno;

    retorno = num + 5;

    return retorno;
}
