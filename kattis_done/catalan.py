n = int(input(''))
dp = []
dp.append(1)
for i in range(1, 5000 + 2):
    j = i - 1
    dp.append(dp[len(dp) - 1] *  (4*j + 2) // (j+2))

for i in range(n):
    x = int(input(''))
    print(int(dp[x]))