#include <stdio.h>
#include <stdlib.h>

//Prototipos
typedef struct {
    int len;
    int* p_inicio;
} vector;
vector leer(char dir[]);
//-----

int main(){
    vector p;
    int i;
    p = leer("vector.dat");
    if(p.p_inicio!=NULL){
        for(i=0;i<(p.len);i++){
            printf("%i: %i\n",i,*((p.p_inicio)+i));
        }
    }else{  
        printf("revento todo");
    }
    free(p.p_inicio);
    return 0;
}

vector leer(char dir[]){
    FILE* fp;
    vector out;
    int nRead, r;
    int len= 0;
    int* p = (int*) malloc(sizeof(int));
    int* pAux = NULL;

    fp=fopen(dir,"rb");
    if(fp==NULL){
        puts("error al abrir el archivo");
        exit(1);
    }else{
        while(!feof(fp)){
            r = fread(&nRead,sizeof(int),1,fp);
            if(r==0){
                break;
            }else{
                pAux = (int*) realloc(p,(len+1)*sizeof(int));
                if(pAux==NULL){
                    puts("error al reservar memoria");
                    exit(1);
                }else{
                    p = pAux;
                    pAux = NULL;
                    *(p + len) = nRead;
                    // printf("read: %i\n",nRead);
                }
                len++;
            }
        };
    }

    out.len = len;
    out.p_inicio = p;
    return out;
}