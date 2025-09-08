#ifndef linked_list_h

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

#endif