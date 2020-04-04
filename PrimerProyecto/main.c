#include <stdio.h>
#include <stdlib.h>

void sacarNumeros(char direccionArchivo[]){
    //printf("La direccion es [%s]\n: ", direccionArchivo);
    FILE *punteroArchivo = NULL;
    punteroArchivo = fopen(direccionArchivo,"r");
    //punteroArchivo = fopen("F:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt","r");

    if(punteroArchivo == NULL){
        printf("No se abrio el archivo");
    }
    else{
        printf("Se abrio el archivo");
    }

    char caracter;
    while (feof(punteroArchivo)==0){
        caracter = fgetc(punteroArchivo);
        printf("%c",caracter);
    }

    fclose(punteroArchivo);
}

int main() {
    char  direccion[100] = "F:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt";
    sacarNumeros(direccion);
    return 0;
}
