x = [1,2,3,4,5,6,7,8,9]

# reverse the list
print(x[-1::-1])

# append (single addition at a time)
x.append(10)
print(x)

# extend (add more than one element)
# x.extend(11,12,13)
# TypeError: extend() takes exactly one argument (3 given)
# extend require the agruments to be in list form
x.extend([11, 12, 13])
print(x)

# Deleting element 
# del() remove particular index
del(x[0])
# delete the first argument then resize the list and then delet the next agrument
del(x[0], x[6])
# delete a group of indexes
del(x[0:3:2])
# remove element with the give value 
x.remove(12)
print(x)

# create a list in range
y = list(range(50))
#print(y)
even = y[::2]
odd = y[1::2]

print(even)
print(odd)

# insert value are particular position
even.insert(0, "hello")
print(even)
l = [1,2,3,4,5,6,7,8,9]
l[2:5] = [10,11,12]
print(l)

# add values at start/end of list
l = l + [10,11,12,13]
print(l)
l = [-3,-2,-1,0] + l
print(l)

# Swapping of values
a = 4
b = 3
print("a = ", a, " b = ", b)
a,b = b,a 
print("after swaping a =", a, " b =", b)
