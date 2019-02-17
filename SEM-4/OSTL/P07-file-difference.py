f1 = open("P07-file1.txt", "r")
f2 = open("P07-file2.txt", "r")

count = 1
f = True

for x in f1:
    if x != '':
        y = f2.readline()
        if y != '':
            if x == y:
                pass
            else:
                print("found difference at line:", count)
                f = False
                break
        else:
            break
    else:
        break
    count += 1

if f:
    print("no difference")
