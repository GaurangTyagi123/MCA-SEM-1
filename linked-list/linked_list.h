#ifndef linked_list_h
#include <cstddef>

template <class T>
struct Node
{
    T data;
    Node *next;
};
template <class T>
class LinkedList
{
private:
    Node<T> *head = new Node<T>();

public:
    LinkedList();
    static T intersectionNode(Node<T> *head1, Node<T> *head2);
    static LinkedList<T> *sumTwoList(Node<T> *head1, Node<T> *head2);
    static bool isPalindrome(Node<T> *head);
    static void reverse(Node<T> *&head);
    static Node<T> *middle(Node<T> *head);
    static Node<T> *mergeAlternate(Node<T> *head1, Node<T> *head2);

    bool isEmpty() const;
    void linkedListFromArray(T[], int size);
    void loopedLinkedListFromArray(T[], T val, int size);
    T nFromEnd(size_t pos) const;
    void mergeAtNode(Node<T> *head, T val);
    void deleteAllOccurrences(T val);
    LinkedList<T> *splitList();
    bool hasLoops() const;
    T loopNodeVal() const;

    Node<T> *getHead();

    void insertAtFront(T data);
    void insertAtEnd(T data);
    void insertAfter(T val, T data);

    void deleteAtFront();
    void deleteAtEnd();
    void deleteNode(T data);
    void displayList() const;
};

template <class T>
struct DNode
{
    T data;
    DNode<T> *next;
    DNode<T> *prev;
};

template <class T>
class DLinkedList
{
private:
    DNode<T> *head;
    DNode<T> *tail;

public:
    DLinkedList();
    void insertFront(T);
    void insertEnd(T);
    void insertAfter(size_t, T);

    void deleteFront();
    void deleteEnd();
    void deleteAfter(size_t);

    void displayList();
    void displayListRev();
};

template <class T>
struct CNode
{
    T data;
    CNode *next;
};

template <class T>
class CLinkedList
{
private:
    CNode<T> *head;

public:
    CLinkedList();
    void insertFront(T);
    void insertEnd(T);
    void insertAfter(size_t, T);

    void deleteFront();
    void deleteEnd();
    void deleteAfter(size_t);

    void displayList();
};

#endif