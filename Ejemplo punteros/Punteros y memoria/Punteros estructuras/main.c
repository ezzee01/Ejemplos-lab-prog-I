#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;

    x = (int*) malloc(sizeof(int)); //asigna y castea direccion de memoria memoria

    if(x == NULL)
    {
        printf("No se pudo asignar memoria\n");
        exit(1); //saca del programa
    }

    printf("Ingrese un numero: ");
    scanf("%d", x);

    printf("El numero ingresado es %d\n", *x);

    free(x);  //libera espacios de memoria

    return 0;
}
