#ifndef DATA_STRUCTURES_LIST_SINGLYLINKEDLIST_H_
#define DATA_STRUCTURES_LIST_SINGLYLINKEDLIST_H_

#include <iostream>

namespace data_structures {

template <typename T>
class SinglyLinkedList {
 public:
  class ListNode {
   public :
    explicit ListNode(const T & value) : data_(value), next_(nullptr) {}

    T data_;
    ListNode* next_;
  };

  //  Constructors + Destructors
  SinglyLinkedList();
  SinglyLinkedList(const SinglyLinkedList& other);
  SinglyLinkedList& operator=(const SinglyLinkedList& other);
  ~SinglyLinkedList();

  //  Insert and Delete functions
  void InsertFront(const T& value);
  void InsertEnd(const T& value);

  void DeleteFront();
  void DeleteEnd();

  //  Operate on List
  void Sort();
  void Reverse();
  void ReverseRecursive();
  void Print() const;
  void PrintReverse() const;

  unsigned size() const;

  //  CTCI Algorithms
  void Partition(const T& pivot);

 private:
  //  Aspects of Structure
  bool IsEmpty() const;

  //  Private helper functions
  ListNode* SortHelper(ListNode* curr, unsigned size);
  ListNode* MergeHelper(ListNode* front, ListNode* back);
  void ReverseRecursiveHelper(ListNode* curr, ListNode* prev);
  void PrintReverseHelper(const ListNode* curr) const;
  void Destroy();
  void DestroyHelper(ListNode* curr);
  void Copy(const SinglyLinkedList<T>& other);

  ListNode* head_;
  ListNode* tail_;
  unsigned size_;
};
}   // namespace data_structures

#endif  // DATA_STRUCTURES_LIST_SINGLYLINKEDLIST_H_
