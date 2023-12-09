#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"


int main()
{
    int op;
    struct Persona *q,*p,*NodoBuscar;
    struct Nodo *Nodo;
    struct Lista *lista1;
    lista1=crearLista();
    do{
      do{
     printf("\n|            Menu               |\n");
     printf("|1)-Agregar:                    |\n");
     printf("|2)-buscar:                     |\n");
     printf("|3)-Borrar:                     |\n");
     printf("|4)-Listar todos los contactos: |\n");
     printf("|5)-Salir:                      |\n");
     printf("--------------------------------|\n");
     scanf("%d",&op);
       if(op<1||op>5)
        printf("Dato invalido");
      }while(op!=1&&op!=2&&op!=3&&op!=4&&op!=5);
     switch(op){
 case 1:
    q=crearPersona();
    if(q==NULL)
        printf("La edad debe suer mayor que 0 y menor a 100");
        else{
    Nodo=crearNodo(*q);
    listaAgregar(Nodo,lista1);}
    break;
     case 2:


    NodoBuscar=BuscarEnLista(lista1);
    if(NodoBuscar==NULL)
        printf("Lista vacia");
        else

        printf("Nombre: %s,Tel: %d,Edad %d-->",NodoBuscar->nombre,NodoBuscar->tel,NodoBuscar->edad);
        printf("                            ");
    break;
     case 3:
    q=borrar(lista1);
    p=q;
    free(p);




    break;
     case 4:

    imprimirLista(lista1);
    break;

     case 5:
         op=8;
         break;
     }
    }while (op!= 8);


    return 0;
}
