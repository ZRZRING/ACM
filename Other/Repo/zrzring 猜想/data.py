import random

filename = "1.in"
f = open(filename,'w')
T = 100
f.write(str(T) + '\n')
for i in range(1,T + 1):
	f.write(str(i) + "\n")
f.close()

filename = "2.in"
f = open(filename,'w')
T = 100
f.write(str(T) + '\n')
for i in range(0,T):
	a = random.randint(1,10**9)
	f.write(str(a) + "\n")
f.close()