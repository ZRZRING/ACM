# import random
# for num in range(1,15):
#     s = str(num) + ".in"
#     f = open(s,'r')
#     n = random.randint(1,1000000)
#     f.write(str(n) + "\n")
#     for i in range(0,n):
#         a = random.randint(0,1)
#         f.write(str(a) + " ")
#     f.write('\n')
#     for i in range(0,n):
#         a = random.randint(0,1)
#         f.write(str(a) + " ")
# f = open("17.in",'w')
# f.write("1000000\n")
# for i in range(0,1000000):
#     f.write('0 ')
# f.write('\n')
# for i in range(0,1000000):
#     f.write('0 ')
import random

for num in range(1, 15):
    s = str(num) + ".in"
    f = open(s, 'r')
    n = f.readline()
    print(n)
    nn = int(n)
    l1 = f.readline()
    a = l1.split()
    if len(a) == nn:
        print("YES1 ", n)
    # n2 = f.readline()
    # nn2 = int(n)
    l2 = f.readline()
    aa = l2.split()
    if len(aa) == nn:
        print("YES2 ", nn)
    f.close()
