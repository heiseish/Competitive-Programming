import sys
def main():
	for line in sys.stdin:
		a = eval(line)
		print("{0:.2f}".format(a))
main()