#include <stdio.h>
#include <stdlib.h>

//prototipos
typedef struct nodo{                                       //estructura de mis nodos
    int dato;
    struct nodo* sig;
} nodo;

nodo* addFIFO(nodo* lista, int dato);                      //funcion que agrega un nodo FIFO
void mostrarElemento(nodo* lista, int clave);              //funcion que busca elementos que coincidan con la clave
void mostrar(nodo* lista);                                 //funcion que muestra la lista
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
    mostrarElemento(lista, 1);
    mostrar(lista);
    destruir(lista);
    return 0;
}

void mostrarElemento(nodo* lista, int clave){              //funcion que busca nodos con un dato igual a la clave
    nodo* p = lista;                                       //apunta al nodo actual
    nodo* p_prev = NULL;                                   //apunta al nodo anterior al actual
    int find = 0;                                          //cantidad de veces que se encontro la clave
    if(p != NULL){                                         //mientras la lista no este vacia
        do{
            if(p->dato == clave){                          //si encuentro en el nodo el dato buscado
                if(p_prev == NULL){                        //si es el primer dato
                    printf("->|%3i|->...\n",p->dato);
                }else{                                     //sino imprimo el anterior y el actual
                    printf("...->|%3i|->|%3i|->...\n",p_prev->dato,p->dato);
                }
                
                find++;                                    //actualizo la cuenta de coincidencias
            }
            p_prev = p;                                    //el anterior va a ser ahora p
            p = p->sig;                                    //y a p lo muevo un nodo
        }while(p != NULL);                                 //y repito esta accion mientras no llegue al final de la lista
        if(find==0){
            printf("No se encontro el elemento\n");
        }
    }else{
        printf("lista vacia\n");
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