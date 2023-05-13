#include <stdio.h>
#include <stdlib.h>

//Prototipos
char* duplicar(char* str);
//-----

int main(){
    char* p_copy = NULL;
    char str[] = "hola";
    int i;
    p_copy = duplicar(str);
    printf("la palabra duplicada es: ");
    for(i=0;*(p_copy+i)!=0;i++){
        printf("%c",*(p_copy+i));
    }
    free(p_copy);
    return 0;
}

char* duplicar(char* str){
    char* p_out = (char*) malloc(sizeof(char)); 
    char* p_aux = NULL;
    int i;
    if(*str==0){
        return NULL;
    }else{
        do{
            p_aux = (char*) realloc(p_out, (i+1)*sizeof(char));
            if(p_aux!=NULL){                                         //control de error
                p_out = p_aux;
                p_aux = NULL;
                *(p_out+i) = *(str+i);
            }else{
                puts("error al reservar memoria");
                exit(1);
            }
            i++;
        }while((*(str+i))!=0);
        p_aux = (char*) realloc(p_out, (i+1)*sizeof(char));
        if(p_aux!=NULL){
            p_out = p_aux;
            p_aux = NULL;
            *(p_out+i) = 0;
        }
        return p_out;
    }
}   