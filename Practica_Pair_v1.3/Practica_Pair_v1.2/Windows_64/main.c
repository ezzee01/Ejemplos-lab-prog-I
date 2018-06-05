#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados;
    listaEmpleados = al_newArrayList();
    Employee* miEmpleado;
    Employee* aux;

    miEmpleado = (Employee*) malloc(sizeof(Employee));
    otroEmpleado = (Employee*) malloc(sizeof(Employee));

    miEmpleado->id = 8;
    strcpy(miEmpleado->name, "juan");
    miEmpleado->isEmpty = 1;
    strcpy(miEmpleado->lastName, "gomez");

    otroEmpleado->id = 9;
    strcpy(otroEmpleado->name, "ana");
    otroEmpleado->isEmpty = 1;
    strcpy(otroEmpleado->lastName, "gomez");

    al_add(listaEmpleados, miEmpleado);
    al_add(listaEmpleados,otroEmpleado);

    for(int i=0; i<(al_len(listaEmpleados)); i++)
    {
        aux =(Employee*) al_get(listaEmpleados, i);

        printf("%d--%s\n", aux->id,aux->name);
    }

    printf("ordenado: \n");

    al_sort(listaEmpleados,employee_compare(),1);

    for(int i=0; i<al_len(listaEmpleados);i++)
    {

    }

    return 0;
}
