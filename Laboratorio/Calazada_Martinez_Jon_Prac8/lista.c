#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

/** Prepara la nueva lista */

Lista *nuevaLista() {
    Lista *nueva;
    nueva = malloc(sizeof(Lista));
    if (nueva == NULL) {
        printf("nuevaLista(): No hay memoria suficiente para crear una lista\n");
        exit(0);
    }
    nueva->h = NULL;
    nueva->t = NULL;
    return nueva;
}

/** Funcion para identificar si una lista está vacia */
int listaVacia(Lista *lista) {
    if (lista->h==NULL)
        return 1;
    return 0;
}

/** FUNCIONES PARA AGREGAR UN NODO */

void agregarFinal(Nodo *nodo,Lista *lista) {
    Nodo *ultimo;
    if (nodo == NULL) {
        return;
    }
    if (listaVacia(lista)) {
        lista->h = nodo;
        lista->t = nodo;
        return;
    }
    ultimo = lista->t;
    ultimo->sig = nodo;
    nodo->ant=ultimo;
    lista->t = nodo;
}

int agregarDespuesDe(Nodo *nodo, char clave[], Lista *lista) {
    Nodo *p;
    if (nodo == NULL) {
        return 0;
    }
    if (listaVacia(lista))
        return 0;
    p = buscar(lista,clave);
    if (p==NULL)
        return 0;
    if (p==lista->t) {
        agregarFinal(nodo,lista);
        return 1;
    }
    nodo->sig = p->sig;
    p->sig->ant=nodo;
    p->sig = nodo;
    nodo->ant=p;
    return 1;
}

/** FUNCIONES PARA RETIRAR UN NODO */

Nodo *retirarInicio(Lista *lista) {
    Nodo *nodo;
    if (listaVacia(lista))
        return NULL;
    if (lista->h == lista->t) {
        nodo = lista->h;
        lista->h = NULL;
        lista->t = NULL;
        return nodo;
    }
    nodo = lista->h;
    lista->h = (lista->h)->sig;
    nodo->sig = NULL;
    lista->h->ant=NULL;
    return nodo;
}

Nodo *retirarFinal(Lista *lista) {
    Nodo *nodo, *p;
    if (listaVacia(lista))
        return NULL;
    if (lista->h == lista->t) {
        nodo = lista->h;
        lista->h = NULL;
        lista->t = NULL;
        return nodo;
    }
    p = lista->h;
    while (p->sig != lista->t)
        p=p->sig;
    nodo = lista->t;
    p->sig = NULL;
    nodo->ant=NULL;
    lista->t = p;
    return nodo;
}

Nodo *retirar(Lista *lista,char nombre[],char clave[]){
    Nodo *nodo, *nodoAnt;
    if (listaVacia(lista))
        return NULL;
    if (strcmp(lista->h->nombre,nombre)==0 && strcmp(lista->h->codigo,clave)==0) {
                    printf("El ataque fue exitoso\n");

        return retirarInicio(lista);
    }
    if (strcmp(lista->t->nombre,nombre)==0 && strcmp(lista->t->codigo,clave)==0) {
                    printf("El ataque fue exitoso\n");

        return retirarFinal(lista);
    }


    nodoAnt=NULL;
    nodo=lista->h;
    while ((nodo!=NULL)&&strcmp(nodo->nombre,nombre)!=0&&strcmp(nodo->codigo,clave)!=0) {
        nodoAnt = nodo;
        nodo = nodo->sig;
        }

    if (nodo == NULL){
        printf("\nNo existe el arma o contraseña incorrecta");
        return NULL;
    }
    nodoAnt->sig = nodo->sig;
    nodo->sig->ant=nodoAnt;
    nodo->sig = NULL;
    nodo->ant=NULL;

    imprimeNodo(nodo);
    printf("\n  ejecucion exitosa. Enemigos eliminados :%3.f,\n ",nodo->cantBajas);
    return nodo;
};

/** FUNCIONES PARA BUSCAR UN NODO */

Nodo *buscar(Lista *lista,char nomArma[]) {
    Nodo *nodo;
    if (listaVacia(lista))
        return NULL;
    nodo = lista->h;
    while ((nodo!=NULL) && (strcmp(nodo->nombre,nomArma)!=0))
        nodo = nodo->sig;
    if(nodo==NULL)
        return NULL;
    return nodo;
};

   Nodo *buscarSiguiente(Nodo *nodo, char nomArma[]) {
    if (nodo==NULL)
        return NULL;
    while ((nodo!=NULL)&&(strcmp(nodo->nombre,nomArma)==0))
        nodo = nodo->sig;
    return nodo;
}

Nodo *buscarAnterior(Nodo *nodo, char nomArma[]) {
    if (nodo==NULL)
        return NULL;
    while ((nodo!=NULL)&&(strcmp(nodo->nombre,nomArma)!=0))
        break;
        nodo = nodo->ant;
    return nodo;
}

/**FUNCIONES PARA IMPRIMIR**/

void imprimeNodo(Nodo* nodo) {
    int op=nodo->arma;
        switch(op){
        case 0:
            printf("\n Arma: %s",nodo->nombre);
    printf("\t Tipo de ataque: quimica");

    printf("\tCapacidad de aniquuilacion: %.3f",nodo->cantBajas);
        break;
        case 1:
             printf("\n Arma: %s",nodo->nombre);
    printf("\t Tipo de ataque: nuclear");

    printf("\tCapacidad de aniquuilacion: %.3f",nodo->cantBajas);
        case 2:
             printf("\n Arma: %s",nodo->nombre);
    printf("\t Tipo de ataque: biologica");

    printf("\tCapacidad de aniquuilacion: %.3f",nodo->cantBajas);
        default:
            break;
        }

}

void imprimeNodoInverso(Nodo* nodo) {
    printf("[%s]->",nodo->nombre);
    if (nodo->ant==NULL)
        printf("Tierra\n");
}

void imprimeLista(Lista *lista){
    Nodo *cabeza;
    if(listaVacia(lista)){
        printf("\nNO hay elementos");
        return;
    }
    cabeza=lista->h;
    while(cabeza!=NULL){
        imprimeNodo(cabeza);
        cabeza=cabeza->sig;
    }
    if(cabeza==NULL)
        printf("\nTIERRA");
}
void imprimeListaInversa(Lista *lista){
    Nodo *cola;
    if(listaVacia(lista)){
        printf("\nNo hay elementos");
        return;
    }
    cola=lista->t;
    while(cola!=NULL){
        imprimeNodo(cola);
        cola=cola->ant;
    }
    if(cola==NULL)
        printf("\nTIERRA");
}
