import sys
import threading
def main():
	n = int(input(''))
	k = int(input(''))
	supermarkets = []
	for i in range(k):
		index, food = input('').split(' ')
		index = int(index)
		if index >= len(supermarkets):
			temp = {}
			temp[food] = -1
			supermarkets.append(temp)
		else:
			supermarkets[index][food] = -1

	m = int(input(''))
	items = []
	for i in range(m):
		items.append(input(''))

	def recurse(root, foodIndex):
		if root >= len(supermarkets):
			return 0
		if foodIndex >= len(items):
			return 1
		if items[foodIndex] in supermarkets[root]:
			return recurse(root + 1, foodIndex) + recurse(root, foodIndex + 1)
		return recurse(root + 1, foodIndex)

	result = recurse(0, 0)
	if result == 0:
		print('impossible')
	elif result == 1:
		print('unique')
	else:
		print('ambiguous')

if __name__ == '__main__':        
  threading.stack_size(67108864)
  sys.setrecursionlimit(2 ** 20)
  thread = threading.Thread(target=main)
  thread.start()