'''
#generate all beautiful numbers < maxn
k = 0
n = 1
maxv = 100000
while n<=maxv:
	n -= 2**k
	n += 2**(2*k+1)
	n += 2**(2*k+2)
	k+=1
	print(n)
'''
bn = [130816,32640,8128,2016,496,120,28,6,1]
bn.reverse()
ans = 1
n = int(input())
for num in bn:
	if n%num==0:
		ans=num
print(ans)