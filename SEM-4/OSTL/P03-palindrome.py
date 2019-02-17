#
# if type(input) == string:
#   find if palindrome
# elif type(input) == number:
#   find factorial
#   find if palindrome
#

def pal(st):
	l = len(st)
	i = 0
	flag = True
	while i < l//2:
		if st[i] == st[l-i-1]:
			pass
		else:
			flag = False

		i += 1

	return flag


while True:
	print("Menu\n1. for palindrome\n2. for factorial\n3. exit")
	ip = int(input("enter your choise: "))

	if ip == 1:
		st = input("enter number or string: ")

		if pal(st):
			print("the input is a plaindrome")
		else:
			print("the input is not a plindrome")
	elif ip == 2:
		st = int(input("enter number: "))

		i = 1
		fact = 1
		while i <= int(st):
			fact *= i
			i += 1

		print("fact of",ip, "is",fact)

	elif ip == 3:
		break
	else:
		print("enter valid choise")
