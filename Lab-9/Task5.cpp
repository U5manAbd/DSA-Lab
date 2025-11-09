#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void inorder(Node* root, vector<int>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root->key);
    inorder(root->right, nodes);
}

void findKth(Node* root, int k) {
    vector<int> nodes;
    inorder(root, nodes);

    int n = nodes.size();

    if (k <= 0 || k > n) {
        cout << "Invalid k\n";
        return;
    }

    int kthSmallest = nodes[k - 1];
    int kthLargest = nodes[n - k];

    cout << "Kth Smallest (" << k << "): " << kthSmallest << endl;
    cout << "Kth Largest (" << k << "): " << kthLargest << endl;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    cout << "Left subtree height: " << leftHeight << endl;
    cout << "Right subtree height: " << rightHeight << endl;

    int k;
    cout << "\nEnter value of k: ";
    cin >> k;

    findKth(root, k);

    return 0;
}
