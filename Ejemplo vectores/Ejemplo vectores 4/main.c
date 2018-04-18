#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int notas1[] = {10, 7, 2, 2, 4};
    int notas2[] = {9, 5, 4, 7, 5};
    float promedio[5];

    for(int i = 0 ; i < 5 ; i++)
    {
        promedio[i] = (float) (notas1[i] + notas2[i]) / 2;

        printf("\n%d  %d  %.2f", notas1[i], notas2[i], promedio[i]);
    }

    getch();
    return 0;
}
