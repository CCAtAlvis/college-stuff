import time
start_time = time.clock()

string = raw_input("enter the string to encode \n")
encode = decode = temp = ''
i = 0

print "\nthe length of the string is : " , len(string) , "\n"

while i < len(string):
	temp = (i+1)*ord(string[i])
	if temp/1000 > 0:
		temp = str(temp)
	elif temp/100 > 0:
		temp = str(temp)
		temp = '0'+temp
	elif temp/10 > 0:
		temp = str(temp)
		temp = '00'+temp

	encode += temp
	i += 1

print "the encoded string is\n" + encode + "\n"

i = j = 0
while i < len(encode)/4:
	j = 4*i
	if encode[j] == 0:
		if encode[j+1] == 0:
			if encode[j+2] == 0:
				temp = chr(encode[j+3])
			else:
				temp = int(encode[j+2] + encode[j+3])
				temp = temp/(i+1)
		else:
			temp = int(encode[j+1] + encode[j+2] + encode[j+3])
			temp = temp/(i+1)
	else:
		temp = int(encode[j] + encode[j+1] + encode[j+2] + encode[j+3])
		temp = temp/(i+1)

	temp = chr(temp)
	decode += temp
	i += 1

print "the decoded string is\n" + decode + "\n"

print"--- %s seconds ---" % (time.clock() - start_time)