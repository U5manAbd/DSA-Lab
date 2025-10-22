#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    int arr1[10] = {42, 12, 90, 34, 23, 78, 56, 11, 67, 89};
    int arr2[10] = {14, 99, 28, 10, 45, 72, 31, 60, 5, 80};

    vector<int> combined;
    for (int i = 0; i < 10; i++) combined.push_back(arr1[i]);
    for (int i = 0; i < 10; i++) combined.push_back(arr2[i]);

    radixSort(combined);

    cout << "Sorted (Radix Sort): ";
    for (int val : combined)
        cout << val << " ";
    cout << endl;
}
