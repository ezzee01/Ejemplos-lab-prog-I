#include <stdio.h>
#include <stdlib.h>

void funcion1(int[], int); //Recibe array como vector y accede a los datos usando notacion vectorial
void funcion2(int[], int); //Recibe array como vector y accede a los datos usando aritmetica de punteros
void funcion3(int*, int); //Recibe el array como puntero y accede a los datos usando notacion vectorial
void funcion4(int*, int); //Recibe array como puntero y accede a los datos usando aritmetica de punteros



int main()
{
    int numero[] = {2,1,5,4,8};

    funcion1(numero,5);
    printf("\n");
    funcion2(numero,5);
    printf("\n");
    funcion3(&numero[0] , 5);
    printf("\n");
    funcion4(&numero[0],5);

    return 0;
}

void funcion1(int vec[], int tam)
{
    for(int i = 0 ; i < tam ; i++)
    {
        printf("%d, ", vec[i]);
    }
}

void funcion2(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%d, ", *(vec +i));
    }
}

void funcion3(int* p, int tam)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d, ", p[i]);
    }
}

void funcion4(int* p, int tam)
{
    for(int i = 0 ; i < tam ; i++)
    {
        printf("%d, ", *(p +i));
    }
}
