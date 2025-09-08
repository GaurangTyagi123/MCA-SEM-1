#include <iostream>
#include "linked_list.cpp"

using namespace std;

// Objective : To Check if linked list has loops.
int main()
{
    LinkedList<int> *L = new LinkedList<int>();
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
    L->loopedLinkedListFromArray(arr,4,8);
    // L->linkedListFromArray(arr,8);

    string hasLoops = L->hasLoops() ? "Contains a loop" : "Does not contain a loop";
    cout << hasLoops << endl;


    return 0;
}