
template <typename T>
ListNode<T>::ListNode() 
	: next(nullptr)
{

}

template <typename T>
ListNode<T>::ListNode(const T& value)
	: data(value), next(nullptr)
{

}

template <typename T>
ListNode<T>::ListNode(const ListNode& other) 
	: data(other.data), next(other.next)
{

}

template <typename T>
ListNode<T>::~ListNode()
{

}