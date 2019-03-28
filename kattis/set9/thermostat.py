from fractions import Fraction 
from sys import stdin, stdout  

def main():
	[n, q] = [int(z) for z in stdin.readline().split(' ')]
	temp = {}
	for i in range(n):
		[a, b] = [int(z) for z in stdin.readline().split(' ')]
		temp[i + 1] = (a, b)

	for _ in range(q):
		[a, b, c] = [int(z) for z in stdin.readline().split(' ')]
		deg = Fraction(c - temp[a][0], temp[a][1] - temp[a][0]) * 100
		ans = temp[b][0] + deg * (temp[b][1] - temp[b][0]) / 100
		if ans == 0:
			stdout.write('0/1\n')
		elif ans.denominator == 1:
			stdout.write('{}/1\n'.format(ans))
		else:
			stdout.write(str(ans) + '\n')

if __name__ == '__main__':
	main()
