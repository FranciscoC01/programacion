//CREO creo que es una solucion valida

#include <stdio.h>

int main(){
    int v[10] = {1,51,33,43,100,6,7,8,9,10};
    int *p_inicio = &v[0];
    int *p_final = &v[9];
    int *p_medio;
    p_medio = p_inicio+((p_final-p_inicio)/2);
    printf("valor de mem i:%p m:%p f:%p",p_inicio,p_medio,p_final);
    return 0;
}