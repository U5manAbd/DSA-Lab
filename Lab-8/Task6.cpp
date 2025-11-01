#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = nullptr;
    }
};

class InventoryBST {
private:
    Node* root;

    Node* insert(Node* node, int id, int qty) {
        if (node == nullptr) {
            cout << "Inserted product ID " << id << " with quantity " << qty << endl;
            return new Node(id, qty);
        }

        if (id < node->productID)
            node->left = insert(node->left, id, qty);
        else if (id > node->productID)
            node->right = insert(node->right, id, qty);
        else {
            node->quantity = qty;
            cout << "Updated product ID " << id << " with new quantity " << qty << endl;
        }

        return node;
    }

    Node* search(Node* node, int id) {
        if (node == nullptr || node->productID == id)
            return node;

        if (id < node->productID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    void findMaxQuantity(Node* node, int& maxQty, int& maxID) {
        if (node == nullptr)
            return;

        if (node->quantity > maxQty) {
            maxQty = node->quantity;
            maxID = node->productID;
        }

        findMaxQuantity(node->left, maxQty, maxID);
        findMaxQuantity(node->right, maxQty, maxID);
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << "Product ID: " << node->productID << ", Quantity: " << node->quantity << endl;
        inorder(node->right);
    }

public:
    InventoryBST() {
        root = nullptr;
    }

    void insertProduct(int id, int qty) {
        root = insert(root, id, qty);
    }

    void searchProduct(int id) {
        Node* result = search(root, id);
        if (result)
            cout << "Found Product ID " << id << " with quantity " << result->quantity << endl;
        else
            cout << "Product ID " << id << " not found." << endl;
    }

    void updateProduct(int id, int newQty) {
        Node* result = search(root, id);
        if (result) {
            result->quantity = newQty;
            cout << "Updated Product ID " << id << " to new quantity " << newQty << endl;
        } else {
            cout << "Product not found! Inserting as new product." << endl;
            insertProduct(id, newQty);
        }
    }

    void displayInventory() {
        cout << "\nCurrent Inventory (In-order):\n";
        inorder(root);
    }

    void productWithHighestQuantity() {
        int maxQty = -1;
        int maxID = -1;
        findMaxQuantity(root, maxQty, maxID);

        if (maxQty == -1)
            cout << "Inventory is empty!" << endl;
        else
            cout << "\nProduct with highest quantity -> ID: " << maxID << ", Quantity: " << maxQty << endl;
    }
};

int main() {
    InventoryBST inventory;

    inventory.insertProduct(101, 50);
    inventory.insertProduct(202, 80);
    inventory.insertProduct(303, 20);
    inventory.insertProduct(150, 100);
    inventory.insertProduct(90, 30);

    inventory.displayInventory();

    inventory.searchProduct(202);
    inventory.searchProduct(400);

    inventory.updateProduct(101, 75);
    inventory.updateProduct(404, 60);

    inventory.displayInventory();

    inventory.productWithHighestQuantity();

    return 0;
}
