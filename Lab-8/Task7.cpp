#include <iostream>
#include <vector>
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
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void inorder(Node* node, vector<int>& arr) {
        if (node == nullptr)
            return;

        inorder(node->left, arr);
        arr.push_back(node->data);
        inorder(node->right, arr);
    }

public:
    BST() { root = nullptr; }

    void insert(int val) {
        root = insert(root, val);
    }

    double findMedian() {
        vector<int> values;
        inorder(root, values);

        int n = values.size();
        if (n == 0) {
            cout << "Tree is empty!" << endl;
            return -1;
        }

        if (n % 2 == 1) {
            return values[n / 2];
        } else {
            return (values[(n / 2) - 1] + values[n / 2]) / 2.0;
        }
    }

    void displayInorder() {
        vector<int> values;
        inorder(root, values);
        cout << "Inorder Traversal (Sorted): ";
        for (int val : values)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(9);
    bst.insert(25);

    bst.displayInorder();

    double median = bst.findMedian();
    cout << "Median of BST: " << median << endl;

    return 0;
}
