data = []
datafile = open("nbc-data.txt", "r")
for line in datafile:
    dataList = list(line.split(','))
    dataList = [i.replace(" ","").replace("\n","") for i in dataList]
    data.append(dataList)

target = int(input("Enter the target attribute number(0-" + str(len(data[0])-1) + "): "))
distinct = [list() for i in data[0]]

for i in data:
    for j in range(len(i)):
        if i[j] not in distinct[j]:
            distinct[j].append(i[j])

count = dict()
for i in distinct[target]:
    p = sum(x.count(i) for x in data)
    count[i] = p

prob = dict()
for i in data:
    for j in i:
        for k in distinct[target]:
            if k in i and j not in distinct[target]:
                prob[j+k] = 0

for i in data:
    for j in i:
        for k in distinct[target]:
            if k in i and j not in distinct[target]:
                prob[j+k] += 1/count[k]

f = input("enter color type origin: ").split()

p = dict()
for i in distinct[target]:
    p[i] = 1

for j in distinct[target]:
    for i in f:
        p[j] = p[j] * prob[i+j]
        # print(prob[i+j])

    p[j] = p[j] * count[j] / len(data)

print(max(p))

# OUTPUT
# Enter the target attribute number(0-3): 3
# enter color type origin: red sports imported
# yes
