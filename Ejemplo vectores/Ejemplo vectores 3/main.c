#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mostrarVector(int [], int);
int buscarMaximo(int [], int);
int buscarMinimo(int [], int);
int buscarElemento(int [], int, int);
void ordenarVector(int vec[], int tam);

int main()
{
    int vector[6] = {4,5,6,8,6,1};
    mostrarVector(vector, 6);
    /*printf("\n%d\n", buscarMaximo(vector, 6));
    printf("\n%d\n", buscarMinimo(vector, 6));
    printf("\nEsta en la posicion %d\n", buscarElemento(vector, 6, 4));
    */

    printf("\n\n");

    ordenarVector(vector, 6);

    getch();
    return 0;
}

void mostrarVector(int vector[], int tam)
{
    for(int i = 0 ; i < tam ; i++)
    {
        printf("%d ", vector[i]);
    }
}

int buscarMaximo(int vec[], int tam)
{
    int max, flag=0;

    for(int i=0; i<tam; i++)
    {
        if(max < vec[i] || flag ==0)
        {
            max = vec[i];
            flag = 1;
        }
    }
    return max;
}

int buscarMinimo(int vec[], int tam)
{
    int min, flag=0;

    for(int i=0; i<tam; i++)
    {
        if(min > vec[i] || flag ==0)
        {
            min = vec[i];
            flag = 1;
        }
    }
    return min;
}

int buscarElemento(int vec[], int tam, int numero)
{
    int elemento = -1;
    for(int i = 0 ; i< tam; i++)
    {
        if(vec[i] == numero)
        {
            elemento = i;
            break;
        }
    }

    return elemento;
}

void ordenarVector(int vec[], int tam)
{
    int aux;
    for(int i = 0 ; i < tam - 1 ; i++)
    {
        for(int j = i+1 ; j < tam ; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }

    for(int i = 0 ; i < tam ; i++)
    {
        printf("%d ", vec[i]);
    }
}
