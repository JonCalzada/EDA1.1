#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "lista.h"



int main() {
   int op1,op2;/**para los menus**/
   int w;/**para los ciclos**/
   char nomArma[20],codigo[8]; /** para nombre del arma y codigo del arma**/
   float cantBajas; /**Cantidad de daño**/
   int tipoarma; /**Asignar el tipo de arma**/
   typeattack tipoArma; /** enum de las armas**/
   Lista *lista; /**estructura tipo lista**/
   lista=nuevaLista(); /** Se crea la estructura**/
   Nodo *q;
   do{                                                   /** Menu principal**/
      printf("\n| -----------------------   |");
      printf("\n|              Menu         |\n");
        printf("| 1)-Agregar arma           |\n");
        printf("| 2)-Activar y detonar      |\n");
        printf("| 3)-Mostrar armas al reves |\n");
        printf("| 4)-Mostrar armas          |\n");
        printf("| 5)-Buscar arma            |\n");
        printf("| 6) -Salir                 |\n");
       printf(" --------------------------   \n ");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1){
        case 1:
            printf("\nIngresa el nombre del arma:");
            fflush(stdin);
            gets(nomArma);

            printf("\n|----------------------- |\n");                /** Menu para el tipo de arma**/
            printf("| ¿Que tipo de arma es? |\n");
            printf("|1)- quimica            |\n");
            printf("|2)- nuclear            |\n");
            printf("|3)- biologica          |\n");
            printf("|-----------------------|\n");
            scanf("%d",&tipoarma);
                switch(tipoarma){
                case 1:
                    tipoArma=quimica;
                    break;
                case 2:
                    tipoArma=nuclear;
                    break;
                case 3:
                    tipoArma=biologica;
                    break;
                    default:
                printf("Ingrese valores validos");
                break;
                }
                printf("\n Codigo de activacion :");
            fflush(stdin);
            gets(codigo);

            printf("\nCantidad de daño(en miles de personas):");
            scanf("%f",&cantBajas);

            q=nuevoNodo(nomArma,codigo,tipoArma,cantBajas);
            agregarFinal(q,lista);
            printf("\nEl arma fue ingresada con exito");
            break;
        case 2:
            printf("\nIngresa el nombre del arma:");
            fflush(stdin);
            gets(nomArma);
            printf("\nIngresa el codigo:");
            fflush(stdin);
            gets(codigo);
            q=retirar(lista,nomArma,codigo);
            if(q==NULL)
                printf("No tienes armas");
              else{
                printf("Ejecucion exitosa\n");
              }
            break;
        case 3:
            printf("\nEstas son las armas");
            imprimeListaInversa(lista);
            break;
        case 4:
            printf("\nEstas son las armas");
            imprimeLista(lista);
            break;
        case 5:
            printf("Ingrese el nombre del arma:");
            fflush(stdin);
            gets(nomArma);
            q=buscar(lista,nomArma);
            while(q!=NULL){
                imprimeNodo(q);
              printf("\n|-----------------------  |");  /**Menu para buscar un arma**/
              printf("\n| 1)-arma siguiente|     \n");
                printf("| 2)-arma anterior       |\n");
                printf("| 3-detonar arma         |\n");
                printf("| 4)-salir de la busqueda|\n");
                printf("|-----------------------  |\n");

                scanf("%d",&op2);
                switch(op2){
                case 1:
                     if(q->sig==NULL)
                        printf("\nHas llegado al final de la lista");
                        else{
                        q=buscarSiguiente(q,nomArma);
                            imprimeNodo(q);
                        }
                        q=q->sig->sig;
                    break;
                case 2:
                     if(q->ant==NULL)
                        printf("\nHas llegado al final de la lista");
                        else{
                     q=buscarAnterior(q,nomArma);
                     imprimeNodoInverso(q);
                        }
                        q=q->ant->ant;

                    break;
                case 3:
                    q=retirar(lista,q->nombre,q->codigo);
                    break;
                case 4:
                    q=NULL;
                    break;
                }
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n Dato invalido\n");
            system("pause");
            break;
        }
        w=1;
   }while(w==1);
    return 0;
}


