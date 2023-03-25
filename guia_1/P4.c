//Leer por teclado 5 strings y mostrar el de mayor longitud

#include <stdio.h>

//constantes globales
#define CANTS 5              //cantidad de palabras a comparar
#define LENS 20              //longitud maxima de las palabras
//-----

//prototipos
int len(char*);
//-----

int main(){
    char palabras[CANTS][LENS];
    int len_palabra,i;
    int len_max=0,orden_max=0;
    for(i=0;i<CANTS;i++){                       //ingreso de cada palabra
        printf("Ingrese la palabra n%i: ",i+1);
        fgets(palabras[i],LENS,stdin);
    }
    for(i=0;i<CANTS;i++){
        len_palabra=len(palabras[i]);
        len_max=len(palabras[orden_max]);
        if(len_palabra>len_max){
            orden_max=i;
        }
    }
    printf("la palabra mas larga ingresada fue: %s",palabras[orden_max]);
    return 0;
}

int len(char* p){
    int length=0;
    do{
        length++;
        p++;
    }while(*p!=10);
    return length;
}