#
# Code Contributor(s) : Rajeev Ranjan
#

import sys

class Node:
	
	def __init__(self):
		self.data = 0
		self.next = None

class LinkedList:

	def __init__(self):
		self.head = None
		self.tail = None
		self.length = 0

	def getLength(self):
		return self.length

	def headInsertion(self, data):

		if self.head is None:
			newNode = Node()
			newNode.data = data
			newNode.next = None
			self.head = newNode
			self.tail = newNode
		else:
			newNode = Node()
			newNode.data = data
			newNode.next = self.head
			self.head = newNode

		self.length += 1

	def tailInsertion(self, data):

		if self.tail is None:
			newNode = Node()
			newNode.data = data
			newNode.next = None
			self.head = newNode
			self.tail = newNode

		else:
			newNode = Node()
			newNode.data = data
			newNode.next = None
			self.tail.next = newNode
			self.tail = newNode

		self.length += 1

	def showList(self):
		
		temp = self.head
		while temp is not None:
			print(temp.data,end='->')
			temp = temp.next

		print('NULL')
			

if __name__ == '__main__':

	l = LinkedList()
	while True:
		print('---------1.Head Insertion---------\n---------2.Tail Insertion---------\n---------3.Show List--------- \
			  \n---------4.Length of List---------\n---------5.Exit---------')
		choice = int(input('Choice :'))
		if choice == 1:
			data = int(input())
			l.headInsertion(data)
		elif choice == 2:
			data = int(input())
			l.tailInsertion(data)
		elif choice == 3:
			l.showList()
		elif choice == 4:
			print('Length : ', l.getLength())
		else:
			sys.exit()
