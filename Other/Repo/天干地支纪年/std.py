chars="ABCDEFGHIJ"
char="abcdefghijkl"
y = int(input())
a=(y-3)%10
b=(y-3)%12
if(a==0):
    a=10
if(b==0):
    b==12
ans=""
# y+=year
if (y%4==0 and y%100)or (y%400==0):
    ans="Yes"
else:
    ans="No"
print(chars[a-1]+char[b-1]+" "+ans)