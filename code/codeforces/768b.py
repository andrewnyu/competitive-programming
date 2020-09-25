#CF768B: Code For 1
from math import floor, log

mid = [0 for i in range((2**50)+1)]
mid[1] = 1


def solve(n, L, R):
	if L>R:
		return 0
	elif n==1 and L==1:
		return 1
	elif n==0:
		return 0
	else:
		mid = 2**(floor(log(n,2)))
		if mid==n+1:
			#precision error
			mid/=2

		return solve(floor(n/2),L,min(mid-1,R)) + solve(n%2,max(1,L-mid+1),min(1,R-mid+1)) + solve(floor(n/2),max(L-mid,1),R-mid)

n,l,r = input().split()
n,l,r = int(n), int(l), int(r)
res = solve(n,l,r)
print(res)