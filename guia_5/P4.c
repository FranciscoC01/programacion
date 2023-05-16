#include <stdio.h>
#include <stdlib.h>

//Se puede optimizar bastante

//prototipos
typedef struct nodo{                                       //estructura de mis nodos
    int dato;
    struct nodo* sig;
} nodo;

nodo* addNLIFO(nodo* lista, int dato);                     //funcion que agrega un nodo LIFO
nodo* addNFIFO(nodo* lista, int dato);                     //funcion que agrega un nodo FIFO
void mostrar(nodo* lista);                                 //funcion que muestra la lista
nodo* destruir(nodo* lista);                               //funcion que elimina la lista
nodo* filtroPar(nodo* lista);                              //funcion que separa par
nodo* filtroImpar(nodo* lista);                            //funcion que separa impar
//-------

int main(){
    nodo* lista = NULL;                                    //desde aca accedo a los nodos
    nodo* lista_impares = NULL;
    nodo* lista_pares = NULL;
    int dato = 0;                                          //variable auxiliar para guardar el dato del nodo
    printf("\ningrese los datos de los nodos, para salir ingrese -1\n");
    while(dato!=-1){                                       //utilizo -1 como flag para salir del loop
        fflush(stdin);                                     //para evitar que cuando se ingrese una letra reviente el programa
        printf("dato del nodo: ");
        scanf("%i",&dato);
        if(dato!=-1){
            lista = addNLIFO(lista, dato);                 //agrego el nodo
        }
    }
    lista_impares = filtroImpar(lista);
    lista_pares = filtroPar(lista);
    mostrar(lista);
    mostrar(lista_impares);
    mostrar(lista_pares);
    destruir(lista);
    destruir(lista_impares);
    destruir(lista_pares);
    return 0;
}


nodo* addNLIFO(nodo* lista, int dato){                     //agregar en forma LIFO
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

nodo* addNFIFO(nodo* lista, int dato){
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

nodo* filtroPar(nodo* lista){
    nodo* p = lista;
    nodo* lista_filtrada = NULL;
    if(lista!=NULL){
        while(p != NULL){
            if((p->dato%2)!=0){
                lista_filtrada = addNFIFO(lista_filtrada,p->dato);
            }
            p = p->sig;
        }
        return lista_filtrada;
    }else{
        return NULL;
    }
}

nodo* filtroImpar(nodo* lista){
    nodo* p = lista;
    nodo* lista_filtrada = NULL;
    if(lista!=NULL){
        while(p != NULL){
            if((p->dato%2)==0){
                lista_filtrada = addNFIFO(lista_filtrada,p->dato);
            }
            p = p->sig;
        }
        return lista_filtrada;
    }else{
        return NULL;
    }
}