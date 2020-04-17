s1 = input()
s2 = input()

x1=0
for i in s1:
    if i=='+':
        x1+=1
    else:
        x1-=1

x2=0
v=0
for i in s2:
    if i=='+':
        x2+=1
    elif i=='-':
        x2-=1
    else:
        v+=1

dp = [[-1 for i in range(0,12)] for j in range(0,12)]
def cmb(n,r):
    if dp[n][r]!=-1:
        return dp[n][r]
    elif n==r:
        dp[n][r]=1
        return dp[n][r]
    elif n==0:
        dp[n][r]=0
        return dp[n][r]
    elif r==0:
        dp[n][r]=1
        return dp[n][r]
    else:
        dp[n][r] = cmb(n-1,r)+cmb(n-1,r-1)
        return dp[n][r]

import math
target = abs(x1-x2)
ans=0
if(target%2!=v%2) or (target>v):
    ans=0
else:
    ans=cmb(v,int((v-target)/2))/math.pow(2,v)

print(ans)

