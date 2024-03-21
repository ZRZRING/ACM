K = {'小米粥': 45, '粗粮馒头': 223, '全麦面包': 235, '瘦猪肉': 143, '鸡翅': 194, '培根': 181, '火腿肠': 212}
A = list(K.keys())
B = list(K.values())
for i in range(0, len(K)):
    print("我吃了二两+" + A[i] + " 增加了+" + str(B[i]) + "卡路里")

temp = input("输入要查找的食物:")
print(K.get(temp, "找不到此食物"))
temp2 = input("输入要查找的食物:")
print(K.get(temp2, "找不到此食物"))
