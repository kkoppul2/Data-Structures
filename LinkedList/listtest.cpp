#include "ListNode.h"
#include "SinglyLinkedList.h"
#include <iostream>

using namespace ds;

int main()
{
	SinglyLinkedList<int> test;
	test.insertFront(1);
	SinglyLinkedList<int> copytest(test);
	copytest.insertFront(2);
	copytest.insertFront(3);
	copytest.insertFront(4);
	copytest.insertFront(5);
	copytest.insertFront(6);
	SinglyLinkedList<int> operatortest = copytest;
	operatortest.print();
	return 0;
}