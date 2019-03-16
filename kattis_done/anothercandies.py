tc = int(input(''))
for i in range(tc):
	b = input('')
	n = int(input(''))
	ans = 0
	for _ in range(n):
		ans += int(input(''))
	if ans % n == 0:
		print('YES')
	else:
		print('NO')