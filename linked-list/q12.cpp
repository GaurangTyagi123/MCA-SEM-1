#include <iostream>
#include "linked_list.cpp"
using namespace std;

// Objective : odd_even linked list
int main()
{
    LinkedList<int> LL;
    int arr[] = {1, 4, 3, 5, 2, 6, 9};
    LL.linkedListFromArray(arr, 7);

    LL.odd_even();
    return 0;
}