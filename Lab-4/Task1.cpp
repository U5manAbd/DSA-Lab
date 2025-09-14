#include <iostream>
using namespace std;

int main() {
    int arr[10];

    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10 - 1; i++) {
        int min = i;
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "The 4 minimum elements are: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
}
