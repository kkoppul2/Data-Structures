#include "ListNode.h"

namespace ds {

template <typename T>
ListNode<T>::ListNode() 
	: next_(nullptr)
{
	data_ = T();
}

template <typename T>
ListNode<T>::ListNode(const T& value)
	: data_(value), next_(nullptr)
{

}

template <typename T>
ListNode<T>::~ListNode()
{

}

}