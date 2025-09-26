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
BNode<T> *BinaryTree<T>::interchangeSubtrees(BNode<T> *root)
{
    BNode<T> *left, *right;
    if (root->left || root->right)
    {
        left = interchangeSubtrees(root->right);
        right = interchangeSubtrees(root->left);
        root->left = left;
        root->right = right;
    }
    else
    {
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

// . BINARY SEARCH TREES

template <class T>
BST<T>::BST()
{
    this->root = nullptr;
}

template <class T>
BNode<T> *BST<T>::getRoot()
{
    return this->root;
}

template <class T>
BNode<T> *BST<T>::findNode(T val)
{
    if (!this->root)
        return nullptr;
    else
    {
        BNode<T> *iter = this->root;
        while (iter)
        {
            if (iter->data == val)
                return iter;
            else if (val > iter->data)
                iter = iter->right;
            else
                iter = iter->left;
        }
        return nullptr;
    }
}

template <class T>
void BST<T>::insertNode(T val)
{
    BNode<T> *newNode = new BNode<T>();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (!root)
    {
        this->root = newNode;
    }
    else
    {
        BNode<T> *iter = this->root;
        while (iter)
        {
            if (val < iter->data && iter->left)
                iter = iter->left;
            else if (val >= iter->data && iter->right)
                iter = iter->right;
            else if (val < iter->data && !iter->left)
            {
                iter->left = newNode;
                break;
            }
            else
            {
                iter->right = newNode;
                break;
            }
        }
    }
}

template <class T>
BNode<T> *BST<T>::inorderPredecessor(BNode<T> *Node)
{
    if (!this->findNode(Node->data))
        return nullptr;
    else if (!Node->left)
    {
        return nullptr;
    }
    else
    {
        BNode<T> *left = Node->left;
        while (left->right)
        {
            left = left->right;
        }
        return left;
    }
}

template <class T>
void BST<T>::deleteLeaf(BNode<T> *leaf)
{
    BNode<T> *iter = this->root;
    BNode<T> *delNode = leaf;
    while (iter->left != delNode && iter->right != delNode)
    {
        if (delNode->data < iter->data)
        {
            iter = iter->left;
        }
        else
        {
            iter = iter->right;
        }
    }
    if (iter->left == delNode)
        iter->left = nullptr;
    else
    {
        iter->right = nullptr;
    }
    delete delNode;
}

template <class T>
void BST<T>::deleteOneChild(BNode<T> *Node)
{
    BNode<T> *iter = this->root;
    while (iter->left != Node && iter->right != Node)
    {
        if (Node->data < iter->data)
        {
            iter = iter->left;
        }
        else
        {
            iter = iter->right;
        }
    }
    BNode<T> *replacement = Node->left ? Node->left : Node->right;
    if (iter->left == Node)
    {
        iter->left = replacement;
    }
    else
    {
        iter->right = replacement;
    }
}

template <class T>
void BST<T>::deleteTwoChild(BNode<T> *Node)
{
    if (Node == this->root)
    {
        BNode<T> *inorderP = this->inorderPredecessor(Node);
        T temp = inorderP->data;
        deleteNode(inorderP->data);
        Node->data = temp;
    }
    else
    {
        BNode<T> *iter = this->root;
        while (iter->left != Node && iter->right != Node)
        {
            if (Node->data < iter->data)
            {
                iter = iter->left;
            }
            else
            {
                iter = iter->right;
            }
        }
        BNode<T> *inorderP = this->inorderPredecessor(Node);
        T temp = inorderP->data;
        deleteNode(inorderP->data);
        if (iter->left == Node)
        {
            iter->left->data = temp;
        }
        else
        {
            iter->right->data = temp;
        }
    }
}

template <class T>
void BST<T>::deleteNode(T val)
{
    if (!this->root)
    {
        cout << "UNDERFLOW" << endl;
    }
    else
    {
        BNode<T> *delNode = this->findNode(val);
        if (delNode)
        {
            if (!delNode->left && !delNode->right)
            {
                this->deleteLeaf(delNode);
            }
            else if ((delNode->left && !delNode->right) || !delNode->left && delNode->right)
            {
                this->deleteOneChild(delNode);
            }
            else
            {
                this->deleteTwoChild(delNode);
            }
        }
    }
}

template <class T>
void BST<T>::inorder(BNode<T> *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}
template <class T>
void BST<T>::preorder(BNode<T> *root)
{
    if (root)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
template <class T>
void BST<T>::postorder(BNode<T> *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }
}

template <class T>
size_t BST<T>::height(BNode<T> *root)
{
    if (root)
    {
        return 1 + max(height(root->left), height(root->right));
    }
    else
        return -1;
}

template <class T>
size_t BST<T>::leaf(BNode<T> *root)
{
    size_t left;
    size_t right;
    if (root->left && root->right)
    {
        left = this->leaf(root->left);
        right = this->leaf(root->right);
        return left + right;
    }
    else
    {
        return 1;
    }
}