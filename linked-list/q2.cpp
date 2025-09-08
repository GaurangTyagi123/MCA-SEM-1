#include <iostream>
#include "linked_list.cpp"
using namespace std;

/*
    Objective : To find nth element from the end of a given linked list
*/
int main()
{
    LinkedList<int> *L1 = new LinkedList<int>();
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    L1->linkedListFromArray(arr, 7);
    L1->displayList();
    cout << L1->nFromEnd(5) << ": is the second last element from the end" << endl;

    return 0;
}