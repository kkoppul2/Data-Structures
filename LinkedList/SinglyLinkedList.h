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
		void insertFront(const T& value);								//Insert a value at the start of the list
		void insertEnd(const T& value);									//Insert a value at the end of the list

		void deleteFront();												//Delete node at the front
		void deleteEnd();												//Delete node at the end of the list

		//Operate on List
		void sort();													//Sorts linked list
		void reverse(); 												//Reverses linked list
		void reverseRecursive();										//Reverses linked list using a recursive algorithm
		void print() const;												//Prints out the contents of list 
		void printReverse() const;										//Prints contents of list in reverse order
		
		unsigned size() const;											//Returns size of list

		//CTCI Algorithms
		//void removeDuplicates();										//
		//T returnKthToLast(unsigned idx);								//Returns the kth to last value in the list
		void partition(const T& value);									//Partitions the list around a given value

	private:
		//Aspects of Structure 
		bool isEmpty() const;											//Checks if list is empty
		
		//Private helper functions
		ListNode<T>* _sort(ListNode<T>* curr, unsigned size);			//Recursive sorting helper fucntion
		ListNode<T>* _merge(ListNode<T>* front, ListNode<T>* back);		//Merge helper function for sorting list
		 
		void _reverseRecursive(ListNode<T>* curr, ListNode<T>* prev);	//Recursive helper to reverse list
		void _printReverse(const ListNode<T>* curr) const;				//Recursive function to print out list
		void _destroy();												//Deep delete contents of list
		void _destroyHelper(ListNode<T>* curr);							//Recursive helper function for deep delete of list
		void _copy(const SinglyLinkedList<T>& other);					//Deep copy of another list 

		ListNode<T>* head_;
		ListNode<T>* tail_;
		unsigned size_;

};

}

#include "SinglyLinkedList.hpp"

#endif