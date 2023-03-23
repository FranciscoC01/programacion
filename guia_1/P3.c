//Leer 5 string por teclado y mostrar el mayor
//(voy a suponer mayor como mayor en tabla ascii) 

#include <stdio.h>

//constantes globales
#define CANTS 5              //cantidad de palabras a comparar
#define LENS 20              //longitud maxima de las palabras
#define MAX_ITER 20          //iteraciones maximas en el bucle de busqueda
//-----

//prototipos
int unico(int* , int);
//-----

int main(){
    char palabras[CANTS][LENS];
    int revisadas[CANTS];
    int i,b;
    int cont=0;
    for(i=0;i<CANTS;i++){
        printf("Ingrese la palabra n%i:",i+1);
        fgets(palabras[i],LENS,stdin);
    }
    for(i=0;i<CANTS;i++){
        revisadas[i]=1;
    }
    do{
        for(i=0;i<CANTS;i++){
            for(b=0;b<LENS;b++){

            }
        }
        cont++;
    }while(unico(revisadas, CANTS)||(cont>MAX_ITER));
    
    return(0);
}

int unico(int* a, int len){
    int i;
    int cont = 0;
    for(i=0;i<len;i++){
        if(*a==1){
            cont++;
        }
    }
    if(cont==1){
        return(0);
    }else{
        return(1);
    }
}