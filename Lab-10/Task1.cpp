#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void update_key(int i, int new_val) {
        if (i >= heap.size()) {
            cout << "Invalid index\n";
            return;
        }

        int old_val = heap[i];
        heap[i] = new_val;

        if (new_val > old_val)
            heapifyUp(i);
        else
            heapifyDown(i);

        delete_at_index(i);
    }

    void delete_at_index(int i) {
        int n = heap.size() - 1;

        heap[i] = heap[n];
        heap.pop_back();

        if (i < heap.size()) {
            heapifyUp(i);
            heapifyDown(i);
        }
    }

    void print() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Original Heap: ";
    h.print();

    h.update_key(1, 10);

    cout << "Heap after update+delete: ";
    h.print();
}
