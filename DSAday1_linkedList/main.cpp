
#include "LinkedList.h"


int main()
{
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.display();

    list.InsertAfter(25, 20);
    list.display();

    list.InsertBefore(5, 10);
    list.display();

    list.remove(20);
    list.display();

    cout << "Length: " << list.GetCount() << endl;
    cout << "Data at index 2: " << list.GetDataByIndex(2) << endl;

    return 0;
}
