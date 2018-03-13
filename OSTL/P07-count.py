f = open("P07-file2.txt", "r")

# word count
wc = 0
# line count
lc = 0
# letter count
leC = 0

for lines in f:
    lc += 1
    words = lines.split()
    wc += len(words)
    leC += sum(len(x) for x in words)

print("line count:", lc)
print("word count:", wc)
print("letter count:", leC)
