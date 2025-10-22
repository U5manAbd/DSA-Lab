#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;

    Product() {}
    Product(string n, double p, string d, bool a) {
        name = n;
        price = p;
        description = d;
        available = a;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Description: " << description << endl;
        cout << "Availability: " << (available ? "In Stock" : "Out of Stock") << endl;
    }
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 3;
    Product products[SIZE];

    cout << "Enter details of 3 products:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nProduct " << i + 1 << " Name: ";
        cin >> ws;
        getline(cin, products[i].name);

        cout << "Price: $";
        cin >> products[i].price;

        cout << "Description: ";
        cin >> ws;
        getline(cin, products[i].description);

        char avail;
        cout << "Is it available (y/n)? ";
        cin >> avail;
        products[i].available = (avail == 'y' || avail == 'Y');
    }

    quickSort(products, 0, SIZE - 1);

    cout << "\nProducts Sorted by Price:\n";
    for (int i = 0; i < SIZE; i++) {
        products[i].display();
    }

    return 0;
}
