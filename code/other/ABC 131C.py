#ABC 131C: Anti-Division
a,b,c,d = [int(i) for i in input().split()]

def lcm(a,b):
	def gcd(a,b):
		if a==0:
			return b
		else:
			return gcd(b%a,a)
	gab = gcd(a,b)
	return int(a*b/gab)

cd = lcm(c,d)

from math import floor
from decimal import Decimal
def div(b1, b2, x):
	return floor(Decimal(b2)/Decimal(x)) - floor(Decimal((b1-1))/Decimal(x))

res = (b-a+1) - div(a,b,c) - div(a,b,d) + div(a,b,cd)
print(res)