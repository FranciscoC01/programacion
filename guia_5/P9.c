#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipos
typedef struct nodo {
    int A;
    float B; 
    char descr[30];
    struct nodo* sig;
} nodo;

void mostrar(nodo* lista);                                 //funcion que muestra la lista
nodo* insertarOrdenadoN(nodo* lista, nodo* nuevo);         //funcion que inserta un nodo de forma ordenada
nodo* insertarOrdenado(nodo* lista, int A, float B, char descr[]);         //funcion que inserta un nodo de forma ordenada
nodo* eliminar(nodo* lista, int dato);                     //funcion que elimina un elemento especifico de la lista
nodo* destruir(nodo* lista);                               //funcion que elimina la lista
void guardar(nodo* lista, char filename[]);                //funcion que guarda una lista en un archivo de nombre elegido
nodo* cargar(char filename[]);                             //funcion que carga un archivo determinado
//-----

int main(){
    nodo* lista = NULL;

    int opt = 0;
    
    //datos nodos
    nodo* nuevo;
    int A;
    float B;
    char descr[30];

    while(opt!=6){
        printf("\n1. agregar nodos a la lista\n");
        printf("2. eliminar nodo de la lista\n");
        printf("3. guardar lista y salir\n");
        printf("4. cargar archivo\n");
        printf("5. mostrar lista\n");
        printf("6. salir\n");
        printf(">> ");
        scanf("%i",&opt);
        switch(opt){
            case 1:
                printf("\nva a ingresar un nuevo nodo\n");
                printf("\ningrese el dato entero: ");
                scanf("%i",&A);
                printf("ingrese el float: ");
                scanf("%f",&B);
                fflush(stdin);
                printf("ingrese la descripcion: ");
                gets(descr);
                nuevo = (nodo*) malloc(sizeof(nodo));
                nuevo->A = A;
                nuevo->B = B;
                strcpy(nuevo->descr,descr);
                lista = insertarOrdenadoN(lista,nuevo);
                break;
            case 2:
                printf("ingrese el dato entero del nodo que desea eliminar: ");
                scanf("%i",&A);
                lista = eliminar(lista,A);
                break;
            case 3:
                guardar(lista,"datos.dat");
                opt = 6;
                break;
            case 4:
                lista = cargar("datos.dat");
                break;
            case 5:
                mostrar(lista);
                break;
            case 6:
                destruir(lista);
                break;
            default:
                printf("la opcion ingresada no se reconoce\n");
        }
    }
    return 0;
}

nodo* destruir(nodo* lista){                               //destruir la lista
    nodo* aux = NULL;                                      //declaro un puntero tipo nodo auxiliar para no perder la lista

    while(lista != NULL){                                  //mientras que la lista no este completamente vacia
        aux = lista;                                       //le asigno a aux el nodo
        lista = lista->sig;                                //muevo el principio de la lista al siguiente elemento
        free(aux);                                         //libero el espacio de memoria que ocupa el nodo
    }
    printf("lista destruida\n");
    return NULL;
}

nodo* insertarOrdenadoN(nodo* lista, nodo* nuevo){
    nodo* p = lista;
    if((p == NULL)||(p->A > nuevo->A)){
        nuevo->sig = lista;
        return nuevo;
    }
    while (p->sig != NULL && p->sig->A <= nuevo->A){
        p = p->sig;
    }
    nuevo->sig = p->sig;
    p->sig = nuevo;
    return lista;
}

nodo* insertarOrdenado(nodo* lista, int A, float B, char descr[]){
    nodo* p = lista;
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    
    nuevo->A = A;
    nuevo->B = B;
    strcpy(nuevo->descr,descr);
    nuevo->sig = NULL;

    if((p == NULL)||(p->A > A)){
        nuevo->sig = lista;
        return nuevo;
    }
    while (p->sig != NULL && p->sig->A <= A)
        p = p->sig;
    nuevo->sig = p->sig;
    p->sig = nuevo;

    return lista;
}

void mostrar(nodo* lista){                                 //mostrar la lista
    nodo* p = NULL;                                        //declaro puntero que se movera por la lista
    int i = 0;
    if(lista == NULL)                                      //si la lista esta vacia
        printf("lista vacia");
    else{                                                  //sino
        p = lista;                                         //p lo posiciono en el primer elemento
        while(p != NULL){                                  //mientras que p no este en el final de la lista
            i++;
            printf("nodo %i: A->%i,B->%f,descripcion:\"%s\" \n",i,p->A,p->B,p->descr);
            p = p->sig;
        }
        printf("\n");
    }
}

nodo* eliminar(nodo* lista, int dato){                     //funcion para eliminar elemento especifico
    nodo* p = lista;                                       //apunto al primer nodo
    nodo* aux = NULL;                                      //utilizo una variable auxiliar que retendra nodos 
    if(p==NULL){                                           //si la lista esta vacia lo informo y devuelvo NULL
        printf("la lista esta vacia");
    }else{
        while((p->sig != NULL)&&(p->sig->A != dato)){
            p = p->sig;
        }
        if(p->sig == NULL){
            printf("no esta en la lista el dato buscado");
        }else{
            if(p->sig->sig == NULL){
                aux = p->sig;
                p->sig = NULL;
                free(aux);
            }else{
                aux = p->sig;
                p->sig = p->sig->sig;
                free(aux);
            }   
        }
    }
    return lista;
}

void guardar(nodo* lista, char filename[]){
    FILE* fp;
    nodo* p = lista;
    int w = 0;

    fp = fopen(filename,"wb");
    if(fp == NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    while(p!=NULL){
        w = fwrite(p,sizeof(nodo),1,fp);
        if(w==0){
            puts("error al escribir el archivo");
            exit(1);
        }
        p = p->sig;
    }
    printf("lista guardada en %s\n",filename);
    destruir(lista);

    if(fclose(fp)!=0){
        puts("error al cerrar el archivo");
        exit(1);
    }
}

nodo* cargar(char filename[]){
    FILE* fp;
    nodo* lista = NULL;
    nodo* aux;
    nodo p;
    int r = 0;
    int i=0;

    fp = fopen(filename,"rb");
    if(fp == NULL){
        puts("error al abrir el archivo");
        exit(1);
    }
    r = fread(&p,sizeof(nodo),1,fp);
    printf("%i",r);
    while(r==1){
        i++;
        lista = insertarOrdenado(lista,p.A,p.B,p.descr);
        r = fread(&p,sizeof(nodo),1,fp);
        // mostrar(lista);
        printf("%i",r);
    }
    mostrar(lista);
    printf("lista cargada desde %s\n",filename);
    
    if(fclose(fp)!=0){
        puts("error al cerrar el archivo");
        exit(1);
    }
    return lista;
}
