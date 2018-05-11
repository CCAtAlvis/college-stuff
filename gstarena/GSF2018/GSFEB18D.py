t = int(input())
op =[]

for i in range(t):
    n = int(input())
    q, a = 0, 0
    truth, lies = 0, 0

    for j in range(n):
        ij = input()
        ib = input()
        for x in ('a', 'e', 'i', 'o', 'u'):
            q += ij.count(x)
            a += ib.count(x)

        if q == a:
            truth += 1
        else:
            lies += 1

    if truth >= lies:
        op.append("jane")
    else:
        op.append("secretbff")

for x in op:
    print(x)
