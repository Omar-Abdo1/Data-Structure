#ifndef STACK_H
#define STACK_H

#include "ITI-LinkedList.h"

template <typename T>
class Stack {
    LinkedList<T> list;
public:
    void push(T data) {
        list.insertAtIndex(data, 0); // insert at head
    }

    void pop() {
        if (list.IsEmpty()) throw std::runtime_error("Stack is empty!");
        list.removeHead();
    }

    T peek() {
        if (list.IsEmpty()) throw std::runtime_error("Stack is empty!");
        return list.GetDataByIndex(0);
    }
};

#endif // STACK_H