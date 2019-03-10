#pragma once

//采用循环数组实现队列

template <typename T,int size = 100>
class ArrayQueue
{
public:
	ArrayQueue();
	~ArrayQueue();

	bool enqueue(const T& i);
	const T denqueue();

	bool isEmpty();
	bool isFull();

private:
	int first, last;
	T storage[size];
};

template <typename T,int size>
ArrayQueue<T, size>::ArrayQueue()
{
	first = last = -1;
}

template <typename T,int size>
bool ArrayQueue<T, size>::isEmpty()
{
	return first == -1;
}

template <typename T,int size>
bool ArrayQueue<T, size>::isFull()
{
	if ((first == 0 && last == size - 1) || (first == last + 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T, int size>
bool ArrayQueue<T, size>::enqueue(const T& i)
{
	if (!isFull())
	{
		if (last == size - 1 || last == -1)
		{
			storage[0] = i;
			last = 0;
			if (first == -1)
			{
				first = 0;
			}
		}
		else
		{
			storage[last] = i;
			last++;
		}
	}
	else
	{
		return false;
	}
}

template <typename T ,int size>
const T ArrayQueue<T, size>::denqueue()
{
	if (!isEmpty())
	{

	}
	else
	{
		T tmp;
		tmp = storage[first];
		if (first == last)
		{
			//只有一个元素
			first = last = -1;
		}
		else if (first == size - 1)
		{
			first = 0;
		}
		else
		{
			first++;
		}
		return tmp;
	}
}
