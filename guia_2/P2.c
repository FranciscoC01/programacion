//Leer el archivo estudiantes.dat e imprimir el estudiante con mayor promedio

#include <stdio.h>
#include <stdlib.h>


//constantes globales
#define MAX_EST 100
#define MAX_STR_LEN 20
//-----

//prototipos
typedef struct {
    char legajo[MAX_STR_LEN];
    char nombre[MAX_STR_LEN];
    float promedio;
} estudiante;

void leerDatos(estudiante data[] ,int* len, char dir[]);
//-----

int main(){
    estudiante aula[MAX_EST];
    int len;
    int i;
    int i_max = 0;
    // float aux;
    leerDatos(aula,&len,"./estudiantes.dat");
    // printf("cant de datos leidos: %i",len);
    for(i=0;i<len;i++){
        if(aula[i].promedio>aula[i_max].promedio){
            i_max=i;
        }
    }
    printf("el estudiante con mayor promedio es: %s",aula[i_max].nombre);
    return(0);
}

void leerDatos(estudiante data[] ,int* len, char dir[]){
    FILE* fp;
    int c = 0;
    fp=fopen(dir,"rb");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    *len = fread(data,sizeof(estudiante),MAX_EST,fp);
    fclose(fp);
}