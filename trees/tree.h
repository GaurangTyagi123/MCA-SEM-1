#ifndef TREE_H
#define TREE_H
#include <cstddef>

template <class T>
struct BNode
{
    T data;
    BNode<T> *left;
    BNode<T> *right;
};

template <class T>
class BinaryTree
{
private:
    BNode<T> *root;

public:
    BinaryTree();
    BNode<T> *getRoot();
    int height(BNode<T> *);
    T sumOfNodes(BNode<T> *);
    T maxNode(BNode<T> *);
    size_t NumOfLeaves(BNode<T> *);
    BNode<T> * interchangeSubtrees(BNode<T> *);

    void InsertNode(T);

    void inorder(BNode<T> *);
    void preorder(BNode<T> *);
    void postorder(BNode<T> *);
};

#endif