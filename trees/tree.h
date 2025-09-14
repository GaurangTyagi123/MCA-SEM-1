#ifndef TREE_H
#define TREE_H

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
    void InsertNode(T);

    void inorder(BNode<T> *);
    void preorder(BNode<T> *);
    void postorder(BNode<T> *);
};

#endif