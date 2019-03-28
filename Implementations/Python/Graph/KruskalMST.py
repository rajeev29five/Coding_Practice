#
# Code Contributor(s) : Rajeev Ranjan
#

import sys

class Node:

	def __init__(self):
		self.data = 0
		self.rank = 0
		self.parent = None

m = {}
weight = 0

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


def unionSet(w, u, v):

	nodeu = m[u]
	nodev = m[v]

	parentu = findSet(nodeu)
	parentv = findSet(nodev)

	# print('Before union parent of {0} is {1} and parent of {2} is {3}'.format(u, parentu.parent.data, v, parentv.parent.data))

	global weight

	if parentu is parentv:
		return 

	if parentu.rank > parentv.rank:
		parentv.parent = parentu
		parentu.rank += 1
		weight += w
	else:
		parentu.parent = parentv
		parentv.rank += 1
		weight += w

	# print('After union parent of {0} is {1} and parent of {2} is {3}'.format(u, parentu.parent.data, v, parentv.parent.data))



if __name__ == '__main__':
	
	vertices = int(input('Enter number of vertices : '))
	edges = int(input('Enter number of edges : '))

	graphAdj = []

	for i in range(edges):
		val = input().split()
		u = int(val[0])
		v = int(val[1])
		w = int(val[2])
		graphAdj.append([w, u, v])

	graphAdj.sort()

	for i in range(vertices+1):
		makeSet(i)

	print('Weight\tSource\tDestination')
	for i in range(len(graphAdj)):
		print(graphAdj[i][0], '\t', graphAdj[i][1], '\t', graphAdj[i][2])
		unionSet(graphAdj[i][0], graphAdj[i][1], graphAdj[i][2])

	print ("Minimum weight : {}".format(weight))