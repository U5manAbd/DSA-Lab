#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    bool search(Node* node, int value) {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        else if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorder() {
        inorder(root);
    }

    void searchOrInsert(int value) {
        if (search(value)) {
            cout << "\nValue " << value << " found in the tree.\n";
        } else {
            cout << "\nValue " << value << " not found, inserting it...\n";
            insert(value);
            cout << "New value inserted.\n";
        }

        cout << "\nUpdated Tree: ";
        inorder();
        cout << endl;
    }
};

int main() {
    BST tree;
    int values[] = {40, 20, 60, 10, 30, 50, 70};

    cout << "Initial Tree: ";
    for (int val : values)
        tree.insert(val);
    tree.inorder();

    int userValue;
    cout << "\n\nEnter a value to search in the tree: ";
    cin >> userValue;

    tree.searchOrInsert(userValue);

    return 0;
}
