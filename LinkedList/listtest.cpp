#include "ListNode.h"
#include "SinglyLinkedList.h"
#include <iostream>

using namespace ds;

int main()
{
	SinglyLinkedList<int> test;
	SinglyLinkedList<int> copytest(test);
	SinglyLinkedList<int> operatortest;
	operatortest = copytest;
	test.print();
	operatortest.print();
	return 0;
}