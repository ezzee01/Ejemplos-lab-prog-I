#include <stdio.h>
#include <stdlib.h>
//#define PATH "C:\\data\\miArchivo.txt"

int main()
{
    FILE* pArchivo;
    char cadena[100];
    char cadena2[] = "Otro texto";

    //pArchivo = fopen(PATH,"w");
    pArchivo = fopen("miArchivo.txt","w"); //ABRE O GUARDA EL ARCHIVO EN LA RAIZ, MODO 'a' concatena, MODO  'w' reemplaza

    if(pArchivo != NULL)
    {
        fprintf(pArchivo, "Hola\n");
        fprintf(pArchivo, "Aca con mascara: %s -- %s\n",cadena2,"15");
        fclose(pArchivo); //CIERRA ARCHIVO
    }
    else
    {
        printf("Imposible guardar en archivo");
    }

    pArchivo = fopen("miArchivo.txt","r");
    if(pArchivo != NULL)
    {
        fgets(cadena,100,pArchivo); //LEE LA PRIMER LINEA
        fclose(pArchivo);

        /*while(feof(pArchivo))
        {
            fgets(cadena,100,pArchivo);
            fclose(pArchivo);
        }*/

        puts(cadena);

    }

    return 0;
}
