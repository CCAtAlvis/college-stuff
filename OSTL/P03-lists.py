# asdfasdfasdf
def evenOdd():
	ip = input("enter numbers: ")
	l = ip.split()
	odd = []
	even = []
	for i in range(len(l)):
		l[i] = int(l[i])

		if l[i]%2 == 0:
			even.append(l[i])
		else:
			odd.append(l[i])

	print("even numbers are: ",even)
	print("odd numbers are: ",odd)


def mergeAndSort():
	ip = input("enter data for lis1: ")
	l1 = ip.split()
	ip = input("enter data for list2: ")
	l2 = ip.split()	
	
	for i in range(len(l)):
		l1[i] = int(l1[i])
		l2[i] = int(l2[i])


def minMax():
	pass


def op3():
	ip = input("enter list of data: ")
	l = ip.split()
	ip = input("enter new element: ")
	lp[0] = ip
	mid = len(l)//2
	del(l[mid])

	print("the new list is", l)


def op5():
	pass

print("Menu")
print("1. sort in even and odd lists")
print("2. Merge & sort")
print("3. update first element and delete mid element")
print("4. find min and max")
print("5. add n names and check if \"python\" exits")

ip = int(input("enter option: "))

if ip == 1:
	evenOdd()
elif ip == 2:
	mergeAndSort()
elif ip == 3:
	op3()
elif ip == 4:
	minMax()
elif ip == 5:
	op5()
else:
	print("enter valid choise")
