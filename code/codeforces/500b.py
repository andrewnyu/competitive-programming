#CF500B: New Year Permutation
n = int(input())
raw = [int(i) for i in input().split()]

g = [[False for i in range(n)] for j in range(n)]
for i in range(n):
	current = input()
	for j in range(n):
		g[i][j] = (current[j]=='1')


ok = [[False for i in range(n)] for j in range(n)]
def dfs(v, g, o):
	global ok
	ok[o][v] = True
	for i in range(n):
		if g[v][i] and not ok[o][i]:
			dfs(i, g, o)

res = [raw[i] for i in range(n)]
for i in range(n):
	dfs(i, g, i)
	for j in range(i,n):
		if ok[i][j] and res[j]<res[i]:
			temp = res[i]
			res[i] = res[j]
			res[j] = temp

res_str = str(res[0])
for i in range(1,n):
	res_str+=" "+str(res[i])

print(res_str)
