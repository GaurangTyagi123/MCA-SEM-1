#include <iostream>
#include "linked_list.cpp"
using namespace std;

/*
    Objective : To find the middle element of the given linked list
*/
int main()
{
    LinkedList<int> *L1 = new LinkedList<int>();
    int arr[7] = {1, 2, 3, 4, 5, 7};

    L1->linkedListFromArray(arr, 7);
    cout << L1->inMiddle() << ": is the middle element of the given linked list" << endl;

    return 0;
}