import math
MAXN = 1000000
prime = [True for i in range(2,MAXN+1)]

n,k= input().split()
n,k = int(n),int(k)
for i in range(2, int(math.sqrt(n)+1)):
    if prime[i]:
        c = i*i
        while(c<=n):
            prime[c] = False
            c += i

pf_cnt = 0
factors = []
num = n
for i in range(2, n+1):
    if prime[i]:
        while(num%i==0):
            num/=i
            factors.append(i)
            pf_cnt+=1

if pf_cnt < k:
    print(-1)
else:
    ans = ""
    for i in range(0, k-1):
        ans += str(factors[i]) + " "
    
    last = factors[k-1]
    for i in range (k, len(factors)):
        last *= factors[i]
    
    ans += str(last)
    print(ans)

