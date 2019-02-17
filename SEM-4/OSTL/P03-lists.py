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

	l3 = []

	for i in range(len(l1)):
		l1[i] = int(l1[i])
	for i in range(len(l2)):
		l2[i] = int(l2[i])

	for i in len(l1):
		l3.append(i)
	for i in len(l2):
		l3.append(i)

	l3.sort()
	print(l3)

def minMax():
	ip = input("enter data for lis1: ")
	l1 = ip.split()

	for i in range(len(l1)):
		l1[i] = int(l1[i])

	l1.sort()
	print("min:", l1[0], "\tmax:",l1[len(l1)-1])


def op3():
	ip = input("enter list of data: ")
	l = ip.split()
	ip = input("enter new element: ")
	l[0] = ip
	mid = len(l)//2
	del(l[mid])

	print("the new list is", l)


def op5():
	ip = input("enter list of data: ")
	l = ip.split()
	ip = int(input("enter number of new entries: "))

	for i in range(ip):
		name = input("enter data: ")
		l.append(name)

	if "python" in l:
		print("\"python\" exist in the list")
	else:
		print("\"python\" does not exist in the list")


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
