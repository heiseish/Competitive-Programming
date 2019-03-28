from sys import stdin, stdout
def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b) 
def lcm(a, b):
	return a * (b / gcd(a, b))

def main():
	tc = int(stdin.readline())
	for _ in range(tc):
		[p, q, n] = [int(z) for z in stdin.readline().split(' ')]
		g = lcm(p, q)
		cycle = g//p
		numcy = n // cycle
		ans = numcy * (q - 1) * q // 2
		nxt = int(numcy * cycle + 1)
		for i in range(nxt, n+1):
			ans += (p * i) % q
		stdout.write(str(int(ans)) + '\n')

if __name__ == '__main__':
	main()