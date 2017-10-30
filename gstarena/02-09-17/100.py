f = open("100.in", "r")
arrSize = int(f.readline())
arr =  []
opArr = []

i = 0
while i < arrSize:
	l = f.readline()

	if l[2:] == '\n':
		l = l[:-1]

	arr.append(l)
	i += 1

i = 0
while i < arrSize:
	if arr[i] == 100 :
		opArr = opArr
	elif arr[i] == 'VD' :
		opArr.append("Valar Dohaeris")
	elif arr[i] == 'VM' :
		opArr.append("Valar Morghulis")
	else :
		opArr.append("He is dead")

	i += 1


i = 0
while i < arrSize:
	print opArr[i]
	i += 1