//escribir una funcion que reciba dos vectores en el plano y devuelva la distancia euclidea

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//constantes globales
//-----

//prototipos
typedef struct {
    float x;
    float y;
} vector;

vector componer(vector v1, vector v2);
//-----

int main(){
    vector p1;
    vector p2;
    vector resultado;
    printf("ingrese las componentes del primer vector\n");
    printf("x1: ");
    scanf("%f", &p1.x);
    printf("y1: ");
    scanf("%f", &p1.y);
    printf("ingrese las componentes del segundo vector\n");
    printf("x2: ");
    scanf("%f", &p2.x);
    printf("y2: ");
    scanf("%f", &p2.y);
    resultado = componer(p1,p2);
    printf("la coordenada del resultante es (%.2f,%.2f)",resultado.x,resultado.y);
    return(0);
}

vector componer(vector v1, vector v2){
    vector out;
    out.x = v1.x + v2.x;
    out.y = v1.y + v2.y; 
    return out;
}