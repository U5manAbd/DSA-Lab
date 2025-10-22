#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    double time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void displayTop5(Runner arr[], int n) {
    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5 && i < n; i++) {
        cout << i + 1 << ". " << arr[i].name 
             << " - " << arr[i].time << " seconds\n";
    }
}

int main() {
    const int SIZE = 10;
    Runner runners[SIZE];

    cout << "Enter details of 10 participants:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nParticipant " << i + 1 << " Name: ";
        cin >> runners[i].name;
        cout << "Finish Time (in seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, SIZE - 1);

    displayTop5(runners, SIZE);

    return 0;
}
