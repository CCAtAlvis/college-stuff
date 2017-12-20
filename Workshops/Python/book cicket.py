import random

wicket = x = p1s = p2s = 0

while wicket != 9:
    x = random.randint(0,10)
    print x
    if x == 0:
        wicket += 1
    else:
        p1s += x

print "the score is "
print p1s

wicket = 0

while wicket != 9:
    x = random.randint(0,10)
    print x
    if x == 0:
        wicket += 1
    else:
        p2s += x

print "the score is "
print p2s

if p1s > p2s:
    print "player 1 wins"
elif p2s > p1s:
    print "player 2 wins"
else:
    print "the match is tie"
