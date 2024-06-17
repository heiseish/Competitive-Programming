a, b, c, d = map(int, input().split())
res = max(a * c, b * d)
f = max(a * d, b * c)

print(max(res, f))