#CF 535B: Tavas and SaDDas
s = int(input())

res = 0
def dfs(num, l):
	global res
	if num<=s:
		res+=1
		dfs(4*(10**l)+num, l+1)
		dfs(7*(10**l)+num, l+1)

dfs(4, 1)
dfs(7, 1)


print(res)
