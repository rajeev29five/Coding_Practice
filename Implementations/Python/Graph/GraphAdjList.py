#
# Code Contributor(s) : Rajeev Ranjan
#

import sys


class Node:

	def __init__(self):
		self.data = 0
		self.next = None

def makeNode(current, data):

	newNode = Node()
	newNode.data = data
	newNode.next = current

	return newNode

if __name__ == '__main__':

	numberOfNodes = int(input('Enter number of Nodes : '))
	numberOfEdges = int(input('Enter number of Edges : '))

	graph = [None] * (numberOfNodes+1)

	for i in range(numberOfEdges):
		start = int(input())
		end = int(input())
		graph[start] = makeNode(graph[start], end)
		graph[end] = makeNode(graph[end], start)



	for i in range(numberOfNodes+1):
		temp = graph[i]
		print(i, end='->')
		while temp is not None:
			print(temp.data,end='->')
			temp = temp.next
		print('NULL')
