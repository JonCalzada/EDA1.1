#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo.h"

Nodo* nuevoNodo(char name[],char codigo[],typeattack arma,float cantBajas) {
    struct Nodo *nodo;
    nodo = malloc(sizeof(struct Nodo));
    if (nodo == NULL) {
        printf("No hay memoria suficiente para crear un nodo\n");
        exit(0);
    }
    strcpy(nodo->nombre,name);
    strcpy(nodo->codigo,codigo);
    nodo->arma=arma;
    nodo->cantBajas=cantBajas;
    nodo->sig = NULL;
    nodo->ant = NULL;
    return nodo;
}

