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
