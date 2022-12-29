import sys
fact = {}
fact[0] = 1
for i in range(1, 101):
  fact[i] = fact[i-1]*i

for line in sys.stdin:
  dp = {}
  ct = 0
  for c in line:
    if c is '\n':
      continue
    ct+=1
    if c in dp:
      dp[c]+=1
    else:
      dp[c] = 1
  ans = fact[ct]
  for key, value in dp.items():
    ans //= fact[value]
  print(int(ans))
  
