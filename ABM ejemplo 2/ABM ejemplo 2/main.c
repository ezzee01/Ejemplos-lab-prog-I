#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct
{
    int id;
    char descripcion[20];
}eMateria;

typedef struct
{
    int legAlumno;
    int idMateria;
}eInscripcion;

void mostrarAlumnosConMaterias(eAlumno[], int, eMateria[], int, eInscripcion[], int );
void materiaConCantInscriptos(eMateria[], int, eInscripcion[], int);
void materiasMasCursadas(eMateria[], int, eInscripcion[],int);

void nombreAlumnosPorMateria(eAlumno[], int, eMateria[], int, eInscripcion[], int );

int main()
{
    system("cls");
    eAlumno alumnos[] = {{1,"Juan"}, {2,"Ana"}, {3, "Pedro"}, {4, "Jose"}};
    eMateria materias[] = {{10, "Matematica"}, {11, "Programacion"}, {12, "Laboratorio"}, {13, "SPD"}, {14, "Ingles"}};
    eInscripcion inscripciones[] = {{1,11}, {1, 12}, {1, 13}, {2, 14}, {2, 11}, {2, 12}, {3, 10}, {4, 10}, {4, 11}, {4, 12}, {4, 13}, {4, 14}};

    mostrarAlumnosConMaterias(alumnos, 4, materias, 5, inscripciones, 12);
    materiaConCantInscriptos(materias, 5, inscripciones, 12);

    system("pause");
    return 0;
}

void mostrarAlumnosConMaterias(eAlumno alum[], int tamAlum, eMateria mat[], int tamMat, eInscripcion insc[], int tamInsc)
{
    system("cls");
    for (int i = 0; i < tamAlum; i++)
    {
        printf("\n%s\n", alum[i].nombre);
        printf("----------\n");
        for(int j = 0; j < tamInsc; j++)
        {
            if(alum[i].legajo == insc[j].legAlumno)
            {
                for(int k = 0; k < tamMat; k++)
                {
                    if(insc[j].idMateria == mat[k].id)
                    {
                        printf("\n%s\n", mat[k].descripcion);
                    }
                }
            }
        }
    }
    printf("\n");
}

void materiaConCantInscriptos(eMateria mat[], int tamMat, eInscripcion insc[], int tamInsc)
{
    int contador = 0;
    printf("\nCantidad de inscripciones por materia.\n");
    printf("-----------------------------------------------\n");

    for(int i = 0; i < tamMat; i++)
    {
        printf("\n%s: ", mat[i].descripcion);

        for(int j = 0; j < tamInsc; j++)
        {
            if(mat[i].id == insc[j].idMateria)
            {
                contador++;
            }
        }
        printf("%d inscriptos.\n", contador);
    }
}
