#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "ABM.h"

#define TAM 50

int main()
{
    int salir = 0;
    eEmpleados empleado[TAM];
    inicializarEmpleados(empleado, TAM);
    eSector sectores[] = {{1,"ventas"}, {2,"compras"}, {3,"comercial"}, {4,"RRHH"}, {5,"sistemas"}};

    do
    {
        switch(menu())
        {
        case 1: altaEmpleado(empleado, TAM);
        break;
        case 2: bajaEmpleado(empleado, TAM);
        break;
        case 3: modEmpleado(empleado, TAM);
        break;
        case 4: listar(empleado, TAM);
        break;
        //case 5:
        case 6: salir = salirF();
        break;
        //case 7:
        //case 8:
        }
    }while(salir != 1);

    system("pause");
    return 0;
}
