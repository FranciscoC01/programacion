#include <stdio.h>
#include <stdlib.h>

//prototipos
typedef struct nodo{                                       //estructura de mis nodos
    int dato;
    struct nodo* sig;
} nodo;

nodo* addFIFO(nodo* lista, int dato);                      //funcion que agrega un nodo de la forma FIFO
nodo* addLIFO(nodo* lista, int dato);                      //funcion que agrega un nodo de la forma LIFO
void mostrar(nodo* lista);                                 //funcion que muestra la lista
nodo* eliminar(nodo* lista, int dato);                     //funcion que elimina un elemento especifico de la lista
nodo* destruir(nodo* lista);                               //funcion que elimina la lista
//-------


int main(){
    nodo* lista = NULL;                                    //desde aca accedo a los nodos

    int dato = 0;                                          //variable auxiliar para guardar el dato del nodo
    printf("\ningrese los datos de los nodos, para salir ingrese -1\n");
    while(dato!=-1){                                       //utilizo -1 como flag para salir del loop
        fflush(stdin);                                     //para evitar que cuando se ingrese una letra reviente el programa
        printf("dato del nodo: ");
        scanf("%i",&dato);
        if(dato!=-1){
            lista = addFIFO(lista, dato);                 //agrego el nodo
        }
    }
    mostrar(lista);
    eliminar(lista, 8);
    mostrar(lista);
    destruir(lista);
    return 0;
}

nodo* eliminar(nodo* lista, int dato){                     //funcion para eliminar elemento especifico
    nodo* p = lista;                                       //apunto al primer nodo
    nodo* aux = NULL;                                      //utilizo una variable auxiliar que retendra nodos 
    if(p==NULL){                                           //si la lista esta vacia lo informo y devuelvo NULL
        printf("la lista esta vacia");
    }else{
        while((p->sig != NULL)&&(p->sig->dato != dato)){
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

void mostrar(nodo* lista){                                 //mostrar la lista
    nodo* p = NULL;                                        //declaro puntero que se movera por la lista
    if(lista == NULL)                                      //si la lista esta vacia
        printf("lista vacia");
    else{                                                  //sino
        p = lista;                                         //p lo posiciono en el primer elemento
        while(p != NULL){                                  //mientras que p no este en el final de la lista
            printf("--> %i ",p->dato);                     //imprimo el dato del nodo al que p apunta
            p = p->sig;
        }
        printf("\n");
    }
}

//agrega dato arriba de los demas
nodo* addLIFO(nodo* lista, int dato){                     //agregar en forma LIFO
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));            //nuevo nodo
    
    nuevo->dato = dato;                                    //dato del nodo
    nuevo->sig = NULL;                                     //apunta a ninguna parte

    if(lista == NULL){                                     //si la lista esta vacia apunto al nuevo nodo
        return nuevo;                                      //devuelvo el nuevo nodo como el primer elemento de la lista
    }
    else{                                                  //si la lista no esta vacia
        nuevo->sig=lista;                                  //al nuevo nodo le agrego todos los nodos anteriores atras
        return nuevo;
    }
}

//agrega dato debajo de los demas
nodo* addFIFO(nodo* lista, int dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));            //nuevo nodo
    nodo* p = lista;

    nuevo->dato = dato;                                    //dato del nodo
    nuevo->sig = NULL;                                     //apunta a ninguna parte

    if(p == NULL){                                         //si la lista esta vacia apunto al nuevo nodo
        return nuevo;                                      //devuelvo el nuevo nodo como el primer elemento de la lista
    }
    else{                                                  //si la lista no esta vacia
        while(p->sig !=NULL){
            p = p->sig;
            
        }
        p->sig=nuevo;                                      //al nuevo nodo le agrego todos los nodos anteriores atras
        return lista;
    }
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