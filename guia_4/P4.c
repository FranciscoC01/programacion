#include <stdio.h>
#include <stdlib.h>

//prototipos
int* crear_vector(int n, int valor_inicial);
//--------------

int main(){
    int numero_elementos = 10;
    int valor_inicial = 1;
    int i;
    int* vec_init = NULL;
    vec_init = (int*) crear_vector(numero_elementos,valor_inicial);
    if(vec_init==NULL){
        printf("error al crear el vector");
    }else{
        for(i=0; i<numero_elementos;i++){
            printf("vec[%i]=%i\n",i,*(vec_init+i));
        }
    }
    free(vec_init);
    return 0;
}

int* crear_vector(int n, int valor_inicial){
    int i;
    if(n >= 0){
        int* vec = (int*) malloc(n*sizeof(int));
        if(vec==NULL){
            return NULL;
        }else{
            for(i=0;i<n;i++){
                *(vec+i) = valor_inicial;
            }
            return vec;
        }
    }
    return NULL;
}