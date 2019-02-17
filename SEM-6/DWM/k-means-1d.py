# K-means (1D)
def avg(arr):
    return sum(arr)/len(arr)

def get_cluster(num):
    global c_mean

    values = list()
    for i in c_mean:
        values.append(dist(num, i))

    return values.index(min(values))


def dist(num1, num2):
    return abs(num1-num2)

num = input("enter numbers: ").split()
num = list(map(int, num))
#num = num.sort()
#print(ip)

k = int(input("enter no. of clusters: "))
c_mean = list()
new_c_mean = list()
cluster = list()

for i in range(k):
    n = input("enter mean " + str((i+1)) + ": ")
    c_mean.append(int(n))

#print(c_mean)

while 1==1:
    #refrest clusters
    cluster = list()
    for i in range(len(c_mean)):
        cluster.append(list())

    #assign new clusters
    for i in num:
        cls = get_cluster(i)
        cluster[cls].append(i)

    #calc new means
    for i in range(len(c_mean)):
        new_c_mean.append(avg(cluster[i]))

    #check with previous means
    if new_c_mean == c_mean:
        break
    else:
        c_mean = new_c_mean

    new_c_mean = list()
    print(cluster)

print(cluster)

# Output:
# enter numbers: 2 4 10 12 3 20 30 11 21
# enter no. of clusters: 2
# enter mean 1: 2
# enter mean 2: 4
# [[2, 3], [4, 10, 12, 20, 30, 11, 21]]
# [[2, 4, 3], [10, 12, 20, 30, 11, 21]]
# [[2, 4, 10, 3], [12, 20, 30, 11, 21]]
# [[2, 4, 10, 3, 11], [12, 20, 30, 21]]
# [[2, 4, 10, 12, 3, 11], [20, 30, 21]]
# [[2, 4, 10, 12, 3, 11], [20, 30, 21]]
