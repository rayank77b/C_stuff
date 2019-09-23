#pragma once
#include <iostream>
using namespace std;
class Data
{
private:
	int wert;
    Data *next;

public:
	Data(int n) {
        wert = n;
        next=nullptr;
	}
    Data* getNext() {
        return next;
    }
    void setNext(Data *d) {
        next = d;
    }// nothing found or list is void
    void Set(int n) {
        wert = n;
    }
    int Get(){
        return wert;
    }
};

////////////////////////////////////////
#pragma once
#include <iostream>
#include "Data.h"
using namespace std;
class SimpleList
{
private:
    Data *header;

public:
    SimpleList() {
        header = nullptr;// nothing found or list is void
    }
    ~SimpleList() {
        // TODO: alle delete
    }

    Data* getLast() {
        if (header == nullptr )
            return nullptr;

        Data *d = header;
        while (d->getNext() != nullptr)
            d=d->getNext();
        return d;
    }

    Data* find(int n) {
        Data *tmp = header;
        while(tmp!=nullptr) {
            if ( tmp->Get() == n )
                return tmp;
            tmp = tmp->getNext();
        }// nothing found or list is void
        return tmp;
    }

    Data* findPrevious(Data *n) {
        Data *tmp = header;
        if (tmp == nullptr)  // list is void
            return nullptr;
        if (tmp->getNext() == nullptr ) // list has only one element
            return nullptr;
        while(tmp->getNext() == n)
            tmp = tmp->getNext();
        return tmp;
    }

    void add(int n) {
        Data *d = new Data(n);
        Data *last = getLast();
        if ( last == nullptr)
            header = d;
        else
            last->setNext(d);
    }

    bool del(int n) {
        Data *tmp = find(n);
        if (tmp == nullptr)  // nothing found or list is void
            return false;
        
        if ( tmp == header ) { // element is header or one elemnt
            header = header->getNext();
            delete tmp;
            return true;
        }

        Data *prev = findPrevious(tmp);  // more than 1 element

        cout << "DEBUG: prev: 0x" << prev << " (" << prev->Get();
        cout << ") -> tmp 0x" << prev->getNext();
        cout << " [ 0x" << tmp << " ("<< tmp->Get()<<")]   ";
        prev->setNext(tmp->getNext());
        delete tmp;
        return true;
    }

    void print() {
        if ( header == nullptr ) {
            cout << "List is void\n";
        } else {
            Data *tmp=header;
            while(tmp!=nullptr) {
                cout << tmp->Get() << " :  0x" << tmp << " -> 0x"<< tmp->getNext() <<endl;
                tmp = tmp->getNext();
            }
        }
        cout<<"----------------------------------------------\n";
    }
};



///////////////////////////////////
// main
#include <stdio.h>
#include "Data.h"

using namespace std;

int main()
{
    SimpleList sl;

    sl.print();
    cout << "del(1): "<<sl.del(1)<<endl;
    sl.add(1);
    cout << "del(2): "<<sl.del(2)<<endl;
    sl.print();

    cout << "del(1): "<<sl.del(1)<<endl;
    sl.print();
    
    sl.add(1);
    sl.add(22); 
    sl.add(33);
    sl.print();
    
    cout << "del(1): "<<sl.del(1)<<endl;
    sl.print();

    sl.add(55); sl.add(40);
    sl.print();
    cout << "del(33): "<<sl.del(33)<<endl;
    sl.print();
    cout << "del(1): "<<sl.del(1)<<endl;
    sl.print();
    cout << "del(55): "<<sl.del(55)<<endl;
    sl.print();
    return 0;


    for(int i(0); i<10; i++)
        sl.add(i);
    sl.del(8);
    sl.add(55);
    sl.print();

    return 0;
}








