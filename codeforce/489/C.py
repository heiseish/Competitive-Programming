MOD=1000000007

def subtract(a, b):
	if b>a: 
		a+=MOD
	return (a-b)%MOD

def multiply(a, b):
	return (a * b) % MOD

def mpow(a, b):
	ret = 1
	while b is not 0:
		if b & 1: 
			ret = multiply(ret, a)
		a = multiply(a, a)
		b = b >> 1
	return ret

i=input('')
[x, k]=[int(z) for z in i.split(' ')]
if x is 0: 
	print(0)
else:
	ans = multiply(x, mpow(2, k+1))
	temp = mpow(2, k)
	temp = subtract(temp, 1)
	ans = subtract(ans, temp)
	print(int(ans))