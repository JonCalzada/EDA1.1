# -*- coding: utf-8 -*-
"""
Editor de Spyder

Este es un archivo temporal
"""

def cambio(monto,denominaciones):
    resultado=[]
    while (monto>0):
        if (monto >= denominaciones[0]):
            numeracion= monto//denominaciones[0]
            resultado.append([denominaciones[0],numeracion])
            monto = monto-(numeracion*denominaciones[0])
        denominaciones=denominaciones[1:]
    return resultado

def main():
    #Prueba del algoritmo
    print("\nAlgoritmo: AVIDO: ")
    print ("\t$1,000 -->",cambio(1000, [500,200,100,50,20,5,1]))
    print ("\t$  500 -->",cambio(500, [500,200,100,50,20,5,1]))
    print ("\t$  300 -->",cambio(300, [50,20,5,1]))
    print ("\t$  200 -->",cambio(200, [5]))
    print ("\t$   98 -->",cambio(98, [50,20,5,1]))
    
main()