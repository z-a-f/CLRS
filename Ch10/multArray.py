#!/usr/bin/env python
# Simulating pointer behavior

# THIS IS VERY BAD!!!
# After several iteration you will run out of memory as every node will have two copies of all the entries!!!

class Node:
	def __init__(self, key=None, next=None, prev=None):
		self.next = next
		self.prev = prev
		self.key = key
	def NULL(self):
		if ( (self.key is None) and (self.next is None) and (self.prev is None) ):
			return True
		else:
			return False


class lList:
	def __init__(self):
		self.head = Node()
	def insertNode(self, node):
		node.next = self.head
		node.next.prev = node
		self.head.next = node

a = Node(3)
b = lList()
b.insertNode(a)
a = Node(4)
b.insertNode(a)
print (b.head)


