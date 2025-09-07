// filepath: cpp-data-structures-template/cpp-data-structures-template/include/Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "ITI-LinkedList.h"

template <typename T>
class Queue {
    LinkedList<T> list;
public:
    void enqueue(T data) { list.insert(data); }
    
    void dequeue() {
        if (list.IsEmpty()) throw std::runtime_error("Queue is empty!");
        list.removeHead();
    }
    
    T front() {
        if (list.IsEmpty()) throw std::runtime_error("Queue is empty!");
        return list.GetDataByIndex(0);
    }
    
    bool isEmpty() {
        return list.IsEmpty();
    }
    
    int size() {
        return list.length;
    }
};

#endif // QUEUE_H