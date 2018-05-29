#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* auxVec;

    vector = (int*) malloc(sizeof(int) * 5); //para cinco elementos

    if(vector == NULL)
    {
        printf("No se pudo asignar memoria\n");
        exit(1); //saca del programa
    }

    for(int i = 0 ; i < 5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vector + i);
    }

    for(int i = 0 ; i < 5; i++)
    {
        printf("%d ", *(vector + i));
    }

    printf("\n\n");

    auxVec = (int*) realloc(vector , 10*sizeof(int)); //Reasigna mas espacio al vector en un auxiliar para no perder direccion de memoria anterior

    if(auxVec != NULL)
    {
        vector = auxVec;
        printf("Se agrando el array con exito.\n");
    }
    else
    {
        printf("No se puede agrandar el array.\n");
    }

    for(int i = 5 ; i < 10; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vector + i);
    }

    for(int i = 0 ; i < 10; i++)
    {
        printf("%d ", *(vector + i));
    }

    printf("\n\n");

    vector = (int*) realloc(vector, 6* sizeof(int)); //Recorta el array

    printf("Achico el array a 6 elementos\n");

    for(int i = 0 ; i < 10; i++)
    {
        printf("%d ", *(vector + i));
    }

    printf("\n\n");

    return 0;
}
