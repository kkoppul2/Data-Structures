#include "ListNode.h"
#include <iostream>

using namespace ds;

int main()
{
	ListNode<int> test1;
	ListNode<int> test2 = test1;
	std::cout << test1.data_ << std::endl;
	// delete test1;
	// std::cout << test1->data << std::endl;
	// ListNode<int> test3(*test1);
	std::cout << test2.data_ << std::endl;
	return 0;
}