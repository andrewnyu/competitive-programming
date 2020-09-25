t = int(input())
for test in range(t):
	n,x = [int(i) for i in input().split()]
	arr = [int(i) for i in input().split()]

	base_inf = 0
	diff = 0
	for a in arr:
		if a==x:
			base_inf+=1
		else:
			diff+=(a-x)

	#Mathematically, if base_inf >= 1 (max 1). We can make the infected join contest and augment his rating so that all others achieve x
	#if base_inf == n then all are infected

	if base_inf == n:
		print(0)
	elif diff==0 or base_inf>=1:
		print(1)
	else:
		print(2)
		#infect 1 and make it join contest to make all others infected

