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

