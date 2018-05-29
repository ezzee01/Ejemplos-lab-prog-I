#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;

}eEmpleado;

eEmpleado* new_Empleado();
eEmpleado* new_Empleado_Param(int, char*,float);
void mostrarEmpleados(eEmpleado*, int);
void mostrarEmpleado(eEmpleado*);
eEmpleado* newArrayEmpleados(int);
void inicializarEmpleados(eEmpleado* , int);
void guardarEmpleados(eEmpleado*, int, char*);
int buscarLibre(eEmpleado*, int);
int cargarEmpleados(eEmpleado*, int, char*);


int main()
{
    eEmpleado* personal;
    eEmpleado* unEmpleado;
    int cantidad;

    personal = newArrayEmpleados(TAM);

    if(personal == NULL)
    {
        printf("No se pudo cojnseguir memoria\n");
        exit(1);
    }

    unEmpleado = new_Empleado_Param(123,"Juan", 20000);

    *personal = *unEmpleado;  //Guarda el contenido en la primera posicion de mem

    unEmpleado = new_Empleado_Param(456,"ana",25000);

    *(personal +1) = *unEmpleado;

    unEmpleado = new_Empleado_Param(789,"jose",15000);

    *(personal +2) = *unEmpleado;

    mostrarEmpleados(personal,TAM);
    guardarEmpleados(personal, TAM, "listaEmpleados.bin");



    return 0;
}

//FUNCIONES

eEmpleado* new_Empleado()
{
    eEmpleado* nuevoEmpleado;
    nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado ->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->estado = 0;
    }
    return nuevoEmpleado;
}

eEmpleado* new_Empleado_Param(int legajo, char* nombre,float sueldo)
{
    eEmpleado* nuevoEmpleado;
    nuevoEmpleado = new_Empleado();

    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado ->legajo = legajo;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->estado = 1;
    }
    return nuevoEmpleado;
}

void mostrarEmpleados(eEmpleado* empleados, int tam)
{
    if(empleados != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(empleados->estado)
            {
                mostrarEmpleado(empleados +i);
            }
        }
    }
    else
    {
        printf("No se puede mostrar los empleados \n");
    }
}

void mostrarEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("%d  %s  %.2f  \n\n", empleado ->legajo , empleado->nombre, empleado->sueldo);
    }
}

eEmpleado* newArrayEmpleados(int tam)
{
    eEmpleado* array;

    if(tam > 0)
    {
        array = (eEmpleado*) malloc(tam * sizeof(eEmpleado));
        if(array != NULL)
        {
            inicializarEmpleados(array, tam);
        }
    }
    return array;
}

void inicializarEmpleados(eEmpleado* empleados , int tam)
{
    if(empleados != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            (empleados + i)->estado = 0;
        }
    }
}

int buscarLibre(eEmpleado* empleado, int tam)
{
    int indice = -1;
    if(empleado != NULL)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if(empleado->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void guardarEmpleados(eEmpleado* empleados, int tam, char* path)
{
    FILE* f;

    f= fopen(path, "vb"); //guarda todo el array en el fichero

    if(f != NULL)
    {
        for(int i = 0; i< tam ; i++)
        {
            if((empleados+i)->estado)
            {
                fwrite((empleados+i), sizeof(eEmpleado), i, f);
            }
        }
    }
}

int cargarEmpleados(eEmpleado* empleados, int tam, char* path)
{
}
