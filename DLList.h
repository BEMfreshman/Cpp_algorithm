//双向链表
#include <iostream>
using namespace std;

/*--------双向链表节点---------------*/

template <typename T>
class DLLNode
{
	DLLNode();
	DLLNode(const T& in, DLLNode<T>* prev = NULL, DLLNode<T>* next = NULL);

	const T getInfo() const;
	T& getInfo();

	void setInfo(const T& in);
	DLLNode<T>* const getPre() const;
	DLLNode<T>* const getNext() const;

	void setPre(DLLNode<T>* Prev);
	void setNext(DLLNode<T>* Next);



private:
	T info;
	DLLNode<T>* preNode;
	DLLNode<T>* nextNode;
};


template <typename T>
DLLNode<T>::DLLNode()
{
	preNode = nextNode = NULL;
}

template <typename T>
DLLNode<T>::DLLNode(const T& in, DLLNode<T>* prev = NULL, DLLNode<T>* next = NULL)
{
	info = in;
	preNode = prev;
	nextNode = next;
}

template <typename T>
const T DLLNode<T>::getInfo() const
{
	return info;
}

template <typename T>
T& DLLNode<T>::getInfo()
{
	return info;
}

template <typename T>
void DLLNode<T>::setInfo(const T& in)
{
	info = in;
}

template <typename T>
DLLNode<T>* const DLLNode<T>::getPre() const
{
	return preNode;
}

template <typename T>
DLLNode<T>* const DLLNode<T>::getNext() const
{
	return nextNode;
}

template <typename T>
void DLLNode<T>::setPre(DLLNode<T>* prev)
{
	preNode = prev;
}

template <typename T>
void DLLNode<T>::setNext(DLLNode<T>* next)
{
	nextNode = next;
}

/*-----------------------------------------------*/


/*---------------双向链表------------------------*/

template <typename T>
class DLList
{
public:
	DLList();

};

/*-----------------------------------------------*/