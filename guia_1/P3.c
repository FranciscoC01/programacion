//Leer 5 string por teclado y mostrar el mayor
//(voy a suponer mayor como lugares alfabeticos, "aa" esta antes que "ab") 

#include <stdio.h>

//constantes globales
#define CANTS 5              //cantidad de palabras a comparar
#define LENS 20              //longitud maxima de las palabras
//-----

//prototipos
void toLower(char*);
void copy(char*, char*, int);
//-----

int main(){
    char palabras[CANTS][LENS];
    char aux[LENS];
    int i,b,c;
    int orden;
    for(i=0;i<CANTS;i++){
        printf("Ingrese la palabra n%i:",i+1);
        fgets(palabras[i],LENS,stdin);
    }   

    for(i=0;i<CANTS;i++){
        toLower(palabras[i]);
    }

    orden=0;
    for(i=0;i<CANTS;i++){
        for(b=CANTS-1;b>=orden;b--){
            // printf("p%i vs p%i\n",i,b);
            if(palabras[i][c]>palabras[b][c]){
                // printf("p%i to p%i\n",b,i);
                copy(palabras[i],aux,LENS);
                copy(palabras[b],palabras[i],LENS);
                copy(aux,palabras[b],LENS);
            }
        }
        orden++;
    }

    for(c=0;c<LENS;i++){
        
        if()
        break;
    }
    for(i=0;i<CANTS;i++){
        printf("palabra n%i: %s",i+1,palabras[i]);
    }
    return 0;
}

void toLower(char* p){
    do{
        if((*p>=65)&&(*p<=90)){             //si el char esta entre 65(A) y 90(Z) 
            *p = *p+32;                     //le sumo 32 para que este entre 97(a) y 122(z)
        }
        p++;                                //muevo el puntero un lugar en memoria
    }while(*p!=10);                         //si el puntero esta en un char 10 llegue al fin del string
}

void copy(char* p_origen, char* p_destino, int len){
    int i;
    for(i=0;i<len;i++){
        *p_destino = *p_origen;
        p_origen++;
        p_destino++;
    }
}