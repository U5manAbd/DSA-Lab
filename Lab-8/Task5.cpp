#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    bool isBSTUtil(Node* node, int min, int max) {
        if (node == nullptr)
            return true;

        if (node->data <= min || node->data >= max)
            return false;

        return isBSTUtil(node->left, min, node->data) &&
               isBSTUtil(node->right, node->data, max);
    }

    bool isBST() {
        return isBSTUtil(root, -999999, +999999);
    }
};

int main() {
    BST tree;

    tree.root = new Node(10);
    tree.root->left = new Node(5);
    tree.root->right = new Node(20);
    tree.root->right->left = new Node(9);
    tree.root->right->right = new Node(25);

    if (tree.isBST())
        cout << "The given tree IS a Binary Search Tree." << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree." << endl;

    return 0;
}
