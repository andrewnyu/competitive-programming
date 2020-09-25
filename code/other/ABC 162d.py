#ABC162D: RGB Triplets
n = int(input())
s = input()
c = [[0 for i in range(3)] for i in range(len(s))]
color = ['R','G','B']

for i in range(3):
	c[0][i] = (s[0]==color[i])

for i in range(1, len(s)):
	for j in range(3):
		if s[i]==color[j]:
			c[i][j] = c[i-1][j]+1
		else:
			c[i][j] = c[i-1][j]

res = 0
for i in range(len(s)-2):
	for j in range(i+1, len(s)-1):
		if s[i] != s[j]:
			for k in range(3):
				if s[i] != color[k] and s[j]!= color[k]:
					#print(i,j,k)
					res += c[n-1][k] - c[j][k]

					if 2*j-i<n:
						#possible principle 2 (j-1==k-j)
						res += -c[2*j-i][k] + c[2*j-i-1][k]

print(res)

	