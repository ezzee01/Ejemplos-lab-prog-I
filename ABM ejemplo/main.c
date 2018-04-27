#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define TAM 50

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    eFecha fechaIngreso;
    int sueldo;
    int isEmpty;
}eEmpleados;

int menu();
void inicializarEmpleados(eEmpleados[], int);
void altaEmpleado(eEmpleados[], int);
int buscarLibre(eEmpleados[], int);
int buscarEmpleado(eEmpleados[], int, int);
void bajaEmpleado(eEmpleados[], int);

int main()
{
    int salir = 0;
    eEmpleados empleado[TAM];
    //Inicializacion de array
    inicializarEmpleados(empleado, TAM);

    do
    {
        switch(menu())
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        }
    }while(salir != 1);

    getche();
    return 0;
}

//FUNCIONES

int menu()
{
    int opcion;
    system("cls");
    printf("Seleccione una opcion: \n\n");
    printf("1_Alta\n");
    printf("2_Baja\n");
    printf("3_Modificacion\n");
    printf("4_Listar\n");
    printf("5_Ordenar\n");
    printf("6_Salir\n\n");

    printf("Opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 6)
    {
        printf("Error. Reingrese: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

void inicializarEmpleados(eEmpleados vec[], int tamanio)
{
    for(int i = 0; i < tamanio ; i++)
    {
        vec[i].isEmpty= 1;
    }
}

void altaEmpleado(eEmpleados vec[], int tamanio)
{
    int lugar;
    int esta;
    eEmpleados auxEmpleado;

    system("cls");

    lugar = buscarLibre(vec, tamanio);

    if(lugar != -1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &auxEmpleado.legajo);
        esta = buscarEmpleado(vec, tamanio, auxEmpleado.legajo);

        if(esta != -1)
        {
            printf("El empleado ya esta en el sistema");
            //mostrarempleado
        }
        else
        {
            printf("Ingrese nombre: ");
            gets(auxEmpleado.nombre);

            printf("Ingrese sexo: ");
            scanf("%c", &auxEmpleado.sexo);

            printf("Ingrese fecha de ingreso: ");
            scanf("%d%d%d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

            printf("Ingrese sueldo: ");
            scanf("%d", &auxEmpleado.sueldo);

            printf("Alta exitosa.");
        }
    }
}

int buscarLibre(eEmpleados vec[], int tamanio)
{
    int indice = -1;

    for (int i = 0 ; i < tamanio ; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            return indice;
            break;
        }
        else return indice;

    }
}

int buscarEmpleado(eEmpleados vec[], int tamanio, int legajo)
{
    int indice = -1;
    for(int i = 0 ; i < tamanio ; i++)
    {
        if(vec[i].legajo == legajo)
        {
            indice = i;
            return indice;
            break;
        }
        else return indice;
    }
}

void bajaEmpleado(eEmpleados vec[], int tam)
{
    int lugar;
    int esta;
    eEmpleados auxEmpleado;
    char confirm;

    system("cls");

    printf("Ingrese legajo: ");
    scanf("%d", &auxEmpleado.legajo);
    esta = buscarEmpleado(vec, tamanio, auxEmpleado.legajo);

    if(esta != -1)
    {
        //mostrarempleado
        printf("Confirma la baja?(S/N): ");
        scanf("%c", &confirm);
        confirm = tolower(confirm);
        while(confirm != 's' || confirm != 'n')
        {
            printf("Error. Reingrese: ");
            scanf("%c", &confirm);
            confirm = tolower(confirm);
        }
        if(confirm == 's')
        {
            vec[esta].isEmpty = 0;
            printf("Baja realizada");
        }
        else
        {
            printf("Se cancelo la baja.");
        }
    }
    else
    {
        printf("El empleado no existe.");
    }

}
