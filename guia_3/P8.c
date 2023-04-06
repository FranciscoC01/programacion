//implementar una funcion que reciba un vector de float y devuelva su promedio

#include <stdio.h>

//prototipos
float promedio(float* v, int len);
//-----

int main(){
    int len = 10;
    float numeros[] = {1.5, 2.4, 6.8, 4.5, 5.3, 6.2, 2.1, 9.1, 10.5, 1.1};
    float prom;
    prom = promedio(numeros,len);
    printf("el promedio es: %.2f",prom);
    return 0;
}

float promedio(float* v, int len){
    float out = 0;
    int i;
    for(i=0;i<len;i++){
        out+=*(v+i);
    }
    out = out/len;
    return out;
}