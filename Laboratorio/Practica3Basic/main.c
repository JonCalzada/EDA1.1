#include <stdio.h>
#include <stdlib.h>
    /*Calzada Martínez Jonathan Omar*/
/*Definimos una estructura de llamada Equipo*/
struct Equipo {
   char nombre[10];
   int pts,jGanados,jPerdidos,jEmpatados;
   };

   /*Declaramos una una estructura y 2 funciones una que imprime y otra de efectividad*/
struct Equipo leer (char texto[]);
void imprime (struct Equipo e);
float efectividad (struct Equipo *e);

/*Funcion main, Se muestra un texto del equipo al que hay que poner los registros y se asigna el nuevo puntaje en caso de que gane, pierda, o empeten los equipos*/
int main()
{
    struct Equipo local, visitante;
     int resultado;
    local= leer("Equipo local\n");
    visitante = leer("Equipo visitante\n");


	printf("\n Local ganados: %d\n",local.jGanados);

    printf(" ¿Quien gano el encuentro?\n");
    printf("Si gano local coloque 1\n");
    printf("Si gano visitante coloque 2\n");
    printf("Si empataron coloque 3\n");
    scanf("%d",&resultado);
    switch(resultado)
    {

    case 1:
	   local.pts=local.pts+2;
    break;
    case 2:
    	 visitante.pts=visitante.pts+3;
    	break;
    	case 3:
    	local.pts=local.pts+1;
    	visitante.pts=visitante.pts+1;
    		break;
      }

       imprime(local);
    imprime(visitante);



    return 0;
}
 /*Se asignan los valores a los campos de la estructura por medio de el teclado*/
struct Equipo leer (char texto[]){
       struct Equipo e;

       printf("\n%s\n\n",texto);
       printf("Nombre:");
       fflush(stdin);/**/
       gets(e.nombre);
       printf("Puntajes:");
       scanf("%d", &e.pts);
       printf("Juegos ganados:");
       scanf("%d",&e.jGanados);
       printf("J uegos perdidos:");
       scanf("%d",&e.jPerdidos);
       printf("Juegos empatados:");
       scanf("%d",&e.jEmpatados);

       return e;
}
/*Funcion imprime donde se muestra en pantalla los datos de cada equipo */
void imprime (struct Equipo e){
    float efecti;

    efecti= efectividad(&e);

	printf("\n\n\n%-10s,  tiene %03d pts, Juegos Ganados: %d , Juegos Perdidos: %d , Juegos Empatados: %d , efectividad: %f \n", e.nombre, e.pts, e.jGanados, e.jPerdidos, e.jEmpatados,efecti );
}

/*Funcion efectividad : Por medio de punteros se manda la efectivida a la funcion imprime para que pueda mostrarse en pantalla*/
float efectividad (struct Equipo *e){
 float efecti;
 efecti = (((float)e->jGanados+(float)e->jEmpatados)/(float)(e->jGanados+(float)e->jEmpatados+(float)e->jPerdidos))*100;

return efecti;
}
