#include <stdio.h>
#include <stdlib.h>

//prototipos
typedef struct nodo{                                       //estructura de mis nodos
    int dato;
    struct nodo* sig;
} nodo;

nodo* add_n(nodo* lista, int dato);                        //funcion que agrega un nodo
void mostrar(nodo* lista);                                 //funcion que muestra la lista
nodo* destruir(nodo* lista);                               //funcion que elimina la lista
int len(nodo* lista);                                      //funcion que devuelve la cantidad de elementos de una lista
//-------

int main(){
    nodo* lista = NULL;                                    //desde aca accedo a los nodos
    int len_lista = 0;
    lista = add_n(lista, 1);
    lista = add_n(lista, 2);
    lista = add_n(lista, 3);
    len_lista = len(lista);
    printf("la cantidad de nodos es: %i\n", len_lista);
    mostrar(lista);
    destruir(lista);
    return 0;
}


nodo* add_n(nodo* lista, int dato){                        //agregar en forma LIFO
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

int len(nodo* lista){
    int cant_nodos = 0;
    nodo* p;
    if(lista == NULL){
        return -1;
    }else{
        p = lista;                                         //p lo posiciono en el primer elemento
        while(p != NULL){                                  //mientras que p no este en el final de la lista
            cant_nodos++;
            p = p->sig;
        }
        return cant_nodos;
    }
}