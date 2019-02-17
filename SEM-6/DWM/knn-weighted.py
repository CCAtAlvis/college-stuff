# 2. KNN - weighted
def l(p, d, w):
    s = 0
    for i in range(len(p)):
        s += w[i]*int(p[i] == d[i])
    s = s/len(p)
    return s

data = [
    ['<=30' ,'hig','n','f','n'],
    ['<=30' ,'hig','n','e','n'],
    ['31-40','hig','n','f','y'],
    ['>40'  ,'med','n','f','y'],
    ['>40'  ,'low','y','f','y'],
    ['>40'  ,'low','y','e','n'],
    ['31-40','low','y','e','y'],
    ['<=30' ,'med','n','f','n'],
    ['<=30' ,'low','y','f','y'],
    ['>40'  ,'med','y','f','y'],
    ['<=30' ,'med','y','e','y'],
    ['31-40','med','n','e','y'],
    ['31-40','hig','y','f','y'],
    ['>40'  ,'med','n','e','n']
]

point = ['<=30' ,'med','y','f']
weight = [1, 2, 1, 1]
dis = list()
k = int(input("enter k: "))

for i in data:
    w = l(point, i, weight)
    dis.append([w, i[4]])

dis.sort(reverse=True)
y = 0

for i in dis[0:k]:
    if i[1] == 'y':
        y += 1

if y >= k/2:
    print("test point is good")
else:
    print("test point is bad")

# OUTPUT:
# enter k: 5
# test point is good
