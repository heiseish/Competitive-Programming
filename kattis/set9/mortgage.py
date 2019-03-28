import math
def main():
	while True:
		[x, y, n, r] = raw_input().split(' ')
		x = int(x)
		y = int(y)
		n = int(n)
		r = float(r)
		if x is 0 and y is 0 and n is 0 and r == 0:
			break
		r/=1200
		if r * x >= y:
			print('NO')
			continue
		
		rate = 1 + r
		mo = n * 12
		if rate == 1:
			if x <= y * mo:
				print('YES')
			else:
				print('NO')
			continue
		
		
		if mo >= math.log(y/(y - r * x)) / math.log(rate):
			print('YES')
		else:
			print('NO')
		

if __name__ == '__main__':
	main()
