def main():
	t = raw_input()
	[r, s, m, d, n] = [int(z) for z in t.split(' ')]
	brands = [int(z) for z in raw_input().split(' ')]
	S = []
	for _ in range(s):
		S.append([int(z) for z in raw_input().split(' ')][1:])

	M = []
	for _ in range(m):
		M.append([int(z) for z in raw_input().split(' ')][1:])

	D = []
	for _ in range(d):
		D.append([int(z) for z in raw_input().split(' ')][1:])

	ans = 0
	cannot = {}
	for _ in range(n):
		[a, b] = [int(z) for z in raw_input().split(' ')]
		cannot[(a, b)] = 1
		cannot[(b, a)] = 1

	for x in range(s):
		for y in range(m):
			for z in range(d):
				nx = x + 1
				ny = s + y + 1
				nz = s + m + z + 1
				if (nx, ny) in cannot or (ny, nz) in cannot or \
					(nx, nz) in cannot:
					continue
				check = [0] * r
				for ii in S[x]:
					check[ii - 1] = 1
				for ii in M[y]:
					check[ii - 1] = 1
				for ii in D[z]:
					check[ii - 1] = 1
				temp = 1
				for i in range(r):
					if check[i]:
						temp *= brands[i]
				ans += temp
	if ans <= 1e18:
		print(int(ans))
	else:
		print('too many')

if __name__ == '__main__':
	main()

