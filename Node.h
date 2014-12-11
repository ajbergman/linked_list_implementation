//
// class Node
// The nested node class for objects in our linked list.
//


#ifndef NODE_H
#define NODE_H

template<class T> class LinkedList;

template<class T> class Node 
{
	friend class LinkedList<T>;
public:
	Node() {next = nullptr;  prev = nullptr;}
	Node(const T &t) {payload = t;  next = nullptr;  prev = nullptr;}

	T Data() {return payload;}
	const T Data() const {return payload;}

private:
	Node<T> *next;
	Node<T> *prev;
	T payload;
};
  
 #endif