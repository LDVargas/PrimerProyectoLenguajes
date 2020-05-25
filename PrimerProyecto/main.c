#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void pruebaRegex(const char* source);
void sacarNumeros(char direccionArchivo[]);

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


    char x;

    char* prueba = (char*)malloc(1);
    char* prueba2=punteroArchivo->_base;

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
    //punteroArchivo->_cnt=0;
    while (fgets(prueba,contador-1,punteroArchivo)){
        int noMatch = regexec(&regCompiled, prueba, matches, nMatches, 0);
        if(noMatch == 0){
            for (i = 0; i<contador;i++){
                cont = nMatches[i].rm_so;
                if(cont!=-1){
                    while (cont<=nMatches[i].rm_eo -1){
                        strcat(numTelefonico,&prueba[cont]);
                        cont++;
                    }
                } else{
                    break;
                }
                cont = 0;
                printf("EL numero encontrado es %s \n", numTelefonico);
                numTelefonico="";

            }

            //printf("\nencontro numero\n");
            //printf("\n encuentra coincidencia %d - %d", nMatches[contador].rm_eo, nMatches[contador].rm_so);
            cont++;
        }

    }

    printf("prueba");
    fclose(punteroArchivo);
    regfree(&regCompiled);

    printf("\n esto es despues del fget \n");
    //printf("despues de fget %s \n",prueba2);
    //pruebaRegex(prueba2);

}

void pruebaRegex(const char* source) {
    const char* p = source;
    const int matches = 10;
    regex_t regCompiled;
    regmatch_t nMatches[matches];
    const char* patronRegex = "([2])?[0-9]{7}";


    if(regcomp(&regCompiled,patronRegex,REG_EXTENDED)){
        printf("No se compilo la expresion regular\n");
        exit(1);
    }

    const char* intento = "25502448";


    while (1){
        int i = 0;
        int noMatch = regexec(&regCompiled,p,matches,nMatches,0);
        if (noMatch!=0){
            printf("No hay numeros. \n");
            break;
        }

        for (i=0;i<matches;i++){
            int start;
            int finish;
            if (nMatches[i].rm_so == -1){
                break;
            }
            start = nMatches[i].rm_so + (p-source);
            finish = nMatches[i].rm_eo + (p-source);
            if(i==0){
                printf("$& is ");
            }
            else{
                printf("'%.*s' (bytes %d:%d)\n",(finish-start), source + start, start,finish);
            }
            p += nMatches[0].rm_eo;
        }
    }
    regfree(&regCompiled);



    /*char* patronRegex = "([2])?[0-9]{7}";
    size_t maxMatches = 2;
    size_t maxGroups = 3;

    regex_t regCompiled;
    regmatch_t groupArray[maxGroups];//regamatch_t groupArray[maxGroups];
    unsigned int m;
    char* cursor;
    cursor =(char*) malloc(1);

    if(regcomp(&regCompiled,patronRegex,0)){
        printf("No se compilo la expresion regular\n");
        exit(1);
    }

    strcpy(cursor,source);
    m=0;

    for (m = 0; m < maxMatches; m++) {
        if (regexec(&regCompiled, cursor, maxGroups, groupArray, 0))
            break;
        unsigned int g=0;
        unsigned int offset=0;
        for (g=0;g<maxGroups;g++){
            if(groupArray[g].rm_so == (size_t)-1)
                break;


            if(g==0)
                offset = groupArray[g].rm_eo;

            char cursorCopy[strlen(cursor)+1];
            strcpy(cursorCopy,cursor);
            cursorCopy[groupArray[g].rm_eo]=0;

        }
        cursor+=offset;
    }
    regfree(&regCompiled);*/

}


int main() {
    //system("cls");
    char  direccion[1000] = "E:/Universidad/Semestre 11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt";
    sacarNumeros(direccion);
    //pruebaRegex();
    return 0;
}