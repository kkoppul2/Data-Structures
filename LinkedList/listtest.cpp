#include "ListNode.h"
#include "SinglyLinkedList.h"
#include <iostream>

using namespace ds;

int main()
{
	SinglyLinkedList<int> test;
	test.insertFront(1);
	test.insertFront(2);

	// test.insertIdx(1, 100);
	// test.print();
	// test.insertIdx(2, 0);
	// test.print();
	// test.insertIdx(3, 2);
	// test.print();
	// test.insertIdx(4);
	// test.print();
	// test.insertIdx(5);
	test.print();

	
	test.sort();
	test.print();

	return 0;
}