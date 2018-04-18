#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define tam 5;

void mostrarEmpleados(char[][20], int [], char[], float[], int);
void mostrarEmpleado();
void ordenarEmpleados(char[][20], int [], char[], float[], int);


int main()
{
    char nombres[5][20];
    int legajos[5];
    char sexos[5];
    float sueldos[5];

    for(int i=0; i<5; i++)
    {
        printf("Ingrese nombre del empleado: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese legajo del empleado: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese sexo del empleado: ");
        fflush(stdin);
        scanf("%s", &sexos[i]);

        printf("Ingrese sueldo del empleado: ");
        scanf("%f", &sueldos[i]);

        system("cls");
    }

    mostrarEmpleados(nombres, legajos, sexos, sueldos, 5);

    return 0;
}

void mostrarEmpleados(char nomb[][20], int leg[], char sex[], float suel[], int tam)
{
    printf("Lista de empleados.\n\n");
    for(int i = 0; i < tam; i++)
    {
        printf("%s    %d    %c    %.2f\n", nomb[i], leg[i], sex[i], suel[i]);
    }
}
