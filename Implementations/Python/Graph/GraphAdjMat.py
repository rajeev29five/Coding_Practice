import sys


def showMatrix(matrix, numberOfNodes):
	
	for i in range(numberOfNodes):
		print(matrix[i])


if __name__ == '__main__':
	
	numberOfNodes = int(input('Enter number of Nodes : '))
	numberOfEdges = int(input('Enter number of Edges : '))
	matrix = [[0 for x in range(numberOfNodes)]for y in range(numberOfNodes)]
	for i in range(numberOfEdges):
		start = int(input('Enter the source node : '))
		end = int(input('Enter the destination node : '))
		matrix[start][end] = 1
		matrix[end][start] = 1
	
	showMatrix(matrix, numberOfNodes)
