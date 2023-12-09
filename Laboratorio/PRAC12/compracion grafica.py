import matplotlib.pyplot as plt

import random
import time

"""# si no tiene instalado patplotlib:
# abrir cmd y ejcutar
# pip install matplotlib"""

def genera(n):
    x = []
    for k in range(n):
        x.insert(0,random.randint(0,n))
	# y = random.sample(range(1000),50)        
    return x


def sortIntercambio(lista):
    n = len(lista)
    p=0
    while p<n-1:
        j=p+1
        """#print ("pasada #: {}\n".format(j))"""
        while j<n:
            if lista[p]>lista[j]:
                aux = lista[p]
                lista[p]=lista[j]
                lista[j]=aux
            j=j+1
        p=p+1

def ordenamientoBurbuja(unaLista):
    for numPasada in range(len(unaLista)-1,0,-1):
        for i in range(numPasada):
            if unaLista[i]>unaLista[i+1]:
                temp = unaLista[i]
                unaLista[i] = unaLista[i+1]
                unaLista[i+1] = temp

def graficarTiempos(numDatos,tiemposIntercambio,tiemposQuick,tiemposBurbuja):
    fig, ax= plt.subplots()
    plt.title("Tiempo de ejecución[seg] Intercambio")
    
    ax.set_xlabel("Numero de Datos")
    ax.set_ylabel("Tiempo")
    ax.grid(True)

    ax.plot(numDatos, tiemposBurbuja, label ="Ordenamiento de burbuja", marker=".", color ="g")
    ax.plot(numDatos, tiemposIntercambio, label ="Ordenamiento de la Intercambio", marker="*", color ="r")
    ax.plot(numDatos, tiemposQuick, label ="Ordenamiento de QuickSort", marker="x", color ="b")
    ax.legend(loc='upper left')


    plt.show()        

def eficienciaAlgoritmos(numDatos):
    tiemposBurbuja=[]
    tiemposIntercambio= []
    tiemposQuick = []
    for n in numDatos:
        #lista_Intercambio = random.sample(range(1000), n)
        lista_Intercambio = genera(n)
        lista_quick = lista_Intercambio.copy()
        lista_Burbuja = lista_Intercambio.copy()



        print("\n=========\n")
        #print (lista_Intercambio)
        t0 = time.clock()
        sortIntercambio(lista_Intercambio)
        dt = round(time.clock()-t0,6)
        tiemposIntercambio.append(dt)
        print("\nIntercambio(n={}): Tiempo transcurrido: {} seg".format(n,round(dt,6)))
        #print("\nLISTA ORDENADA\n")
        #print (lista_Intercambio)
        t0 = time.clock()
        lista_quick.sort() #<----- se emplea el ordenamiento implementado en python
        dt = round(time.clock()-t0,6)
        tiemposQuick.append(dt)
        print("\nQuickSort(n={}): Tiempo transcurrido: {} seg".format(n,round(dt,6)))
        #Print("LISTA BURBUJA")
        t0=time.clock()
        ordenamientoBurbuja(lista_Burbuja)
        dt = round(time.clock()-t0,6)
        tiemposBurbuja.append(dt)
        print("\n ordenamientoBurbuja(n={}): Tiempo transcurrido: {} seg".format(n,round(dt,6)))
    return tiemposIntercambio,tiemposQuick,tiemposBurbuja

def main():
    random.seed()
    numDatos = [100,500,1000,2000,3000,5000]
    tiemposBurbuja = []
    tiemposIntercambio= []
    tiemposQuick = []
    tiemposIntercambio,tiemposBurbuja, tiemposQuick = eficienciaAlgoritmos(numDatos)
    print ("Tiempos de ejecucion intercambio: {}".format(tiemposIntercambio))
    print ("Tiempos de ejecucion QuickSort: {}".format(tiemposQuick))
    print ("Tiempos de ejecucion ordenamientoBurbuja: {}".format(tiemposBurbuja))

    graficarTiempos(numDatos,tiemposBurbuja,tiemposIntercambio,tiemposQuick)

if __name__ == "__main__":
	main()
    
