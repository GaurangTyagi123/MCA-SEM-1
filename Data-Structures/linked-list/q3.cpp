#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To reverse a given linked list
int main()
{
    LinkedList<int> *L = new LinkedList<int>();

    int arr[] = {1, 2, 3, 4, 5, 6};
    L->linkedListFromArray(arr, 6);
    L->reverse();

    L->displayList();
    return 0;
}