d={}
ch = 0
while ch != 5:
	print("\nMenu\n1. Create a dictionary")
	print("2. Update and delete item of dictionary")
	print("3. Find a key and print its value")
	print("4. Map two list into dictionary\n5. Exit")
	ch = int(input("Enter your choice: "))

	if ch == 1:
		n = int(input("Enter number of items: "))
		print("enter key value pair") 
		for i in range(n):
			s = input().split()
			d[s[0]] = s[1]
		print(d)

	elif ch == 2:
		key = input("enter key whose value is to be changed: ")
		temp = input("enter replacement: ")
		d[key] = temp
		print(d)
		key = input("enter key at which you want to delete: ")
		d.pop(key)
		print(d)

	elif ch == 3:
		key = input("enter a key you have to search: ")
		if key in d.keys():
			print("value of key found is:", d[key])
		else:
			print("key not present in dictionary")

	elif ch == 4:
		print("mapped dictionary is: ")
		l1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
		l2 = ['jan','feb','march','april','may','june','july','august','september','october','november','december']
		l3 = dict(zip(l1,l2))
		print(l3)

	elif ch == 5:
		break

	else:
		print("Invalid Choice")
