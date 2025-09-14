#include <iostream>
#include "linked_list.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
}
template <class T>
bool LinkedList<T>::isEmpty() const
{
    return this->head == NULL;
}
template <class T>
void LinkedList<T>::linkedListFromArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        this->insertAtEnd(arr[i]);
    }
}
template <class T>
void LinkedList<T>::loopedLinkedListFromArray(T arr[], T val, int size)
{
    for (int i = 0; i < size; i++)
    {
        this->insertAtEnd(arr[i]);
    }
    Node<T> *iter = this->head;
    Node<T> *valPtr = this->head;
    while (iter->next != NULL)
    {
        if (iter->data == val)
        {
            valPtr = iter;
        }
        iter = iter->next;
    }
    iter->next = valPtr;
}
template <class T>
Node<T> *LinkedList<T>::middle(Node<T> *head)
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
template <class T>
T LinkedList<T>::nFromEnd(size_t pos) const
{
    Node<T> *ptr1 = this->head;
    Node<T> *ptr2 = this->head;
    size_t start = pos;
    while (ptr1 != NULL)
    {
        if (start > 0)
        {
            ptr1 = ptr1->next;
            --start;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return ptr2->data;
}

template <class T>
void LinkedList<T>::reverse(Node<T> *&head)
{
    // ? BETTER APPROACH
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
    // . MY APPROACH
    // if (!isEmpty() && this->head->next != NULL && this->head->next->next != NULL)
    // {
    //     Node<T> *ptr1 = this->head;
    //     Node<T> *ptr2 = this->head->next;
    //     Node<T> *ptr3 = this->head->next->next;

    //     this->head->next = NULL;
    //     while (true)
    //     {
    //         ptr2->next = ptr1;

    //         if (ptr3 == NULL)
    //         {
    //             this->head = ptr2;
    //             break;
    //         }
    //         ptr1 = ptr3->next;
    //         ptr3->next = ptr2;

    //         if (ptr1 == NULL)
    //         {
    //             this->head = ptr3;
    //             break;
    //         }
    //         ptr2 = ptr1->next;
    //         ptr1->next = ptr3;

    //         if (ptr2 == NULL)
    //         {
    //             this->head = ptr1;
    //             break;
    //         }
    //         ptr3 = ptr2->next;
    //     }
    // }
    // else if (this->head->next != NULL)
    // {
    //     Node<T> *ptr1 = this->head;
    //     Node<T> *ptr2 = this->head->next;
    //     ptr2->next = ptr1;
    //     this->head->next = NULL;
    //     this->head = ptr2;
    // }
}
template <class T>
void LinkedList<T>::mergeAtNode(Node<T> *head, T val)
{
    Node<T> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node<T> *iter = this->head;
    while (iter->data != val)
    {
        iter = iter->next;
    }
    temp->next = iter;
}
template <class T>
T LinkedList<T>::intersectionNode(Node<T> *head1, Node<T> *head2)
{
    size_t l1_length = 0;
    size_t l2_length = 0;

    Node<T> *iter1 = head1;
    Node<T> *iter2 = head2;

    while (iter1 != NULL)
    {
        l1_length++;
        iter1 = iter1->next;
    }
    while (iter2 != NULL)
    {
        l2_length++;
        iter2 = iter2->next;
    }
    size_t diff = l1_length - l2_length;
    Node<T> *common_pointer;
    if (l1_length > l2_length)
    {
        common_pointer = head1;
        Node<T> *finalIter = head2;
        while (diff > 0)
        {
            common_pointer = common_pointer->next;
            --diff;
        }
        while (finalIter != common_pointer)
        {
            finalIter = finalIter->next;
            common_pointer = common_pointer->next;
        }
        delete finalIter;
    }
    else
    {
        common_pointer = head2;
        Node<T> *finalIter = head1;
        while (diff > 0)
        {
            common_pointer = common_pointer->next;
            --diff;
        }
        while (finalIter != common_pointer)
        {
            finalIter = finalIter->next;
            common_pointer = common_pointer->next;
        }
        delete finalIter;
    }
    delete iter1, iter2;
    return common_pointer->data;
}
template <class T>
void LinkedList<T>::deleteAllOccurrences(T val)
{
    Node<T> *temp = this->head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            this->deleteNode(val);
        }
        temp = temp->next;
    }
}
template <class T>
LinkedList<T> *LinkedList<T>::splitList()
{
    Node<T> *temp = this->head;
    LinkedList<T> *oddList = new LinkedList<T>();
    size_t iter = 1;
    while (temp != NULL)
    {
        if (iter % 2 != 0)
        {
            oddList->insertAtEnd(temp->data);
            Node<T> *delNode = temp;
            this->deleteNode(temp->data);
            temp = delNode->next;
            delete delNode;
        }
        else
        {
            temp = temp->next;
        }
        iter++;
    }
    return oddList;
}
template <class T>
LinkedList<T> *LinkedList<T>::sumTwoList(Node<T> *head1, Node<T> *head2)
{
    Node<T> *iter1 = head1;
    Node<T> *iter2 = head2;
    LinkedList<T> *output = new LinkedList<T>;
    long long sum = 0;
    const size_t BASE = 10;
    size_t multiplier = 1;

    while (iter1 != NULL || iter2 != NULL)
    {
        if (iter1 == NULL)
        {
            sum += iter2->data * multiplier;
            iter2 = iter2->next;
        }
        else if (iter2 == NULL)
        {
            sum = sum + (iter1->data * multiplier);
            iter1 = iter1->next;
        }
        else
        {
            sum += iter1->data * multiplier + iter2->data * multiplier;
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        multiplier *= BASE;
    }
    while (sum > 0)
    {
        size_t digit = sum % BASE;
        sum = sum / BASE;
        output->insertAtEnd(digit);
    }
    return output;
}
template <class T>
bool LinkedList<T>::hasLoops() const
{
    Node<T> *fastPtr = this->head;
    Node<T> *slowPtr = this->head;

    do
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    } while (fastPtr != slowPtr && fastPtr != NULL && slowPtr != NULL && slowPtr->next != NULL && fastPtr->next != NULL);
    if (fastPtr == slowPtr)
        return true;
    else
        return false;
}
template <class T>
T LinkedList<T>::loopNodeVal() const
{
    if (this->hasLoops())
    {
        Node<T> *fastPtr = this->head;
        Node<T> *slowPtr = this->head;
        do
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        } while (fastPtr != slowPtr && fastPtr != NULL && slowPtr != NULL && slowPtr->next != NULL && fastPtr->next != NULL);
        Node<T> *valPtr = this->head;
        while (valPtr != slowPtr)
        {
            valPtr = valPtr->next;
            slowPtr = slowPtr->next;
        }
        return valPtr->data;
    }
    else
        return -1;
}
template <class T>
bool LinkedList<T>::isPalindrome(Node<T> *head)
{
    Node<int> *second = middle(head);
    reverse(second);

    Node<int> *first = head;
    while (second != nullptr)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}
