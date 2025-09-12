#include <iostream>
#include "linked_list.cpp"
using namespace std;

int main()
{
    DLinkedList<int> dll;
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);

    dll.insertAfter(0, 5);

    dll.deleteFront();
    dll.deleteEnd();
    dll.deleteAfter(1);

    dll.displayList();
    dll.displayListRev();
    return 0;
}