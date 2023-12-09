
#include "Pila.h"

struct Pila *crear()
{
    struct Pila *pila;
    pila = malloc(sizeof(struct Pila));
    pila->tos=-1;
    pila->MAX=20;
    return pila;
};

int vacia(struct Pila *p)
{
    if(p->tos==-1)
        return 1;
    return 0;
}

void push(struct Pila *p, char c)
{
    if(p->tos==(p->MAX-1))
    {
        printf("Error de Underflow(La pila esta llena)");
        exit(1);
    }
    p->tos=p->tos+1;
    p->v[p->tos]=c;
}

char pop(struct Pila *p)
{
    char r;
    if(p->tos==-1)
    {
        printf("Error de Overflow(No hay elementos para eliminar)");
        exit(2);
    }
    r=p->v[p->tos];
    p->tos=p->tos-1;
    return r;
}
