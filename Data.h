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











