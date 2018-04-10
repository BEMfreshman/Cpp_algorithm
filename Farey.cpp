#include "Farey.h"

Farey::Farey()
{
	p_dl = new DLList<FareyNum>;
}

Farey::Farey(int n)
{
	p_dl = new DLList<FareyNum>;

	int a, b, c, d;

	//��ʼ��
	//1��Farey��
	a = 0;
	b = 1;
	c = 1;
	d = 1;

	FareyNum One;
	FareyNum Two;
	One.up = a;
	One.down = c;

	Two.up = b;
	Two.down = d;
	

	p_dl->addToTail(One);
	p_dl->addToTail(Two);

	if (n == 1)
	{
		return;
	}
	else
	{
		//n��1��
		
		//�����������е�������Ŀ����������c+d>n,����
		while (1)
		{
			FareyNum First;
			FareyNum Second;

			bool exitflag = true;

			for (DLLNode<FareyNum>* dlnode = p_dl->getHead();
				dlnode != p_dl->getTail();
				dlnode = dlnode->getNext())
			{
				First = dlnode->getInfo();
				Second = dlnode->getNext()->getInfo();

				if (First.down + Second.down <= n)
				{
					FareyNum tmp;
					tmp.up = First.up + Second.up;
					tmp.down = First.down + Second.down;
					if (p_dl->InsertAfter(dlnode, tmp) == false)
					{
						throw("Error:Node Not Found");
					}
				}
				else
				{

				}

				exitflag = exitflag && (First.down + Second.down > n);

			}

			if (exitflag == true)
			{
				break;
			}
		}

	}
}

Farey::~Farey()
{
	delete p_dl;
	p_dl = NULL;
}

void Farey::ShowAll()
{
	for (DLLNode<FareyNum>* p_node = p_dl->getHead();
		p_node != NULL;
		p_node = p_node->getNext())
	{
		cout << double(p_node->getInfo().up) / p_node->getInfo().down << "  ";
	}
	cout << endl;
}

