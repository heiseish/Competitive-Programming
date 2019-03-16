n = int(input(''))
dp = []
dp.append(1)
for i in range(1, n + 2):
    j = i - 1
    dp.append(dp[len(dp) - 1] *  (4*j + 2) // (j+2))

print(int(dp[n+1]))