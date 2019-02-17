# program to understand sets in python
str1 = input("enter string 1: ")
str2 = input("enter string 2: ")

s1 = set(str1)
s2 = set(str2)

# display common letters in 2 strings
op1 = []
for x in s1 :
	if x in s2:
		op1.append(x)
print(op1)

# display letters which are in first string and not in second
op2 = []
for x in s1:
	if x not in s2:
		op2.append(x)
print(op2)

# set of letter in both string
op3 = []
for x in s1:
	if x in s2:
		op3.append(x)
print(op3)

# set of letters either in string 1 or string 2
op4 = []
for x in s1:
	if x not in s2:
		op4.append(x)
for x in s2:
	if x not in s1:
		op4.append(x)
print(op4)
