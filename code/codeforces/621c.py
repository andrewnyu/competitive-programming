#CF 621C: Wet Shark and Flowers
from math import floor
n,p = input().split()
n,p = int(n),int(p)

res = 0
pb = [0 for i in range(n)]
for i in range(n):
	a,b = input().split()
	a,b = int(a), int(b)
	pb[i] = 1-(floor(b/p)-floor((a-1)/p))/(b-a+1)

for i in range(n):
	if i==n-1:
		res += 2000*(1-pb[0]*pb[i])
	else:
		res += 2000*(1-pb[i]*pb[i+1])

print(res)
