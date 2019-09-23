///  double list example

#pragma once
#include <iostream>
using namespace std;
class Data
{
private:
	int wert;
	Data *prev;
	Data *next;

public:
	Data(int n) 
	{
		wert = n;
		next = nullptr;
		prev = nullptr;
	}
	Data* getNext() 
	{
		return next;
	}
	Data* getPrev()
	{
		return prev;
	}
	void setNext(Data *d) 
	{
		next = d;
	}
	void setPrev(Data *d)
	{
		prev = d;
	}
	void Set(int n) {
		wert = n;
	}
	int Get() {
		return wert;
	}
};

/////////////////////////
// double list
#pragma once
#include <iostream>
#include "Data.h"
using namespace std;

class DoubleList
{
private:
	Data *header;

public:
	DoubleList()
	{
		header = nullptr;
	}
	~DoubleList()
	{
		Data *d = header;
		while (d != nullptr)
		{
			Data *tmp2 = d;
			d = d->getNext();
			delete tmp2;
		}
	}

	void add(int n)
	{
		Data *d = new Data(n);
		d->setNext(header);
		d->setPrev(nullptr);

		if (header != nullptr)
		{
			header->setPrev(d);
		}
		header = d;
	}

	bool del(int n)
	{
		cout << "del( " << n << ") : \n";
		Data *d = header;
		while (d != nullptr)
		{
			if (d->Get() == n) // found
			{
				debug(d);
				Data *prev = d->getPrev();
				Data *next = d->getNext();
				if ( prev == nullptr ) // first element
				{
					header = next;
					if ( header != nullptr )
					{
						header->setPrev(nullptr);
					}
				}
				else if (next == nullptr) // last element
				{
					if (prev != nullptr)
					{
						prev->setNext(nullptr);
					}
				}
				else
				{
					prev->setNext(next);
					next->setPrev(prev);
				}
				delete d;
				return true;
			}
			d = d->getNext();
		}
		return false;
	}

	void debug(Data *tmp)
	{
		Data *next = tmp->getNext();
		Data *prev = tmp->getPrev();
		int prevValue = 0, nextValue = 0;
		if (prev != nullptr)
			prevValue = prev->Get();
		if (next != nullptr)
			nextValue = next->Get();
		cout << "DEBUG: prev: 0x" << prev << " (" << prevValue;
		cout << ") -> 0x" << tmp << " (" << tmp->Get() << ") -> ";
		cout << " next: 0x" << next << " (" << nextValue << ")\n";
	}

	void print()
	{
		Data *tmp = header;
		if (tmp == nullptr)
			cout << "void List\n";
		while (tmp != nullptr)
		{
			cout << tmp->Get() << " : pre 0x" << tmp->getPrev();
			cout << " <- 0x" << tmp << " ->  next 0x" << tmp->getNext() << endl;
			tmp = tmp->getNext();
		}
		cout << "--------------------------------\n";
	}
};




////////////////////////////77
// main

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "DoubleList.h"

using namespace std;

int main()
{
	DoubleList dl;
	dl.print();
	dl.del(-12);

	dl.add(12);
	dl.print();
	dl.del(12);
	dl.print();

	for (int i(-15); i<20; i++)
		dl.add(i);

	dl.print();
	dl.del(-2333);
	dl.del(19);
	dl.del(-15);
	dl.del(3);
	dl.print();

	
	return 0;

}