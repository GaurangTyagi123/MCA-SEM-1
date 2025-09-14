#include "tree.h"
#include <queue>
#include <iostream>
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template <class T>
BNode<T> *BinaryTree<T>::getRoot()
{
    return this->root;
}

template <class T>
void BinaryTree<T>::InsertNode(T val)
{
    BNode<T> *newNode = new BNode<T>();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    queue<BNode<T> *> q;
    if (!this->root)
    {
        this->root = newNode;
    }
    else
    {
        q.push(this->root);
        while (!q.empty())
        {
            BNode<T> *temp = q.front();
            q.pop();
            if (!temp->left)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }
            if(!temp->right)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}

template <class T>
void BinaryTree<T>::inorder(BNode<T> *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

template <class T>
void BinaryTree<T>::preorder(BNode<T> *root)
{
    if (!root)
        return;
    cout << root->data << endl;
    inorder(root->left);
    inorder(root->right);
}

template <class T>
void BinaryTree<T>::postorder(BNode<T> *root)
{
    if (!root)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << endl;
}