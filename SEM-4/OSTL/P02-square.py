# return square of integers
y = input("enter integers ")
y = y.split()
# print(y)

result1 = []
result2 = []

#method 1
for x in range(len(y)):
	result1.append( int(y[x]) ** 2 )

# method 2
for i in y:
	 result2.append( int(i) ** 2 )

print(result1)
print(result2)
