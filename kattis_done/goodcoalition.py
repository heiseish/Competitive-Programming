maxn = 153
dp = {}
S = {}
T = {}
def solve(idx, seat, chance): 
	if idx == n:
		if seat >= 76:
			return chance
		else:
			return 0.0
	if chance in dp[idx]:
		return dp[idx][chance]
	dp[idx][chance] = max(solve(idx + 1, seat + S[idx], chance * T[idx] / 100.0), solve(idx + 1, seat, chance))
	return dp[idx][chance]

tc = int(input(''))
for _ in range(tc):
	n = int(input(''))
	for i in range(maxn):
		dp[i] = {}
	for i in range(n):
		S[i], T[i] = [int(z) for z in input('').split(' ')]
	print("{:.15f}".format(solve(0, 0, 1.0) * 100))
