#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

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
        if(caracter=='o'){
            printf("encontro la %c",caracter);
            break;
        }
        //printf("%c",caracter);
    }

    fclose(punteroArchivo);
}

void pruebaRegex() {
    regex_t intentoRegex;
    int prueba = regcomp(&intentoRegex, "^a[[:alnum:]]", 0);
    //printf("%i",prueba);
    char msgbuf[100];


    if (prueba){
        fprintf(stderr,"no compilo en intentoRegex\n");
        exit(1);
    }

    prueba = regexec(&intentoRegex, "abc",0,NULL,0);
    if(!prueba){
        puts("se encontro");
    } else{
        regerror(prueba,&intentoRegex,msgbuf, sizeof(msgbuf));
        fprintf(stderr, "regex fallo %s", msgbuf);
        exit(1);
    }
}

int main() {
    char  direccion[1000] = "E:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt";
    //sacarNumeros(direccion);
    pruebaRegex();
    return 0;
}
