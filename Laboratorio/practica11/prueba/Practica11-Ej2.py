# -*- coding: utf-8 -*-
"""
Created on Wed May  2 14:20:31 2018

@author: edaI11alu35
"""

f_parciales=[0,1]

def fibonacci_bottom_up(numero):
    while len(f_parciales) <= numero:
        f_parciales.append(f_parciales[len(f_parciales)-1] + f_parciales[len(f_parciales)-2])
        print("\tn= {}: {}".format(len(f_parciales)-1, f_parciales))
    return f_parciales[numero]

def main():
    numero=10
    print("Numero: {}".format(numero))
    fibonacci_bottom_up(numero)
    
main()