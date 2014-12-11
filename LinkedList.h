/**
 * A doubly-linked list.
 * Stub written by James Daly, 5 Sept 2014
 * Completed by Alex Bergman
 */
 
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <functional>


template<class T> class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	~LinkedList();

	void operator=(const LinkedList<T>& other);
	
	// These methods are provided for you
	void Clear();
	void Display() const;
	bool IsEmpty() const;
	int Size() const;
	
	// Methods to add data to the front or the back of the list
	// These should run in O(1) time
	void PushFront(const T &t);
	void PushBack(const T &t);
	void PopFront();
	void PopBack();
	
	// These methods can run in O(n) time
	void Filter(std::function<bool (const T)> isIn);
	void ForEach(std::function<void (const T)> func) const;
	
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
	
	// You can put helper methods here
};

/**
 * Default constructor
 * Creates an empty list
 * You are allowed (but not required) to change this method
 */
template <class T> LinkedList<T>::LinkedList():
	head(nullptr),
	tail(nullptr),
	size(0)
{
	// Empty
}

/**
 * Copy Constructor
 * Creates a shallow copy of the other list
 */
template <class T> LinkedList<T>::LinkedList(const LinkedList<T> & other) : LinkedList() {
	auto insertItem = [=](T x){ this->PushBack(x); };
	other.ForEach(insertItem);
}

template <class T> LinkedList<T>::~LinkedList() {
	Clear();
}

/**
 * Assignment operator
 * Creates a shallow copy of the other list
 */
template <class T> void LinkedList<T>::operator=(const LinkedList<T> & other) {
	if (this != &other) {
		Clear();
		auto insertItem = [=](T x){ this->PushBack(x); };
		other.ForEach(insertItem);
	}
}

/**
 * Removes all elements from this list
 */
template <class T> void LinkedList<T>::Clear() {
	while(!IsEmpty()) {
		PopFront();
	}
}

/**
 * Prints the contents of this list to the console
 */
template <class T> void LinkedList<T>::Display() const {
	using namespace std;
	auto printItem = [](T x) { cout << x << " "; };
	ForEach(printItem);
	cout << endl;
}

/**
 * Checks if the list contains no items
 */
template <class T> bool LinkedList<T>::IsEmpty() const{
	return size == 0;
}

/**
 * Counts the number of items in the list
 */
template <class T> int LinkedList<T>::Size() const {
	return size;
}

/**
 * Adds the item to the front of the list
 */
template <class T> void LinkedList<T>::PushFront(const T &t) {
	
	if(head == nullptr){
		head = new Node<T>(t);
		tail = new Node<T>(t);
	} else {
 		head->prev = new Node<T>(t);
 		Node<T>* temp = head;
 		head = new Node<T>(t);
 		head->next = temp;
 	}
 	size++;
}

/**
 * Adds the item to the back of the list
 */
template <class T> void LinkedList<T>::PushBack(const T &t) {
 	if(head == nullptr && tail == nullptr){
		head = new Node<T>(t);
		
	} else if(tail == nullptr) {
		tail = new Node<T>(t);
		head->next = tail;
		tail->prev = head;
	} else {
		Node<T>* temp = new Node<T>(t);
 		tail->next = temp;
 		temp->prev = tail;
 		tail = temp;
 	}
 	size++;
}

/**
 * Removes the item at the front of the list
 */
template <class T> void LinkedList<T>::PopFront() {
	if(size == 0){

		head = nullptr;
		tail = nullptr;
		size = 0;
	} else if(size == 1){

		Node<T>* temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		size = 0;

	} else {
		Node<T>* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
		size--;
	}
}

/**
 * Removes the item at the back of the list
 */
template <class T> void LinkedList<T>::PopBack() {
 	if(size == 0){
		head = nullptr;
		tail = nullptr;
		size = 0;
	} else if(size == 1) {
		Node<T>* temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		size = 0;

	} else {
		Node<T>* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		size--;
	}
}

/**
 * Edits this list to keep only the items where isIn(x) returns true
 * Other items are deleted
 */
template <class T> void LinkedList<T>::Filter(std::function<bool (const T)> isIn) {
	
	int n = 0;
 	Node<T>* count = head;
 	while(n < size){
 		
 		if(!isIn(count->payload) && !IsEmpty()){
 			Node<T>* temp = count;
 			if(count == head) {
 				if(count->next != nullptr)
 					count->next->prev = nullptr;
 				head = count->next;
 				size--;

 			} else if(count == tail) {
 				if(count->prev != nullptr)
 					count->prev->next = nullptr;
 				tail = count->prev;
 				size--;
 			} else {
 				if(count->next != nullptr)
 					count->next->prev = count->prev;
 				if(count->prev != nullptr)
 					count->prev->next = count->next;
 				size--;
 			}
 			count = count->next;
 			delete temp;
 		} else {
 			count = count->next;
 			n++;
 		}
 		
 	}

}

/**
 * Executes func(x) on each x in the list
 */
template <class T> void LinkedList<T>::ForEach(std::function<void (const T)> func) const {
 	int n = 0;
 	Node<T>* temp = head;
 	while(n < size){
 		func(temp->payload);
 		temp = temp->next;
 		n++;
 	}

}

#endif
