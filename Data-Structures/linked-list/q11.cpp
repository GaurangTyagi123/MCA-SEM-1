#include <iostream>
#include "linked_list.cpp"
using namespace std;

// objective: merge two linked lists
int main()
{
    int arr1[] = {5, 10, 15, 20, 25};
    int arr2[] = {3, 6, 9, 12, 15};

    LinkedList<int> *L1 = new LinkedList<int>();
    LinkedList<int> *L2 = new LinkedList<int>();

    L1->linkedListFromArray(arr1, 5);
    L2->linkedListFromArray(arr2, 5);

    Node<int> *mergedL = LinkedList<int>::mergeAlternate(L1->getHead(), L2->getHead());
    while(mergedL){
        cout << mergedL->data << endl;
        mergedL = mergedL->next;
    }

    return 0;
}