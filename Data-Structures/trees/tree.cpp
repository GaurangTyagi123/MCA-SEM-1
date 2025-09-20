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
int BinaryTree<T>::height(BNode<T> *root)
{
    if (root->left || root->right)
    {
        return 1 + max(height(root->left), height(root->right));
    }
    else
        return 0;
}
template <class T>
T BinaryTree<T>::sumOfNodes(BNode<T> *root)
{
    if (root)
    {
        return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
    }
    else
        return 0;
}
template <class T>
T BinaryTree<T>::maxNode(BNode<T> *root)
{
    T r, left, right, max;
    if (root)
    {
        r = root->data;
        left = maxNode(root->left);
        right = maxNode(root->right);
        if (left > right)
            max = left;
        else
            max = right;
        if (max < r)
            return r;
        else
            return max;
    }
    else
    {
        return -1;
    }
}
template <class T>
size_t BinaryTree<T>::NumOfLeaves(BNode<T> *root)
{
    size_t leaf = 0;
    size_t left, right;
    if (root->left || root->right)
    {
        left = NumOfLeaves(root->left);
        right = NumOfLeaves(root->right);
        return left + right;
    }
    else
    {
        return leaf + 1;
    }
}
template <class T>
BNode<T>* BinaryTree<T>::interchangeSubtrees(BNode<T> *root)
{
    BNode<T> *left, *right;
    if (root->left || root->right)
    {
        left = interchangeSubtrees(root->right);
        right = interchangeSubtrees(root->left);
        root->left = left;
        root->right = right;
    }
    else{
        return root;
    }
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
            if (!temp->right)
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