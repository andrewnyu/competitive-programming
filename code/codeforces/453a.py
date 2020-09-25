#CF 453a: Little Pony and Expected Maximum
from math import pow
m,n = input().split()
m,n = int(m),int(n)


res = 0
for i in range(1,m):
	res += (i/m)**n
print(m-res)