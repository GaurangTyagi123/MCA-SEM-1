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
    do
    {
        cin >> input;
        if (input != -1)
            bst.insertNode(input);
    } while (input != -1);
    
    std::cout << "Height of the tree : " << bst.height(bst.getRoot()) << std::endl;
    std::cout << "Num of leaves in the tree : " << bst.leaf(bst.getRoot()) << std::endl;
    
    std::cout << "inorder: "<<std::endl;
    bst.inorder(bst.getRoot());
    cout << endl;
    
    std::cout << "preorder: "<<std::endl;
    bst.preorder(bst.getRoot());
    cout << endl;

    std::cout << "postorder: "<<std::endl;
    bst.postorder(bst.getRoot());
    cout << endl;
    int delNum;

    
    std::cout << "Enter node value to delete: ";
    std::cin >> delNum;
    
    bst.deleteNode(delNum);
    
    std::cout << "Height of the tree : " << bst.height(bst.getRoot()) << std::endl;
    std::cout << "Num of leaves in the tree : " << bst.leaf(bst.getRoot()) << std::endl;
    bst.inorder(bst.getRoot());

    return 0;
}

/*
        50
      /    \
    30      70
   /  \    /  \
 20   40  60   80

*/