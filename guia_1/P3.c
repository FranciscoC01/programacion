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
    char aux[LENS],mayor;
    int i,b,c;
    int min_len=20;
    int orden, reps, len;

    for(i=0;i<CANTS;i++){                       //ingreso de cada palabra
        printf("Ingrese la palabra n%i: ",i+1);
        fgets(palabras[i],LENS,stdin);
    }   

    for(i=0;i<CANTS;i++){                       //las normalizo a minusculas
        toLower(palabras[i]);
    }

    len=0;
    for(i=0;i<CANTS;i++){                      //busco el string mas corto
        for(b=0;palabras[i][b]!=10;b++){
            len++;
        }
        if(len<min_len){
            min_len=len;
        }
    }

    for(c=0;c<min_len;c++){                        //comienzo la busqueda desde el primer caracter hasta el ultimo caracter del string mas corto
        orden=0;                                   //variable que me dice cuales lugares ya estan ordenados
        if(c==0){                                  //si estoy en la primer vuelta
            for(i=0;i<CANTS;i++){                  //reviso de 0 a CANTS
                for(b=CANTS-1;b>=orden;b--){       //y desde el ultimo string al primero
                    if(palabras[i][c]>palabras[b][c]){      //si la primer letra es mayor en i que en b los muevo de lugar
                        copy(palabras[i],aux,LENS);
                        copy(palabras[b],palabras[i],LENS);
                        copy(aux,palabras[b],LENS);
                    }
                }
                orden++;                           //elimino la busqueda del primer lugar en la siguiente vuelta
            } 
        }else{                                     //si no estoy en la primer vuelta
            for(i=0;i<reps;i++){                   //reviso las palabras que se repitieron desde el principio la final
                for(b=reps;b>=orden;b--){          //reviso las palabras que se repitieron desde el final
                    if(palabras[i][c]>palabras[b][c]){  //IDEM c==0
                        copy(palabras[i],aux,LENS);
                        copy(palabras[b],palabras[i],LENS);
                        copy(aux,palabras[b],LENS);
                    }
                }
                orden++;
            }
        }
        reps=0;
        mayor=palabras[0][c];
        for(i=1;i<CANTS;i++){                      //reviso si hay repeticion del caracter "mayor" del string
            if(palabras[i][c]==mayor){
                reps++;
            }
        }
        if(reps==0){                               //si no hay ninguno salgo
            break;
        }
    }

    printf("el primer string en orden alfabetico es: %s",palabras[0]);
    // for(i=0;i<CANTS;i++){
    //     printf("palabra n%i: %s",i+1,palabras[i]);
    // }
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
    for(i=0;i<len;i++){                     //recorro los dos arrays
        *p_destino = *p_origen;             //mando el valor del espacio al destino
        p_origen++;                         //muevo los punteros un lugar
        p_destino++;
    }
}