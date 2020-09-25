#CF 96B: Lucky Numbers (Easy)
n = int(input())

res = 4444477777 #highest possible ans given constraints

def dfs(v, c4, c7):
	global res

	if c4==c7 and v>=n:
		res = min(res, v)
	elif v<res:
		l = c4+c7
		dfs(4*(10**l)+v,c4+1,c7)
		dfs(7*(10**l)+v,c4,c7+1)

dfs(4, 1, 0)
dfs(7, 0 ,1)
print(res)