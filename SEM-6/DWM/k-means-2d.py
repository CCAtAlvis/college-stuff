# K-means (2D)
def avg(arr, c):
    s = 0
    for i in arr:
        s += i[c]

    return s/len(arr)

def get_cluster(x,y):
    global c_mean

    values = list()
    for i in c_mean:
        values.append(dis([x,y], i))

    return values.index(min(values))


def dis(num1, num2):
    #print(num1)
    #print(num2)
    return ((num1[0]-num2[0])**2 + (num1[1]-num2[1])**2)

numx = input("enter x coords: ").split()
numx = list(map(int, numx))
numy = input("enter y coords: ").split()
numy = list(map(int, numy))

k = int(input("enter no. of clusters: "))
c_mean = list()
new_c_mean = list()
cluster = list()

for i in range(k):
    nx = input("enter mean x " + str((i+1)) + ": ")
    ny = input("enter mean y " + str((i+1)) + ": ")
    c_mean.append([int(nx), int(ny)])

#print(c_mean)

while 1==1:
    #refrest clusters
    cluster = list()
    for i in range(len(c_mean)):
        cluster.append(list())

    #assign new clusters
    for i in range(len(numx)):
        cls = get_cluster(numx[i], numy[i])
        cluster[cls].append([numx[i], numy[i]])

    #calc new means
    for i in range(len(c_mean)):
        new_c_mean.append([avg(cluster[i], 0), avg(cluster[i], 1)])

    #check with previous means
    if new_c_mean == c_mean:
        break
    else:
        c_mean = new_c_mean

    new_c_mean = list()
    print(cluster)

print(cluster)

# Output:
# ag27@ag27-OptiPlex-3020:~/Downloads$ python3 k_means_2d.py
# enter x coords: 1 2 4 5
# enter y coords: 1 1 3 4
# enter no. of clusters: 2
# enter mean x 1: 1
# enter mean y 1: 1
# enter mean x 2: 4
# enter mean y 2: 3
# [[[1, 1], [2, 1]], [[4, 3], [5, 4]]]
# [[[1, 1], [2, 1]], [[4, 3], [5, 4]]]