import math
t = int(input())

prime = [True for i in range(1001)]
prime[1] = False
parent = [i for i in range(1001)]
for i in range(2, int(math.sqrt(1001))+1):
    if(prime[i]):
        k = i*i
        
        while(k<1001):
            prime[k] = False
            parent[k] = i
            k = k + i
            


for test in range(t):
    n = int(input())
    a = input().split(' ')
    for i in range(len(a)):
        a[i] = int(a[i])

    color = [-1 for i in range(1001)]
    visited = [False for i in range(1001)] #if multiple of prime i is in list
    cnt = 1
    for num in a:
        if not visited[parent[num]]:
            visited[parent[num]] = True
            color[parent[num]] = cnt
            cnt+=1
    
    ans = str(color[parent[a[0]]])
    for i in range(1,len(a)):
        ans = ans + ' ' + str(color[parent[a[i]]])
    
    print(cnt-1)
    print(ans)
        
            
        
