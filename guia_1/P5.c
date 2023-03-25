//Leer 5 strings por teclado y almacenarlos en un archivo

#include <stdio.h>
#include <stdlib.h>

//constantes globales
#define CANTS 5              //cantidad de palabras a comparar
#define LENS 20              //longitud maxima de las palabras
//-----

//prototipos
void guardar(char* ,int);
//-----

int main(){
    char palabras[CANTS][LENS];
    int i;
    for(i=0;i<CANTS;i++){                       //ingreso de cada palabra
        printf("Ingrese la palabra n%i: ",i+1);
        fgets(palabras[i],LENS,stdin);
    }
    for(i=0;i<CANTS;i++){
        guardar(palabras[i],LENS);
    }
    return 0;
}

void guardar(char* p,int len){
    FILE* fp;
    int i;
    char c = 10;
    char destino[]="./palabras.dat";
    fp=fopen(destino,"ab");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    for(i=0;i<len;i++){
        printf("p: %c\n",*p);
        if(*p==10){
            fwrite(&c,sizeof(char),1,fp);
            break;
        }else{
            fwrite(p,sizeof(char),1,fp);
        }
        p++;
    }
    fclose(fp);
}