# 1.KNN - simple

def dis(a, b):
    d = (a[0]-b[0])**2 + (a[1]-b[1])**2
    return d

print("label classification: good: 1, bad: 0")
n = int(input('enter number of samples: '))

points = []
dist = []

for i in range(n):
    x = int(input("enter x: "))
    y = int(input("enter y: "))
    q = int(input("enter label: "))
    points.append([x,y,q])

print("enter point to classify: ")
x = int(input("x: "))
y = int(input("y: "))

k = int(input("enter k: "))

for i in points:
    d = dis([x, y], i)
    dist.append([d, i[0], i[1], i[2]])

dist = sorted(dist)
s = 0
for i in range(k):
    s += dist[i][3]

label = "bad"
if s >= k/2:
    label = "good"

print("point has label: " + label)

# OUTPUT:
# label classification: good: 1, bad: 0
# enter number of samples: 4
# enter x: 7
# enter y: 7
# enter label: 0
# enter x: 7
# enter y: 4
# enter label: 0
# enter x: 3
# enter y: 4
# enter label: 1
# enter x: 1
# enter y: 4
# enter label: 1
# enter point to classify:
# x: 2
# y: 6
# enter k: 3
# point has label: good
