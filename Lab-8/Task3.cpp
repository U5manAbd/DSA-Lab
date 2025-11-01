#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;

    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }

    void display() const {
        cout << "Name: " << name << ", Roll: " << roll << ", Score: " << score << endl;
    }
};

struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, Student s) {
        if (node == nullptr)
            return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        return node;
    }

    Node* search(Node* node, string name) {
        if (node == nullptr || node->data.name == name)
            return node;
        if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* deleteLowScore(Node* node) {
        if (node == nullptr) return nullptr;

        node->left = deleteLowScore(node->left);
        node->right = deleteLowScore(node->right);

        if (node->data.score < 10) {
            Node* temp;
            if (node->left == nullptr) {
                temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                temp = node->left;
                delete node;
                return temp;
            } else {
                Node* minRight = findMin(node->right);
                node->data = minRight->data;
                node->right = deleteNode(node->right, minRight->data.name);
            }
        }
        return node;
    }

    Node* deleteNode(Node* node, string name) {
        if (node == nullptr) return node;

        if (name < node->data.name)
            node->left = deleteNode(node->left, name);
        else if (name > node->data.name)
            node->right = deleteNode(node->right, name);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = deleteNode(node->right, minNode->data.name);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    void findMaxScore(Node* node, Student &maxStu) {
        if (node == nullptr) return;
        if (node->data.score > maxStu.score)
            maxStu = node->data;
        findMaxScore(node->left, maxStu);
        findMaxScore(node->right, maxStu);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            node->data.display();
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Student s) {
        root = insert(root, s);
    }

    void searchStudent(string name) {
        Node* result = search(root, name);
        if (result)
            cout << "Student found:\n", result->data.display();
        else
            cout << "Student not found.\n";
    }

    void deleteStudentsWithLowScore() {
        root = deleteLowScore(root);
    }

    void getMaxScoreStudent() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }
        Student maxStu = root->data;
        findMaxScore(root, maxStu);
        cout << "\nStudent with Maximum Score:\n";
        maxStu.display();
    }

    void displayAll() {
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else {
            cout << "\nAll Students (Inorder Traversal):\n";
            inorder(root);
        }
    }
};

int main() {
    srand(time(0));
    BST tree;

    Student arr[10] = {
        {"Ali", 101, 15}, {"Usman", 102, 8}, {"Jazlan", 103, 20},
        {"Bilal", 104, 5}, {"Maryum", 105, 25}, {"Absar", 106, 12},
        {"Hamza", 107, 18}, {"Sibtain", 108, 30}, {"Omer", 109, 9},
        {"Taha", 110, 14}
    };

    cout << "Inserting 7 random students into BST\n";
    bool used[10] = {false};
    int count = 0;

    while (count < 7) {
        int idx = rand() % 10;
        if (!used[idx]) {
            used[idx] = true;
            tree.insert(arr[idx]);
            count++;
        }
    }

    tree.displayAll();

    cout << "\nEnter name to search: ";
    string searchName;
    cin >> searchName;
    tree.searchStudent(searchName);

    cout << "\nDeleting all students with score < 10...\n";
    tree.deleteStudentsWithLowScore();

    tree.displayAll();

    tree.getMaxScoreStudent();

    return 0;
}
