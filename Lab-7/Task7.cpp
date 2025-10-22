#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons;

int partitionFirst(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (true) {
        while (i <= high && arr[i] <= pivot) { comparisons++; i++; }
        while (arr[j] > pivot) { comparisons++; j--; }
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int partitionMiddle(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}

int partitionRandom(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIndex]);
    return partitionFirst(arr, low, high);
}

int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);
    swap(arr[mid], arr[low]);
    return partitionFirst(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high, int pivotType) {
    if (low < high) {
        int p;
        if (pivotType == 1) p = partitionFirst(arr, low, high);
        else if (pivotType == 2) p = partitionRandom(arr, low, high);
        else if (pivotType == 3) p = partitionMiddle(arr, low, high);
        else p = medianOfThree(arr, low, high);
        quickSort(arr, low, p - 1, pivotType);
        quickSort(arr, p + 1, high, pivotType);
    }
}

void runTest(vector<int> arr, int type, string name) {
    comparisons = 0;
    quickSort(arr, 0, arr.size() - 1, type);
    cout << name << " pivot comparisons: " << comparisons << endl;
}

int main() {
    srand(time(0));
    vector<int> sorted = {1,2,3,4,5,6,7,8,9,10};
    vector<int> reverse = {10,9,8,7,6,5,4,3,2,1};
    vector<int> random = {4,9,1,7,3,10,2,8,5,6};

    cout << "Sorted Array" << endl;
    runTest(sorted, 1, "First");
    runTest(sorted, 2, "Random");
    runTest(sorted, 3, "Middle");
    runTest(sorted, 4, "Median");

    cout << "\nReverse Sorted Array" << endl;
    runTest(reverse, 1, "First");
    runTest(reverse, 2, "Random");
    runTest(reverse, 3, "Middle");
    runTest(reverse, 4, "Median");

    cout << "\nRandom Array" << endl;
    runTest(random, 1, "First");
    runTest(random, 2, "Random");
    runTest(random, 3, "Middle");
    runTest(random, 4, "Median");
}
