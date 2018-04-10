#pragma once
#include <assert.h>

/*---------------����ڵ�----------------------*/

template <typename T>
class SLLNode
{
public:
	SLLNode();
	SLLNode(const T& i, SLLNode *in = NULL);

	SLLNode* getNext();
	void setNext(SLLNode* in);
	T getinfo();
	

private:
	SLLNode* next;
	T info;
};

template <typename T>
SLLNode<T>::SLLNode()
{
	next = NULL;
	info = (T)0;
}

template <typename T>
SLLNode<T>::SLLNode(const T& i, SLLNode* in)
{
	info = i;
	next = in;
}

template <typename T>
SLLNode<T>* SLLNode<T>::getNext()
{
	return next;
}

template <typename T>
void SLLNode<T>::setNext(SLLNode<T>* in)
{
	next = in;
}

template <typename T>
T SLLNode<T>::getinfo()
{
	return info;
}

/*---------------------------------------------*/


/*-----------------��������--------------------*/

template <typename T>
class SLList
{
public:
	SLList();
	~SLList();

	bool isEmpty();                 //�п�
	void addToHead(T i);         //�ӿ�ͷ�����
	void addToTail(T i);
	T deleteFromHead();
	T deleteFromTail();
	T deleteNode(T i);      //ɾ������i�����ݽڵ�
	bool isInList(T i) const;    //�Ƿ���list��

	void reserve();         //��ת����

private:
	SLLNode<T>* head, *tail;
	//int SLListLength;               //������
};


template <typename T>
SLList<T>::SLList()
{
	head = tail = NULL;
}

template <typename T>
SLList<T>::~SLList()
{
	for (SLLNode<T> *p; !isEmpty();)
	{
		p = head->getNext();
		delete head;
		head = p;
	}
}

template <typename T>
bool SLList<T>::isEmpty()
{
	return head == NULL;
}

template <typename T>
void SLList<T>::addToHead(T i)
{
	SLLNode<T>* p_sl =new SLLNode<T>(i, head);
	head = p_sl;
	if (tail == NULL)
	{
		tail = head;
	}
}

template <typename T>
void SLList<T>::addToTail(T i)
{
	SLLNode<T>* p_sl = new SLLNode<T>(i);        //���һ����
	if (isEmpty())
	{
		//������û��һ����
		head = tail = p_sl;
	}
	else
	{
		tail->setNext(p_sl);
		tail = tail->getNext();
	}
}

template <typename T>
T SLList<T>::deleteFromHead()
{
	//ɾ��Head���ڵ�
	if (isEmpty())
	{
		//�ձ����¿����������˳�
		return 0;
	}
	else if (head == tail)
	{
		//����ֻ��һ��Ԫ��
		T i = head->getinfo();
		delete head;
		head = tail = NULL;
		return i;
	}
	else
	{
		//�ǿձ�
		SLLNode<T>* newHead = head->getNext();
		T i = head->getinfo();
		delete head;
		head = newHead;
		return i;
	}
}

template <typename T>
T SLList<T>::deleteFromTail()
{
	//ɾ��β���ڵ�
	if (isEmpty())
	{
		return 0;
	}
	else if (head == tail)
	{
		T i = tail->getinfo();
		delete tail;
		head = tail = NULL;
		return i;
	}
	else
	{
		T i = tail->getinfo();

		SLLNode<T>* newtail = NULL;
		SLLNode<T>* p_now = head;
		SLLNode<T>* p_next = head->getNext();
		while(p_next != tail)
		{
			p_now = p_next;
			p_next = p_now->getNext();
		}

		newtail = p_now;

		delete tail;
		tail = newtail;
		tail->setNext(NULL);

		return i;
	}
}


template <typename T>
T SLList<T>::deleteNode(T i)
{
	//ɾ������������i�Ľڵ�
	if (isEmpty())
	{
		return 0;
	}
	else if (head == tail)
	{
		//ֻ��һ����
		if (head->getinfo() == i)
		{
			T tmp_num = head->getinfo();
			delete head;
			head = tail = NULL;
			return tmp_num;
				
		}
		else
		{
			return 0;
		}
	}
	else if (head != tail && head->getinfo() == i)
	{
		//����㣬�ҵ�һ�����info��Ϊi
		T tmp_num = head->getinfo();
		SLLNode<T>* newhead = head->getNext();
		delete head;
		head = newhead;
		return tmp_num;
	}
	else
	{
		//�����
		SLLNode<T>* p_pre;
		SLLNode<T>* p_now;
		
		for (p_pre = head, p_now = head->getNext(); !(p_now->getinfo() == i) && !(p_now == NULL); p_pre = p_pre->getNext(),
			p_now = p_now->getNext())
		{

		}

		if (p_now != NULL)
		{
			//��ʾ�ҵ���
			T tmp_num = p_now->getinfo();
			p_pre->getNext() = p_now->getNext();
			if (p_now == tail)
			{
				tail = p_pre;
			}
			delete p_now;
			return tmp_num;
		}
		else
		{
			return 0;
		}
	}
}

template <typename T>
bool SLList<T>::isInList(T i) const
{
	SLLNode<T>* tmp;
	for (tmp = head; !(tmp == NULL) && !(tmp->getinfo() == i); tmp = tmp->getNext())
	{
		
	}

	return !(tmp == NULL);
}


template <typename T>
void SLList<T>::reserve()
{
	if (isEmpty())
	{
		return;
	}
	else if (head == tail)
	{
		return;
	}
	else
	{
		//�����
		SLLNode<T>* NowNode = head->getNext();
		SLLNode<T>* PreNode = head;
		SLLNode<T>* tmp;
		while (NowNode != NULL)
		{
			tmp = NowNode->getNext();
			NowNode->setNext(PreNode);
			PreNode = NowNode;
			NowNode = tmp;
		}

		tmp = head;
		head = tail;
		tail = tmp;

	}
}

