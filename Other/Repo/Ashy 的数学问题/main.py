import random

# for t in range(2,6):
t = 1
filename = str(t) + ".in"
f = open(filename,'w')
n = random.randint(1,10 ** 5)
f.write(str(n) + '\n')
for i in range(0, n - 1):
    a = random.randint(1,10 ** 9)
    f.write(str(a) + ' ')
a = 0
f.write(str(a) + ' ')
f.close()
