#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    int anio;
    int estado;
} eAuto;

void mostrarAutos(eAuto*, int);
void mostrarAuto(eAuto*);
eAuto* new_Auto();
eAuto* new_Auto_Param(char color, char marca, char modelo , int anio, int id);
void guardarAutos(eAuto*, int, char*);
int buscarLibre(eAuto*, int);
int cargarAutos(eAuto*, int, char*);
void inicializarAutos(eAuto*, int);
eAuto* newArrayAutos(int);

int main()
{
    eAuto* flota;
    eAuto* unAuto;
    int tam = 20;
    int cantidad;
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    char idCad[20];
    char anioCad[20];
    int anio;

    flota = newArrayAutos(tam);

    if(flota == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }


  cantidad = cargarAutos(flota, tam, "autos.cvs");

    printf("Se cargaron %d autos\n", cantidad);

    mostrarAutos(flota, tam);



    return 0;
}


void mostrarAuto(eAuto* unAuto)
{
    if(unAuto != NULL)
    {
        printf("%s %s %s  %d\n", unAuto->marca, unAuto->modelo, unAuto->color, unAuto->anio);
    }
}

void mostrarAutos(eAuto* autos, int tam)
{

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {

            if((autos+ i)->estado)
            {
                mostrarAuto(autos+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los autos\n");
    }

}

eAuto* new_Auto()
{

    eAuto* nuevoauto;

    nuevoauto = (eAuto*)malloc(sizeof(eAuto));
    if(nuevoauto != NULL)
    {
        nuevoauto->anio = 0;
        strcpy(nuevoauto->color, "");
        strcpy(nuevoauto->marca, "");
        strcpy(nuevoauto->modelo, "");
        nuevoauto->id = 0;
        nuevoauto->estado = 0;
    }
    return nuevoauto;

}



eAuto* new_Auto_Param(char color, char marca, char modelo , int anio, int id)
{

    eAuto* nuevoauto;

    nuevoauto = new_Auto();

    if(nuevoauto != NULL)
    {
        nuevoauto->anio = anio;
        strcpy(nuevoauto->color, color);
        strcpy(nuevoauto->marca, marca);
        strcpy(nuevoauto->modelo, modelo);
        nuevoauto->id = id;
        nuevoauto->estado = 1;
    }
    return nuevoauto;

}

void guardarAutos(eAuto* autos, int tam, char* path)
{

    FILE* f;

    f = fopen(path, "wb");

    if(f != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if( (autos + i)->estado)
            {
                fwrite( (autos+i), sizeof(eAuto), 1, f);
            }
        }
        fclose(f);
    }
}

int cargarAutos(eAuto* autos, int tam, char* path)
{
    FILE* f;
    int indice;
    eAuto autoAuxiliar;
    int cant;
    int total = 0;

    f = fopen(path, "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(f))
    {
        indice = buscarLibre(autos, tam);
        if(indice == -1)
        {
            printf("No hay mas lugar\n");
            break;
        }
        else
        {
            cant = fread(&autoAuxiliar, sizeof(eAuto), 1, f);

            if(cant != 1)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }

            *(autos+indice) = autoAuxiliar;
            total++;
            //indice = buscarLibre(autos, tam);

        }
    }
    fclose(f);
    return total;
}

int buscarLibre(eAuto* autos, int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((autos+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAutos(eAuto* autos, int tam)
{
    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            (autos+i)->estado = 0;
        }
    }
}

eAuto* newArrayAutos(int tam)
{
    eAuto* array;

    if(tam > 0)
    {
        array = (eAuto*) malloc(tam * sizeof(eAuto));

        if(array != NULL)
        {
            inicializarAutos(array, tam);
        }
    }
    return array;
}
