#CF 371C: Hamburgers
#NOTE: After upsolving and looking at editorial, there is a MUCH MORE elegant solution (also using Binary Search)
#f(x) = max(0, cost*x-on hand)*price (for all three ingredients) and find the largest x where value is still true.
s = input()
fb=0; fs=0; fc=0
 
for c in s:
	if c=='B':
		fb+=1
	elif c=='S':
		fs+=1
	else:
		fc+=1
 
nb, ns, nc = [int(i) for i in input().split()]
pb, ps, pc = [int(i) for i in input().split()]
fp = int(input())
 
INT_MX = 10**12+101
rb = INT_MX; rs = INT_MX; rc = INT_MX
lb = INT_MX; ls = INT_MX; lc = INT_MX
rs1 = INT_MX; ls1 = INT_MX;
 
def solve2(l, r, p):
	global rb; global rs; global rc;
	global lb; global ls; global lc;
	global rs1; global ls1;
 
	m = int((l+r)/2)
	m1= min(m+fs-((ns+m)%fs),r)
 
	if fs>0:
		rs1 = int((ns+m1)/fs)
		ls1 = int((ns+m)/fs)
 
	if fc>0:
		rc = int((nc+int((p-m1*ps)/pc))/fc)
		lc = int((nc+int((p-m*ps)/pc))/fc)
	
	right = min(rs1,rc)
	left = min(ls1,lc)
 
	#print(l,' ',r,' ',p,' ',left,' ',mid,' ',right)
	
	if l==r:
		return left
	elif right>left:
		return solve2(m+1,r,p)
	else:
		return solve2(l,m,p)
 
def solve(l, r):
	global rb; global rs; global rc;
	global lb; global ls; global lc;
 
	m = int((l+r)/2)
	m1 = min(m+fb-((nb+m)%fb),r)
 
	if fb>0:
		rb = int((nb+m1)/fb)
		lb = int((nb+m)/fb)
 
	if fs>0:
		rs = solve2(0,int((fp-m1*pb)/ps),(fp-m1*pb))
		ls = solve2(0,int((fp-m*pb)/ps),(fp-m*pb))
	elif fc>0:
		#NOT elegant but superimpose c as s
		rs = int((nc+int((fp-m1*pb)/pc))/fc)
		ls = int((nc+int((fp-m*pb)/pc))/fc)
	
	right = min(rb,rs)
	left = min(lb,ls)
 
	#print(m==r, ' ',rb, ' ',rs)
	#print(m,' ',m1,' ',left,' ',right)
	#print(solve2(0,2,2))
 
 
	if l==r:
		return left
	elif right>left:
		return solve(m+1,r)
	else:
		return solve(l,m)
 
if fb>0:
	res = solve(0,int(fp/pb))
elif fs>0:
	res = solve2(0, int(fp/ps),fp)
else:
	#at least one of them must be > 0 (non empty string)
	res = int((int(fp/pc)+nc)/fc)
 
#print(solve2(0,2,2))
print(res)