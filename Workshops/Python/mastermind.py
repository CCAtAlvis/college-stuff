#
# Mastermind : v 1.0.0
# Created by : Chinmay Chandak
# Start      : 8 Jan 2017 Sunday
#

import time
start_time = time.clock()

r = wf = rf = 0
c = []
c.append(0)
inp = "4321" #raw_input("Enter the code ")
#print inp
r = 1

while r < 9:
	if wf + rf != 4 and r == 2:
		c.append("5678")

	if r == 1:
		c.append("1234")

	for i in range(0, 4):
		for j in range(0, 4):
			print "c = ", c[i]," inp = ", inp[j]
			if c[r][i] == inp[j]:
				if i == j:
					rf += 1
				else:
					wf += 1
				break


	if r > 1:
		

	print "_"*40
	r += 1
	#rf += 1

print wf
print rf

print"--- %s seconds ---" % (time.clock() - start_time)