template <class T>
Node<T> *LinkedList<T>::mergeAlternate(Node<T> *head1, Node<T> *head2)
{
    Node<T> *iter = head1;
    Node<T> *curr = head2;
    while (iter->next != nullptr && curr->next != nullptr)
    {
        Node<T> *next = curr->next;
        curr->next = iter->next;
        iter->next = curr;
        iter = curr->next;
        curr = next;
    }
    if (!iter->next && curr)
    {
        iter->next = curr;
    }
    else if (!curr->next && iter)
    {
        curr->next = iter;
    }
    else
    {
        curr->next = nullptr;
    }

    return head1;
}
template <class T>
void LinkedList<T>::odd_even()
{
    Node<T> *oddHead = nullptr;
    Node<T> *evenHead = nullptr;
    Node<T> *odd = nullptr;
    Node<T> *even = nullptr;
    Node<T> *iter = this->head;

    while (iter)
    {
        bool isEven = !(iter->data % 2);
        if (isEven && !evenHead)
        {
            evenHead = iter;
            even = iter;
        }
        else if (!isEven && !oddHead)
        {
            oddHead = iter;
            odd = iter;
        }
        else if (isEven)
        {
            even->next = iter;
            even = iter;
        }
        else if (!isEven)
        {
            odd->next = iter;
            odd = iter;
        }
        iter = iter->next;
    }
    this->head = oddHead;
    odd->next = evenHead;
    even->next = nullptr;

    this->displayList();
}

