#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void sacarNumeros(char direccionArchivo[]);

struct numeroTelefonico{
    char* num;
    char* operadora;
};

struct nodoNumeros{
    struct numeroTelefonico;
    struct nodoNumeros *sig;
}*cabeza = NULL;




void sacarNumeros(char direccionArchivo[]){
    FILE *punteroArchivo = NULL;
    punteroArchivo = fopen(direccionArchivo,"r");

    if(punteroArchivo == NULL){
        printf("No se abrio el archivo");
    }
    else{
        printf("Se abrio el archivo");
    }

    char caracter;
    int contador = 0;

    while (feof(punteroArchivo)==0){
        caracter = fgetc(punteroArchivo);
        if(caracter!= EOF){
            contador++;
        }
    }
    rewind(punteroArchivo);

    char* prueba = (char*)malloc(1);


    //prueba de regex
    const int matches = contador;
    regex_t regCompiled;
    regmatch_t nMatches[matches];
    const char* patronRegex = "[\\(]?[\\+]?(\\d{3})[\\)]?[\\s]?((\\d{6}|\\d{8})|(\\d{3}[\\*\\.\\-\\s]){3}|(\\d{2}[\\*\\.\\-\\s]){4}|(\\d{4}[\\*\\.\\-\\s]){2})|\\d{8}|\\d{4}-\\d{4}|\\d{2}-\\d{2}-\\d{2}-\\d{2}|[\\+]?\\d{3} \\d{8}";


    if(regcomp(&regCompiled,patronRegex,REG_EXTENDED)){
        printf("No se compilo la expresion regular\n");
        exit(1);
    }


    int cont = 0;
    int i = 0;
    char* numTelefonico = (char*) malloc(1);
    *numTelefonico = '\0';
    //punteroArchivo->_cnt=0;
    while (fgets(prueba,contador-1,punteroArchivo)){
        int noMatch = regexec(&regCompiled, prueba, matches, nMatches, 0);
        if(noMatch == 0){
            for (i = 0; i<contador;i++){
                cont = nMatches[i].rm_so;
                if(nMatches[i].rm_so == -1){
                    break;
                } else{
                    strcat(numTelefonico,&prueba[cont]);
                }
                cont = 0;
                printf("EL numero encontrado es %s \n", numTelefonico);
                *numTelefonico = '\0';

            }


        }

    }

    printf("prueba");
    //regfree(&regCompiled);
    fclose(punteroArchivo);


    printf("\n esto es despues del fget \n");


}


int main() {
    char  direccion[1000] = "E:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo2.txt";
    sacarNumeros(direccion);
    //pruebaRegex();
    return 0;
}