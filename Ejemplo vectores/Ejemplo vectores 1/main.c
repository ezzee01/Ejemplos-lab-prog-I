#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];

    for(int i=0;i<5;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &numeros[i]);
    }

    printf("Los numeros ingresados son: ");

    for(int j=0;j<5;j++)
    {
        printf("%d, ", numeros[j]);
    }
    return 0;
}
