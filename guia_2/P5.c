//escribir una funcion que reciba dos horas y devuelva la diferencia entre las mismas

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//constantes globales
//-----

//prototipos
typedef struct {
    int h;
    int m;
    int s;
} time;

time dif(time t1, time t2);
//-----

int main(){
    time h1;
    time h2;
    time diff;
    printf("ingrese la primer hora\n");
    printf("horas: ");
    scanf("%i", &h1.h);
    printf("minutos: ");
    scanf("%i", &h1.m);
    printf("segundos: ");
    scanf("%i", &h1.s);
    printf("ingrese la segunda hora\n");
    printf("horas: ");
    scanf("%i", &h2.h);
    printf("minutos: ");
    scanf("%i", &h2.m);
    printf("segundos: ");
    scanf("%i", &h2.s);
    diff = dif(h1,h2);
    printf("la diferencia entre ambas horas es de %02d:%02d:%02d",diff.h,diff.m,diff.s);
    return(0);
}

time dif(time t1, time t2){
    time out;
    out.h = abs(t1.h-t2.h);
    out.m = abs(t1.m-t2.m);
    out.s = abs(t1.s-t2.s);
    if(out.s>=60){
        out.m += out.s/60;
    }
    if(out.m>=60){
        out.h += out.m/60;
    }
    return out; 
}