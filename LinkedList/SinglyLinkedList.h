#ifndef SINGLY_LINKED_H
#define SINGLY_LINKED_H 

#include "ListNode.h"

namespace ds {

template <typename T>
class SinglyLinkedList
{
	public:
		//Constructors + Destructors
		SinglyLinkedList();												//Custom constructor
		SinglyLinkedList(const SinglyLinkedList& other);				//Copy constructor
		SinglyLinkedList<T>& operator=(const SinglyLinkedList& other);	//Overloaded assignment operator
		~SinglyLinkedList();											//Destructor

		//Insert and Delete functions
		void insertFront(const T& value);				//Insert a value at the start of the list
		void insertEnd(const T& value);					//Insert a value at the end of the list
		//void insertIdx(const T& value, int idx);		//Insert a value at a specified index in the list

		//void deleteFront();							//Delete node at the front
		//void deleteEnd();								//Delete node at the end of the list
		//void deleteIdx(int idx);						//Delete node at an index
		//void deleteNode(const ListNode<T>* node);		//Delete a particular node from the list

		//Operate on List
		//void sort();									//Sorts linked list
		//void reverse(); 								//Reverses linked list
		//void reverseRecursive();						//Reverses linked list using a recursive algorithm
		void print();									//Prints out the contents of list 
		void printReverse();							//Prints contents of list in reverse order
		

	private:
		//Aspects of Structure 
		bool isEmpty() const;							//Checks if list is empty
		int size() const;								//Returns size of list

		//Private helper functions
		void _printReverse(const ListNode<T>* curr);	//Recursive function to print out list
		void _destroy();								//Deep delete contents of list
		void _destroyHelper(ListNode<T>* curr);			//Recursive helper function for deep delete of list
		void _copy(const SinglyLinkedList<T>& other);	//Deep copy of another list 

		ListNode<T>* head_;
		ListNode<T>* tail_;
		int size_;

};

}

#include "SinglyLinkedList.hpp"

#endif