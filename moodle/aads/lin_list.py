class Node:
	def __init__(self, data, prev = None, next = None):
		self.__data = data
		self.__prev__ = prev
		self.__next__ = next

	def get_data(self):
		return self.__data

	def __str__(self):
		return "data: {0}, prev: {1}, next: {2}".format(self.__data, self.__prev__.get_data() if self.__prev__ else None, self.__next__.get_data() if self.__next__ else None)

class LinkedList:
	def __init__(self, first = None, last = None):
		if first == None and last != None:
			raise ValueError("invalid value for last")
		elif first != None and last == None:
			self.__first__ = self.__last__ = Node(first)
		else:
			if first:
				self.__first__ = Node(first)
			else:
				self.__first__ = None
			if last:
				self.__last__ = Node(last, self.__first__)
			else:
				self.__last__ = None
			if first:
				self.__first__.__next__ = self.__last__

	def __len__(self):
		i = 0
		it = self.__first__
		while it:
			i += 1
			it = it.__next__
		return i

	def append(self, element):
		new = Node(element, self.__last__)
		if self.__last__:
			self.__last__.__next__ = new
			self.__last__ = new
		else:
			self.__first__ = self.__last__ = new

	def __str__(self):
		if len(self) == 0:
			return "LinkedList[]"

		res = "LinkedList[length = {0}, [".format(len(self))
		it = self.__first__
		while it:
			res += str(it)
			if it.__next__:
				res += "; "
			it = it.__next__

		return res + "]]"

	def pop(self):
		if not self.__first__:
			raise IndexError("LinkedList is empty!")
		self.__last__.__prev__.__next__ = None
		self.__last__ = self.__last__.__prev__

	def popitem(self, element):
		it = self.__first__
		found = False
		while it:
			if it.get_data() == element:
				found = True
				pr = it.__prev__
				nx = it.__next__
				if pr:
					pr.__next__ = nx
				if nx:
					nx.__prev__ = pr

				if it == self.__first__:
					self.__first__ = nx
				if it == self.__last__:
					self.__last__ = pr

				break

			it = it.__next__

		if not found:
			raise KeyError("{0} doesn't exist!".format(element))

	def clear(self):
		self.__first__ = self.__last__ = None
