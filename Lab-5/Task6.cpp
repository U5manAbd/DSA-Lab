#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    int sum = 0;

    if (dim == 1) {
        int* intArr = (int*)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += intArr[i];
        }
    } else {
        for (int i = 0; i < sizes[0]; i++) {
            sum += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
        }
    }
    return sum;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6};

    int* jagged[] = {arr1, arr2, arr3};

    int sizes[] = {3, 3};

    cout << "Sum = " << recursiveArraySum(jagged, sizes, 2) << endl;
    return 0;
}