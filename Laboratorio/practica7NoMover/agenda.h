#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

struct Persona{
 char nombre[30];
 int tel;
 int edad;
};

struct Nodo{
 struct Persona info;
 struct Nodo *sig;
};

struct Lista{
   struct Nodo *h;
   struct Nodo *t;
};

struct Persona *crearPersona();
void imprimirLista (struct Lista *lista);
void listaAgregar(struct Nodo *nuevo, struct Lista *lista);
struct Nodo *crearNodo(struct Persona dato);
struct Lista *crearLista();
struct Nodo* BuscarEnLista(struct Lista *lista);
struct Nodo *borrar(struct Lista* lista);
/**struct BorraFinal(struct Lista *lista);
struct BorraInicio(struct Lista *lista);**/
































































































































































#endif // AGENDA_H_INCLUDED
