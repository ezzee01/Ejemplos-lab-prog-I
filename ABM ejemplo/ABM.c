#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "ABM.h"

//MENU--------------------------------------------------------------------------

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
    printf("6_Salir\n");
    printf("7_Total sueldos\n");
    printf("8_Empleados que mas ganan\n\n");

    printf("Opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 6)
    {
        printf("Error. Reingrese: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

//INICIALIZACION--------------------------------------------------------------------------

void inicializarEmpleados(eEmpleados vec[], int tamanio)
{
    for(int i = 0; i < tamanio ; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//ALTA--------------------------------------------------------------------------

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
            system("cls");
            printf("El empleado ya esta en el sistema.\n");

            mostrarEmpleado(vec, esta);

            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);

            printf("Ingrese sexo: ");
            auxEmpleado.sexo = tolower(getche());
            printf("\n");
            while(auxEmpleado.sexo != 'f' && auxEmpleado.sexo != 'm')
            {
                printf("Error. Reingrese: ");
                auxEmpleado.sexo = tolower(getche());
                printf("\n");
            }

            printf("Ingrese fecha de ingreso: ");
            scanf("%d %d %d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

            printf("Ingrese sueldo: ");
            scanf("%f", &auxEmpleado.sueldo);

            vec[lugar] = auxEmpleado;

            printf("\nAlta exitosa.\n");
        }
    }
}

//BUSCAR LUGAR LIBRE--------------------------------------------------------------------------

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

//BUSCAR EMPLEADO--------------------------------------------------------------------------

int buscarEmpleado(eEmpleados vec[], int tamanio, int legajo)
{
    int indice = -1;
    for(int i = 0 ; i < tamanio ; i++)
    {
        if(vec[i].legajo == legajo && vec[i].isEmpty != 1)
        {
            indice = i;
            return indice;
            break;
        }
        else return indice;
    }
}

//BAJA--------------------------------------------------------------------------

void bajaEmpleado(eEmpleados vec[], int tamanio)
{
    int esta;
    eEmpleados auxEmpleado;
    char confirm;

    system("cls");

    printf("Ingrese legajo: ");
    scanf("%d", &auxEmpleado.legajo);
    esta = buscarEmpleado(vec, tamanio, auxEmpleado.legajo);

    if(esta != -1)
    {
        mostrarEmpleado(vec, esta);

        printf("Confirma la baja?(S/N): ");
        //scanf("%c", &confirm);
        confirm = tolower(getche());
        while(confirm != 's' && confirm != 'n')
        {
            printf("Error. Reingrese: ");
            //scanf("%c", &confirm);
            confirm = tolower(getche());
        }
        if(confirm == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nBaja realizada.\n");
            system("pause");
        }
        else
        {
            printf("\nSe cancelo la baja.\n");
            system("pause");
        }
    }
    else
    {
        printf("El empleado no existe.\n");
        system("pause");
    }

}

//MODIFICACION--------------------------------------------------------------------------

void modEmpleado(eEmpleados vec[], int tamanio)
{
    int esta;
    eEmpleados auxEmpleado;
    char confirm;

    system("cls");

    printf("Ingrese legajo: ");
    scanf("%d", &auxEmpleado.legajo);
    esta = buscarEmpleado(vec, tamanio, auxEmpleado.legajo);

    if(esta != -1)
    {
        mostrarEmpleado(vec, esta);

        printf("Ingrese nuevo sueldo: ");
        scanf("%f", &auxEmpleado.sueldo);

        printf("Confirma la modificacion?(S/N): ");
        //scanf("%c", &confirm);
        confirm = tolower(getche());
        printf("\n");
        while(confirm != 's' && confirm != 'n')
        {
            printf("\nError. Reingrese: ");
            //scanf("%c", &confirm);
            confirm = tolower(getche());
            printf("\n");
        }
        if(confirm == 's')
        {
            vec[esta].sueldo = auxEmpleado.sueldo;
            printf("\nModificacion realizada.\n");
            system("pause");
        }
        else
        {
            printf("\nSe cancelo la modificacion.\n");
            system("pause");
        }
    }
    else
    {
        printf("El empleado no existe.\n");
        system("pause");
    }
}

//LISTAR--------------------------------------------------------------------------

void listar(eEmpleados vec[], int tamanio)
{
    system("cls");
    printf("Legajo          Nombre  Sexo    Fecha de Ingreso    Sueldo\n");

    for (int i = 0 ; i < tamanio; i++)
    {
        if(vec[i].isEmpty != 1)
        {
            printf("%4d      %10s    %c       %02d/%02d/%4d        %10.2f\n",vec[i].legajo, vec[i].nombre, vec[i].sexo, vec[i].fechaIngreso.dia, vec[i].fechaIngreso.mes, vec[i].fechaIngreso.anio, vec[i].sueldo);
        }
    }
    system("pause");
}

//MOSTRAR EMPLEADO--------------------------------------------------------------------------

void mostrarEmpleado(eEmpleados vec[], int indice)
{
    system("cls");
    printf("Legajo          Nombre  Sexo    Fecha de Ingreso    Sueldo\n");
    printf("%4d      %10s    %c       %02d/%02d/%4d        %10.2f\n",vec[indice].legajo, vec[indice].nombre, vec[indice].sexo, vec[indice].fechaIngreso.dia, vec[indice].fechaIngreso.mes, vec[indice].fechaIngreso.anio, vec[indice].sueldo);
    system("pause");
}

//SALIR--------------------------------------------------------------------------

int salirF(void)
{
    int sal = 1;

    return sal;
}


