import os

for x,y,z in os.walk("/home/cc"):
    for filename in z:
        print(filename)
