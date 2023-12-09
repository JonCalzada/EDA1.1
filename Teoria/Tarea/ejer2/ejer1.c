#include <stdio.h>
#include<stdio.h>
/* Se inicializo un Array de 5 elementos,
Y por medio de un ciclo for se mostro cada uno de los elementos*/

/*Al valor dentro de *p que es 1.3 se le suma "k" en cada ciclo, entonces en el cliclo uno
tendra 1.3, en el dos 2.3, en el 3, 3.3 y así sucesivamente */

/*SE LE ASIGNO LA DIRECCIÓN DEL PRIMER VALOR DEL ARREGLO A LA VARIABLE *P Y CON ELLA SE OPERO EL ARREGLO EN EL CICLO FOR*/
int main (){

double x[5]={1.3,2.4,3.3,6.7,0.0};
double *p;
int k;



p=&x[0];
for(k=0;k<5;k++)
    printf("%5.2f\n",p[k]);
printf("------------- \n");
return 0;
}



