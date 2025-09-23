#include "tree.cpp"
#include <iostream>
using namespace std;

int main()
{
    // ? BINARY TREE
    // BinaryTree<int> t;
    // t.InsertNode(1);
    // t.InsertNode(2);
    // t.InsertNode(3);
    // t.InsertNode(4);
    // t.InsertNode(5);
    // t.InsertNode(6);
    // t.InsertNode(7);
    // t.InsertNode(8);
    // t.InsertNode(9);

    // t.inorder(t.getRoot());
    // cout << endl;
    // t.preorder(t.getRoot());
    // cout << endl;
    // t.postorder(t.getRoot());

    // cout << t.height(t.getRoot()) << endl;
    // cout << t.sumOfNodes(t.getRoot()) << endl;
    // cout << t.maxNode(t.getRoot()) << endl;
    // cout << t.NumOfLeaves(t.getRoot()) << endl;
    // cout << endl;

    // t.interchangeSubtrees(t.getRoot());
    // t.inorder(t.getRoot());

    // t.InsertNode(t.getRoot(), 6);

    // ? BINARY SEARCH TREE

    BST<int> bst;

    int input;
    do{
        cin >> input;
        if(input != -1)
        bst.insertNode(input);
    } while (input != -1);

    // bst.deleteNode(20);
    bst.deleteNode(85);
    bst.inorder(bst.getRoot());
    return 0;
}