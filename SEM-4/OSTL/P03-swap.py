# swap 2 no. and check if the first no is +ve, -ve, or 0
a = int(input("enter nubmer 1: "))
b = int(input("enter number 2: "))

a,b = b,a

print("the swapped no. are a=",a ,"and b=",b)

if a==0:
	print("a is 0")
elif a<0:
	print("a is -ve number")
else:
	print("a is +ve number")
