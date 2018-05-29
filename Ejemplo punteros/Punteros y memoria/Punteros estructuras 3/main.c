#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* auxVec;

    vector = (int*) calloc(5, sizeof(int)); //para cinco elementos, inicializa todos los elementos en cero

    if(vector == NULL)
    {
        printf("No se pudo asignar memoria\n");
        exit(1); //saca del programa
    }

    for(int i = 0 ; i < 5; i++)
    {
        printf("%d ", *(vector + i));
    }

    printf("\n\n");


    return 0;
}
