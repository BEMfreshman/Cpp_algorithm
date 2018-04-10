#pragma once
//˫������
#include <iostream>
using namespace std;

/*--------˫������ڵ�---------------*/

template <typename T>
class DLLNode
{
public:
	DLLNode();
	DLLNode(const T& in, DLLNode* prev = NULL, DLLNode* next = NULL);

	const T getInfo() const;
	T& getInfo();

	void setInfo(const T& in);
	DLLNode* const getPre() const;
	DLLNode* const getNext() const;

	void setPre(DLLNode* Prev);
	void setNext(DLLNode* Next);


private:
	T info;
	DLLNode* preNode;
	DLLNode* nextNode;
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


/*---------------˫������------------------------*/

template <typename T>
class DLList
{
public:
	DLList();
	~DLList();

	bool isEmpty();

	const T deleteFromHead();
	const T deleteFromTail();
	const T deleteNode(const T& i);

	void addToHead(const T& i);
	void addToTail(const T& i);
	bool InsertAfter(DLLNode<T>* node, const T& i);
	//��node�����i

	DLLNode<T>* const getHead() const;
	DLLNode<T>* const getTail() const;

private:
	DLLNode<T>* head, *tail;
};

template <typename T>
DLLNode<T>* const DLList<T>::getHead() const
{
	return head;
}

template <typename T>
DLLNode<T>* const DLList<T>::getTail() const
{
	return tail;
}


template <typename T>
DLList<T>::DLList()
{
	head = tail = NULL;
}

template <typename T>
DLList<T>::~DLList()
{
	for (DLLNode<T>* p; !isEmpty();)
	{
		p = head->getNext();
		delete head;
		head = p;
	}
}

template <typename T>
bool DLList<T>::isEmpty()
{
	return head == NULL;
}

template <typename T>
const T DLList<T>::deleteFromHead()
{
	//ɾ��ͷ���ڵ�
	if (isEmpty())
	{
		throw("Empty List");
	}
	else if (head == tail)
	{
		//ֻ��һ���ڵ�
		T i = head->getInfo();
		delete head;
		head = tail = NULL;
		return i;

	}
	else
	{
		//����ڵ�
		T i = head->getInfo();
		DLLNode<T>* newHead = head->getNext();
		delete head;
		newHead->setPre(NULL);
		head = newHead;
		return i;
	}
}

template <typename T>
const T DLList<T>::deleteFromTail()
{
	//ɾ��β���ڵ�
	if (isEmpty())
	{
		throw("Empty List");
	}
	else if (head == tail)
	{
		//ֻ��һ���ڵ�
		T i = tail->getInfo();
		delete tail;
		head = tail = NULL;
		return i;
	}
	else
	{
		//����ڵ�
		T i = tail->getInfo();
		DLLNode<T>* newTail = tail->getPre();
		delete tail;
		newTail->setNext(NULL);
		tail = newTail;
		return i;
	}
}

template <typename T>
const T DLList<T>::deleteNode(const T& i)
{
	DLLNode<T>* p;
	for (p = head; p != NULL; p = p->getNext())
	{
		if (p->getInfo() == i)
		{
			break;
		}
	}

	if (p != NULL)
	{
		T i = p->getInfo();
		p->getPre()->setNext(p->getNext());
		delete p;
		return i;
	}
	else
	{
		throw("Not in List");
	}
}

template <typename T>
void DLList<T>::addToHead(const T& i)
{
	if (isEmpty())
	{
		//�ձ�
		head = tail = new DLLNode<T>(i);
	}
	else
	{
		//�����
		head = new DLLNode<T>(i, NULL, head);
		head->getNext()->setPre(head);
	}
}

template <typename T>
void DLList<T>::addToTail(const T& i)
{
	if (isEmpty())
	{
		//�ձ�
		head = tail = new DLLNode<T>(i);
	}
	else
	{
		//�����
		tail = new DLLNode<T>(i, tail, NULL);
		tail->getPre()->setNext(tail);
	}
}

template <typename T>
bool DLList<T>::InsertAfter(DLLNode<T>* node, const T& i)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		DLLNode<T>* findNode;
		for (findNode = head; findNode != NULL; findNode = findNode->getNext())
		{
			if (findNode == node)
			{
				break;
			}
		}

		if (findNode == NULL)
		{
			//�޴˵�
			return false;
		}
		else
		{
			DLLNode<T>* findNodeNext = findNode->getNext();

			DLLNode<T>* newNode = new DLLNode<T>(i, findNode, findNodeNext);

			findNode->setNext(newNode);
			findNodeNext->setPre(newNode);
			return true;
		}

	}
}








/*-----------------------------------------------*/