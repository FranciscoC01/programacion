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
    printf("hola?");
    printf("la palabra duplicada es: ");
    for(i=0;*(p_copy+i)!=10;i++){
        printf("%c",*(p_copy+i));
    }
    free(p_copy);
    return 0;
}

char* duplicar(char* str){
    char* p_out = (char*) malloc(sizeof(char)); 
    char* p_aux = NULL;
    int i;
    if(*str==10){
        return NULL;
    }else{
        *p_out = *str;
        for(i=1;*(str+i)!=10;i++){
            p_aux = (char*) realloc(p_out, (i+1)*sizeof(char));
            if(p_aux!=NULL){
                p_out = p_aux;
                p_aux = NULL;
                *(p_out+i) = *(str+i);
            }else{
                puts("error al reservar memoria");
                exit(1);
            }
        }
        p_aux = (char*) realloc(p_out, (i+1)*sizeof(char));
        if(p_aux!=NULL){
            p_out = p_aux;
            p_aux = NULL;
            *(p_out+i) = 10;
        }
        return p_out;
    }
}   