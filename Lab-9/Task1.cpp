/*
Q:
A: AVL trees maintain balance by keeping the height difference between left and right subtrees ≤ 1.
This ensures faster operations — search, insert, and delete — in O(log n) time.
*/

// Conversion Function with explanation
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* n) {
    if (!n) return 0;
    return 1 + max(height(n->left), height(n->right));
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x; // new root after rotation
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y; // new root after rotation
}

Node* balanceBST(Node* root) {
    int balance = getBalance(root);

    // LL or LR case
    if (balance > 1) {
        if (getBalance(root->left) >= 0)
            return rightRotate(root);           // LL Rotation
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);           // LR Rotation
        }
    }
    // RR or RL case
    if (balance < -1) {
        if (getBalance(root->right) <= 0)
            return leftRotate(root);            // RR Rotation
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);            // RL Rotation
        }
    }
    return root; // already balanced
}
