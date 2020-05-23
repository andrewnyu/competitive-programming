from math import sqrt
MAXN = 1000000
prime = [True for i in range(MAXN+1)]
for i in range(2,int(sqrt(MAXN))+1):
    if prime[i]:
        num = i*i
        while(num<=MAXN):
            prime[num]=False
            num += i
n=1
while(n!=0):
    n = int(input())
    ans = ""
    possible = False
    if(n!=0):
        for i in range(2,int(n/2)+1):
            if prime[i] and prime[n-i]:
                ans = str(n)+' = '+str(i)+' + '+str(n-i) 
                possible=True
                break
    
        if possible:
            print(ans)
        else:
            print("Goldbach's conjecture is wrong.")


