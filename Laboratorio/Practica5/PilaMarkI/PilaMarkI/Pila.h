#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

struct Pila
{
    char v[20];
    int tos;
    int MAX;
};
struct Pila *crear();

int vacia(struct Pila *p);

void push(struct Pila *p, char c);

char pop(struct Pila *p);

#endif // PILA_H_INCLUDED
