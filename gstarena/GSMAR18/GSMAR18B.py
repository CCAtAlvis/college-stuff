t = int(input())
op = list()

for i in range(t):
    n = int(input())

    name = list()
    view = list()
    for j in range(n):
        temp = input().split()
        name.append(temp[0])
        view.append(int(temp[1]))

    for j in range(n):
        for k in range(n):
            if view[j] > view[k]:
                view[j], view[k] = view[k], view[j]
                name[j], name[k] = name[k], name[j]

    op.append(name[0])

for i in op:
    print(i)
