#ABC 181B: Trapezoid Sum

n = int(input())
res = 0
for i in range(n):
    a,b = [int(num) for num in input().split()]
    res += (a+b)*(b-a+1)/2

print(int(res))
