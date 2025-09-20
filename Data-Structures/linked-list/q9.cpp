#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To return the value of the node where the loop starts.

int main()
{
    LinkedList<int> *L = new LinkedList<int>();
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    L->loopedLinkedListFromArray(arr, 4, 8);
    // L->linkedListFromArray(arr,8);

    cout << L->loopNodeVal() << endl;

    return 0;
}