import matplotlib.pyplot as plt

import random
import time

# si no tiene instalado matplotlib:
# abrir cmd y ejcutar
# pip install matplotlib

def genera(n):
    x = []
    for k in range(n):
        x.insert(0,random.randint(0,n))
	# y = random.sample(range(n),n)        
    return x


def sortIntercambio(lista):
    n = len(lista)
    p=0
    while p<n-1:
        j=p+1
        while j<n:
            if lista[p]>lista[j]:
                aux = lista[p]
                lista[p]=lista[j]
                lista[j]=aux
            j=j+1
        p=p+1
