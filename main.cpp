//算法测试文件

#include <iostream>
#include "SLList.h"
#include "DLList.h"
#include "Farey.h"

using namespace std;

int main()
{
	
	////单向链表
	//SLList<int>* p_sl = new SLList<int>;

	//for (int i = 0; i < 10; i++)
	//{
	//	p_sl->addToTail(i);
	//}

	//p_sl->reserve();


	//cout << p_sl->deleteFromHead() << endl;
	//cout << p_sl->deleteFromHead() << endl;

	//cout << p_sl->deleteFromTail() << endl;
	//cout << p_sl->deleteFromTail() << endl;

	//delete p_sl;
	

	////双向链表
	//DLList<int>* p_dl = new DLList<int>;
	//for (int i = 0; i < 10; i++)
	//{
	//	p_dl->addToTail(i);
	//}
	//cout << p_dl->deleteFromHead() << endl;
	//cout << p_dl->deleteFromTail() << endl;
	//cout << p_dl->deleteNode(5) << endl;
	//cout << p_dl->deleteNode(6) << endl;


	Farey fnum(4);
	fnum.ShowAll();


	getchar();
	return 0;
}