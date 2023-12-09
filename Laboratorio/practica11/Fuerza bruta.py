# -*- coding: utf-8 -*-

def primero():
    return [0]

def siguientesub(j,m):
    j=j+1
    if j<=m:
        return j
    return 0

def mostrar(contador):
    print(contador)
    return

def siguiente(i,n):
    i=i+1
    if i<=n:
        return i
    return 0

def valido(i,n,j,m,cadena1,cadena2,contador):
    if cadena1[j]==[i]:
        siguientesub(j,m)
        valido(i,n,j,m,cadena1,cadena2,contador)
        if j==m:
            contador=contador+1
    else:
        j=primero()
        siguiente(i,n)
def main():
    s1="abbd"
    s2="bb"
    t1="jdfabbdjabbdhjabbdlaabbddabb"
    t2="jfbbbfbbbhh"
    contador1=0
    contador2=0
    n1=len(t1)
    i1=primero()
    m1=len(s1)
    j1=primero()
    n2=len(t2)
    i2=primero()
    m2=len(s2)
    j2=primero()
    valido(i1,n1,j1,m1,s1,t1,contador1)
    print("Las veces que se repite 'abbd' es:")
    print(mostrar(contador1))
    valido(i2,n2,j2,m2,s2,t2,contador2)
    print("Las veces que se repite'ss' es:")
    print(mostrar(contador2))
    
    



if __name__ == "__main__":
    main()