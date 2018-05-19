#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    eTipo tipo;
}eMascota;

void modificarEdad(eMascota*,int);
void mostrarMascotas(eMascota* vec , int tam);

int main()
{
    eMascota unaMascota;
    eMascota grupo[5]={{11, "Felipe",6,{1, "gato"},1}, {22,"Flor",5,{2,"perro"},2}, {33, "Cami",2,{3,"ave"},3}};
    unaMascota.edad = 5;
    unaMascota.id = 1234;
    strcpy(unaMascota.nombre,"Felipe");

    modificarEdad(&unaMascota, 2);

    printf("%d  %s  %d  %s\n\n", unaMascota.id, unaMascota.nombre, unaMascota.edad, unaMascota.tipo.descripcion);

    return 0;
}

void modificarEdad(eMascota* masc,int edad)
{
    masc->edad = edad;
    strcpy(masc->tipo.descripcion, "perro");
}

void mostrarMascotas(eMascota* vec1 , int tam)
{

}

void mostrarMascotas(eMascota* mascota)
{
    printf("%d  %s  %d  %s\n\n",mascota->id, vec->nombre, vec->edad, vec->tipo.descripcion);
}
