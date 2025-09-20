#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To delete all occurarences of a key
int main()
{
    LinkedList<int> *L = new LinkedList<int>();

    int arr[] = {3, 2, 3, 3, 5, 6};
    L->linkedListFromArray(arr, 6);
    L->deleteAllOccurrences(3);

    L->displayList();
    return 0;
}