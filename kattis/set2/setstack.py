class Stack:
	def __init__(self):
		self.items = []

	def isEmpty(self):
		return self.items == []

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def peek(self):
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)

class WTF:
    def __init__(self):
		self.children = []
    def __eq__(self,other):
		if len(self.children) != len(other.children):
			return false
		for i in len(self.children):
			if self.children[i] != other.children[i]:
