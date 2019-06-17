#include "SinglyLinkedList.h"
#include "ListNode.h"
#include <iostream>

namespace ds {

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() 
	: head_(nullptr), tail_(nullptr), size_(0)
{

}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
{
	_copy(other);
}
template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other)
{
	if (&other != this)
	{
		_destroy();
		_copy(other);
	}
	return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	_destroy();
}

template <typename T>
void SinglyLinkedList<T>::insertFront(const T& value)
{
	ListNode<T>* newNode = new ListNode<T>(value);
	ListNode<T>* temp = head_;
	newNode->next_ = temp;
	head_ = newNode;
	if (tail_ == nullptr) {
		tail_ = newNode;
	}
	size_++;

}

template <typename T>
void SinglyLinkedList<T>::insertEnd(const T& value)
{
	ListNode<T>* newNode = new ListNode<T>(value);
	ListNode<T>* temp = tail_;
	temp->next_ = newNode;
	tail_ = newNode;
	if (head_ == nullptr) {
		head_ = newNode;
	}
	size_++;
}

/*
template <typename T>
void SinglyLinkedList<T>::insertIdx(const T& value)
{

}*/

/*
template <typename T>
void SinglyLinkedList<T>::deleteFront()
{
	if (isEmpty()) {
		std::cout << "Empty list, nothing to delete" << std::endl;
		return;
	}
	if (head_ == tail_){
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
	}
	
}*/

/*
template <typename T>
void SinglyLinkedList<T>::deleteEnd()
{

}

template <typename T>
void SinglyLinkedList<T>::deleteIdx(int idx)
{

}

template <typename T>
void SinglyLinkedList<T>::deleteNode(const ListNode* node)
{

}

template <typename T>
void SinglyLinkedList<T>::sort()
{

}

template <typename T>
void SinglyLinkedList<T>::reverse()
{

}
*/

template <typename T>
void SinglyLinkedList<T>::print()
{
	if (isEmpty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}
	std::cout << "This list contains: ";
	ListNode<T>* curr = head_;
	while (curr != nullptr) {
		std::cout << curr->data_ << " ";
		curr = curr->next_;
	}
	std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::printReverse()
{
	if (isEmpty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}
	std::cout << "The reverse list contains: ";
	_printReverse(head_);
	std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::_printReverse(const ListNode<T>* curr)
{
	if (curr == nullptr) {
		return;
	}
	_printReverse(curr->next_);
	std::cout << curr->data_ << " ";
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
	return (size_ == 0 && head_ == nullptr) ? true : false;
}

template <typename T>
int SinglyLinkedList<T>::size() const
{
	return size_;
}

template <typename T>
void SinglyLinkedList<T>::_destroy()
{
	_destroyHelper(head_);
	size_ = 0;
	head_ = nullptr;
	tail_ = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::_destroyHelper(ListNode<T>* curr)
{
	if (curr == nullptr) {
		return;
	}
	_destroyHelper(curr->next_);
	delete curr;
}

template <typename T>
void SinglyLinkedList<T>::_copy(const SinglyLinkedList<T>& other)
{
	if (other.isEmpty()) {
		return;
	}
	ListNode<T>* ocurr = other.head_;
	head_ = new ListNode<T>(ocurr->data_);
	ListNode<T>* curr = head_;
	while (ocurr->next_ != nullptr) {
		curr->next_ = new ListNode<T>(ocurr->next_->data_);
		ocurr = ocurr->next_;
		curr = curr->next_;
	}
	tail_ = curr;
	size_ = other.size_;
}

}