#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To find the intersection node of two intersecting linked lists
int main()
{
    LinkedList<int> *L1 = new LinkedList<int>();
    LinkedList<int> *L2 = new LinkedList<int>();

    int arr[] = {1, 2, 3, 4, 5, 6};
    L1->linkedListFromArray(arr, 6);

    int arr2[] = {7, 8};
    L2->linkedListFromArray(arr2, 2);

    L1->mergeAtNode(L2->getHead(), 5);
    int res = LinkedList<int>::intersectionNode(L1->getHead(), L2->getHead());
    cout << res << endl;
    L2->displayList();

    return 0;
}