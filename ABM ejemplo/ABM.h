typedef struct
{
    char dia[10];
    char mes[10];
    char anio[10];
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;
    int idSector;
}eEmpleados;

typedef struct
{
    int id;
    char nombre[20];
}eSector;


int menu();
void inicializarEmpleados(eEmpleados[], int);
void altaEmpleado(eEmpleados[], int);
int buscarLibre(eEmpleados[], int);
int buscarEmpleado(eEmpleados[], int, int);
void bajaEmpleado(eEmpleados[], int);
void modEmpleado(eEmpleados[], int);
void listar(eEmpleados[], int);
void mostrarEmpleado(eEmpleados[], int);
int salirF(void);
