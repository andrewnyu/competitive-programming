#CF 617B: Chocolate
n = int(input())
cb = [int(i) for i in input().split()]

res = 1
curr = 1
start = False
for a in cb:
	if a==1:
		if start:
			res*=curr
		else:
			start = True
		curr=1
	else:
		curr+=1

if not start:
	print(0)
else:
	print(res)