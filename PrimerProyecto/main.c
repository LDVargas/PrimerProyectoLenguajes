#include <stdio.h>

int main() {
    FILE *punteroArchivo = NULL;
    punteroArchivo = fopen("F:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt","r");

    if(punteroArchivo == NULL){
        printf("No se abrio el archivo");
        return -1;
    }

    fclose(punteroArchivo);
    return 0;
}
