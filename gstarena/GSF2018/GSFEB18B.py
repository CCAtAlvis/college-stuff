t = int(input())
op =[]

for i in range(t):
    op1 = []
    inp = input().split()
    for x in range(1, len(inp)):
        unit = int(inp[x])%10
        if unit != 7:
            op1.append(inp[x])

    op.append(op1)

for x in op:
    for i in x:
        print(i, end=" ")
    print()
