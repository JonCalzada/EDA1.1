#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
struct Persona *crearPersona()
{
    int edad;
    struct Persona *nuevo;
    /**Se crea el nodo**/
    nuevo=malloc(sizeof(struct Persona));
    do{

    printf("Dame el nombre: \n");
    fflush(stdin);
    gets(nuevo->nombre);
    printf("Dame el telefono: ");
    scanf("%d", &nuevo->tel);
    printf("Deme la edad: \n");
    scanf("%d",&edad);
    if(edad>0&&edad<100)
    nuevo->edad=edad;
    else{
        return NULL;
        }

    }while(edad<0&&edad<100);
    return nuevo;

};

struct Lista *crearLista()
{
    struct Lista *unaLista;
    unaLista=malloc(sizeof(struct Lista));
    unaLista->h=NULL;
    unaLista->t=NULL;
    return unaLista;
};

struct Nodo *crearNodo(struct Persona dato)
{
    struct Nodo *nuevo;
    nuevo=malloc(sizeof(struct Nodo));
    nuevo->info=dato;
    nuevo->sig=NULL;
    return nuevo;
};
void listaAgregar(struct Nodo *nuevo, struct Lista *lista)
{

    if (lista->h== NULL)
    {
        lista->h=nuevo;
        lista->t=nuevo;
        return;
    }
    lista->t->sig=nuevo;
    lista->t=nuevo;
}

void imprimirLista (struct Lista *lista)
{

    struct Nodo *q;
    q=lista->h;
  if(lista->h==NULL)
    printf("Lista vacia");
 else {
        while (q!=NULL)
    {
        printf("\n |Nombre: %s,Tel: %d,Edad: %d| \n>>",q->info.nombre,q->info.tel,q->info.edad);
               printf("                            ");

        q=q->sig;
    }
    printf("NULL ");
    }
}




struct Nodo* BuscarEnLista(struct Lista *lista)
{
    char nomBuscar[30];
    struct Nodo *p;
    if(lista->h==NULL){
     printf("\nLista vacia \n");}
     else{
     printf("Deme el nombre que busca: \n");
         fflush(stdin);
         gets(nomBuscar);
    p=lista->h;
    while(p!=NULL)
    {
        if(strcmp(p->info.nombre,nomBuscar)==0)
            return p;
        p=p->sig;

    }}
    return NULL;
}

struct Nodo *retiraInicio(struct Lista *lista){
    struct Nodo *aux;
    if (lista->h==NULL)
        return NULL;
    if(lista->h==lista->t)
    {
        aux=lista->h;
        lista->h=lista->t=NULL;
        return aux;
    }
    aux=lista->h;
    lista->h=lista->h->sig;
    aux->sig=NULL;
    return aux;
};

struct Nodo *retiraFinal(struct Lista *lista){
struct Nodo *p,*q;
if(lista->h==NULL)
    return NULL;
if(lista->h==lista->t){
    p=lista->h;
    lista->h=lista->t=NULL;
    return p;
}
p=lista->t;
q=lista->h;
while(q->sig!=lista->t){
         q=q->sig;}
    lista->t=q;


 q->sig=NULL;

 return p;
};

struct Nodo *borrar(struct Lista* lista){
struct Nodo *p,*q, *tmp;
 char nomBuscar[30];
 if(lista->h==NULL){
        printf("Lista vacia");
    return NULL;
      }
    printf("Deme el contacto que desea borrar: \n");
         fflush(stdin);
         gets(nomBuscar);
 if(strcmp(lista->h->info.nombre,nomBuscar)==0)
    return retiraInicio(lista);
 if(strcmp(lista->t->info.nombre,nomBuscar)==0)
    return retiraFinal(lista);

 p=lista->h;
 /*
 if(p!=NULL){
    strcpy(p->info.nombre,nomBuscar);
    }*/

 while(p!=NULL && strcmp(p->info.nombre,nomBuscar)!=0){
    //if(strcmp(p->info.nombre,nomBuscar)==0)
      // break;
    p=p->sig;
    if(p==NULL){
        printf("El dato no existe");
        return NULL;
    }
}
 q=lista->h;

 while (q->sig!=p)
    q=q->sig;

 q->sig=p->sig;
 p->sig=NULL;
 return p;


tmp->info=p->info;
p->info=p->sig->info;
p->sig->info=tmp->info;
q=p->sig;
p->sig=NULL;
q->sig=NULL;

return q;
};





/**struct Nodo *borrar(struct Lista* lista){
struct Nodo *q;
char nomBuscar[30];
 if(lista->h==NULL)
    return NULL;
   else{
     printf("Deme el contacto que desea borrar: \n");
         fflush(stdin);
         gets(nomBuscar);
 if(strcmp(lista->h->info.nombre,nomBuscar)==0)
    return q;
 if(strcmp(lista->t->info.nombre,nomBuscar)==0)
    return q;
    }
// p=lista->h;
 }
 while((p!=NULL)&&(p->info.nombre!=nomBuscar))
    if(p==NULL)
    return NULL;
 q=lista->h;
 while (q->sig!=p){
    q=q->sig;
 q->sig=p->sig;
 p->sig=NULL;
 return p;
}
strcpy(tmp,p->info.nombre);
p->info=p->sig->info;
p->sig->info.=p->info.nombre;
q=p->sig;
p->sig=NULL;
q->sig=NULL;
return q;
}};
**/
