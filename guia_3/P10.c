//escriba un programa que permita al usuario ingresar los valores de una matriz de 3x3
//y luego imprimir los valores de la diagonal

//TO DO
// porque funciona de esa manera y no funciona *(*(v+x)+y)

#include <stdio.h>

//prototipos
void diagonal(int** v, int lenx,int leny);
//-----

int main(){
    int matriz[3][3];
    int x,y;
    printf("ingrese los valores de la matriz \n");
    for(y=0;y<3;y++){
        for(x=0;x<3;x++){
            printf("(%i,%i): ",x,y);
            scanf("%i",&matriz[x][y]);
        }
    }
    diagonal(matriz,3,3);
    return 0;
}

void diagonal(int** v, int lenx, int leny){
    int x,y;
    printf("\nlos valores de la diagonal son: ");
    for(y=0;y<leny;y++){
        for(x=0;x<lenx;x++){
            if(y==x){
                printf("(%i,%i) %i ",x,y,*(v + (x+y)));
            }
        }
    }
}