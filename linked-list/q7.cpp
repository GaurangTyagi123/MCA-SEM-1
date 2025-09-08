#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To Sum of 2 numbers where digits of each number is stored in nodes of the linked list.
int main()
{
    LinkedList<int> *L1 = new LinkedList<int>();
    LinkedList<int> *L2 = new LinkedList<int>();

    int arr1[] = {9,9,9,9,9,9,9};
    L1->linkedListFromArray(arr1, 7);

    int arr2[] = {9,9,9,9};
    L2->linkedListFromArray(arr2, 4);

    LinkedList<int>* output = LinkedList<int>::sumTwoList(L1->getHead(), L2->getHead());
    output->displayList();

    return 0;
}