template <class T>
Node<T> *LinkedList<T>::getHead()
{
    return this->head;
}
template <class T>
void LinkedList<T>::insertAtFront(T data)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = this->head;
    this->head = newNode;
}
template <class T>
void LinkedList<T>::insertAtEnd(T data)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    if (this->isEmpty())
    {
        newNode->next = NULL;
        this->head = newNode;
    }
    else
    {

        Node<T> *temp = this->head;
        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
template <class T>
void LinkedList<T>::insertAfter(T val, T data)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    Node<T> *temp = this->head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
template <class T>
void LinkedList<T>::deleteAtFront()
{
    if (!this->isEmpty())
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;

        delete temp;
    }
    else
    {
        throw "Underflow";
    }
}
template <class T>
void LinkedList<T>::deleteAtEnd()
{
    if (!this->isEmpty())
    {
        Node<T> *temp = head;
        while (temp->next != NULL && temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node<T> *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        throw "Underflow";
    }
}
template <class T>
void LinkedList<T>::deleteNode(T data)
{
    if (!this->isEmpty())
    {
        if (this->head->data == data)
        {
            Node<T> *delNode = this->head;
            this->head = this->head->next;
            delete delNode;
        }
        else
        {
            Node<T> *temp = this->head;
            while (temp->next != NULL && temp->next->data != data)
            {
                temp = temp->next;
            }
            Node<T> *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
    else
    {
        throw "Underflow";
    }
}
template <class T>
void LinkedList<T>::displayList() const
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
// .Doubly linked list

template <class T>
DLinkedList<T>::DLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
void DLinkedList<T>::insertFront(T val)
{
    DNode<T> *newNode = new DNode<T>();
    newNode->data = val;
    if (!this->head)
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->head = newNode;
        this->tail = newNode;
    }
    else if (this->head == this->tail)
    {
        newNode->next = this->tail;
        newNode->prev = nullptr;
        this->head->prev = newNode;
        this->tail = this->head;
        this->head = newNode;
    }
    else
    {
        newNode->next = this->head;
        newNode->prev = nullptr;
        this->head->prev = newNode;
        this->head = newNode;
    }
}

template <class T>
void DLinkedList<T>::insertEnd(T val)
{
    DNode<T> *newNode = new DNode<T>();
    newNode->data = val;
    if (!this->tail)
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->head = newNode;
        this->tail = newNode;
    }
    else if (this->head == this->tail)
    {
        newNode->next = nullptr;
        newNode->prev = this->head;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = nullptr;
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

template <class T>
void DLinkedList<T>::insertAfter(size_t index, T val)
{
    DNode<T> *iter = this->head;
    while (index && iter)
    {
        iter = iter->next;
        --index;
    }
    DNode<T> *newNode = new DNode<T>();
    newNode->data = val;
    newNode->next = iter->next;
    newNode->prev = iter;
    iter->next->prev = newNode;
    iter->next = newNode;
}

template <class T>
void DLinkedList<T>::deleteFront()
{
    DNode<T> *delNode = this->head;
    if (!this->head)
    {
        return;
    }
    else if (this->head == this->tail)
    {
        this->head = nullptr;
        this->tail = nullptr;
        delete delNode;
    }
    else
    {
        this->head = delNode->next;
        this->head->prev = nullptr;
        delete delNode;
    }
}
template <class T>
void DLinkedList<T>::deleteEnd()
{
    DNode<T> *delNode = this->tail;
    if (!this->tail)
    {
        return;
    }
    else if (this->head == this->tail)
    {
        this->head = nullptr;
        this->tail = nullptr;
        delete delNode;
    }
    else
    {
        this->tail = delNode->prev;
        this->tail->next = nullptr;
        delete delNode;
    }
}

template <class T>
void DLinkedList<T>::deleteAfter(size_t index)
{
    DNode<T> *iter = this->head;
    while (iter && index)
    {
        iter = iter->next;
        --index;
    }
    if (iter->next == this->tail)
    {
        this->deleteEnd();
    }
    else
    {
        DNode<T> *delNode = iter->next;
        iter->next = delNode->next;
        delNode->next->prev = iter;
        delete delNode;
    }
}

template <class T>
void DLinkedList<T>::displayList()
{
    DNode<T> *iter = this->head;
    while (iter)
    {
        cout << iter->data << " -> ";
        iter = iter->next;
    }
    cout << endl;
}

template <class T>
void DLinkedList<T>::displayListRev()
{
    DNode<T> *iter = this->tail;
    while (iter)
    {
        cout << iter->data << " -> ";
        iter = iter->prev;
    }
    cout << endl;
}
// . Circular linked list

template <class T>
CLinkedList<T>::CLinkedList()
{
    this->head = nullptr;
}

template <class T>
void CLinkedList<T>::insertFront(T val)
{
    CNode<T> *newNode = new CNode<T>();
    newNode->data = val;
    if (!this->head)
    {
        newNode->next = newNode;
        this->head = newNode;
    }
    else if (this->head->next == this->head)
    {
        newNode->next = this->head;
        this->head->next = newNode;
        this->head = newNode;
    }
    else
    {
        newNode->next = this->head;
        CNode<T> *iter = new CNode<T>();
        iter = this->head;
        while (iter->next != this->head)
        {
            iter = iter->next;
        }
        iter->next = newNode;
        this->head = newNode;
    }
}

template <class T>
void CLinkedList<T>::insertEnd(T val)
{
    CNode<T> *newNode = new CNode<T>();
    newNode->data = val;
    if (!this->head)
    {
        newNode->next = newNode;
        this->head = newNode;
    }
    else if (this->head == this->head->next)
    {
        newNode->next = this->head;
        this->head->next = newNode;
    }
    else
    {
        CNode<T> *iter = this->head;
        while (iter->next != this->head)
        {
            iter = iter->next;
        }
        newNode->next = this->head;
        iter->next = newNode;
    }
}

template <class T>
void CLinkedList<T>::insertAfter(size_t index, T val)
{
    CNode<T> *newNode = new CNode<T>();
    newNode->data = val;

    CNode<T> *iter = this->head;
    while (iter && index)
    {
        iter = iter->next;
        --index;
    }
    newNode->next = iter->next;
    iter->next = newNode;
}

template <class T>
void CLinkedList<T>::deleteFront()
{
    CNode<T> *delNode = this->head;
    CNode<T> *iter = this->head;

    while (iter->next != this->head)
    {
        iter = iter->next;
    }

    iter->next = delNode->next;
    this->head = iter->next;
    delete delNode;
}

template <class T>
void CLinkedList<T>::deleteEnd()
{
    CNode<T> *iter = this->head;
    while (iter->next->next != this->head)
    {
        iter = iter->next;
    }
    CNode<T> *delNode = iter->next;
    iter->next = this->head;
    delete delNode;
}

template <class T>
void CLinkedList<T>::deleteAfter(size_t index)
{
    CNode<T> *iter = this->head;
    while (iter && index)
    {
        iter = iter->next;
        --index;
    }
    CNode<T> *delNode = iter->next;
    iter->next = delNode->next;
    delete delNode;
}

template <class T>
void CLinkedList<T>::displayList()
{
    CNode<T> *iter = this->head;
    do
    {
        cout << iter->data << " - ";
        iter = iter->next;
    } while (iter != this->head);
    cout << endl;
}