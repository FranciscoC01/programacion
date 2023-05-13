#include <stdio.h>
#include <stdlib.h>

//prototipos 
struct punto{
    int x;
    int y;
};
struct rectangulo{
    struct punto superior_izq;
    struct punto inferior_der;
}
//---------

int main(){
    struct rectangulo* p;
    p = (rectangulo*) malloc(4*sizeof(int));
    p->superior_izq.x = 10;
    p->superior_izq.y = 25;
    p->inferior_der.x = 20;
    p->inferior_der.y = 15;
    return 0;
}