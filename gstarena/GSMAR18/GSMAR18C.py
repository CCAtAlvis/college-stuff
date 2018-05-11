t = int(input())
op = list()

for i in range(t):
    n = input().split()
    n = list(map(int, n))
    N = n[0]
    k = n[1]
    p = n[2]

    st = input()
    noP = st.count("P")
    noP += k

    if noP >= p:
        op.append("yes")
    else:
        op.append("no")

for i in op:
    print(i)
