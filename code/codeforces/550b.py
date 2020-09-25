#CF 550B: Preparing Olympiad
n,l,r,x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

res = 0
for i in range(2,1<<len(a)):
	cmin = 10**9+1
	cmax = 0
	ctotal = 0
	for j in range(len(a)):
		if i&(1<<j):
			cmin = min(a[j], cmin)
			cmax = max(a[j], cmax)
			ctotal+=a[j]
	if ctotal>=l and ctotal<=r and cmax-cmin>=x:
		res+=1

print(res)

