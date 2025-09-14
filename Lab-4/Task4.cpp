#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool checkDuplicate(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {3, 7, 2, 9, 5, 2}; 
    int n = 6;

    bubbleSort(arr, n);

    if (checkDuplicate(arr, n) == true) {
        cout << "Duplicate found!" << endl;
    }
    else {
        cout << "No duplicates!" << endl;
    }
}
