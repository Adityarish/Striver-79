// Problem Statement: Implement min heap

// Problem Link: https://www.codingninjas.com/studio/problems/min-heap-implementation_5480527?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int size;
    int capacity;

    void heapify(int i) {
        int smallest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (i != smallest) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int size) {
        this->capacity = size;
        this->heap.resize(size);
        this->size = 0;
    }

    int extractMinElement() {
        if (size == 0) {
            return -1; // Heap is empty
        }

        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return minValue;
    }

    void deleteElement(int ind) {
        if (ind < 0 || ind >= size) {
            return; // Index out of bounds
        }

        heap[ind] = heap[size - 1];
        size--;
        heapify(ind);
    }

    void insert(int val) {
        if (size == capacity) {
            return; // Heap is full
        }

        heap[size] = val;
        size++;
        int currentIndex = size - 1;

        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (heap[parentIndex] > heap[currentIndex]) {
                swap(heap[parentIndex], heap[currentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }
};
