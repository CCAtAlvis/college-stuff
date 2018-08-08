# for python3
t = int(input())
op = list()

for i in range(t):
    fm, iceN = map(int, input().split())

    a = input().split()
    a = list(map(int, a))

    flag = True
    for x in range(fm):
        temp = input().split()[1:]
        temp = list(map(int, temp))
        for j in temp:
            a[j-1] -= 1
            if a[j-1] < 0:
                flag = False
                break
        if not flag:
            break

    if flag:
        op.append("yes")
    else:
        op.append("no")

for i in op:
    print(i)
