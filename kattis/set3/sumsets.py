
def main():
	n=int(raw_input(''))
	a=[0]*n
	for i in range(n):
		a[i]=int(raw_input(''))
	dict={}
	for i in range(n):
		for j in range(i+1, n):
			s=a[i]+a[j]
			if s in dict:
				dict[s].append((i, j))
			else:
				dict[s]=[]
				dict[s].append((i, j))
	ans = -536870913
	for i in range(n):
		for j in range(i+1, n):
			h=a[i]-a[j]
			if h in dict:
				for pair in dict[h]:
					if pair[0] != i and pair[1] != i and pair[0] != j and pair[1] != j:
						ans=max(ans, a[i])
			k=a[j]-a[i]
			if k in dict:
				for pair in dict[k]:
					if pair[0] != i and pair[1] != i and pair[0] != j and pair[1] != j:
						ans=max(ans, a[j])
	if ans is -536870913:
		print('no solution')
	else:
		print(ans)
main()
