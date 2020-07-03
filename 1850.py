def gcd(a,b):
    while b!= 0:
        tmp = a % b
        a = b
        b = tmp

    return a


val = list(map(int, input().split(' ')))
x = val[0]
y = val[1]
res = gcd(x,y)

for i in range(res):
    print(1, end='')
