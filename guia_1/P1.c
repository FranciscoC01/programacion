//Leer un String por teclado y convertirlo a mayusculas

#include <stdio.h>

//prototipos
void toUpper(char*);
//-----

int main(){
    char in[20];                             //variable que guarda la palabra
    printf("Ingrese una palabra: ");
    fgets(in,20,stdin);                      //ingreso de la palabra
    printf("La palabra ingresada fue: %s",in);
    toUpper(in);                             //pasaje a mayusculas
    printf("La palabra en mayusculas es: %s",in);
    return(0);
}

void toUpper(char* p){
    do{
        if((*p>=97)&&(*p<=122)){             //si el char esta entre 97(a) y 122(z) 
            *p = *p-32;                      //le resto 32 para que este entre 65(A) y 90(Z)
        }
        p++;                                 //muevo el puntero un lugar en memoria
    }while(*p!=10);                          //si el puntero esta en un char 10 llegue al fin del string
}