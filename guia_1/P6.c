//Leer 5 strings del archivo del punto 5 y mostrarlos

#include <stdio.h>
#include <stdlib.h>

//constantes globales
#define CANTS 5              //cantidad de palabras a comparar
#define LENS 20              //longitud maxima de las palabras
//-----

//prototipos
void leer(char* p, char origen[],char stop,int place);
//-----

int main(){
    char palabras[CANTS][LENS];
    int i;
    for(i=0;i<CANTS;i++){
        leer(palabras[i],"./palabras.dat",10,i);
    }
    for(i=0;i<CANTS;i++){                       //ingreso de cada palabra
        printf("La palabra n%i: %s",i+1,palabras[i]);
    }
    return 0;
}

void leer(char* p, char origen[],char stop,int place){
    FILE* fp;
    int cont = 0;
    char buffer;
    fp=fopen(origen,"rb");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    if(place==0){
        do{
            fread(&buffer,sizeof(char),1,fp);
            *p=buffer;
            p++;
        }while(buffer!=stop);
        *p=buffer;
    }else{
        while(1){
            fread(&buffer,sizeof(char),1,fp);
            if(buffer==stop){
                cont++;
                if(cont==place){
                    do{
                        fread(&buffer,sizeof(char),1,fp);
                        *p=buffer;
                        p++;
                    }while(buffer!=stop);
                    *p=buffer;
                    break;
                }
            }
        }
    }
    
    // fread(&p,sizeof(char[lenC][lenF]),1,fp);
    // do{
    //     fread(&buffer,sizeof(char),1,fp);
    //     *p=buffer;
    //     p++;
    // }while(buffer!=stop);
    // *p=buffer;
    fclose(fp);
}