//implementar la funcion prod_esc

#include <stdio.h>

//prototipos
double prod_esc(const double *a, const double *b, int n);
//-----

int main(){
    double v1[] = {1,2};
    double v2[] = {2,1};
    double result;
    result = prod_esc(v1,v2,2);
    printf("el producto escalar es igual a %lf",result);
    return 0;
}

double prod_esc(const double *a, const double *b, int n){
    double out=0;
    int i;
    for(i=0;i<n;i++){
        out+= (*(a+i)) * (*(b+i)); 
    }
    return out;
}