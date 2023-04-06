/* escribir una funcion que reciba un vector de enteros y su tamaño
y devuelva la cantidad de numeros impares */

#include <stdio.h>

//prototipos
double* max(double *v, int cant);
//-----

int main(){
    double v[10] = {1,51,33,43,100,6,7,8,9,10};
    int len = 10;
    double* maximo;
    maximo = max(v,len);
    printf("maximo numero encontrado fue: %.2lf",*maximo);
    return 0;
}

double* max(double *v, int cant){
    double* max = v;
    int i;
    if(cant==0){
        return NULL;
    }else{
        for(i=1;i<cant;i++){
            if(*max<(*(v+i))){
                max=(v+i);
            }
        }
    }
    return max;
}