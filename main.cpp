//Ëã·¨²âÊÔÎÄ¼ş

#include <iostream>
#include "SLList.h"

using namespace std;

int main()
{
	SLList<int>* p_sl = new SLList<int>;

	for (int i = 0; i < 10; i++)
	{
		p_sl->addToTail(i);
	}

	cout << p_sl->isInList(5) << endl;

	cout << p_sl->deleteFromHead() << endl;
	cout << p_sl->deleteFromTail() << endl;

	delete p_sl;

	getchar();
	return 0;
}