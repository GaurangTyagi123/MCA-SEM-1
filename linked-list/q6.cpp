#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To Split a linked list into 2 list such that First list must contain the all nodes with even places and Second list must contain all the nodes with odd places.

int main()
{
    LinkedList<int> *L = new LinkedList<int>();

    int arr[] = {1,2,3,4,3,1};
    L->linkedListFromArray(arr, 6);
    LinkedList<int>* OddList = L->splitList();

    OddList->displayList();
    return 0;
}