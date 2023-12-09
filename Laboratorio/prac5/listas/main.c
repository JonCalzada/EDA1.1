#include <stdio.h>
#include <stdlib.h>
struct Nodo
{
    int info;
    struct Nodo *sig;
};

struct Nodo *crearNodo(int dato)
{

    struct Nodo *nuevo;
    /** Se creara el nodo **/
    nuevo=malloc(sizeof(struct Nodo));
    nuevo->info=dato;
    nuevo->sig=NULL;
    return nuevo;


}



void listaAgregar (struct Nodo *nuevo, struct Nodo **h, struct Nodo **t)
{
    if (*h==NULL)
    {
        *h=nuevo;
        *t=nuevo;
        return;
    }
    (*t)->sig=nuevo;
    (*t)=nuevo;

}

struct Nodo *retiraNodo(struct lista *lista){
struct Nodo *aux;

if (lista->h1==NULL)
    return NULL;
if (lista->h1==lista->t1){
    aux=lista->h1;
    lista->h1=lista->t1=NULL;
    return aux;
}
aux=lista->h1;
lista->h1=lista->h1->sig;
aux->sig=NULL;
return aux;

}

int main()
{
    struct Nodo *h1, *t1,*q,*rN;
    h1=NULL;
    t1=NULL; /**La lista esta vacia **/
    q = crearNodo(10);
    listaAgregar(q,&h1,&t1);
    q = crearNodo(20);
    listaAgregar(q,&h1,&t1);
    q = crearNodo(40);
    listaAgregar(q,&h1,&t1);

    q=h1;


    while (q!=NULL)
    {
        printf("%2d>> ", q->info);
        q=q->sig;
    }
    printf("NULL\n");



    q=retiraNodo(q);
     while (q!=NULL)
    {
        printf("%2d>> ", q->info);
        q=q->sig;
    }
    printf("NULL\n");


    return 0;



}
