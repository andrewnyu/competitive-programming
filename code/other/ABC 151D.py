h,w = [int(i) for i in input().split()]
a = [[False for i in range(w)] for j in range(h)]
#print(a)

for i in range(h):
	v = input()
	for j in range(w):
		if v[j]=='.':
			a[i][j]=True
		else:
			a[i][j]=False

res = 0
ok = [[False for i in range(w)] for j in range(h)]
def bfs(x, y, d):
	q = []
	q.append((x,y,d))
	
	global res
	global ok

	while not len(q)==0:
		x, y, d = q[0]
		q.pop(0)

		if a[x][y] and not ok[x][y]:
			res = max(res, d)
			ok[x][y]=True

			if x-1>=0:
				q.append((x-1,y,d+1))
			if y-1>=0:
				q.append((x,y-1,d+1))
			if x+1<h:
				q.append((x+1,y, d+1))
			if y+1<w:
				q.append((x,y+1, d+1))


for i in range(h):
	for j in range(w):
		ok = [[False for i in range(w)] for j in range(h)]
		bfs(i,j,0)

print(res)

