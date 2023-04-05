//Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes(n<100) y almacenar en estudiantes.dat

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

void guardarDatos(estudiante[] ,int ,char[]);
//-----

int main(){
    estudiante aula[MAX_EST];
    int cont=0;
    // float aux;
    printf("Para terminar la carga de datos ingrese legajo: 0\n");
    printf("ingrese el legajo: ");
    fgets(aula[cont].legajo,MAX_STR_LEN,stdin);
    do{
        printf("ingrese el nombre: ");
        fgets(aula[cont].nombre,MAX_STR_LEN,stdin);
        printf("ingrese el promedio: ");
        scanf("%f",&aula[cont].promedio);
        printf("======================\n");
        cont++;
        fflush(stdin);
        printf("ingrese el legajo: ");
        fgets(aula[cont].legajo,MAX_STR_LEN,stdin);
    }while(aula[cont].legajo[0] != '0');
    guardarDatos(aula,cont,"./estudiantes.dat");
    return(0);
}

void guardarDatos(estudiante data[],int len,char dir[]){
    FILE* fp;
    int c = 0;
    fp=fopen(dir,"wb");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    c=fwrite(data,sizeof(estudiante[len]),1,fp);
    if(c!=1){
        puts("error al escribir el archivo");
        exit(2);
    }
    fclose(fp);
}