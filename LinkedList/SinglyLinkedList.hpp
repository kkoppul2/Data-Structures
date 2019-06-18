#include "SinglyLinkedList.h"
#include "ListNode.h"
#include <iostream>

namespace ds {

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() 
	: head_(nullptr), tail_(nullptr), size_(0)
{
	//
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
	: head_(nullptr), tail_(nullptr), size_(0)
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
	if (tail_== nullptr) {
		tail_ = newNode;
	} else {
		tail_->next_ = newNode;
		tail_ = tail_->next_;
	}
	if (head_ == nullptr) {
		head_ = newNode;
	}
	size_++;
}

template <typename T>
void SinglyLinkedList<T>::deleteFront()
{
	if (isEmpty()) {
		std::cout << "Invalid Delete: The list is already empty!" << std::endl;
		return;
	}
	ListNode<T>* temp = head_;
	head_ = head_->next_;
	if (head_ == nullptr) {
		tail_ = nullptr;
	}
	delete temp;
	size_--;
}

template <typename T>
void SinglyLinkedList<T>::deleteEnd()
{
	if (isEmpty()) {
		std::cout << "Invalid Delete: The list is already empty!" << std::endl;
		return;
	}
	ListNode<T>* curr = head_;
	if (curr->next_ == nullptr) {
		delete tail_;
		head_ = nullptr;
		tail_ = nullptr;
	} else {
		while (curr->next_ != tail_) {
			curr = curr->next_;
		}
		curr->next_ = nullptr;
		delete tail_;
		tail_ = curr;
	}
	size_--;
}

template <typename T>
void SinglyLinkedList<T>::sort()
{
	head_ = _sort(head_, size_);
	ListNode<T>* curr = head_;
	while (curr->next_ != nullptr) {
		curr = curr->next_;
	}
	tail_ = curr;
	
}

template <typename T>
ListNode<T>* SinglyLinkedList<T>::_sort(ListNode<T>* front, unsigned size)
{
	if (front == nullptr || front->next_ == nullptr) {
		return front;
	}
	ListNode<T>* back = front;
	ListNode<T>* prev = nullptr;
	for (unsigned i = 0; i < size/2; ++i) {
		prev = back;
		back = back->next_;
	}
	prev->next_ = nullptr;
	front = _sort(front, size/2);
	back = _sort(back, size-(size/2));
	return _merge(front, back);
}

template <typename T>
ListNode<T>* SinglyLinkedList<T>::_merge(ListNode<T>* front, ListNode<T>* back)
{
	ListNode<T>* head = nullptr;
	if (front->data_ <= back->data_) {
		head = front;
		front = front->next_;
	} else {
		head = back;
		back = back->next_;
	}
	ListNode<T>* next = head;
	while (front != nullptr && back != nullptr) {
		if (front->data_ <= back->data_) {
			next->next_ = front;
			front = front->next_;
		} else {
			next->next_ = back;
			back = back->next_;
		}
		next = next->next_;
	}
	if (front == nullptr) {
		next->next_ = back;
	} else if (back == nullptr) {
		next->next_ = front;
	}

	return head;
}

template <typename T>
void SinglyLinkedList<T>::reverse()
{
	if (isEmpty() || head_ == tail_)
	{
		return;
	}
	ListNode<T>* prev = nullptr;
	ListNode<T>* curr = head_;
	ListNode<T>* next = curr->next_;
	while (next != nullptr) {
		curr->next_ = prev;
		prev = curr;
		curr = next;
		next = curr->next_;
	}
	curr->next_ = prev;
	curr = head_;
	head_ = tail_;
	tail_ = curr;
}

template <typename T>
void SinglyLinkedList<T>::reverseRecursive()
{
	_reverseRecursive(head_, nullptr);
	ListNode<T>* temp = head_;
	head_ = tail_;
	tail_ = temp;
}

template <typename T>
void SinglyLinkedList<T>::_reverseRecursive(ListNode<T>* curr, ListNode<T>* prev)
{
	if (curr == nullptr) {
		return;
	}
	_reverseRecursive(curr->next_, curr);
	curr->next_ = prev;
}

template <typename T>
void SinglyLinkedList<T>::print() const
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
void SinglyLinkedList<T>::printReverse() const
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
void SinglyLinkedList<T>::_printReverse(const ListNode<T>* curr) const
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
unsigned SinglyLinkedList<T>::size() const
{
	return size_;
}

template <typename T>
void SinglyLinkedList<T>::_destroy()
{
	if (isEmpty()) {
		return;
	}
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

template <typename T>
void SinglyLinkedList<T>::partition(const T& value) 
{
	
}

}