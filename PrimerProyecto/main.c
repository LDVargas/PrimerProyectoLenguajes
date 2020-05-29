#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void sacarNumeros(char direccionArchivo[]);
char* escogerOperadora(char telefono[]);
void insertarNumero(char* num, char* operadora);
void imprimirTelefonos();

struct numeroTelefonico{
    char* num;
    char* operadora;
};

struct nodoNumeros{
    struct numeroTelefonico num;
    struct nodoNumeros* sig;
}*cabeza = NULL;


void insertarNumero(char* num, char* operadora){
    struct nodoNumeros* nuevoNumero;
    nuevoNumero = (struct nodoNumeros*) malloc(sizeof(struct nodoNumeros));
    char* temp = (char*)malloc(1);
    strcpy(temp,num);


    nuevoNumero->num.num = temp;
    nuevoNumero->num.operadora = operadora;
    nuevoNumero->sig = NULL;


    if(cabeza== NULL){
        cabeza = nuevoNumero;
    }
    else{
        nuevoNumero->sig = cabeza;
        cabeza = nuevoNumero;
    }
}

char* escogerOperadora(char telefono[]){
    int cont = 0;
    while(cont<8){
        if(telefono[cont] == '2'){
            return "Residencial";
        }
        else if (telefono[cont] == '8'){
            return "Kolbi";
        }
        else if (telefono[cont] == '7'){
            return "Movistar";
        }
        else if (telefono[cont] == '6'){
            if(cont==0 | cont == 4 | cont==5 | cont==6 | cont==7){
                return "Claro";
            }
        }
        cont++;
    }
    return "Desconocido";
}

void imprimirTelefonos(){
    struct nodoNumeros* actual = cabeza;
    printf("************Lista de numeros************\n");

    if(actual == NULL){
        printf("Lista Vacia");
    }
    else{
        while (actual!= NULL){
            printf("Numero: %s     Operadora: %s\n", actual->num.num, actual->num.operadora);
            printf("\n");
            actual = actual->sig;
        }

    }
}


int main() {
    char  direccion[1000] = "E:/Universidad/Semestre11/Lenguajes/Proyectos/PrimerProyect/PrimerProyectoLenguajes/archivo.txt";

    char direccionArchivo[1000];
    //*direccionArchivo = '\0';


    printf("Ingrese la direccion del archivo (Unicamente con un backslash / y sin espacios): ");
    scanf("%s", direccionArchivo);

    printf("%s",direccionArchivo);

    // /////////////////////////////////////////////////////////////////////////////////////////////

    FILE *punteroArchivo = NULL;
    punteroArchivo = fopen(direccionArchivo,"r");

    if(punteroArchivo == NULL){
        printf("Formato erroneo, reintente otra vez\n");
        main();
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
                insertarNumero(numTelefonico,escogerOperadora(numTelefonico));
                cont = 0;
                //printf("EL numero encontrado es %s \n", numTelefonico);
                *numTelefonico = '\0';

            }


        }

    }

    //printf("prueba");
    //regfree(&regCompiled);
    fclose(punteroArchivo);

    //printf("\n esto es despues del fget \n");

    //sacarNumeros(direccion);
    insertarNumero("86151925","Kolbi");
    imprimirTelefonos();
    return 0;
}