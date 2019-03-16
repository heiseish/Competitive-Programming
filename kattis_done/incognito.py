import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

a = int(input(''))
for i in range(a):
  b = int(input(''))
  s = {}
  for j in range(b):
    x, y = input('').split(' ')
    if y in s:
      s[y]+=1
    else:
      s[y] = 1
  ans = 1
  for key, value in s.items():
    ans *= value + 1
  print(int(ans - 1))