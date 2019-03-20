

def extendedEuclid(a, b):
	xx = y=  0
	yy = x = 1
	while(b):
		q = a//b
		t = b 
		b = a % b 
		a = t
		t =xx 
		xx = x-q*xx
		x=t
		t = yy 
		yy= q * yy
		y=t
	return (a, x, y)

def modInverse(b, m):
	(d, x, y) = extendedEuclid(b, m)
	if d != 1:
		return -1
	return x%m
def chineseRemainderTheorem(a, p, b, q):
	p1 = modInverse(p, q)
	q1 = modInverse(q, p)
	ans = (a * q * q1 + b * p * p1) % (p * q)
	if ans < 0:
		ans += (p * q)
	return ans

def main():
	tc = int(input())
	for _ in range(tc):
		[a, n, b, m] = [int(a) for a in input().split(' ')]
		print('{} {}'.format(chineseRemainderTheorem(a, n, b, m), n * m))

main()
