
def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)
def lcm(a, b):
	return a * (b // gcd(a, b))
N = int(input(''))
for i in range(N):
	[x1, y1, op, x2, y2] = input('').split(' ')
	x1 = int(x1)
	y1 = int(y1)
	x2 = int(x2)
	y2 = int(y2)
	denum = 0
	num = 0
	if op == '+':
		denum = lcm(y1, y2)
		num1 = x1 * (denum // y1)
		num2 = x2 * (denum // y2)
		num = num1 + num2
	elif op == '-':
		denum = lcm(y1, y2)
		num1 = x1 * (denum// y1)
		num2 = x2 * (denum// y2)
		num = num1 - num2
	elif op == '*':
		num = x1 * x2
		denum = y1 * y2
	else:
		num = x1 * y2
		denum = y1 * x2

	g = gcd(abs(num), abs(denum))
	num //= g
	denum //= g

	if denum < 0:
		denum //= -1
		num //= -1

	
	if num is 0 or denum is 0:
		print('0 / 1')
	else:
		print('{:d} / {:d}'.format(num, denum))
