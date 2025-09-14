#include <iostream>
using namespace std;

int main() {
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    int n = 9;

    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }

    int max = arr[n - 1];

    int mid = n / 2;
    for (int i = n - 1; i > mid; i--) {
        arr[i] = arr[i - 1];
    }
    arr[mid] = max;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
