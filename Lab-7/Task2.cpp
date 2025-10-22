#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int num : arr)
        if (num > mx)
            mx = num;
    return mx;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortAsc(vector<int>& arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

void reverseArray(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void radixSortDesc(vector<int>& arr) {
    radixSortAsc(arr);
    reverseArray(arr);
}

void display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array:\n";
    display(arr);

    vector<int> asc = arr;
    radixSortAsc(asc);
    cout << "\nAscending Order:\n";
    display(asc);

    vector<int> desc = arr;
    radixSortDesc(desc);
    cout << "\nDescending Order:\n";
    display(desc);

    return 0;
}