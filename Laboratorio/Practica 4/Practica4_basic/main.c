#include <stdio.h>
#include <stdlib.h>
 //Calzada Martínez Jonathan Omar
//Se crea una estructura Datos
 struct Datos
{
    char nombre [30];
    char apellido [30];
};
   // SE CREA UNA ESTRUCTURA PELICULA
typedef struct
{
     char pelicula [30];
     int N_ejemplares;
     float precio;
     float Monto_invertido;
     struct Datos aut,dir;
}pelicula;


// SE DECLARAN LOS PROTOTIPOS
void imprimeCatalogo(pelicula *h ,int Npeliculas,float *monIn,int sumaTotal);
float calculaInversion (pelicula *h,int N_ejemplares,float precio,float monIn);

 void leerCatalgo(pelicula *h ,int Npeliculas,float monIn[], float *sumaTotal);

 //FUNCION PRINCIPAL DONDE SE LLAMAN LAS FUNCIONES Y SE PIDE LA CANTIDAD DE PELICULAS

int main()
{

    pelicula *catalogo;
    int k,Npeliculas;
    float sumaTotal;

    printf("¿Cuantas peliculas desea ingresar?");
    scanf("%d",&Npeliculas);

    float monIn[Npeliculas];
    catalogo= (pelicula *)malloc(Npeliculas*sizeof( pelicula));

    leerCatalgo(catalogo,Npeliculas, monIn, &sumaTotal);

    imprimeCatalogo(catalogo,Npeliculas, monIn, sumaTotal);

//---------------------------------------------------
    return 0;
}


//FUNCION QUE LEE EL CATALOGO DE PELICULAS

 void leerCatalgo(pelicula *h,int Npeliculas,float monIn[],float *sumaTotal){
    int k;
    *sumaTotal=0;

    for (k=0;k<Npeliculas;k++){
        fflush(stdin);
        printf("Deme el nombre del autor : %d\n", k+1);
        fflush(stdin);
        gets(h->aut.nombre);
        printf("Deme el apellido del autor : %d", k+1);
        fflush(stdin);
        gets(h->aut.apellido);
        printf("Deme el el nombre del actor principal: %d \n", k+1);
        fflush(stdin);
        gets(h->dir.nombre);
        printf("Deme el apellido del actor principal : %d \n",k+1);
        fflush(stdin);
        gets(h->dir.apellido);
        printf("Deme el numero de ejemplares : %d \n", k+1);
        scanf("%d",&h->N_ejemplares);
        printf("Deme el precio : %d \n", k+1);
        scanf("%f",&h->precio);

        monIn[k]=calculaInversion (h, h->N_ejemplares, h->precio, monIn[k]);

        *sumaTotal=*sumaTotal+monIn[k];

        h=h+1;
     }
 }

 //FUNCION QUE CALCULA LA INVERSION DE CADA PELICULA
 float calculaInversion (pelicula *h,int N_ejemplares,float precio,float monIn)
 {
    monIn=h->N_ejemplares*h->precio;

    return monIn;

 }

//FUNCION QUE IMPRIME EL CATALOGO Y EL MONTO FINAL DE LA INVERSION
void imprimeCatalogo(pelicula *h ,int Npeliculas,float monIn[Npeliculas],int sumaTotal)
    {
        int k;


        printf("EXISTENCIA \n");
        for (k=0;k<Npeliculas;k++){
            printf(" el nombre del autor : %s \n", h->aut.nombre);
            printf(" el apellido del autor: %s \n" ,h->aut.apellido );
            printf(" el el nombre del actor principal: %s  \n",h->dir.nombre);
            printf(" el apellido del actor principal: %s \n",h->dir.apellido);
            printf(" el numero de ejemplares: %d \n",h->N_ejemplares);
            printf(" el precio: %f \n",h->precio);

            printf(" el Monto invertido en el libro %d : %f \n ",k+1, monIn[k]);

            printf("\n\n  ------------------------------------------------\n\n");
            h=h+1;
        }
        printf(" el Monto invertido en los libros es  : %d\n", sumaTotal);


    }
