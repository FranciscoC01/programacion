//leer un string e imprimirlo en orden inverso

#include <stdio.h>

//prototipos
void invertir(char*);
//-------

int main(){
    char in[20];                             //variable que guarda la palabra
    printf("Ingrese una palabra: ");
    fgets(in,20,stdin);                      //ingreso de la palabra
    printf("La palabra ingresada fue: %s",in);
    invertir(in);                            //inversion de la palabra
    printf("La palabra invertida: %s",in);
    return(0);
}

void invertir(char* p){
    int len;                               //variable de longitud del string
    char* p2 = p;                          //puntero auxiliar
    char aux, i;
    for(p2;*p2!=10;p2++){                  //reviso la longitud del string buscando char 10
        len++;                             //cuento las iteraciones
    }
    p2 = p2-1;                             //p en el inicio y p2 en el final
    
    for(i=0;i<(len/2);i++){                //recorro el array hasta la mitad
        aux = *p2;                         //el valor del final lo almaceno
        *p2 = *p;                          //le doy el valor del principio
        *p = aux;                          //al valor del principio le doy el valor almacenado
        p++;                               //avanzo el puntero del principio
        p2--;                              //retrocedo el puntero del final
    }
}