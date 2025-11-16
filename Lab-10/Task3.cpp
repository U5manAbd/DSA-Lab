#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int kthLargest(vector<int> arr, int K) { 
    int n = arr.size();

    buildMaxHeap(arr);

    int result = -1;

    for (int i = n - 1; i >= n - K; i--) {
        result = arr[0];
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    return result;
}

int main() {
    int n, K;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter K: ";
    cin >> K;

    int result = kthLargest(arr, K);

    cout << "The " << K << "th largest element is: " << result << endl;

    return 0;
}
