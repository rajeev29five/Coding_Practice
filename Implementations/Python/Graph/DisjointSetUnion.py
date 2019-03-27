import sys

class Node:

	def __init__(self):
		self.data = 0
		self.rank = 0
		self.parent = None


m = {}


def makeSet(data):

	newNode = Node()
	newNode.data = data
	newNode.rank = 0
	newNode.parent = newNode

	m[data] = newNode


def findSet(node):
	if node.parent is node:
		return node
	node.parent = findSet(node.parent)
	return node.parent


def unionSet(x, y):

	nodex = m[x]
	nodey = m[y]

	parentx = findSet(nodex)
	parenty = findSet(nodey)

	if parentx is parenty:
		return

	if parentx.rank > parenty.rank:
		parenty.parent = parentx.parent
		parentx.rank += 1
	else:
		parentx.parent = parenty.parent
		parenty.rank += 1

def findParent(data):
	return findSet(m[data]).data

if __name__ == '__main__':
	

	for i in range(1,11):
		makeSet(i)

	unionSet(1, 2)
	unionSet(3, 5)
	unionSet(1, 10)
	unionSet(1, 4)
	unionSet(1, 6)
	unionSet(6, 7)
	unionSet(1, 3)
	unionSet(1, 9)

	for i in range(1, 11):
		print("parent of {0} is {1}".format(i, findParent(i)))

'''
Output

parent of 1 is 2
parent of 2 is 2
parent of 3 is 2
parent of 4 is 2
parent of 5 is 2
parent of 6 is 2
parent of 7 is 2
parent of 8 is 8
parent of 9 is 2
parent of 10 is 2

'''