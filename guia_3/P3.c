// escribir un programa que imprima los elementos de un vector en orden inverso

#include <stdio.h>

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = v;
    int i;

    for(i=9;i>=0;i--){
        printf("%i\n",*(p+i));
    }
    return 0;
}