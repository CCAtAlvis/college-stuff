date = input("enter the date: ").split()
dd = int(date[0])
yyyy = int(date[2])
mm = date[1]

l = []
l.append(yyyy)
l.append(mm)
l.append(dd)

t = tuple(l)
print(t)
