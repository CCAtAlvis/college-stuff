msg = '110111'
gx = '11'

def xor(a, b):
	return str(int(a) ^ int(b))

for i in range(len(gx)-1):
	msg += '0'

rem = list(msg[:len(gx)])

for i in range(len(gx), len(msg)):
	for j in range(len(gx)):
		rem[j] = xor(rem[j], gx[j])
	print(rem)

	for j in range(len(rem)):
		if rem[j] == 1:
			rem = list(rem[j:])
			break
	print(rem)
	print("\n\n\n")
	
	#rem = int(''.join(rem))
	#if rem == 0:
	#	rem = list()
	#	rem = msg[i:i+1]
	#	i += 2
	#if rem == 1:
	#	rem = list()
	#	rem = [1, msg[i]]
	#	i += 1

	#print(rem)
	#rem = list(rem)

	#while len(rem) != 2:
	#	rem[0] = rem[1]
	#	rem[1] = rem[i+1]
	#	i += 1

