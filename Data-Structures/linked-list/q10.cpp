#include <iostream>
#include "linked_list.cpp"
#include <stack>
using namespace std;

// Objective : To check whether the given linked list is a palindrome or not
void rev(Node<int> *&head)
{
    Node<int> *curr = head;
    Node<int> *prev = nullptr;
    while (curr != nullptr)
    {
        Node<int> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
Node<int> *middleNode(Node<int> *head)
{
    Node<int> *fastPtr = head;
    Node<int> *slowPtr = head;
    while (fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

int main()
{

    int arr2[] = {1, 2, 2, 1};

    LinkedList<int> *L = new LinkedList<int>();
    L->linkedListFromArray(arr2, 4);

    cout << LinkedList<int>::isPalindrome(L->getHead());

    return 0;
}