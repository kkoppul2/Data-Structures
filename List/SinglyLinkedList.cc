#include "SinglyLinkedList.h"

namespace data_structures {

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
    : head_(nullptr), tail_(nullptr), size_(0) {
    Copy(other);
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(
    const SinglyLinkedList<T>& other) {
    if (&other != this) {
        Destroy();
        Copy(other);
    }
    return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Destroy();
}

template <typename T>
void SinglyLinkedList<T>::InsertFront(const T& value) {
    ListNode* newNode = new ListNode(value);
    ListNode* temp = head_;
    newNode->next_ = temp;
    head_ = newNode;
    if (tail_ == nullptr) {
        tail_ = newNode;
    }
    size_++;
}

template <typename T>
void SinglyLinkedList<T>::InsertEnd(const T& value) {
    ListNode* newNode = new ListNode(value);
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
void SinglyLinkedList<T>::DeleteFront() {
    if (IsEmpty()) {
        std::cout << "Invalid Delete: The list is already empty!" << std::endl;
        return;
    }
    ListNode* temp = head_;
    head_ = head_->next_;
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
    delete temp;
    size_--;
}

template <typename T>
void SinglyLinkedList<T>::DeleteEnd() {
    if (IsEmpty()) {
        std::cout << "Invalid Delete: The list is already empty!" << std::endl;
        return;
    }
    ListNode* curr = head_;
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
void SinglyLinkedList<T>::Sort() {
    head_ = SortHelper(head_, size_);
    ListNode* curr = head_;
    while (curr->next_ != nullptr) {
        curr = curr->next_;
    }
    tail_ = curr;
}

template <typename T>
typename SinglyLinkedList<T>::ListNode* SinglyLinkedList<T>::SortHelper(
    ListNode* front, unsigned size) {
    if (front == nullptr || front->next_ == nullptr) {
        return front;
    }
    ListNode* back = front;
    ListNode* prev = nullptr;
    for (unsigned i = 0; i < size/2; ++i) {
        prev = back;
        back = back->next_;
    }
    prev->next_ = nullptr;
    front = SortHelper(front, size/2);
    back = SortHelper(back, size-(size/2));
    return MergeHelper(front, back);
}

template <typename T>
typename SinglyLinkedList<T>::ListNode* SinglyLinkedList<T>::MergeHelper(
    ListNode* front, ListNode* back) {
    ListNode* head = nullptr;
    if (front->data_ <= back->data_) {
        head = front;
        front = front->next_;
    } else {
        head = back;
        back = back->next_;
    }
    ListNode* next = head;
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
void SinglyLinkedList<T>::Reverse() {
    if (IsEmpty() || head_ == tail_) {
        return;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head_;
    ListNode* next = curr->next_;
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
void SinglyLinkedList<T>::ReverseRecursive() {
    ReverseRecursiveHelper(head_, nullptr);
    ListNode* temp = head_;
    head_ = tail_;
    tail_ = temp;
}

template <typename T>
void SinglyLinkedList<T>::ReverseRecursiveHelper(ListNode* curr,
                                                ListNode* prev) {
    if (curr == nullptr) {
        return;
    }
    ReverseRecursiveHelper(curr->next_, curr);
    curr->next_ = prev;
}

template <typename T>
void SinglyLinkedList<T>::Print() const {
    if (IsEmpty()) {
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    std::cout << "This list contains: ";
    ListNode* curr = head_;
    while (curr != nullptr) {
        std::cout << curr->data_ << " ";
        curr = curr->next_;
    }
    std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::PrintReverse() const {
    if (IsEmpty()) {
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    std::cout << "The reverse list contains: ";
    PrintReverseHelper(head_);
    std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::PrintReverseHelper(const ListNode* curr) const {
    if (curr == nullptr) {
        return;
    }
    PrintReverseHelper(curr->next_);
    std::cout << curr->data_ << " ";
}

template <typename T>
bool SinglyLinkedList<T>::IsEmpty() const {
    return size_ == 0;
}

template <typename T>
unsigned SinglyLinkedList<T>::size() const {
    return size_;
}

template <typename T>
void SinglyLinkedList<T>::Destroy() {
    if (IsEmpty()) {
        return;
    }
    DestroyHelper(head_);
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::DestroyHelper(ListNode* curr) {
    if (curr == nullptr) {
        return;
    }
    DestroyHelper(curr->next_);
    delete curr;
}

template <typename T>
void SinglyLinkedList<T>::Copy(const SinglyLinkedList<T>& other) {
    if (other.isEmpty()) {
        return;
    }
    ListNode* ocurr = other.head_;
    head_ = new ListNode(ocurr->data_);
    ListNode* curr = head_;
    while (ocurr->next_ != nullptr) {
        curr->next_ = new ListNode(ocurr->next_->data_);
        ocurr = ocurr->next_;
        curr = curr->next_;
    }
    tail_ = curr;
    size_ = other.size_;
}

template <typename T>
void SinglyLinkedList<T>::Partition(const T& pivot) {
    ListNode* curr = head_;
    ListNode* prev = nullptr;
    bool swap = false;
    while (curr != nullptr) {
        if (curr->data_ < pivot && curr != head_) {
            prev->next_ = curr->next_;
            curr->next_ = head_;
            head_ = curr;
            swap = true;
        }
        if (swap) {
            curr = prev->next_;
        } else {
            prev = curr;
            curr = curr->next_;
        }
        swap = false;
    }
}
}   // namespace data_structures
