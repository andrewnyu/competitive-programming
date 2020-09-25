#SPOJ subarrays
n = int(input())
a = input().split()
a = [int(v) for v in a]
k = int(input())

from collections import deque

dq = deque()
res = ""
#print(len(dq))
for i in range(n):
	q = True
	while(q and len(dq)>0):
		if(dq[-1][0]<=a[i]):
			dq.pop()
		else:
			q=False
	q = True
	while(q and len(dq)>0):
		if(dq[0][1]<=i-k):
			dq.popleft()
		else:
			q=False
	
	dq.append([a[i], i])
	if i>=k-1:
		res += str(dq[0][0])+' '

print(res)


