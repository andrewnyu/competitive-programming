#CF 1556A: A Variety of Operations
t = int(input())

for _ in range(t):
    a, b = [int(i) for i in input().split()]

    if (a-b)%2!=0:
        print(-1)
    else:
        if a==b and a==0:
            print(0)
        elif a==b:
            print(1)
        else:
            print(2)
            