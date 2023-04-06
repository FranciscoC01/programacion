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

double norma(vector v1, vector v2);
//-----

int main(){
    vector p1;
    vector p2;
    double resultado;
    printf("ingrese las coordenadas del primer punto\n");
    printf("x1: ");
    scanf("%f", &p1.x);
    printf("y1: ");
    scanf("%f", &p1.y);
    printf("ingrese las coordenadas del segundo punto\n");
    printf("x2: ");
    scanf("%f", &p2.x);
    printf("y2: ");
    scanf("%f", &p2.y);
    resultado = norma(p1,p2);
    printf("la distancia entre los puntos es: %.2lf",resultado);
    return(0);
}

double norma(vector v1, vector v2){
    float dx = abs(v1.x - v2.x);
    float dy = abs(v1.y - v2.y); 
    return sqrt(pow(dx,2)+pow(dy,2));
}