// filepath: cpp-data-structures-template/cpp-data-structures-template/include/Heap.h
#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class MaxHeap {
public:
    MaxHeap() {}

    void push(T value) {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        HeapifyDown(0);
    }

    T peek() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

private:
    vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void HeapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void HeapifyDown(int index) {
        int max_index = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[index]) max_index = left;
        if (right < heap.size() && heap[right] > heap[max_index]) max_index = right;

        if (index != max_index) {
            swap(heap[index], heap[max_index]);
            HeapifyDown(max_index);
        }
    }
};

template <typename T>
class MinHeap {
public:
    MinHeap() {}

    void push(T value) {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        HeapifyDown(0);
    }

    T peek() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

private:
    vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void HeapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void HeapifyDown(int index) {
        int min_index = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] < heap[min_index]) min_index = left;
        if (right < heap.size() && heap[right] < heap[min_index]) min_index = right;

        if (index != min_index) {
            swap(heap[index], heap[min_index]);
            HeapifyDown(min_index);
        }
    }
};

#endif // HEAP_H