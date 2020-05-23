n = int(input())
arr = input().split(' ')
arr = [int(i) for i in arr]
mx = 0
mn = 1000000001
for i in arr:
    if i > mx:
        mx = i
    if i < mn:
        mn = i

cnt_min = 0
cnt_max = 0
for i in arr:
    if i == mn:
        cnt_min+=1
    elif i==mx:
        cnt_max+=1

diff = mx - mn
num = cnt_min * cnt_max
if mx == mn:
    num = int(cnt_min * (cnt_min - 1)/2)

print(diff,num)