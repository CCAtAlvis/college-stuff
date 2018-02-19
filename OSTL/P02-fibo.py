# fibo series
n = input("enter the number of terms (greater than 2) ")
n = int(n)
f1 = 0
f2 = 1

result = []
result.extend([f1, f2])

for x in range(n-2) :
	f1, f2 = f2, f1 + f2
	result.append(f2)

print(result)
