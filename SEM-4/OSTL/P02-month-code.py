# return the month number
str = "JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC"
mon = str.split()
code = {}

for i in range(len(mon)):
	code[mon[i]] = i+1;

ip = input("enter the month name: ").upper()[:3]

#ip = input("enter the month name: ")
# ip = ip.upper()
# ip = ip[:3]

# ip = ip[:3].upper()
# ip = ip.upper()[:3]

print(code[ip])
