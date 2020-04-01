
#cf 217 a
xvisited = [False for i in range(1001)]
yvisited = [False for i in range(1001)]
def dfs(g1, g2, n, axis):
	if(axis == True):
		xvisited[n] = True
		for node in g1[n]:
			if (yvisited[node]==False):
					dfs(g2, g1, node, False)

	else:
		yvisited[n] = True
		for node in g1[n]:
			if (xvisited[node]==False):
					dfs(g2, g1, node, True)

n = int(input ())
#declare g as an empty dict
gx = {}
gy = {}
for i in range (n):
	x, y = input().split(" ")
	x = int(x); y=int(y)
	if x not in gx:
		gx[x] = [y]
	else:
		gx[x].append(y)
	
	if y not in gy:
		gy[y] = [x]
	else:
		gy[y].append(x)
	

count = 0
for k in gx:
	if(xvisited[k] == False):
		count+=1
		dfs(gx, gy, k, True)

print(count-1)