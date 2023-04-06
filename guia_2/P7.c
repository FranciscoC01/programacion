/* Definir  un  tipo  de  dato  que  tenga  dos  campos:  tipo  (1,  2,  o  3)  y  un  segundo 
campo  para  el  valor.  El  valor  dependiendo  del  tipo  debe  permitir  almacenar  un 
int, un float o un double pero sólo uno simultáneamente.*/

#include <stdio.h>
#include <stdlib.h>

typedef union {
    int a;
    float b;
    double c;
} numeros;

typedef struct {
    char opt;
    numeros dato;
} var_flexible;