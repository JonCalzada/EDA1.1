def primero(universo):
	if universo == []:
		return ""
	primer = universo[0]
	universo.pop(0)
	return primer

def siguiente(universo):
	if universo == []:
		return ""	
	res = universo[0]
	universo.pop(0)
	return res

def UniversoPosibles(s,sub):
	u = []
	k = len(sub)
	for n in range(0,len(s)):
		u.append(s[n:n+len(sub)])
	return u





def prueba(candidato,valor):
	return candidato == valor

def fuerzaBruta(s,sub):
	n = 0
	posibles = UniversoPosibles(s,sub)
	candidato = primero(posibles)
	while (candidato!=""):
		if (prueba(candidato,sub)):
			n = n+1
		candidato = siguiente(posibles)
	return n

def main():
	cadena = "sdfjndksfjsdksdsf"
	x = "sd"
	print(fuerzaBruta(cadena,x))

if __name__ == "__main__":
	main()
