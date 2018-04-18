#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5];

    for(int i = 0 ; i < 5 ; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }

    printf("Vector ingresado: ");

    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d, ", vector[i]);
    }

    printf("\n\n");

    for(int i = 0 ; i < 5 ; i++)
    {
        vector[i] = vector[i] * 2;
    }

    printf("Vector modificado al doble: ");

    for(int i=0;i<5;i++)
    {
        printf("%d, ", vector[i]);
    }

    return 0;
}
