/* escribir una funcion que reciba un vector de enteros y su tamaño
y devuelva la cantidad de numeros impares */

#include <stdio.h>

//prototipos
int impares(int *v, int tam);
//-----

int main(){
    int v[10] = {1,1,3,3,5,6,7,8,9,10};
    int len = 10;
    int cantImpares;
    cantImpares = impares(v,len);
    printf("la cantidad de impares encontrados fue: %i",cantImpares);
    return 0;
}

int impares(int *v,int tam){
    int out=0;
    int i;
    for(i=0;i<tam;i++){
        if((*(v+i)%2)!=0){
            out++;
        }
    }
    return out;
}