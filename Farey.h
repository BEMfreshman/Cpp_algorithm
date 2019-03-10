#pragma once


#include "DLList.h"

struct FareyNum
{
	int up;
	int down;
} ;

class Farey
{
public:
	Farey();
	Farey(int n);
	~Farey();

	void ShowAll();

private:
	DLList<FareyNum>* p_dl;
};
