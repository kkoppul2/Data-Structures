#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
class ListNode
{
	public :
		ListNode();
		ListNode(const T & value);
		ListNode(const ListNode& other);
		~ListNode();
	
		T data;
		ListNode* next;
	
};

#include "ListNode.hpp"

#endif