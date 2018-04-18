#include <stdio.h>
#include <stdlib.h>

int sumar ();

int main()
{
    int resultado;
    resultado = sumar();
    printf("La suma es: %d", resultado);
    return 0;
}

int sumar()
{
    int retorno, numero1, numero2;
    printf("Ingrese un numero: ");
    scanf("%d", &numero1);
    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);
    retorno = numero1 + numero2;
    return retorno;
}
