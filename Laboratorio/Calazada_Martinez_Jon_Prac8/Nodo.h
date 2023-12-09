#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

enum typeattack {quimica, nuclear, biologica};
typedef enum typeattack typeattack;
struct Nodo {
    char nombre[20];
    char codigo[8];
    typeattack arma;
    float cantBajas;
    struct Nodo *sig;
    struct Nodo *ant;
};

typedef struct Nodo Nodo;

Nodo* nuevoNodo(char name[20],char codigo[8],typeattack arma,float cantBajas);




struct Lista {
    Nodo *h;
    Nodo *t;
};

typedef struct Lista Lista;


Lista *nuevaLista();
int listaVacia(Lista *lista);

void agregarFinal(Nodo *nodo,Lista *lista);
void agregarInicio(Nodo *m, Lista *lista);
int agregarDespuesDe(Nodo *nodo, char clave[], Lista *lista);

Nodo *retirarFinal(Lista *lista);
Nodo *retirar(Lista *lista,char nombre[] ,char clave[]);

Nodo *buscar(Lista *lista, char clave[]);
Nodo *buscarSiguiente(Nodo *nodo, char nomArma[]);
Nodo *buscarAnterior(Nodo *nodo, char nomArma[]);


void imprimeNodo(Nodo* nodo);
void imprimeLista(Lista *lista);
void imprimeListaInversa(Lista *lista);
void imprimeNodoInverso(Nodo* nodo);

#endif // NODO_H_INCLUDED
