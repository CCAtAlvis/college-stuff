# print("hello! ", end="")
# print("hi, there")

# var = "hello"
# print(type(var))

# var = 3 + 4j
# print(type(var))

# var = 354
# print(type(var))

# var = 136.2165
# print(type(var))

# var = True
# print(type(var))

# x, y = 3, 5
# x, y = y, x

# true, false = True, not True
# if true or false:
#	print("hello")

# %s -> string
# %d -> integer
# %f -> float

# str = "hello world"
# print("%s"%str)

# float = 11.53439746374674
# print("%.1f"%float) # sepcified length after decimal point
# print("%f"%float)   # default length of 6 places after decimal point

# int = 34
# print("%f"%int)


# dealing with complex no.
# c = 3 + 6j
# print(c.real)
# print(c.imag)
# print("%1.2f + i%.2f"%(c.real, c.imag))

# number system conversion
# x = 64
# bin = bin(x)
# print(bin)
# print(type(bin))

# hex = hex(x)
# print(hex)
# print(type(hex))

# oct = oct(x)
# print(oct)
# print(type(oct))

# Arithmatics
# operators: + - / * % // **
# a,b = 505, 74

# print(a**b)
# str = "hello"
# print(str*2)
# print("a/b = ", a/b)
# print("a//b = ", a//b)
# print("a%b = ", a%b)

# User Input
# ip = input("enter a number ")
# print("you entered %s, which is suposed to be a number but it is taken as string by default in python" %ip)

#ip = float(input("enter tepmerature "))
#print("Enter \n1. Convert cel -> far\n2. Convert far -> cel : ", end="")
#op = int(input())

#if op == 1:
#	print("temp in far: %.3fF" %(ip*1.8 + 32))
#elif op == 2:
#	print("temp in cel: %.3fC" %( (ip-32)/1.8 ))
#else:
#	print("invalid choice. ")


# string as array
a = "hello LOLO LOLO lo"
# print(a[0])

# a[0]="H"
#####
# STRINGS ARE IMMUATABLE
#####
# print(a)
# print(a.startswith("h"))    # True
# print(a.startswith("hell")) # True
# print(a.endswith("lo"))     # True
# print(a.endswith("e"))      # False

# print(a.upper()) # HELLO
# print(len(a))    # 5

# print(a.index("lo")) # 3

# b = "    s d    f   "
# print(b.strip())
# c = "/\#/\#/\#/\# asdasdasd "
# print(c.strip("/ #\\"))

# hw = "hello world"
# print(hw.replace("world", "Hello"))

spl = "hello, how are you !!!"
print(spl.split())
print(spl.split(","))
print(spl.split("h"))

toJoin = spl.split()
join = "23423".join(toJoin)
print(join)