#include <iostream>
#include <vector>
using namespace std;

void heapifyMax(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void convertToMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

int main() {
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    convertToMaxHeap(arr);

    cout << "Max Heap Array: ";
    for (int x : arr)
        cout << x << " ";
}
