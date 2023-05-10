#include <stdio.h>
#include <stdlib.h>

//Prototipos
void guardar(int* p,char dir[],int len);
//-----

int main(){
    int cant, i;
    int* p;
    printf("cantidad de elementos a ingresar: ");
    scanf("%i",&cant);
    p = (int*) calloc(cant, sizeof(int));
    if(p != NULL){
        for(i=0;i<cant;i++){
            printf("ingrese el valor %i: ",i+1);
            scanf("%i",(p+i));
        }
        guardar(p,"vector.dat",cant);
        free(p);
        p=NULL;
    }else{
        printf("no se pudo reservar el espacio en memoria.");
    }
    
    return 0;
}

void guardar(int* p,char dir[],int len){
    FILE* fp;
    int w;
    fp=fopen(dir,"wb");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    w = fwrite(p,sizeof(int),len,fp);
    if(w!=len){
        printf("error al escribir el archivo");
    }
    fclose(fp);
}   