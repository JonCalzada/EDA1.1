#include <stdio.h>
#include<stdio.h>
/* Se inicializo un Array de 5 elementos,
Y por medio de un ciclo for se mostro cada uno de los elementos*/

/*Al valor dentro de *p que es 1.3 se le suma "k" en cada ciclo, entonces en el cliclo uno
tendra 1.3, en el dos 2.3, en el 3, 3.3 y as� sucesivamente */

/*SE LE ASIGNO LA DIRECCI�N DEL PRIMER VALOR DEL ARREGLO A LA VARIABLE *P Y CON ELLA SE OPERO EL ARREGLO EN EL CICLO FOR*/

/*Muestra en pantalla las direcciones de memoria de lod nuemeros inicializados */
/*Muestra las direcciones de memoria en donde se encuentran los datos inicializados de con el indice del for y el ampersand*/
/*Nos muestra el los valorez inicializados en el arreglo accediendo a la direcci�n de memoria*/
int main (){


double x[5]={1.3,2.4,3.3,6.7,0.0};
int k;

printf("Tamanio de un double: %d bytes \n\n", sizeof(double));
for(k=0;k<5;k++){
    printf("%5.2f\n",*(x+k));


}

return 0;
}



