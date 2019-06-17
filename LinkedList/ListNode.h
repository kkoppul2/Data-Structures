#ifndef LIST_NODE_H
#define LIST_NODE_H

namespace ds {

template <typename T>
class ListNode
{
	public :
		ListNode();
		ListNode(const T & value);
		~ListNode();
	
		T data_;
		ListNode* next_;
	
};

}

#include "ListNode.hpp"

#endif