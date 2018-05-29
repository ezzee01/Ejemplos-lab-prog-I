#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;

}eEmpleado;

void empleadoSetLegajo(eEmpleado* empleado, int legajo);
int empleadoGetLegajo(eEmpleado* empleado);

int main()
{
    eEmpleado* unEmpleado;

    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (unEmpleado == NULL)
    {
        printf("No se pudo asignar memoria\n");
        exit(1); //saca del programa
    }

    unEmpleado ->legajo = 1234;
    strcpy(unEmpleado->nombre, "juan");
    unEmpleado->sueldo = 20000;
    unEmpleado->estado = 1;

    printf("%d  %s  %.2f  \n\n", unEmpleado ->legajo , unEmpleado->nombre, unEmpleado->sueldo);

    free(unEmpleado);

    return 0;
}

void empleadoSetLegajo(eEmpleado* empleado, int legajo) // SET  Carga y valida
{
    if(empleado != NULL && legajo > 0)
    {
        empleado->legajo = legajo;
    }
}

int empleadoGetLegajo(eEmpleado* empleado)  //GET Lee datos
{
    int legajo = -1;
    if(empleado != NULL)
    {
        legajo = empleado->legajo;
    }

    return legajo;
}
