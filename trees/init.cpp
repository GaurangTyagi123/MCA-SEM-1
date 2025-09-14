#include "tree.cpp"
#include <iostream>
using namespace std;

int main()
{
    BinaryTree<int> t;
    t.InsertNode(1);
    t.InsertNode(2);
    t.InsertNode(3);

    t.inorder(t.getRoot());
    cout << endl;
    t.preorder(t.getRoot());
    cout << endl;
    t.postorder(t.getRoot());

    // t.InsertNode(t.getRoot(), 6);
    return 0;
}