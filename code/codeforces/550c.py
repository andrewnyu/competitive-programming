#CF 550C: Divisibility by Eight
n = input()

m8 = []
num=0
while(num<1000):
	m8.append(str(num))
	num+=8

def is_subseq(a,b):
	#check if a is a subsequence of b
	idx=0
	sidx=0
	res = False
	while(idx<len(b) and sidx<len(a)):
		if b[idx]==a[sidx]:
			sidx+=1
			if sidx==len(a):
				res=True
		idx+=1
	return res


res = False
resn = -1
for i in m8:
	if is_subseq(i,n):
		res=True
		resn = i

if(res):
	print("YES")
	print(resn)
else:
	print("NO")
